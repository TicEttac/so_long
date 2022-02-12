/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:50:09 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/12 17:58:43 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ftp(){}

int		add_el(char **line, int size, char get)
{
	char	*tmp;
	int		i;

	i = 0;
	ftp();
	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (0);
	while (i != size)
	{
		tmp[i] = *line[i];
		i++;
	}
	tmp[i] = get;
  	tmp[i + 1] = 0;
	free(*line);
	*line = tmp;
	return (1);	
}

int		get_next_line(int fd, char **line)
{
	int		ret;
	int		end;
	char	get;

	ret = 0;
	if (fd < 0)
		return (-1);
	end = read(fd, &get, 1);
	ret += end;
	printf("ret [%d]\n", ret);
	*line = malloc(sizeof(char) * ret);
	if (!line)
		return (-1);
	line[0] = 0;
	if (!add_el(line, ret, get))
		return (-1);
	while (get != '\n' && end != 0)
	{
		end = read(fd, &get, 1);
		ret += end;
		if (!add_el(line, ret, get))
			return (-1);
	}
	return (ret);
}
