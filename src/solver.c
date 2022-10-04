/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:40:38 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/04 12:25:44 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_number(t_stack *stack_a)
{
	int i, max;

	i = 0;
	max = *(stack_a->data);
	while (i < stack_a->size)
	{
		if (stack_a->data[i] > max)
			max = stack_a->data[i];
		i++;
	}
	return (ft_strlen(ft_itoa(max)));
}
// direction 1 : a -> b 2 : b -> a
void push_on_digit(int digit, t_stack *a, t_stack *b, int direction)
{
	int power;
	int iter;

	power = 1;
	while (digit--)
		power *= 10;
	iter = 0;
	
	
}

int solver_stack(t_stack *a, t_stack *b)
{
	int iterations, iter;

	iterations = get_max_iterations(a);
	iter = 0;
	while(iter < iterations)
	{
		push_on_digit(iter, a, b);
	}
	return (0);
}
