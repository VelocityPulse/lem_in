/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:39:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/03 14:00:56 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pipe	*new_pipe(char *box[2], int pipe_id)
{
	t_pipe		*pipe;

	pipe = (t_pipe *)ft_memalloc(sizeof(t_pipe));
	pipe->box[0] = box[0];
	pipe->box[1] = box[1];
	pipe->pipe_id = pipe_id;
	pipe->next = NULL;
	return (pipe);
}

static int		check_valid_pipe(t_pipe *lp, t_box *lb, char *pipe[2])
{
	int		match;

	match = _UNKNOW_;
	while (lp)
	{
		if (!ft_strcmp(lp->box[0], pipe[0]) &&
				!ft_strcmp(lp->box[1], pipe[1]))
			return (_ERROR_);
		if (!ft_strcmp(lp->box[0], pipe[1]) &&
				!ft_strcmp(lp->box[1], pipe[0]))
			return (_ERROR_);
		lp = lp->next;
	}
	while (lb)
	{
		if (!ft_strcmp(lb->name, pipe[0]) || !ft_strcmp(lb->name, pipe[1]))
		{
			if (match == 1)
				return (_SUCCESS_);
			else
				match = 1;
		}
		lb = lb->next;
	}
	return (_ERROR_);
}

void			add_pipe(t_lemin *lemin, char *line, t_pipe **begin)
{
	t_pipe		*list;
	char		**str;
	char		*pipe[2];

	str = ft_strsplit(line, '-');
	if (ft_memlen((void **)str) != 2)
	{
		ft_memdel2((void ***)&str);
		exit_lemin(lemin, _ERROR_);
	}
	pipe[0] = ft_strdup(str[0]);
	pipe[1] = ft_strdup(str[1]);
	ft_memdel2((void ***)&str);
	if (!ft_strcmp(pipe[0], pipe[1]) ||
			!check_valid_pipe(*begin, lemin->l_box, pipe))
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
		ft_memdel((void **)&list->box[0]);
		ft_memdel((void **)&list->box[1]);
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}

char	*next_pipe(t_pipe *list, char *name, int *id)
{
	while (list && list->pipe_id < *id)
		list = list->next;
	while (list)
	{
		if (!ft_strcmp(list->box[0], name))
		{
			*id = list->pipe_id + 1;
			return (list->box[1]);
		}
		else if (!ft_strcmp(list->box[1], name))
		{
			*id = list->pipe_id + 1;
			return (list->box[0]);
		}
		list = list->next;
	}
	return (NULL);
}

/*
** next_pipe() :
** make pipe in ID position
** travel the pipe list until find an adjacent of 'current'
** in the same time, modify the value of ID with the current id of pipe_list
** return the number of adjacent or error
*/
