/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:13:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/21 14:59:52 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdbool.h>
# include <limits.h> 

# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			best_match;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// moves
void		push(t_stack **dst, t_stack **src);
void		pa(t_stack **a, t_stack **b, bool print);
void		pb(t_stack **b, t_stack **a, bool print);
void		reverse_rotate(t_stack **stack_a);
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b, bool print);
void		rrr_special(t_stack **stack_a, t_stack **stack_b,
				t_stack *b_m, bool pt);
void		rotate(t_stack **stack);
void		ra(t_stack **a, bool print);
void		rb(t_stack **b, bool print);
void		rr(t_stack **a, t_stack **b, bool print);
void		rr_special(t_stack **stack_a, t_stack **stack_b, t_stack *b_m,
				bool pt);
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b, bool print);

// error handeling
void		free_stack(t_stack **stack);
void		generic_error(t_stack **stack, char **av);
bool		check_av(const char *input);
bool		check_duplicate(t_stack *stack, int n);
void		free_av(char **split_av);

// stack utiles
int			stack_size(t_stack *stack);
bool		stack_sorted(t_stack *stack);
t_stack		*find_last_element(t_stack *stack);
t_stack		*find_best_match(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
int			find_min_value(t_stack *stack);
int			find_max_value(t_stack *stack);

// sorting
void		sort_stack(t_stack **stack_a, t_stack **stack_b);
void		sort_two(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		sort_special(t_stack **stack_a, t_stack **stack_b);
void		sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort_b(t_stack **stack_a, t_stack **stack_b);
void		rotate_to_top(t_stack **stack_a, t_stack *top, char stack);
void		finish_sorting(t_stack **stack_a);

// update
void		update_index(t_stack *stack);
void		update_target_a(t_stack *stack_a, t_stack *stack_b);
void		update_target_b(t_stack *stack_a, t_stack *stack_b);
void		update_push_cost(t_stack *stack_a, t_stack *stack_b);
void		update_best_match(t_stack *stack);

// create stack
long		ft_atoil(const char *str);
void		create_stack(t_stack **stack_a, char **av);
void		add_element(t_stack **stack, int value);
void		update_status_stack_a(t_stack *a, t_stack *b);

// special split
char		**ft_split2(char const *s, char c);

#endif