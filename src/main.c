/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:26:03 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/09 15:21:24 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(void)
{
	static char	*line_read = (char *)NULL;

	if (line_read)
	{
		free(line_read);
		line_read = (char *)NULL;
	}
	line_read = readline("$< : ");
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_env	v;

	line = get_line();
	parser(&v, line);
	print_list(v.list);
	printf("you entered: %s\n", line);
	return (EXIT_SUCCESS);
}
