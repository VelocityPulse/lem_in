/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:30:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/08 10:31:09 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		init_lemin(t_lemin *l)
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
