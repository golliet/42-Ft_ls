/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:06:58 by golliet           #+#    #+#             */
/*   Updated: 2018/01/15 15:44:16 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

int				ft_is_lnk_dir(struct stat stat, char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (S_ISLNK(stat.st_mode) && str[i] == '/')
		return (1);
	return (0);
}

void			ft_fsort(t_list *first, t_flag *flag)
{
	if (flag->t == 1)
		ft_sort_time(first, flag);
	else
		ft_sort(first, flag);
}

static char		*ft_doublejoin(char *root, char *dir)
{
	char	*path;
	char	*tmp;
	int		i;

	i = ft_strlen(root) - 1;
	if (ft_strcmp(root, "/") == 0)
	{
		path = ft_strjoin(root, dir);
		return (path);
	}
	tmp = ft_strjoin(root, "/");
	path = ft_strjoin(tmp, dir);
	free(tmp);
	return (path);
}

t_list			*ft_fill_list(char *str, t_list *list, t_flag *flag, DIR *dir)
{
	struct dirent	*tmp;
	char			*path;

	while ((tmp = readdir(dir)) != NULL)
	{
		path = ft_doublejoin(str, tmp->d_name);
		list = ft_add_elem(list, tmp, path, flag);
		free(path);
	}
	return (list);
}

int				ft_buflstat(t_flag flag, char *str, struct stat *buf)
{
	if (flag.l == 1)
	{
		if (lstat(str, buf) != 0)
		{
			ft_errorstat(errno, str);
			return (0);
		}
	}
	else if (flag.l == 0)
	{
		if (stat(str, buf) != 0)
		{
			ft_putendl(str);
			return (0);
		}
	}
	return (1);
}
