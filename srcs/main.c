/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:10:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/03 14:51:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		init_lemin(t_lemin *l)
{
	l->nb_lem = _UNKNOW_;
	l->start = NULL;
	l->end = NULL;
	l->end_weight = _UNKNOW_;
	l->l_pipe = NULL;
	l->l_box = NULL;
	l->l_path = NULL;
	l->lstline = NULL;
}

static void		nb_lem(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strisdigit(line) == 1 && ft_strlen(line) > 0)
		{
			lemin->nb_lem = ft_atoi(line);
			if (lemin->nb_lem <= 0)
				exit_lemin(lemin, _ERROR_);
			ft_add_lstline(&lemin->lstline, line);
			break;
		}
		else if (!ft_strncmp(line, "#", 1) && line[1] != '#')
			;
		else
			exit_lemin(lemin, _ERROR_);
		ft_add_lstline(&lemin->lstline, line);
	}
}

static int		get_start_end(t_lemin *lemin, char *line)
{
	if (!ft_strncmp(line, "##start", 8))
	{
		get_next_line(0, &line);
		if (line == NULL || is_box(line) == _ERROR_)
			exit_lemin(lemin, _ERROR_);
		lemin->start = add_box(lemin, line, &lemin->l_box);
		ft_add_lstline(&lemin->lstline, line);
		return (_SUCCESS_);
	}
	else if (!ft_strncmp(line, "##end", 6))
	{
		get_next_line(0, &line);
		if (line == NULL || is_box(line) == _ERROR_)
			exit_lemin(lemin, _ERROR_);
		lemin->end = add_box(lemin, line, &lemin->l_box);
		ft_add_lstline(&lemin->lstline, line);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void		help_get_map(t_lemin *lemin, char *line)
{
	int		ret;

	ret = 1;
	if (lemin->start < 0 || lemin->end < 0)
		exit_lemin(lemin, _ERROR_);
	while (ret > 0)
	{
		if (!ft_strncmp(line, "#", 1))
			;
		else if (is_pipe(line) == _SUCCESS_)
			add_pipe(lemin, line, &lemin->l_pipe);
		else
			break;
		ret = get_next_line(0, &line);
		ft_add_lstline(&lemin->lstline, line);
	}
}

static void		get_map(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_add_lstline(&lemin->lstline, line);
		if (get_start_end(lemin, line) == _SUCCESS_)
			;
		else if (is_box(line) == _SUCCESS_)
			add_box(lemin, line, &lemin->l_box);
		else if (!ft_strncmp(line, "#", 1))
			;
		else
			break;
	}
	help_get_map(lemin, line);
}

int				main(void)
{
	t_lemin		lemin;

	init_lemin(&lemin);
	nb_lem(&lemin);
	get_map(&lemin);
	ft_supp_lstline(&lemin.lstline);
	if (!process(&lemin))
		exit_lemin(&lemin, _ERROR_);
	ft_print_lstline(lemin.lstline);
	parse(&lemin);
	exit_lemin(&lemin, _SUCCESS_);
	return (0);
}
