/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:44:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/25 14:46:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_gnl
{
	char		*buff;
	char		*temp;
	int			ret;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
