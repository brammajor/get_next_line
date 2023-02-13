/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:00:16 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/13 16:57:50 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*new;
	int		i;
	int		j;

	if (!src)
		return (dest);
	if (!dest)
		return (NULL);
	new = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (dest[i])
	{
		new[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		new[i] = src[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_split2(char *str, char c)
{
	char	*new;
	int	i;
	int	j;

	i = ft_strlen(str);
	j = 0;
	while (str[i] != c)
	{
		i--;
		j++;
	}
	new = malloc(j + 1);
	if (!new)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_split1(char *str, char c)
{
	char	*new;
        int	i;

	i = 0;
	while (str[i] != c)
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	new[i--] = '\0';
	while (str[i])
	{
		new[i] = str[i];
		i--;
	}
	return (new);
}
