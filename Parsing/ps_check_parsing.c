/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloud <bloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:07:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 03:14:52 by bloud            ###   ########.fr       */
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

size_t	strstrlen(char **a)
{
	size_t	i;

	i = 0;
	while (a[i] != NULL)
		i++;
	return (i);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	num;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = -1;
	}
	else
		i = 0;
	while (++i < (int)strstrlen(av))
	{
		if (is_number(av[i]) == 0)
			return (call_free(ac, av), 0);
		if (ft_strlen(av[i]) >= 11)
			return (call_free(ac, av), 0);
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (call_free(ac, av), 0);
	}
	return (call_free(ac, av), 1);
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

void	ps_error(int error_code, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (error_code != PS_OK)
		write(2, ERR_MSG, 6);
	if (error_code == PS_OK)
		exit(0);
	else
		exit(1);
}
