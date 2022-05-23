/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:10:57 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 16:57:00 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;
	size_t	slen_1;
	size_t	slen_2;

	dif = 0;
	i = 0;
	slen_1 = ft_strlen(s1);
	slen_2 = ft_strlen(s2);
	if (slen_1 > slen_2)
		slen_2 = slen_1;
	while (i < n && (dif == 0) && i < slen_2)
	{
		dif = (unsigned char)s1[i] - (unsigned char)s2[i];
		++i;
	}
	return (dif);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		dif;

	i = 0;
	dif = 0;
	while (dif == 0 && (s1[i] != 0 || s2[i] != 0))
	{
		dif = (unsigned char)s1[i] - (unsigned char)s2[i];
		++i;
	}
	return (dif);
}
