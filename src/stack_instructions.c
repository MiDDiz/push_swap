/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:36:43 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 12:36:48 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_swap(t_stack *stack)
{
	int swap;

	swap = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = swap;
}


// Pushes from a to b
void stack_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	stack_b->data[stack_b->size] = stack_a->data[stack_a->size - 1];
	stack_b->size++;
	stack_b->size--;
}

void stack_rotate(t_stack *stack)
{
	int i;
	int swap;
	int prev_swap;

	i = 0;
	while (i < stack->size)
	{
		if (i == 0)
		{
			swap = stack->data[i];
		}
		else if (i == stack->size - 1)
		{
			swap = stack->data[i];
			stack->data[i] = prev_swap;
			stack->data[0] = swap;
		}
		else 
		{
			swap = stack->data[i];
			stack->data[i] = prev_swap;
			prev_swap = swap;
		}
		i++;
	}
}

void stack_reverse_rotate (t_stack *stack)
{
	int i;
	int swap;
	int prev_swap;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (i == stack->size - 1)
		{
			swap = stack->data[i];
		}
		else if (i == 0)
		{
			swap = stack->data[i];
			stack->data[i] = prev_swap;
			stack->data[stack->size - 1] = swap;
		}
		else 
		{
			swap = stack->data[i];
			stack->data[i] = prev_swap;
			prev_swap = swap;
		}
		i--;
	}
}

void instructor_2(int instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (instruction == ra)
		stack_rotate(stack_a);
	else if (instruction == rb)
		stack_rotate(stack_b);
	else if (instruction == rr)
	{
		stack_rotate(stack_a);
		stack_rotate(stack_b);
	}
	else if (instruction == rra)
		stack_reverse_rotate(stack_a);
	else if (instruction == rrb)
		stack_reverse_rotate(stack_b);
	else if (instruction == rrr)
	{
		stack_reverse_rotate(stack_a);
		stack_reverse_rotate(stack_b);
	}
}

void instructor(int instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (instruction == sa)
		stack_swap(stack_a);
	else if (instruction == sb)
		stack_swap(stack_b);
	else if (instruction == ss)
	{
		stack_swap(stack_a);
		stack_swap(stack_b);
	}
	else if (instruction == pa)
		stack_push(stack_b, stack_a);
	else if (instruction == pb)
		stack_push(stack_a, stack_b);
	else
		instructor_2(instruction, stack_a, stack_b);
}
