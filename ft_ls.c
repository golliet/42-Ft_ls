/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:16:34 by golliet           #+#    #+#             */
/*   Updated: 2018/01/15 16:43:57 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

static int		ft_is_point(char *str)
{
	if (ft_strcmp(str, ".") == 0)
		return (1);
	if (ft_strcmp(str, "..") == 0)
		return (1);
	return (0);
}

static	void	ft_search(t_flag *flag, char *str)
{
	t_list			*first;
	t_list			*list;
	DIR				*dir;
	t_list			*test;

	if (!(dir = opendir(str)) && ft_display_error_open(str, errno) == 1)
		return ;
	list = ft_list_init(list, flag);
	first = list;
	test = list;
	list = ft_fill_list(str, list, flag, dir);
	if (flag->f == 0)
		ft_fsort(first, flag);
	ft_read_name(first, flag, 0);
	if (flag->rmaj)
		while ((first = first->next))
			if ((S_ISDIR(first->data->stat.st_mode) ||
				ft_is_lnk_dir(first->data->stat, first->data->str)) == 1 &&
				ft_is_point(first->data->str) != 1)
				ft_search(flag, first->data->path);
	ft_free_list(&test);
	closedir(dir);
}

void			ft_lnklist(t_list *list, t_flag *flag, char *str)
{
	t_list *first;

	list = ft_list_init(list, flag);
	first = list;
	list = ft_add_elem(list, NULL, str, flag);
	ft_read_name(first, flag, 1);
	ft_free_list(&list);
}

void			ft_ls(t_list *list, t_param *pa, struct stat buf, t_flag flag)
{
	while (pa)
	{
		if (ft_buflstat(flag, pa->str, &buf) == 0)
			break ;
		if (S_ISLNK(buf.st_mode))
			ft_lnklist(list, &flag, pa->str);
		else if (!S_ISDIR(buf.st_mode))
			ft_putendl(pa->str);
		else
		{
			if (buf.st_mode & S_IRUSR)
				ft_search(&flag, pa->str);
			else
				ft_permission_denied(pa->str);
		}
		pa = pa->next;
	}
}

int				main(int argc, char **argv)
{
	t_flag			flag;
	t_param			*paramv;
	struct stat		buf;
	char			*str;
	t_list			*list;

	paramv = ft_parse(argc, argv, &flag);
	if (paramv != NULL)
	{
		ft_sort_param(paramv);
		ft_ls(list, paramv, buf, flag);
		ft_free_param(paramv);
	}
	else if (flag.inv == 1)
		;
	else
		ft_search(&flag, ".");
	return (0);
}
