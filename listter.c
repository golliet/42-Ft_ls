/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:57:58 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 11:05:49 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

int				ft_rank(off_t nb)
{
	int n;
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	n = (int)nb;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void		ft_aff_total(t_flag *flag, t_list *list, t_rank *rank, int link)
{
	if (flag->l == 1 || flag->gmin == 1 || flag->o == 1 || flag->s == 1)
	{
		ft_find_highest_rank(list, rank, flag);
		if ((flag->a == 1 || ft_is_only_point(list) == 0) && link == 0)
		{
			ft_putstr("total ");
			ft_putnbr(flag->block);
			ft_putchar('\n');
		}
	}
}

static void		ft_display_all(t_list *list, t_flag *flag, t_rank *rank)
{
	while ((list = list->next))
	{
		if (flag->a == 0 && list->data->str[0] == '.')
			continue;
		if (flag->s != 0)
			ft_display_blk(list, *rank);
		if (flag->l != 0 || flag->gmin != 0 || flag->o != 0)
		{
			if ((ft_print_right(flag, list, rank)) == 0)
				break ;
		}
		else
		{
			if (flag->g == 1)
			{
				ft_choose_color(list);
				ft_putchar('\n');
			}
			else
				ft_putendl(list->data->str);
		}
	}
}

void			ft_read_name(t_list *list, t_flag *flag, int link)
{
	static int		first = 0;
	t_rank			rank;
	t_list			*head;

	ft_init_rank(&rank);
	ft_strrank(flag, list, &rank);
	head = list;
	if (first != 0 && link == 0)
		ft_putchar('\n');
	if (flag->rmaj == 1 && first != 0)
		ft_putendl_other(list->next->data->path);
	first += 1;
	ft_aff_total(flag, list, &rank, link);
	ft_display_all(list, flag, &rank);
	list = head;
}

void			ft_free_param(t_param *list)
{
	if (list->next != NULL)
		ft_free_param(list->next);
	free(list);
}
