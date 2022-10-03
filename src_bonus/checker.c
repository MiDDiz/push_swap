/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:03:08 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 11:14:22 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	main(int argc, char *argv[])
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
	// Get input, do operation given check for solved.
	return (0);
}