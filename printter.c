/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:45:19 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 12:25:00 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

void	ft_right(struct stat stat)
{
	if (S_ISLNK(stat.st_mode))
		ft_putstr("l");
	else if (S_ISFIFO(stat.st_mode))
		ft_putstr("p");
	else if (S_ISBLK(stat.st_mode))
		ft_putstr("b");
	else if (S_ISCHR(stat.st_mode))
		ft_putstr("c");
	else if (S_ISDIR(stat.st_mode))
		ft_putstr("d");
	else if (S_ISSOCK(stat.st_mode))
		ft_putstr("s");
	else
		ft_putstr("-");
	ft_putstr((stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_displays_gid(stat);
	ft_putstr((stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_displays_uid(stat);
	ft_putstr((stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_displayt(stat);
}

void	ft_display_nb_space(off_t nb, off_t flagnb)
{
	int i;

	i = flagnb - ft_rank(nb);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(nb);
}

int		ft_6_month(long timet)
{
	long currtime;
	long lol;

	currtime = time(NULL);
	lol = currtime - timet;
	if (lol < -15552000 || lol > 15552000)
		return (1);
	return (0);
}

char	*ft_cut(char *str)
{
	char *tmp;
	char *tmp2;
	char *tim;

	tmp2 = ft_strsub(str, 4, 7);
	tmp = ft_strjoin(tmp2, " ");
	free(tmp2);
	tmp2 = ft_strsub(str, 20, 4);
	tim = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (tim);
}

void	ft_display_date(struct stat stat)
{
	char *path;

	if (ft_6_month(stat.st_mtime) == 1)
		path = ft_cut(ctime(&stat.st_mtime));
	else
		path = ft_strsub(ctime(&stat.st_mtime), 4,
				ft_strlen(ctime(&stat.st_mtime)) - 13);
	ft_putstr(path);
	free(path);
}
