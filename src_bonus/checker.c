/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:03:08 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 14:11:05 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int check_solved(t_stack *stack_a, t_stack* stack_b)
{
	int	i;
	int prev;

	if (stack_b->size != 0)
		return (-1);
	prev = stack_a->data[stack_a->size - 1];
	i = stack_a->size - 2;
	while (i > 0)
	{
		if (prev > stack_a->data[i])
		{
			ft_perror("Error\n");
			return (-1);
		}
		prev = stack_a->data[i];
		i--;
	}
	ft_printf("OK\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	// Check if stack given is correct
	if (check_args(argc, argv) < 0)
		return (-1);
	// Parse argumeents given and build stack_a
	if (parse_stack(&stack_a, argc, argv) < 0)
		return(-1);
	// Generate empty stack_b with size equals to stack_a
	if (generate_empty_stack(&stack_b, stack_a.size) < 0)
	{
		free(stack_a.data);
		return(-1);
	}

	print_stacks(&stack_a, &stack_b, 0);
	// Get, parse and do operations given.
	if (solve_instructions(&stack_a, &stack_b) < 0)
	{
		free(stack_a.data);
		free(stack_b.data);
		return (-1);
	}
	// Check if solved:
	if (check_solved(&stack_a, &stack_b) < 0)
	{
		free(stack_a.data);
		free(stack_b.data);
		return (-1);
	}
	return (0);
}