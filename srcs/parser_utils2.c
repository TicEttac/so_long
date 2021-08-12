/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:09:34 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:13:07 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("Error\n");
	perror(msg);
	return (0);
}

void	free_dtab(char **dtab, int size)
{
	while (size)
	{
		free(dtab[size]);
		dtab[size] = NULL;
		size--;
	}
	free(dtab[0]);
	free(dtab);
	dtab = NULL;
}
