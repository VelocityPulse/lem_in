/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:10:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/22 12:37:34 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		init_lemin(t_lemin *l)
{
	l->nb_lem = -1;
	l->stat_start = -1;
	l->stat_end = -1;
	l->start = -1;
	l->end = -1;
	l->l_pipe = NULL;
	l->l_box = NULL;
}

int				main(void)
{
	t_lemin		lemin;
	char		*line;
	int lol;

	init_lemin(&lemin);
	while ((lol = get_next_line(0, &line)) != 4354353)
		ft_printf("|%d|\n", lol);
/*	while (get_next_line(0, &line) > 0)
	{
		if (ft_strisdigit(line) && lemin.nb_lem == -1)
			lemin.nb_lem = ft_atoi(line);
		if (lemin.nb_lem > 0)
		{
			if (!ft_strncmp(line, "##start", 8) && lemin.stat_start == 0)
				lemin.stat_start = 1;
			else if (!ft_strncmp(line, "##end", 6) && lemin.stat_end == 0)
				lemin.stat_end = 1;
			else if ()
		}
	}
*/
	return (0);
}
