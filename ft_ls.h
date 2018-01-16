/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:31:36 by golliet           #+#    #+#             */
/*   Updated: 2018/01/16 12:25:43 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <time.h>
# include "string.h"
# include <errno.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>

typedef struct		s_data
{
	char			str[NAME_MAX];
	char			path[PATH_MAX];
	int				type;
	struct stat		stat;
}					t_data;

typedef struct		s_list
{
	struct s_list	*next;
	t_data			*data;
}					t_list;

typedef struct		s_param
{
	char			str[NAME_MAX];
	struct s_param	*next;
}					t_param;

typedef struct		s_truc
{
	t_param			*beginv;
	t_param			*paramv;
	t_param			*begini;
	t_param			*parami;
}					t_truc;

typedef struct		s_flag
{
	int				a;
	int				r;
	int				rmaj;
	int				t;
	int				l;
	int				g;
	int				u;
	int				umaj;
	int				s;
	int				o;
	int				f;
	int				gmin;
	int				inv;
	int				block;
}					t_flag;

typedef struct		s_rank
{
	int				ranko;
	int				rankl;
	int				rpwd;
	int				rgroup;
	int				rblk;
}					t_rank;

t_list				*ft_list_init(t_list *list, t_flag *flag);
t_list				*ft_add_elem(t_list *list, struct dirent *dir,
					char *str, t_flag *flag);
void				ft_read_name(t_list *list, t_flag *flag, int link);
void				ft_free_list(t_list **list);
t_param				*ft_parse(int argc, char **argv, t_flag *flag);
void				ft_free_param(t_param *list);
t_param				*ft_param_init(t_param *param, char *str);
t_param				*ft_add_e(t_param *param, char *str);
void				ft_sort_param(t_param *param);
void				ft_sort(t_list *head, t_flag *flag);
void				ft_sort_time(t_list *head, t_flag *flag);
int					ft_print_right(t_flag *flag, t_list *list, t_rank *rank);
int					ft_rank(off_t nb);
void				ft_choose_color(t_list *list);
void				ft_colum(t_list *list, t_flag *flag);
void				ft_strrank(t_flag *flag, t_list *list, t_rank *rank);
void				ft_display_error(char *str, char *str2);
int					ft_display_error_open(char *str, int err);
void				ft_errorstat(int err, char *str);
void				ft_permission_denied(char *str);
int					ft_is_lnk_dir(struct stat stat, char *str);
void				ft_fsort(t_list *list, t_flag *flag);
t_list				*ft_fill_list(char *str, t_list *list,
													t_flag *flag, DIR *dir);
int					ft_buflstat(t_flag flag, char *str, struct stat *buf);
char				*ft_addslash(char *str);
void				ft_check(int argc, char **argv);
int					ft_flag(char *str, t_flag *flag, int i);
void				ft_exit(char *str, int i);
int					ft_is_flag(char *str, t_flag *flag);
int					is_file_exist(char *path);
void				ft_find_highest_rank(t_list *list, t_rank *rank,
																t_flag *flag);
void				ft_putendl_other(char *str);
int					ft_is_only_point(t_list *list);
void				ft_display_blk(t_list *list, t_rank rank);
void				ft_init_rank(t_rank *rank);
int					ft_rank(off_t nb);
char				*ft_group(struct stat stat, struct group *group);
char				*ft_passwd(struct stat stat, struct passwd *passwd);
void				ft_displays_gid(struct stat stat);
void				ft_displays_uid(struct stat stat);
void				ft_displayt(struct stat stat);
void				ft_right(struct stat stat);
void				ft_display_nb_space(off_t nb, off_t flagnb);
int					ft_6_month(long timet);
char				*ft_cut(char *str);
void				ft_display_date(struct stat stat);
void				ft_display_nb_space_str(char *str, int nb);
void				ft_putblock(int block1, int block2);
void				ft_block(struct stat stat, t_rank *rank);
void				ft_first(t_flag *flag, t_list *list, t_rank *rank);

#endif
