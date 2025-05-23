/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:39:23 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:57:03 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_incharset(char s, char const *charset)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (charset[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = (int)(ft_strlen(s1) - 1);
	while (ft_incharset(s1[i], set))
		i++;
	while (ft_incharset(s1[j], set))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
