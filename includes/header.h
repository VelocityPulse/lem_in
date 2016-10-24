/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:10:11 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/24 16:00:41 by cchameyr         ###   ########.fr       */
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
}				t_box;

typedef struct	s_pipe
{
	int				box[2];
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_lemin
{
	int			nb_lem;
	int			start;
	int			end;
	t_pipe		*l_pipe;
	t_box		*l_box;
	t_lstline	*lstline;
}				t_lemin;

int				is_pipe(char *line);
int				is_box(char *line);

int				add_box(t_lemin *lemin, t_box **begin);
void			free_lbox(t_box **begin);
void			add_pipe(t_lemin *lemin,
		char *line, t_pipe **begin);
void			free_lpipe(t_pipe **begin);

void			exit_lemin(t_lemin *lemin);



#endif
