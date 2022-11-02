/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:34:00 by hbadr             #+#    #+#             */
/*   Updated: 2022/10/22 07:56:07 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	wait_and_return_value_of_waitpid(t_mini *lst)
{
	if (lst->next == NULL)
	{
		if (waitpid(g_global.pid, &g_global.exit_status, 0) != -1)
		{
			if (WIFEXITED(g_global.exit_status))
				g_global.exit_status = WEXITSTATUS(g_global.exit_status);
			else
				g_global.exit_status = WTERMSIG(g_global.exit_status) + 128;
		}
		while (waitpid(0, NULL, 0) != -1)
			;
	}
}
