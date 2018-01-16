/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:05:57 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 12:24:53 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

char	*ft_group(struct stat stat, struct group *group)
{
	char			*str;

	group = getgrgid(stat.st_gid);
	if (!group)
		return (ft_strdup(ft_itoa(stat.st_gid)));
	str = ft_strdup(group->gr_name);
	return (str);
}

char	*ft_passwd(struct stat stat, struct passwd *passwd)
{
	char			*str;

	passwd = getpwuid(stat.st_uid);
	if (!passwd)
		return (ft_strdup(ft_itoa(stat.st_uid)));
	str = ft_strdup(passwd->pw_name);
	return (str);
}

void	ft_displays_gid(struct stat stat)
{
	int a;

	a = 0;
	if (stat.st_mode & S_IXUSR)
	{
		if (stat.st_mode & S_ISGID)
			ft_putstr("s");
		else
			a = 1;
	}
	else
	{
		if (stat.st_mode & S_ISGID)
			ft_putstr("S");
		else
			a = 1;
	}
	if (a == 1)
		ft_putstr((stat.st_mode & S_IXUSR) ? "x" : "-");
}

void	ft_displays_uid(struct stat stat)
{
	int a;

	a = 0;
	if (stat.st_mode & S_IXGRP)
	{
		if (stat.st_mode & S_ISUID)
			ft_putstr("s");
		else
			a = 1;
	}
	else
	{
		if (stat.st_mode & S_ISUID)
			ft_putstr("S");
		else
			a = 1;
	}
	if (a == 1)
		ft_putstr((stat.st_mode & S_IXGRP) ? "x" : "-");
}

void	ft_displayt(struct stat stat)
{
	int a;

	a = 0;
	if (stat.st_mode & S_IXOTH)
	{
		if (stat.st_mode & S_ISVTX)
			ft_putstr("t");
		else
			a = 1;
	}
	else
	{
		if (stat.st_mode & S_ISVTX)
			ft_putstr("T");
		else
			a = 1;
	}
	if (a == 1)
		ft_putstr((stat.st_mode & S_IXOTH) ? "x" : "-");
}
