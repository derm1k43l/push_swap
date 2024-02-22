/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:03 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/22 16:27:48 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_av;

	a = NULL;
	b = NULL;
	split_av = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		split_av = ft_split2(av[1], 32);
		create_stack(&a, split_av);
		free_av(split_av);
	}
	else if (ac > 2 && av[1][0])
	{
		copy_split(av, &split_av);
		create_stack(&a, split_av);
		free_av(split_av);
	}
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
