/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:09 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/06 16:57:22 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list *));
	if (list == NULL)
		return (NULL);
	list->start = NULL;
	return (list);
}

int	add_line_list(t_list *list, char *str)
{
	t_token	*new;
	t_token	*current;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		return (FAILURE);
	new->str = str;
	new->size = ft_strlen(str);
	new->next = NULL;
	if (list->start == NULL)
		list->start = new;
	else
	{
		current = list->start;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (SUCCESS);
}

int	free_list(t_list *list)
{
	t_token	*current;

	if (list == NULL)
		return (FAILURE);
	current = list->start;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	free(list);
	return (SUCCESS);
}

int	print_list(t_list *list)
{
	t_line *current;

	if (list == NULL)
		return (FAILURE);
	current = list->start;
	while (current != NULL)
	{
		printf("%s\n", current->str);
		current = current->next;
	}
	return (SUCCESS);
}

