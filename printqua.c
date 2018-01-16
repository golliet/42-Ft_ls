/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printqua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:45:28 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 12:24:01 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

void	ft_strrank(t_flag *flag, t_list *list, t_rank *rank)
{
	t_list			*head;
	char			*pwd;
	char			*group;

	head = list;
	while ((list = list->next))
	{
		pwd = ft_passwd(list->data->stat, NULL);
		group = ft_group(list->data->stat, NULL);
		if (flag->a == 0 && ft_strncmp(list->data->str, ".", 1) == 0)
			continue;
		if (ft_strlen(pwd) > rank->rpwd)
			rank->rpwd = ft_strlen(pwd);
		if (ft_strlen(group) > rank->rgroup)
			rank->rgroup = ft_strlen(group);
		free(pwd);
		free(group);
	}
	list = head;
}

void	ft_display_nb_space_str(char *str, int nb)
{
	int i;

	i = ft_strlen(str);
	ft_putstr(str);
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_putblock(int block1, int block2)
{
	int i;

	i = 4 - ft_rank(block1);
	ft_putstr(" ");
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(block1);
	ft_putstr(",");
	i = 3 - ft_rank(block2);
	ft_putstr(" ");
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(block2);
}

void	ft_block(struct stat stat, t_rank *rank)
{
	if (S_ISCHR(stat.st_mode) || (S_ISBLK(stat.st_mode)))
		ft_putblock((stat.st_rdev >> 8) / 65536, stat.st_rdev & 0xFF);
	else
	{
		ft_putstr("  ");
		ft_display_nb_space(stat.st_size, rank->ranko);
	}
}

void	ft_first(t_flag *flag, t_list *list, t_rank *rank)
{
	ft_right(list->data->stat);
	ft_putstr("  ");
	ft_display_nb_space(list->data->stat.st_nlink, rank->rankl);
	ft_putstr(" ");
}
