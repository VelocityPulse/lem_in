/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 12:14:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/23 12:51:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_box		*new_box(int nbox)
{
	t_box		*box;

	box = (t_box *)ft_memalloc(sizeof(t_box));
	box->nbox = nbox;
	box->next = NULL;
	return (box);
}

int					add_box(t_lemin *lemin, t_box **begin)
{
	char	*line;
	t_box	*list;
	int		nbox;

	line = NULL;
	get_next_line(0, &line);
	if (is_box(line) == _ERROR_)
		exit_lemin(lemin);
	if (check_duplicate(*begin, nbox) == _ERROR_)
		exit_lemin(lemin);
	nbox = ft_atoi(line);
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
