/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:04 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/22 11:40:39 by mrusu            ###   ########.fr       */
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

#endif