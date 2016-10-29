/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:08:44 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/29 11:53:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_path	*make_path(t_lemin *lemin, t_box *lbox)
{
	t_path		*end;
	t_path		*begin;
	t_box		*box;

	end = NULL;
	box = get_box_index(lbox, lemin->end);
	while (box->nbox != lemin->start)
	{
		add_path_box(box->nbox, &end);
		box = get_box_index(lbox, box->back);
	}
	begin = end;
	while (begin->back)
		begin = begin->back;
	return (begin);
}

static void		recursive_search(t_lemin *lemin, t_box *box, int weight)
{
	int		pipe_id;
	int		next_box_id;
	t_box	*next_box;

	pipe_id = -1;
	if (box->nbox == lemin->end)
	{
		lemin->end_weight = box->weight;
		return ;
	}
	if (lemin->end_weight > 0 && box->weight >= lemin->end_weight)
		return ;
	while (!((next_box_id = next_pipe(lemin->l_pipe, box->nbox, &pipe_id)) == -1))
	{
		next_box = get_box_index(lemin->l_box, next_box_id);
		if (next_box->weight == _UNKNOW_ || next_box->weight > weight)
		{
			next_box->weight = weight;
			next_box->back = box->nbox;
			recursive_search(lemin, next_box, weight + 1);
		}
	}
}

int			process(t_lemin *lemin)
{
	t_box	*box;

	box = get_box_index(lemin->l_box, lemin->start);
	box->weight = 0;
	box->back = _UNKNOW_;
	recursive_search(lemin, box, 1);
	box = lemin->l_box;
	if (box->weight == _UNKNOW_)
		exit_lemin(lemin, _ERROR_);
	lemin->l_path = make_path(lemin, lemin->l_box);
	return (_SUCCESS_);
}
