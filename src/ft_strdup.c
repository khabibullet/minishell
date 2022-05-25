/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:17:02 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 12:38:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	lens;

	if (s1 == NULL)
		return (NULL);
	lens = ft_strlen(s1);
	ptr = malloc(lens + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[lens] = '\0';
	ft_strlcpy(ptr, s1, lens + 1);
	return (ptr);
}
