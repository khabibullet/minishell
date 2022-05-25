/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:45:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 17:48:21 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_pow(double base, int deg)
{
	if (deg < 1)
		return (1);
	return (base * ft_pow(base, deg - 1));
}
