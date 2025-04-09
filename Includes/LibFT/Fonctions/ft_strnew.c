/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/09 01:53:05 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, size + 1);
	return (res);
}
