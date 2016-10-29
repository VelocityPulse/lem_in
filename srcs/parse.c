/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 11:56:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/29 14:00:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int		push_lem(t_path *list, int lem_id)
{
	if (lem_id == _UNKNOW_ && list->lem_id == _UNKNOW_)
		return (_ERROR_);
	while (list->back && list->lem_id == _UNKNOW_ && list->back->lem_id == _UNKNOW_)
		list = list->back;
	if (list->back == NULL)
	{
		list->lem_id = lem_id;
		return (_SUCCESS_);
	}
	while (list->back != NULL)
	{
		list->lem_id = list->back->lem_id;
		list = list->back;
	}
	list->lem_id = lem_id;
	return (_SUCCESS_);
}

static void		print_path(t_path *path)
{
	while (path)
	{
		if (path->lem_id != _UNKNOW_)
			ft_printf("L%d-%d ", path->lem_id, path->box);
		path = path->next;
	}
	write(1, "\n", 1);
}

void			parse(t_lemin *lemin)
{
	int		lem;

	lem = -1;
	while (++lem <= lemin->nb_lem)
	{
		push_lem(lemin->l_path->end, lem);
		print_path(lemin->l_path);
	}
	while (push_lem(lemin->l_path->end, -1))
		print_path(lemin->l_path);
}
