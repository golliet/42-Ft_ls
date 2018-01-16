/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:00:26 by golliet           #+#    #+#             */
/*   Updated: 2018/01/15 15:45:30 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

void			ft_display_error(char *str, char *str2)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(ft_strrchr(str2, '/'), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
}

int				ft_display_error_open(char *str, int err)
{
	ft_putchar('\n');
	ft_putstr(str);
	ft_putstr(":\n");
	ft_display_error(strerror(errno), str);
	return (1);
}

void			ft_errorstat(int err, char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
}

void			ft_permission_denied(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": Permission denied", 2);
}

char			*ft_addslash(char *str)
{
	char	*slash;
	int		i;

	i = 0;
	slash = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (i < ft_strlen(str))
	{
		slash[i] = str[i];
		i++;
	}
	slash[i] = '/';
	slash[i + 1] = '\0';
	return (slash);
}
