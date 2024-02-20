/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:04 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/20 15:47:13 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../inc/push_swap.h"

int		ft_strcmp(const char *str1, const char *str2);
void	parse_av(t_stack **stack_a, t_stack **stack_b, char *command);
void	error_av(t_stack **stack_a, t_stack **stack_b);

#endif