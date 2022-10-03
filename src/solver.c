/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:40:38 by jnaftana          #+#    #+#             */
/*   Updated: 2022/09/29 12:41:21 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min_number(t_stack *stack_a)
{
	int i, min;

	i = 0;
	min = *(stack_a->data);
	while (i < stack_a->size)
	{
		if (stack_a->data[i] < min)
			min = stack_a->data[i];
		i++;
	}
	return (min);
}

int solver_stack(t_stack *stack_a, t_stack *stack_b)
{
	int element_to_push;
	
	element_to_push = get_min_number(stack_a);
	while (stack_a->size)
	{
		if (stack_a->data[0] != element_to_push)
			instructor(ra ,stack_a, stack_b);
		else
		{
			instructor(pb ,stack_a, stack_b);
			element_to_push = get_min_number(stack_a);
		}
	}
	while(stack_b->size)
		instructor(pa, stack_a, stack_b);
	return (0);
}
