/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:19:42 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:47:34 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

size_t	ft_print_c(int fd, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	write(fd, &c, 1);
	return (1);
}
