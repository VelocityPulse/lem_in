/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 12:14:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/27 14:35:32 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_box		*new_box(int nbox)
{
	t_box		*box;

	box = (t_box *)ft_memalloc(sizeof(t_box));
	box->nbox = nbox;
	box->weight = _UNKNOW_;
	box->back = _UNKNOW_;
	box->next = NULL;
	return (box);
}

static int			check_duplicate_box(t_box *list, int nbox)
{
	while (list)
	{
		if  (list->nbox == nbox)
			return (_ERROR_);
		list = list->next;
	}
	return (_SUCCESS_);
}

int					add_box(t_lemin *lemin, char *line, t_box **begin)
{
	t_box	*list;
	int		nbox;

	nbox = ft_atoi(line);
	if (check_duplicate_box(*begin, nbox) == _ERROR_)
		exit_lemin(lemin, _ERROR_);
	if (*begin == NULL)
		*begin = new_box(nbox);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = new_box(nbox);
	}
	return (nbox);
}

void				free_lbox(t_box **begin)
{
	t_box	*list;

	list = *begin;
	while (list)
	{
		*begin = list->next;
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}
