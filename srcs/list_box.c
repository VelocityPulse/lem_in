/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 12:14:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/03 14:17:39 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_box		*new_box(char *name)
{
	t_box		*box;

	box = (t_box *)ft_memalloc(sizeof(t_box));
	box->name = name;
	box->weight = _UNKNOW_;
	box->back = NULL;
	box->next = NULL;
	return (box);
}

static int			check_duplicate_box(t_box *list, char *name)
{
	while (list)
	{
		if  (!ft_strcmp(list->name, name))
			return (_ERROR_);
		list = list->next;
	}
	return (_SUCCESS_);
}

char				*add_box(t_lemin *lemin, char *line, t_box **begin)
{
	t_box	*list;
	char	**str;
	char	*name;

	if (ft_strchr(&line[ft_strlen(line) - 1], ' '))
		exit_lemin(lemin, _ERROR_);
	str = ft_strsplit(line, ' ');
	name = ft_strdup(str[0]);
	ft_memdel2((void ***)&str);
	if (check_duplicate_box(*begin, name) == _ERROR_)
		exit_lemin(lemin, _ERROR_);
	if (*begin == NULL)
		*begin = new_box(name);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = new_box(name);
	}
	return (name);
}

void				free_lbox(t_box **begin)
{
	t_box	*list;

	list = *begin;
	while (list)
	{
		*begin = list->next;
		ft_memdel((void **)&list->name);
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}

t_box				*get_box_index(t_box *list, char *name)
{
	while (list)
	{
		if (!ft_strcmp(list->name, name))
			return (list);
		list = list->next;
	}
	return (_ERROR_);
}
