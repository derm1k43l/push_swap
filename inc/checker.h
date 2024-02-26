/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:04 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/26 12:25:47 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../inc/push_swap.h"

void	process_commands(t_stack **stack_a, t_stack **stack_b, char **split_av);
void	error_av(t_stack **stack_a, t_stack **stack_b, char **split_av,
			char *command);
void	parse_av(t_stack **stack_a, t_stack **stack_b,
			char *command, char **split_av);
void	create_stack2(t_stack **stack_a, char **av);
void	generic_error2(t_stack **stack_a, char **av);

#endif