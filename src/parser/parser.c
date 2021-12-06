/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:23:46 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/06 18:15:59 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	i = 0;
	while(str[i])
	{
		
	}
}

int	parser(t_env *v, char *str)
{
	v->list = init_list();
		
}


