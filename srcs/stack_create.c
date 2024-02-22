/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:47 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/22 16:43:03 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atoil(const char *str)
{
	long	negative;
	long	result;
	long	i;

	negative = 0;
	result = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || \
	str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}

void	add_element(t_stack **stack, int value)
{
	t_stack	*element;
	t_stack	*last_element;

	last_element = NULL;
	if (!stack)
		return ;
	element = malloc(sizeof(t_stack));
	if (!element)
		return ;
	element->value = value;
	element->next = NULL;
	if (!(*stack))
	{
		*stack = element;
		element->prev = last_element;
	}
	else
	{
		last_element = find_last_element(*stack);
		last_element->next = element;
		element->prev = last_element;
	}
}

void	create_stack(t_stack **stack_a, char **av)
{
	long	value;
	int		i;

	i = 0;
	if (!stack_a || !av || !*av)
		generic_error(stack_a, av);
	while (av[i])
	{
		if (check_av(av[i]))
			generic_error(stack_a, av);
		value = ft_atoil(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			generic_error(stack_a, av);
		if (check_duplicate (*stack_a, (int)value))
			generic_error(stack_a, av);
		add_element(stack_a, (int)value);
		i++;
	}
}

void	update_status_stack_a(t_stack *a, t_stack *b)
{
	update_index(a);
	update_index(b);
	update_target_a(a, b);
	update_push_cost(a, b);
	update_best_match(a);
}

int	copy_split(char **av, char ***split_av)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 1;
	j = 0;
	while (av[size + 1])
		size++;
	*split_av = (char **)malloc((size + 1) * sizeof(char *));
	if (!(*split_av))
		return (1);
	while (av[i])
	{
		(*split_av)[j] = ft_strdup(av[i]);
		if (!(*split_av)[j])
		{
			free_av(*split_av);
			return (1);
		}
		i++;
		j++;
	}
	(*split_av)[j] = NULL;
	return (0);
}
