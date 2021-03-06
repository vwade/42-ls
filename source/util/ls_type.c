/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:41 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 12:44:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	ls_color(t_entry *e)
{
	e->color = 7;
	((e->t.t == 'b') && (e->color = 44)) ||
	((e->t.t == 'c') && (e->color = 11)) ||
	((e->t.t == 'd') && (e->color = 32)) ||
	((e->t.t == 'l') && (e->color = 5)) ||
	((e->t.t == 's') && (e->color = 118)) ||
	((e->t.t == 'p') && (e->color = 197)) ||
	(e->t.t == '-'
	&& (((e->t.owner[2] | e->t.group[2] | e->t.other[2]) & ~5) == 'x')
	&& (e->color = 1));
	return (1);
}

static int
	ls_link(e)
	t_entry *e;
	{
	readlink(e->fullname, e->link, PATH_MAX);
	ft_strcat(ft_strncpy(e->name_ext, " -> ", 5), e->link);
	return (1);
}

static void
	ls_typecheck(t_entry *e)
{
	((S_ISBLK(e->stat.st_mode)) && (e->t.t = 'b')) ||
	((S_ISCHR(e->stat.st_mode)) && (e->t.t = 'c')) ||
	((S_ISDIR(e->stat.st_mode)) && (e->t.t = 'd')) ||
	((S_ISLNK(e->stat.st_mode)) && (e->t.t = 'l') && ls_link(e)) ||
	((S_ISSOCK(e->stat.st_mode)) && (e->t.t = 's')) ||
	((S_ISFIFO(e->stat.st_mode)) && (e->t.t = 'p')) ||
	(e->t.t = '-');
}

static void
	ls_attributes(t_entry *e)
{
	e->t.owner[0] = (e->stat.st_mode & S_IRUSR) ? 'r' : '-';
	e->t.owner[1] = (e->stat.st_mode & S_IWUSR) ? 'w' : '-';
	e->t.owner[2] = (e->stat.st_mode & S_IXUSR) ? 'x' : '-';
	e->t.group[0] = (e->stat.st_mode & S_IRGRP) ? 'r' : '-';
	e->t.group[1] = (e->stat.st_mode & S_IWGRP) ? 'w' : '-';
	e->t.group[2] = (e->stat.st_mode & S_IXGRP) ? 'x' : '-';
	e->t.other[0] = (e->stat.st_mode & S_IROTH) ? 'r' : '-';
	e->t.other[1] = (e->stat.st_mode & S_IWOTH) ? 'w' : '-';
	e->t.other[2] = (e->stat.st_mode & S_IXOTH) ? 'x' : '-';
}

int
	ls_type(e)
	t_entry *e;
	{
	e->t.null = 0;
	ls_attributes(e);
	ls_typecheck(e);
	ls_xcheck(e);
	((!e->color) && (e->color = 7)) || ls_color(e);
	return (1);
}
