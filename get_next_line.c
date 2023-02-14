/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:55:10 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/14 16:25:47 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char		*d;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	d = malloc(j + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buff;
	char		*str;

	if (!fd || fd <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (rest)
		str = ft_strdup(rest);
	free(rest);
	while (read(fd, buff, BUFFER_SIZE))
	{
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n') == 1)
			break ;
	}
	free(buff);
	rest = ft_split2(str, '\n');
	str = ft_split1(str, '\n');
	return (str);
}

#include<fcntl.h>
#include<stdio.h>
int	main()
{
	int 	i = 0;
	int fd = open("./test", O_RDWR);
	
	while (i++ < 8)
		printf("%s", get_next_line(fd));
}
