/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:57:22 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/09 01:52:05 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <strings.h>
#include <stdio.h>

int	ft_strcasecmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*s1 = "B";
	const char	*s2 = "Bonjour";

	printf("ft_memchr = %d\n", ft_strcasecmp(s1, s2));
	printf("memchr = %d\n", strcasecmp(s1, s2));
	return (0);
}*/