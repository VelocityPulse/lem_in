/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:56:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/25 15:52:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	exit_lemin(t_lemin *lemin, int mode)
{
	if (mode == _ERROR_)
		ft_putstr("ERROR\n");
	free_lbox(&lemin->l_box);
	free_lpipe(&lemin->l_pipe);
	ft_lstline_del(&lemin->lstline);
	_exit(0);
}
