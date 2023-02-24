/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:55:17 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/24 11:32:56 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*get_line(char *str, char c);
char	*get_rest_of_line(char *str, char c);
char	*ft_strjoin(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);

#endif
