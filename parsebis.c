/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsebis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:06 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 10:49:12 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

void	ft_check(int argc, char **argv)
{
	int i;

	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			exit(-1);
		}
		i++;
	}
}

int		ft_flag(char *str, t_flag *flag, int i)
{
	if (str[i] == 'a')
		flag->a = 1;
	else if (str[i] == 'r')
		flag->r = 1;
	else if (str[i] == 'R')
		flag->rmaj = 1;
	else if (str[i] == 'l')
		flag->l = 1;
	else if (str[i] == 't')
		flag->t = 1;
	else if (str[i] == 'G')
		flag->g = 1;
	else if (str[i] == 's')
		flag->s = 1;
	else if (str[i] == 'g')
		flag->gmin = 1;
	else if (str[i] == 'o')
		flag->o = 1;
	else
		return (0);
	return (1);
}

void	ft_exit(char *str, int i)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(str[i], 2);
	ft_putstr_fd("\nusage: ls [-GRafglorst]\n", 2);
	exit(EXIT_FAILURE);
}

int		ft_is_flag(char *str, t_flag *flag)
{
	int i;

	i = 1;
	if (str[0] != '-')
		return (0);
	if (str[0] == '-' && str[1] == '-' && str[2] == '\0')
		return (0);
	if (str[0] == '-' && str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_flag(str, flag, i) == 1)
			;
		else if (str[i] == 'f')
		{
			flag->f = 1;
			flag->a = 1;
		}
		else
			ft_exit(str, i);
		i++;
	}
	return (1);
}

int		is_file_exist(char *path)
{
	struct stat buffer;

	return ((lstat(path, &buffer) == 0) ? 1 : 0);
}
