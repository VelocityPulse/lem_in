/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 15:15:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/25 15:51:06 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int				is_pipe(char *line)
{
	int		i;
	int		part;

	part = 1;
	i = -1;
	if (ft_strlen(line) == 0)
	{
		return (_ERROR_);
	}
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
			;
		else if (line[i] == '-')
		{
			part++;
			if (part > 2)
				return (_ERROR_);
		}
		else
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

static int		help_is_box(char *line)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	if (ft_memlen((void **)str) != 3)
	{
		ft_memdel2((void ***)&str);
		return (_ERROR_);
	}
	ft_memdel2((void ***)&str);
	return (_SUCCESS_);
}

int				is_box(char *line)
{
	int		i;
	int		part;

	part = 1;
	i = -1;
	if (help_is_box(line) == _ERROR_)
		return (_ERROR_);
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
			;
		else if (line[i] == ' ')
		{
			part++;
			if (part > 3)
				return (_ERROR_);
		}
		else
			return (_ERROR_);
	}
	return (_SUCCESS_);
}
