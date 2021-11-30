/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:30:55 by abhousse          #+#    #+#             */
/*   Updated: 2021/11/29 19:31:40 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t			ft_strlen(const char *s);
char			*ft_strdup(char *src);
char			*ft_strchr(char *str, int c);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
