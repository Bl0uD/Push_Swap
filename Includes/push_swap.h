/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:42:36 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/09 02:03:44 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "LibFT/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// Fonctions de parsing
int			check_args(int ac, char **av);
t_stack		*create_stack(int ac, char **av);
void		free_stack(t_stack **stack);
int			check_doubles(t_stack *stack);
long		ft_atol(const char *str);

// Prototypes des fonctions
int		ps_push(t_stack **stack_to, t_stack **stack_from);
int		ps_pb(t_stack **stack_a, t_stack **stack_b);

// Prototypes des opérations
int		ps_sa(t_stack **stack_a);
int		ps_sb(t_stack **stack_b);
int		ps_ss(t_stack **stack_a, t_stack **stack_b);
int		ps_ra(t_stack **stack_a);
int		ps_rb(t_stack **stack_b);
int		ps_rr(t_stack **stack_a, t_stack **stack_b);
int		ps_rra(t_stack **stack_a);
int		ps_rrb(t_stack **stack_b);
int		ps_rrr(t_stack **stack_a, t_stack **stack_b);

// Fonctions utilitaires
void	print_stack(t_stack *stack, char name);

#endif