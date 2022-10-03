/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:57 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 11:13:52 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A ->  67 55 2 -52 90 23 
// B ->
// Menor a mayor
// 


int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;

	// Check if stack given is correct
	if (!check_args(argc, argv))
		return (-1);
	// Parse argumeents given and build stack_a
	if (!parse_stack(&stack_a, argc, argv))
		return(-1);
	// Generate empty stack_b with size equals to stack_a
	if (!generate_empty_stack(&stack_b, stack_a.size))
	{
		free(stack_a.data);
		return(-1);
	}
	// Solve problem
	if (!solver_stack(&stack_a, &stack_b))
	{
		free(stack_a.data);
		free(stack_b.data);
		return;
	}
}
