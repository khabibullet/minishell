/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:29:10 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 21:35:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	is_all_chars_valid(char *str)
{
	while (*str)
	{
		if (((int)*str < 65 && (int)*str > 32)
			|| ((int)*str < 95 && (int)*str > 90)
			|| ((int)*str < 128 && (int)*str > 122)
			|| ((int)*str == 96))
			return (1);
		str++;
	}
	return (0);
}
