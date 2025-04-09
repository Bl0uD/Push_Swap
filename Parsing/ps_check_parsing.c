/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:07:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/09 02:21:40 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}
