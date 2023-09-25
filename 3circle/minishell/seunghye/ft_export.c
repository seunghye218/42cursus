/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:41:47 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 12:51:23 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	*check_name(char *name)
{
	int	i;

	if (!name)
		return (0);
	i = 0;
	while (name[i] && name[i] != '=' && (name[i] == '_' || ft_isalnum(name[i])))
		i++;
	if (*name == '=' || ft_isdigit(*name) || (name[i] && name[i] != '='))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	return (&name[i]);
}

static t_list	*get_name_env(t_list *env, char *name)
{
	char	**strs;
	char	**name2;

	name2 = ft_split(name, '=');
	while (env)
	{
		strs = ft_split(env->content, '=');
		if (!ft_strncmp(strs[0], name2[0], ft_strlen(name2[0])))
		{
			free_split(strs);
			free_split(name2);
			return (env);
		}
		free_split(strs);
		env = env->next;
	}
	free_split(name2);
	return (0);
}

static char	**equal_split(char *content)
{
	char	**strs;
	char	*p;
	int		len;

	if (!content)
		return (0);
	p = ft_strchr(content, '=');
	if (!p)
	{
		strs = malloc(sizeof(char *) * 2);
		strs[0] = ft_strdup(content);
		strs[1] = 0;
		return (strs);
	}
	len = ft_strlen(content);
	strs = malloc(sizeof(char *) * 3);
	strs[0] = ft_strndup(content, p - content + 1);
	strs[0][p - content] = 0;
	strs[1] = ft_strndup(p + 1, len - (p - content));
	strs[2] = 0;
	return (strs);
}

static int	none_arg(t_list *env)
{
	char	**strs;

	while (env)
	{
		if (!(ft_strncmp(env->content, "_=", 2)))
		{
			env = env->next;
			continue ;
		}
		strs = equal_split(env->content);
		if (!strs[1])
			printf("declare -x %s\n", strs[0]);
		else
			printf("declare -x %s=\"%s\"\n", strs[0], strs[1]);
		free_split(strs);
		env = env->next;
	}
	return (0);
}

int	ft_export(char **args, t_list **env)
{
	char	*s;
	int		i;
	t_list	*tmp;

	i = 1;
	if (!args[1])
		return (none_arg(*env));
	while (args[i])
	{
		s = check_name(args[i]);
		if (!s && i++)
			continue ;
		tmp = get_name_env(*env, args[i]);
		if (tmp)
		{
			if (!*s && i++)
				continue ;
			lstdel_node(env, tmp);
		}
		ft_lstadd_back(env, ft_lstnew(ft_strdup(args[i])));
		i++;
	}
	return (0);
}
