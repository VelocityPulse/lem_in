/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:48:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/29 12:18:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_path	*new_path_box(int nbox, t_path *end)
{
	t_path		*path_box;

	path_box = (t_path *)ft_memalloc(sizeof(t_path));
	path_box->box = nbox;
	path_box->lem_id = _UNKNOW_;
	path_box->end = end;
	path_box->next = NULL;
	path_box->back = NULL;
	return (path_box);
}

void			add_path_box(int nbox, t_path **end)
{
	t_path		*list;

	if (*end == NULL)
		*end = new_path_box(nbox, *end);
	else
	{
		list = *end;
		while (list->back)
			list = list->back;
		list->back = new_path_box(nbox, *end);
		list->back->next = list;
	}
}

void			free_lpath(t_path **list)
{
	t_path		*temp;

	if (!*list)
		return ;
	if ((*list)->next)
	{
		while (*list)
		{
			temp = (*list)->next;
			ft_memdel((void **)&(*list));
			*list = temp;
		}
		*list = NULL;
	}
	else if ((*list)->back)
	{
		while (*list)
		{
			temp = (*list)->back;
			ft_memdel((void **)&(*list));
			*list = temp;
		}
		*list = NULL;
	}
}
