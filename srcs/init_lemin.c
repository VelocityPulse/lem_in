/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:30:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/09 17:24:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		init_lemin(t_lemin *lemin)
{
	lemin->nb_lem = _UNKNOW_;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->end_weight = _UNKNOW_;
	lemin->l_pipe = NULL;
	lemin->l_box = NULL;
	lemin->l_path = NULL;
	lemin->lstline = NULL;
}
