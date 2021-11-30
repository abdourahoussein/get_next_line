/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:33:38 by abhousse          #+#    #+#             */
/*   Updated: 2021/11/29 19:34:10 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*lire_une_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		s = malloc(sizeof(char) * (i + 2));
	else
		s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_error(ssize_t ret, char *buf, char *result)
{
	if (ret < 0)
	{
		free(buf);
		if (result != NULL)
			free(result);
		return (1);
	}
	else if (ret == 0 && result == NULL)
	{
		free(buf);
		return (1);
	}
	else if (result[0] == '\0')
	{
		free(result);
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

char	*sauvegarde(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(sizeof(char) * ft_strlen(str) - i);
	i++;
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	free (str);
	s[j] = '\0';
	return (s);
}

char	*lire(int fd, char *result, char *buf)
{
	char	*temp;
	ssize_t	ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = 0;
		if (result == 0)
			result = ft_strdup(buf);
		else
		{	
			temp = ft_strjoin(result, buf);
			free(result);
			result = temp;
		}
		if (ft_strchr(result, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_error(ret, buf, result))
		return (0);
	return (result);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*result[10240];
	char			*buf;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result[fd] = lire(fd, result[fd], buf);
	if (!result[fd])
		return (NULL);
	line = lire_une_line(result[fd]);
	result[fd] = sauvegarde(result[fd]);
	return (line);
}
