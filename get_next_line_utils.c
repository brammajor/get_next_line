/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:00:16 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/14 15:55:54 by brmajor          ###   ########.fr       */
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
		return (src);
	i = ft_strlen(dest);
	j = ft_strlen(src);
	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	new[i + j + 1] = '\0';
	while (j-- != 0)
		new[i + j] = src[j];
	while (i-- != 0)
		new[i] = dest[i];
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
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] != c && str[len])
		len++;
	new = malloc(ft_strlen(str) - len + 1);
	if (!new)
		return (NULL);
	len++;
	while (str[len])
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_split1(char *str, char c)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] != c && str[len])
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i <= len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
