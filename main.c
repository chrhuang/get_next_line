/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:10:06 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/27 16:06:25 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 1)
		return (-1);
	str = NULL;
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	while (get_next_line(fd, &str) == 1)
		printf("%s\n", str);
	//printf("%s\n", str);
	/*get_next_line(fd, &str);
	printf("%s\n", str);
	get_next_line(fd, &str);
	printf("%s\n", str);*/
/*	fd = open(av[2], O_RDONLY);
	get_next_line(fd, &str);
	fd = open(av[3], O_RDONLY);
	get_next_line(fd, &str);
	get_next_line(3, &str);	*/
	return (0);
}