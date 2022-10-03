/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:53:15 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 13:34:16 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void print_stacks(t_stack *stack_a, t_stack *stack_b, int instr)
{
	ft_printf("Size A: %d Size B: %d Instruction: %d\n", stack_a->size, stack_b->size, instr);
	return ;

	ft_printf("Stack A |\tStack B\n");
	int greater_size = (stack_a->size > stack_b->size) ? stack_a->size : stack_b->size;
	for (int i = 0; i < greater_size; i++)
	{
		if (i < stack_a->size && i < stack_b->size)
			ft_printf("%d\t|\t%d\n", stack_a->data[i], stack_b->data[i]);
		else if (i < stack_a->size && i >= stack_b->size)
			ft_printf("%d\t|\t-\n", stack_a->data[i]);
		else if (i >= stack_a->size && i < stack_b->size)
			ft_printf("-\t|\t%d\n", stack_b->data[i]);
		else
			ft_printf("ERROR\n");
	}	
}*/

void print_stacks(t_stack *stack_a, t_stack *stack_b, int instr)
{
	int i_a = stack_a->size;
	int i_b = stack_b->size;

	ft_printf("Size A: %d Size B: %d Instruction: %d\n", stack_a->size, stack_b->size, instr);

	ft_printf("Stack A |\tStack B\n");
	while (i_a > 0 || i_b > 0)
	{
		if (i_a > 0) 
		{
			ft_printf("%d", stack_a->data[i_a - 1]); 
			i_a--;
		}
		else ft_printf("-");
		ft_printf("\t|\t");
		if (i_b > 0) 
		{
			ft_printf("%d", stack_b->data[i_b - 1]); 
			i_b--;
		}
		else ft_printf("-");
		ft_printf("\n");
	}
	
}