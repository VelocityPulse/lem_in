/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:10:11 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/22 11:29:34 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "get_next_line.h"

# define	BOX1 0
# define	BOX2 1

typedef struct	s_box
{
	int				nbox;
	struct s_box	*next;
	struct s_box	*back;
}				t_box;

typedef struct	s_pipe
{
	int				box[2];
	struct s_pipe	*next;
	struct s_pipe	*back;
}				t_pipe;

typedef struct	s_lemin
{
	int			nb_lem;
	t_bool		stat_start;
	t_bool		stat_end;
	int			start;
	int			end;
	t_pipe		*l_pipe;
	t_box		*l_box;
}				t_lemin;

#endif
