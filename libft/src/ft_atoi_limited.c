/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_limited.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:40:49 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 17:41:47 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi_limited(const char	*str)
{
	long	sum;
	long	lsum;
	int		sign;

	if (!str)
		exit_error();
	sum = 0;
	sign = 1;
	while (((9 <= *str) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (ft_isdigit(*str))
	{
		lsum = sum;
		sum = 10 * sum + *str - '0';
		if (sum < lsum)
			exit_error();
		str++;
	}
	if ((sum * sign < -2147483648) || (sum * sign > 2147483647))
		exit_error();
	return (sum * sign);
}
