/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:55:09 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/12 20:40:23 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	a;
	char	*d;

	a = 0;
	d = (unsigned char *)s;
	while (a != n)
	{
		d[a] = (unsigned char)c;
		a++;
	}
	return (d);
}
