/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:10:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/24 16:13:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		init_lemin(t_lemin *l)
{
	l->nb_lem = -1;
	l->start = -1;
	l->end = -1;
	l->l_pipe = NULL;
	l->l_box = NULL;
	l->lstline = NULL;
}

static void		nb_lem(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strisdigit(line) == 1)
			lemin->nb_lem = ft_atoi(line);
		else if (!ft_strncmp(line, "#", 1))
			;
		else
		{
			ft_putstr("ERROR\n");
			_exit(0);
		}
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
}

static void		help_get_map(t_lemin *lemin, char *line)
{
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if (!ft_strncmp(line, "#", 1))
			;
		else if (is_pipe(line))
			add_pipe(lemin, line, &lemin->l_pipe);
		else
			break;
		ft_memdel((void **)&line);
		ret = get_next_line(0, &line);
	}
	ft_memdel((void **)&line);
}

static void		get_map(t_lemin *lemin)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "##start", 8))
			lemin->start = add_box(lemin, &lemin->l_box);
		else if (!ft_strncmp(line, "##end", 6))
			lemin->end = add_box(lemin, &lemin->l_box);
		else if (is_box(line) == _SUCCESS_)
		{
			add_box(lemin, &lemin->l_box);
		}
		else if (!ft_strncmp(line, "#", 1))
			;
		else
			break;
		ft_memdel((void **)&line);
	}
	help_get_map(lemin, line);
	ft_memdel((void **)&line);
}

int				main(void)
{
	t_lemin		lemin;

	init_lemin(&lemin);
	nb_lem(&lemin);
	get_map(&lemin);

	t_lstline *lst;
	lst = lemin.lstline;
	while (lst)
	{
		ft_printf("%d\n", lst->line);
		lst = lst->next;
	}
	return (0);
}
