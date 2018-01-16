/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:08:37 by golliet           #+#    #+#             */
/*   Updated: 2018/01/15 13:04:29 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_sort_param(t_param *param)
{
	t_param		*tmp;
	t_param		buf;

	tmp = param;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->str, tmp->next->str) > 0)
		{
			ft_strcpy(buf.str, tmp->str);
			ft_strcpy(tmp->str, tmp->next->str);
			ft_strcpy(tmp->next->str, buf.str);
			tmp = param;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_swap_data(void *tmp, t_list *l, t_list *begin)
{
	tmp = l->data;
	l->data = begin->data;
	begin->data = tmp;
}

void	ft_sort(t_list *begin, t_flag *f)
{
	t_list		*l;
	void		*tmp;

	while (begin->next)
	{
		begin = begin->next;
		l = begin;
		while (l->next)
		{
			l = l->next;
			if ((f->r == 0) && (ft_strcmp(begin->data->str, l->data->str) > 0))
				ft_swap_data(tmp, l, begin);
			if ((f->r == 1) && (ft_strcmp(begin->data->str, l->data->str) < 0))
				ft_swap_data(tmp, l, begin);
		}
	}
}

void	ft_sort_time(t_list *begin, t_flag *flag)
{
	t_list			*lst;
	void			*tmp;
	long			res;

	while (begin->next && (begin = begin->next))
	{
		lst = begin;
		while (lst->next && (lst = lst->next))
		{
			res = lst->data->stat.st_mtime - begin->data->stat.st_mtime;
			if ((flag->r == 0) && ((res > 0) ||
			(res == 0 && (ft_strcmp(lst->data->str, begin->data->str) < 0))))
				ft_swap_data(tmp, lst, begin);
			if ((flag->r == 1) && ((res < 0) ||
			(res == 0 && (ft_strcmp(lst->data->str, begin->data->str) > 0))))
				ft_swap_data(tmp, lst, begin);
		}
	}
}
