/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:37:33 by golliet           #+#    #+#             */
/*   Updated: 2018/01/15 13:58:32 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "color.h"

void	ft_putstr_c(char *str, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, "\033[0m", 5);
}

int		ft_hyell(struct stat stat)
{
	if ((stat.st_mode & S_IRUSR) && (stat.st_mode & S_IWUSR) &&
		(stat.st_mode & S_IRGRP) && (stat.st_mode & S_IWGRP) &&
		(stat.st_mode & S_IROTH) && (stat.st_mode & S_IWOTH))
		return (1);
	return (0);
}

int		ft_capital(struct stat stat)
{
	if ((stat.st_mode & S_IRUSR) && (stat.st_mode & S_IWUSR) &&
		(stat.st_mode & S_IXUSR) && (stat.st_mode & S_IRGRP) &&
		(stat.st_mode & S_IWGRP) && (stat.st_mode & S_IXGRP) &&
		(stat.st_mode & S_IROTH) && (stat.st_mode & S_IWOTH) &&
		(stat.st_mode & S_IXOTH))
		return (1);
	return (0);
}

void	ft_choose_color(t_list *list)
{
	if (S_ISDIR(list->data->stat.st_mode))
	{
		if (ft_hyell(list->data->stat) == 1)
			ft_putstr_c(list->data->str, HGREEN);
		else
			ft_putstr_c(list->data->str, BLUE);
	}
	else if (S_ISREG(list->data->stat.st_mode))
	{
		if (((list->data->stat.st_mode & S_ISUID) ||
					(list->data->stat.st_mode & S_ISGID)))
			ft_putstr_c(list->data->str, HRED);
		else if ((list->data->stat.st_mode & S_IXOTH) ||
				(list->data->stat.st_mode & S_IXGRP) ||
				(list->data->stat.st_mode & S_IXUSR))
			ft_putstr_c(list->data->str, RED);
		else
			ft_putstr(list->data->str);
	}
	else if (S_ISLNK(list->data->stat.st_mode))
		ft_putstr_c(list->data->str, PINK);
	else if (S_ISCHR(list->data->stat.st_mode))
		ft_putstr_c(list->data->str, HYELLOW);
	else
		ft_putstr(list->data->str);
}
