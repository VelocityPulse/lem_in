/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 15:15:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/03 14:48:10 by cchameyr         ###   ########.fr       */
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
		return (_ERROR_);
	while (line[++i])
	{
		if (ft_isalnum(line[i]) == _SUCCESS_)
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

int				is_box(char *line)
{
	int		i;
	int		part;
	char	**str;

	part = 1;
	i = -1;
	str = ft_strsplit(line, ' ');
	if (ft_memlen((void **)str) != 3)
	{
		ft_memdel2((void ***)&str);
		return (_ERROR_);
	}
	if (str[0][0] == 'L' || ft_strisdigit(str[1]) == _ERROR_ ||
			ft_strisdigit(str[2]) == _ERROR_)
	{
		ft_memdel2((void ***)&str);
		return (_ERROR_);
	}
	ft_memdel2((void ***)&str);
	return (_SUCCESS_);
}
