/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:23:18 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 10:53:11 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void		aff_error(t_param *parami)
{
	while ((parami = parami->next))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(parami->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void		ft_display_and_free(t_param *begini, t_param *parami)
{
	parami = begini;
	ft_sort_param(parami);
	aff_error(parami);
	ft_free_param(parami);
}

void		ft_init_param(char **argv, int i, t_truc *truc, t_flag *flag)
{
	truc->parami = ft_param_init(truc->parami, argv[i]);
	truc->paramv = ft_param_init(truc->paramv, argv[i]);
	truc->begini = truc->parami;
	truc->beginv = truc->paramv;
}

t_param		*ft_verif(char **argv, int i, int argc, t_flag *flag)
{
	t_truc truc;

	ft_init_param(argv, i, &truc, flag);
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')
		{
			i++;
			continue;
		}
		if (is_file_exist(argv[i]) == 1)
			truc.paramv = ft_add_e(truc.paramv, argv[i]);
		else
		{
			flag->inv = 1;
			truc.parami = ft_add_e(truc.parami, argv[i]);
		}
		i++;
	}
	truc.paramv = truc.beginv->next;
	free(truc.beginv);
	if (truc.parami)
		ft_display_and_free(truc.begini, truc.parami);
	return (truc.paramv);
}

t_param		*ft_parse(int argc, char **argv, t_flag *flag)
{
	int		i;

	ft_check(argc, argv);
	ft_memset(flag, 0, sizeof(t_flag));
	i = 1;
	while (i < argc)
	{
		if ((ft_is_flag(argv[i], flag)) == 0)
			return (ft_verif(argv, i, argc, flag));
		i++;
	}
	return (NULL);
}
