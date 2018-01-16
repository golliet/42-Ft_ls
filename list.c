/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:06:45 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 11:04:03 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/xattr.h>

t_list		*ft_list_init(t_list *list, t_flag *flag)
{
	t_data *data;

	flag->block = 0;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		exit(EXIT_FAILURE);
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	list->data = data;
	list->next = NULL;
	return (list);
}

t_list		*ft_add_elem(t_list *lis, struct dirent *dir, char *str, t_flag *f)
{
	t_list			*new;
	t_data			*data;
	struct stat		buf;
	char			liste[1024];

	lstat(str, &buf);
	if (!(data = (t_data*)malloc(sizeof(t_data))) ||
			!(new = (t_list*)malloc(sizeof(t_list))))
		exit(-1);
	if (dir)
	{
		if (!(f->a == 0 && dir->d_name[0] == '.'))
			f->block += buf.st_blocks;
		data->type = dir->d_type;
		ft_strcpy(data->str, dir->d_name);
	}
	else
		ft_strcpy(data->str, str);
	ft_strcpy(data->path, str);
	new->data = data;
	new->data->stat = buf;
	lis->next = new;
	new->next = NULL;
	return (new);
}

void		ft_free_list(t_list **head_ref)
{
	t_list *current;
	t_list *next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

t_param		*ft_param_init(t_param *param, char *str)
{
	if (!(param = (t_param*)malloc(sizeof(t_param))))
		exit(EXIT_FAILURE);
	ft_strcpy(param->str, str);
	param->next = NULL;
	return (param);
}

t_param		*ft_add_e(t_param *param, char *str)
{
	t_param *new;

	if (!(new = (t_param *)malloc(sizeof(t_param))))
	{
		ft_free_param(new);
		exit(EXIT_FAILURE);
	}
	param->next = new;
	new->next = NULL;
	ft_strcpy(new->str, str);
	return (new);
}
