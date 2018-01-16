/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:41:41 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 12:24:13 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>

void	ft_gmin(t_list *list, t_rank *rank)
{
	char *pwd;

	pwd = ft_passwd(list->data->stat, NULL);
	ft_display_nb_space_str(pwd, rank->rpwd);
	ft_putstr("  ");
	free(pwd);
}

void	ft_o(t_list *list, t_rank *rank)
{
	char	*group;

	group = ft_group(list->data->stat, NULL);
	ft_display_nb_space_str(group, rank->rgroup);
	free(group);
}

void	ft_display_link(t_list *list)
{
	char	path[PATH_MAX];
	int		a;

	ft_putstr(" -> ");
	if ((a = readlink(list->data->path, path, PATH_MAX)) == -1)
		ft_putstr("error");
	else
	{
		path[a] = '\0';
		ft_putstr(path);
	}
}

int		ft_print_right(t_flag *flag, t_list *list, t_rank *rank)
{
	ft_first(flag, list, rank);
	if (flag->gmin == 0)
		ft_gmin(list, rank);
	if (flag->o == 0)
		ft_o(list, rank);
	ft_block(list->data->stat, rank);
	ft_putstr(" ");
	ft_display_date(list->data->stat);
	ft_putstr(" ");
	if (flag->g == 1)
		ft_choose_color(list);
	else
		ft_putstr(list->data->str);
	if (S_ISLNK(list->data->stat.st_mode))
		ft_display_link(list);
	ft_putchar('\n');
	return (1);
}
