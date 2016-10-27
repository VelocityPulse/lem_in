/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:08:44 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/27 15:59:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			process(t_lemin *lemin)
{
	t_box	*box;

	if (!(box = get_box_index(lemin->l_box, lemin->start)))
		return (_ERROR_);
	return (_SUCCESS_);
}
