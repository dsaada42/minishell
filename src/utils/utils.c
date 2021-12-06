/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:56 by dsaada            #+#    #+#             */
/*   Updated: 2021/12/06 18:16:18 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	cmp_str(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[++i] && (i < n))
	{
		if (s1[i] != s2[i])
			return (FAILURE);
	}
	if (i == n)
		return (SUCCESS);
	else
		return (FAILURE);
}

char	*ft_strdup(char *s)
{
	int	i;
	char	*res;

	i = -1;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (s == NULL || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < start)
		i++;
	while (s[i + j] && j < len)
	{
		res[j] = s[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char)* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		dst[i] = s1[i];
	while (++i < (ft_strlen(s1) + ft_strlen(s2)))
		dst[i] = s2[i - ft_strlen(s1)];
	dst[i] = '\0';
	return (dst);
}
