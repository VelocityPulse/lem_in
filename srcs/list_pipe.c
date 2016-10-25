/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:39:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/25 10:47:11 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_pipe	*new_pipe(int box[2])
{
	t_pipe		*pipe;

	pipe = (t_pipe *)ft_memalloc(sizeof(t_pipe));
	pipe->box[0] = box[0];
	pipe->box[1] = box[1];
	pipe->next = NULL;
	return (pipe);
}

static int		check_duplicate_pipe(t_pipe *list, int pipe[2])
{
	while (list)
	{
		if (list->box[0] == pipe[0] && list->box[1] == pipe[1])
			return (_ERROR_);
		if (list->box[0] == pipe[1] && list->box[1] == pipe[0])
			return (_ERROR_);
		list = list->next;
	}
	return (_SUCCESS_);
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
	if (check_duplicate_pipe(*begin, pipe) == _ERROR_)
		exit_lemin(lemin, _ERROR_);
	if (*begin == NULL)
		*begin = new_pipe(pipe);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = new_pipe(pipe);
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
