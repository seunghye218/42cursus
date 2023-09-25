/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:58:17 by seunghye          #+#    #+#             */
/*   Updated: 2022/08/30 11:00:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <signal.h>
#include <sys/fcntl.h>
#include <unistd.h>

typedef struct	s_pipex
{
	int		stdin;
	int		stdout;
	char	*cmd;
	char	**args;
}	t_pipex;

t_pipex	init_p(int stdin, int stdout, char *cmd, char **args)
{
	t_pipex	p;
	
	p.stdin = stdin;
	p.stdout = stdout;
	p.cmd = cmd;
	p.args = args;
	return (p);
}

int	execute(t_pipex p, char **path, char **envp)
{
	int		i;
	char	*tmp;

// p.in에 해당하는 파일로 입력 받음
	dup2(p.stdin, 0);
// p.out에 해당하는 파일로 출력
	dup2(p.stdout, 1);
	close(p.stdin);
	close(p.stdout);
	execve(p.cmd, p.args, envp);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		execve(ft_strjoin(tmp, p.cmd), p.args, envp);
		free(tmp);
		i++;
	}
	perror("execve error : ");
	return (1);
}

char	**get_env_path(char **envp)
{
	int	i;
	char	*tmp;
	char	**ret;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tmp = ft_strdup(envp[i] + 5);
			ret = ft_split(tmp, ':');
			free(tmp);
			return (ret);
		}	
		i++;
	}
	return (0);
}

int	madatory(char **av, char **envp)
{
	int 	fd_infile;
	int		fd_outfile;
	pid_t	pid[2];
	char	**cmd[2];
	int		pip[2];
	char	**path;

// PATH ':' 구분자 split return
	path = get_env_path(envp);

// infile 및 outfile 오픈
	if (((fd_infile = open(av[1], O_RDONLY)) < 0))
	{
		perror("open error:");
		return (1);
	}
// command 인자 split
	cmd[0] = ft_split(av[2], ' ');
	cmd[1] = ft_split(av[3], ' ');
// 파이프 생성
	if (pipe(pip))
	{
		perror("pipe error : ");
		return (1);
	}
// 자식 프로세스 생성
	pid[0] = fork();
	if (pid[0] == -1)
	{
		perror("fork error : ");
		return (1);
	}
	else if (pid[0] == 0)
	{
		if (execute(init_p(fd_infile, pip[1], cmd[0][0], cmd[0]), path, envp))
			return (1);
	}
// 안쓰는 fd 닫기
	close(fd_infile);
	close(pip[1]);
	if ((pid[1] = fork()) == -1)
	{
		perror("fork error : ");
		return (1);
	}
	if (pid[1] == 0)
	{
		if ((fd_outfile = open(av[4], O_CREAT|O_WRONLY, 0644)) < 0)
		{
			perror("open error:");
			return (1);
		}
	if (execute(init_p(pip[0], fd_outfile, cmd[1][0], cmd[1]), path, envp))
		return (1);
	}
	wait(0);
	wait(0);
	return (0);
}

int	bonus_here_doc_appending(char **av, char **envp)
{
	int		bytes;
	int		fd_outfile;
	int		fd_tmp;
	pid_t	pid[2];
	char	**cmd[2];
	int		pip[2];
	char	**path;
	char	*eof;
	char	buf[512];

	eof = ft_strjoin(av[2], "\n");
	path = get_env_path(envp);
	cmd[0] = ft_split(av[3], ' ');
	cmd[1] = ft_split(av[4], ' ');
	if (pipe(pip))
	{
		perror("pipe error : ");
		return (1);
	}
// 임시파일 생성 및 eof 입력 까지 write
	fd_tmp = open("here_doc_tmp_file", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	while (1)
	{
		bytes = read(0, buf, 511);
		buf[bytes] = 0;
		if (!ft_strncmp(buf, eof, ft_strlen(eof) + 2))
			break ;
		write(fd_tmp, buf, bytes);
	}
	free(eof); 
	close(fd_tmp);
	pid[0] = fork();
	if (pid[0] == -1)
	{
		perror("fork error : ");
		return (1);
	}
	else if (pid[0] == 0)
	{
		fd_tmp = open("here_doc_tmp_file", O_RDONLY, 0644);
		close(pip[0]);
		if (execute(init_p(fd_tmp, pip[1], cmd[0][0], cmd[0]), path, envp))
			return (1);
	}
// 안쓰는 fd 닫기
	close(pip[1]);
	// close(fd_tmp);

	if ((pid[1] = fork()) == -1)
	{
		perror("fork error : ");
		return (1);
	}
	if (pid[1] == 0)
	{
		if ((fd_outfile = open(av[5], O_CREAT|O_WRONLY|O_APPEND, 0644)) < 0)
		{
			perror("open error:");
			return (1);
		}
		if (execute(init_p(pip[0], fd_outfile, cmd[1][0], cmd[1]), path, envp))
			return (1);
	}
	wait(0);
	unlink("here_doc_tmp_file");
	wait(0);
	return (0);
}

// int	multiple_pipe(char **av, char **envp)
// {
// 	int 	fd_infile;
// 	int		fd_outfile;
// 	pid_t	pid[2];
// 	char	**cmd[2];
// 	int		pip[2][2];
// 	char	**path;

// // PATH ':' 구분자 split return
// 	path = get_env_path(envp);
// // infile 및 outfile 오픈
// 	if (((fd_infile = open(av[1], O_RDONLY)) < 0))
// 	{
// 		perror("open error:");
// 		return (1);
// 	}
// 	cmd[0] = ft_split(av[2], ' ');
// 	cmd[1] = ft_split(av[3], ' ');
// 	if (pipe(pip[0]) || pipe(pip[1]))
// 	{
// 		perror("pipe error : ");
// 		return (1);
// 	}
// 	pid[0] = fork();
// 	if (pid[0] == -1)
// 	{
// 		perror("fork error : ");
// 		return (1);
// 	}
// 	else if (pid[0] == 0)
// 	{
// 		if (execute(init_p(fd_infile, pip[1], cmd[0][0], cmd[0]), path, envp))
// 			return (1);
// 	}
// 	close(fd_infile);
// 	close(pip[1]);
// 	if ((pid[1] = fork()) == -1)
// 	{
// 		perror("fork error : ");
// 		return (1);
// 	}
// 	if (pid[1] == 0)
// 	{
// 		if ((fd_outfile = open(av[4], O_CREAT|O_WRONLY, 0644)) < 0)
// 		{
// 			perror("open error:");
// 			return (1);
// 		}
// 	if (execute(init_p(pip[0], fd_outfile, cmd[1][0], cmd[1]), path, envp))
// 		return (1);
// 	}
// 	wait(0);
// 	wait(0);
// 	return (0);
// }

int main(int ac, char **av, char **envp)
{
	if (ac < 5)
	{
		printf("invalid args\n");
		return (0);
	}
	if (ac == 5)
		return (madatory(av, envp));
	else if (ac == 6 && !ft_strncmp(av[1], "here_doc", 8))
		return (bonus_here_doc_appending(av, envp));
	else
		;
		// return (multiple_pipe(av, envp));
	return (0);
}
