/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:40:38 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/04 11:02:25 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_number(t_stack *stack_a)
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
	
	element_to_push = get_max_number(stack_a);
	
	return (0);
}
