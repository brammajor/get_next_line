/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:55:10 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/13 16:58:12 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	if (!fd || fd <= 0)
		return (NULL);
	str = malloc(BUFFER_SIZE + ft_strlen(rest) + 1);
	if (!str)
		return (NULL);
	read(fd, str, BUFFER_SIZE);
	str = ft_strjoin(rest, str);
	if (!str)
		return (NULL);
	while (ft_strchr(str, '\n') == 0)
	{
		read(fd, rest, BUFFER_SIZE);
		str = ft_strjoin(str, rest);
		rest = ft_split2(str, '\n');
		str = ft_split1(str, '\n');
	}
	if (ft_strchr(str, '\n') == 1)
	{
		rest = ft_split2(str, '\n');
		str = ft_split1(str, '\n');
	}
	return (str);
}
