/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:19:04 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/06 18:16:14 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# define SUCCESS 1
# define FAILURE -1

typedef struct  s_token
{
	char			*str;
	struct s_token	*next;
}				t_token;

typedef struct	s_list
{
	t_token	*start;
}				t_list;

typedef	struct	s_env
{
	t_list 	*list;
}				t_env;

//utils
int ft_strlen(char *str);
int cmp_str(char *s1, char *s2, size_t n);
char    *ft_strdup(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);

#endif
