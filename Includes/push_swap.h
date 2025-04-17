/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:42:36 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 03:21:39 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "LibFT/Includes/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// Fonctions de parsing et gestion de pile
int			check_args(int ac, char **av);
t_stack		*create_stack(int ac, char **av);
void		free_stack(t_stack **stack);
int			check_doubles(t_stack *stack);
void		add_to_stack(t_stack **stack, t_stack *new);

// Opérations de base
int			ps_push(t_stack **stack_to, t_stack **stack_from);
int			ps_pa(t_stack **stack_a, t_stack **stack_b);
int			ps_pb(t_stack **stack_a, t_stack **stack_b);
int			ps_sa(t_stack **stack_a);
int			ps_sb(t_stack **stack_b);
int			ps_ss(t_stack **stack_a, t_stack **stack_b);
int			ps_ra(t_stack **stack_a);
int			ps_rb(t_stack **stack_b);
int			ps_rr(t_stack **stack_a, t_stack **stack_b);
int			ps_rra(t_stack **stack_a);
int			ps_rrb(t_stack **stack_b);
int			ps_rrr(t_stack **stack_a, t_stack **stack_b);

// Algorithmes de tri
void		ps_sort_stack(t_stack **stack_a, t_stack **stack_b, int size);
void		ps_sort_two(t_stack **stack_a);
void		ps_sort_three(t_stack **stack_a);
void		ps_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_hundred(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_five_hundred(t_stack **stack_a, t_stack **stack_b);

// Fonctions utilitaires
void		index_stack(t_stack *stack);
int			find_max_pos(t_stack *stack);
int			ps_stacksize(t_stack *stack);
int			is_sorted(t_stack *stack);
void		print_stack(t_stack *stack, char name);
int			find_min_pos(t_stack *stack);
int			closest_in_chunk(t_stack *stack, int min, int max, int size);

// Gestion des erreurs
void		ps_error(int error_code, t_stack **stack_a, t_stack **stack_b);

// silly :3
size_t		strstrlen(char **a);
void		ft_free(char **str);
void		call_free(int defaultSw, char **ptr);

// Codes d'erreur
# define PS_OK 0
# define PS_ERROR -1
# define PS_EMPTY_STACK -2
# define PS_MALLOC_ERROR -3
# define PS_INVALID_ARG -4
# define PS_DUPLICATE -5

// Message d'erreur standardisé
# define ERR_MSG "Error\n"

#endif