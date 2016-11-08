/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:41:26 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/08 10:50:39 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "get_next_line.h"

# include "debug.h"

# define _UNKNOW_	-1

typedef struct	s_box
{
	char			*name;
	int				weight;
	char			*back;
	struct s_box	*next;
}				t_box;

typedef struct	s_pipe
{
	char			*box[2];
	int				pipe_id;
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_path
{
	char			*box;
	int				lem_id;
	struct s_path	*next;
	struct s_path	*back;
	struct s_path	*end;
}				t_path;

typedef struct	s_lemin
{
	int			nb_lem;
	char		*start;
	char		*end;
	int			end_weight;
	t_path		*l_path;
	t_pipe		*l_pipe;
	t_box		*l_box;
	t_lstline	*lstline;
}				t_lemin;

void			init_lemin(t_lemin *l);
int				process(t_lemin *lemin);
void			parse(t_lemin *lemin);

int				is_pipe(char *line);
int				is_box(char *line);

char			*add_box(t_lemin *lemin, char *line, t_box **begin);
t_box			*get_box_index(t_box *list, char *name);
void			free_lbox(t_box **begin);

void			add_pipe(t_lemin *lemin, char *l, t_pipe **begin);
char			*next_pipe(t_pipe *list, char *name, int *id);
void			free_lpipe(t_pipe **begin);

void			add_path_box(char *name, t_path **end);
void			free_lpath(t_path **begin);

void			exit_lemin(t_lemin *lemin, int mode);

#endif
