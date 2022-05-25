/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 16:50:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	exec_echo(char **args)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (ft_strcmp(args[1], "-n") != EQUAL)
		flag = NEWLINE;
	else
		i++;
	while (args[i])
	{
		if (ft_strcmp(args[i], "-n") != EQUAL)
			printf("%s ", args[i]);
		i++;
	}
	if (flag == NEWLINE)
		printf("\n");
	else
		printf("\b");
}
