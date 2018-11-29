/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:10:06 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/29 11:17:21 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 1)
		return (-1);
	str = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) == 1)
	{
		ft_putstr(str);
		free(str);
		ft_putchar('\n');
	}
	return (0);
}
