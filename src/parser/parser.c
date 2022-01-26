/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:23:46 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/09 15:21:13 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_keyword(char *str)
{
	if (cmp_str(str, "echo", 4) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "cd", 2) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "pwd", 3) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "export", 6) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "unset", 5) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "env", 3) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "exit", 4) == SUCCESS)
		return (SUCCESS);
	else if (cmp_str(str, "|", 1) == SUCCESS)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	tokenize(t_env *v, char *str)
{
	//chercher les mots cles, ignorer ce qu'il y a entre ' et "
	//stocker chaque mot cle et ce qui suit jusqu'au prochain mot cle
	int		i[2];
	int		flag;
	char	*buf;

	flag = 0;
	i[0] = 0;
	while(str[i[0]])
	{
		if (is_keyword(&(str[i[0]])) == SUCCESS)
		{
			i[1] = i[0];
			i[0]++;
			while (str[i[0]] && is_keyword(&(str[i[0]])) != SUCCESS)
			{
				if (str[i[0]] == '\'')
				{
					i[0]++;
					while (str[i[0]] && str[i[0]] != '\'')
						i[0]++;
					i[0]++;
				}
				else if (str[i[0]] == '\"')
				{
					i[0]++;
					while (str[i[0]] && str[i[0]] != '\"')
						i[0]++;
					i[0]++;
				}
				else
					i[0]++;
			}
			buf = ft_substr(str, i[1], i[0] - i[1]);
			if (!buf)
				return (FAILURE);
			add_line_list(v->list, buf); 
		}
		else if (is_wspace(str[i[0]]) == SUCCESS)
			i[0]++;
		else
		{
			printf("Command not found\n");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	parser(t_env *v, char *str)
{
	v->list = init_list();
	if (tokenize(v, str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
