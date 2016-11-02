/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:39:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/02 13:14:43 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pipe	*new_pipe(int box[2], int pipe_id)
{
	t_pipe		*pipe;

	pipe = (t_pipe *)ft_memalloc(sizeof(t_pipe));
	pipe->box[0] = box[0];
	pipe->box[1] = box[1];
	pipe->pipe_id = pipe_id;
	pipe->next = NULL;
	return (pipe);
}

static int		check_valid_pipe(t_pipe *listp, t_box *listb, int pipe[2])
{
	int		match;

	match = _UNKNOW_;
	while (listp)
	{
		if (listp->box[BOX1] == pipe[BOX1] && listp->box[BOX2] == pipe[BOX2])
			return (_ERROR_);
		if (listp->box[BOX1] == pipe[BOX2] && listp->box[BOX2] == pipe[BOX1])
			return (_ERROR_);
		listp = listp->next;
	}
	while (listb)
	{
		if (listb->nbox == pipe[BOX1] || listb->nbox == pipe[BOX2])
		{
			if (match == 1)
				return (_SUCCESS_);
			else
				match = 1;
		}
		listb = listb->next;
	}
	return (_ERROR_);
}

void			add_pipe(t_lemin *lemin, char *line, t_pipe **begin)
{
	t_pipe		*list;
	char		**str;
	int			pipe[2];

	str = ft_strsplit(line, '-');
	pipe[0] = ft_atoi(str[0]);
	pipe[1] = ft_atoi(str[1]);
	ft_memdel2((void ***)&str);
	if (pipe[0] == pipe[1])
		exit_lemin(lemin, _ERROR_);
	if (check_valid_pipe(*begin, lemin->l_box, pipe) == _ERROR_)
		exit_lemin(lemin, _ERROR_);
	if (*begin == NULL)
		*begin = new_pipe(pipe, 1);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = new_pipe(pipe, list->pipe_id + 1);
	}
}

void			free_lpipe(t_pipe **begin)
{
	t_pipe		*list;

	list = *begin;
	while (list)
	{
		*begin = list->next;
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}

int		next_pipe(t_pipe *list, int current, int *id)
{
	while (list && list->pipe_id < *id)
		list = list->next;
	while (list)
	{
		if (list->box[BOX1] == current)
		{
			*id = list->pipe_id + 1;
			return (list->box[BOX2]);
		}
		else if (list->box[BOX2] == current)
		{
			*id = list->pipe_id + 1;
			return (list->box[BOX1]);
		}
		list = list->next;
	}
	return (-1);
}

/*
** next_pipe() :
** make pipe in ID position
** travel the pipe list until find an adjacent of 'current'
** in the same time, modify the value of ID with the current id of pipe_list
** return the number of adjacent or error
*/
