/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:28:33 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 16:27:13 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include <string.h>
# include <signal.h>
# include <stdio.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define CMD_TOKEN		(1)
# define REDIR_TOKEN	(2)
# define PIPE_TOKEN		(3)
# define WORD_TOKEN		(4)

typedef struct s_token
{
	int				type;
	char			*content;
	struct s_token	*next;
}			t_token;

typedef struct s_info
{
	t_token			**cmds;
	unsigned char	exit_status;
	int				size;
}			t_info;

typedef struct s_pid
{
	pid_t			*pid;
	int				size;
	unsigned char	status;
}	t_pid;

#endif
