/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:04:53 by hbadr             #+#    #+#             */
/*   Updated: 2022/10/26 17:52:47 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	fanc_aplic(int status)
{
	if (status == SIGINT)
	{
		if (g_global.if_fork == 1
			&& ft_strcmp(g_global.last_cmd, "./minishell") != 0)
			write(1, "\n", 1);
		else if (g_global.if_fork == 0)
		{
			g_global.skip = 1;
			g_global.exit_status = 1;
			rl_done = 1;
		}
	}
	else if (status == SIGQUIT)
	{
		if (g_global.if_fork == 1
			&& ft_strcmp(g_global.last_cmd, "./minishell") != 0)
			ft_putendl_fd("^'\'Quit: 3", 1);
	}
}

int	get_c(void)
{
	return (0);
}
