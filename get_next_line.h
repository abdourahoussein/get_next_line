/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:51:26 by abhousse          #+#    #+#             */
/*   Updated: 2021/11/29 18:25:36 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t			ft_strlen(const char *s);
char			*ft_strdup(char *src);
char			*ft_strchr(char *str, int c);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
