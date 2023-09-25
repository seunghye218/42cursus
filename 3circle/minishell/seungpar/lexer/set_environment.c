/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:02:32 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 17:31:33 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_environment(struct termios *term)
{
	if (term != NULL)
	{
		if (tcgetattr(STDIN_FILENO, term) == -1)
			print_error_and_exit(strerror(errno), 2, 1);
		term->c_lflag &= ~(ECHOCTL);
		if (tcsetattr(STDIN_FILENO, TCSANOW, term) == -1)
			print_error_and_exit(strerror(errno), 2, 1);
	}
	setting_signal();
}
