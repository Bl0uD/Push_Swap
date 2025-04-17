/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:12:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 13:04:46 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	call_free(int defaultSw, char **ptr)
{
	if (defaultSw == 2)
		ft_free(ptr);
}
