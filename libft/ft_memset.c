/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:30:28 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/06 15:49:27 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n != 0)
	{
		*tmp = c;
		tmp = tmp + 1;
		n = n - 1;
	}
	return (s);
}