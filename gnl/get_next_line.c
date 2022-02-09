/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 04:37:26 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/09 15:11:25 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_bln(char *buf)
{
	int		i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_assign(char **end, char *buf, int i)
{
	char		*tmp;

	tmp = ft_strdupimp(buf, i);
	free(*end);
	*end = tmp;
	return (*end);
}

int	dodashit(char **buf, char **end, int *i)
{
	char		*tmp;
	int			r;

	r = read(fd, buf, BUFFER_SIZE);
	while (*i < 0 && r > 0)
	{
		(*buf)[r] = 0;
		*i = ft_bln(*buf);
		tmp = ft_strjoin_pimp(*end, *buf);
		if (*end)
			free(*end);
		*end = tmp;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (r);
}

int	make_str(int fd, char **end, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			i;
	int			r;

	i = ft_bln(*end);
	if (i >= 0 && (ft_assign(line, *end, 1) != NULL))
	{
		ft_assign(end, *end + i + 1, 0);
		return (1);
	}
	r = dodashit(&buf, end, &i);
	tmp = ft_strdupimp(*end, 1);
	if (tmp != NULL)
		*line = ft_assign(line, tmp, 0);
	free(tmp);
	if (buf + i + 1 && i >= 0)
		ft_assign(end, buf + i + 1, 0);
	if (r > 0)
		r = 1;
	return (r);
}

int	get_next_line(int fd, char **line)
{
	static char	*end = NULL;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	if (!*line)
		return (-1);
	(*line)[0] = '\0';
	ret = make_str(fd, &end, line);
	if (ret != 1)
	{
		free(end);
		end = NULL;
	}
	return (ret);
}
