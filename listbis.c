/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:53:07 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 10:57:06 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_find_highest_rank(t_list *list, t_rank *ran, t_flag *flag)
{
	t_list	*head;
	int		l;
	int		o;
	int		blk;

	ran->rankl = 0;
	ran->ranko = 0;
	head = list;
	while ((list = list->next))
	{
		if (flag->a == 0 && list->data->str[0] == '.')
			continue;
		if ((l = ft_rank(list->data->stat.st_nlink)) > ran->rankl)
			ran->rankl = l;
		if ((o = ft_rank(list->data->stat.st_size)) > ran->ranko)
			ran->ranko = o;
		if ((blk = ft_rank(list->data->stat.st_blocks)) > ran->rblk)
			ran->rblk = blk;
	}
	list = head;
}

void		ft_putendl_other(char *str)
{
	write(1, str, ft_strlen(str) - 2);
	write(1, ":\n", 2);
}

int			ft_is_only_point(t_list *list)
{
	t_list *head;

	head = list;
	while ((list = list->next))
	{
		if (list->data->str[0] != '.')
		{
			list = head;
			return (0);
		}
	}
	list = head;
	return (1);
}

void		ft_display_blk(t_list *list, t_rank rank)
{
	int i;

	i = rank.rblk - ft_rank(list->data->stat.st_blocks);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(list->data->stat.st_blocks);
	ft_putchar(' ');
}

void		ft_init_rank(t_rank *rank)
{
	rank->ranko = 0;
	rank->rpwd = 0;
	rank->rankl = 0;
	rank->rgroup = 0;
	rank->rblk = 0;
}
