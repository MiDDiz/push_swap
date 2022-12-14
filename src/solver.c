/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:40:38 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/14 15:25:35 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 







SOPESA USAR A* PARA COMPLETAR ESTE PROYECTO!




*/
int	get_max_number(t_stack *stack_a)
{
	int	i, max;

	i = 0;
	/* Max starts at the bottom of the stack*/
	max = *(stack_a->data);
	while (i < stack_a->size)
	{ /* And is checkinf from botton to top */
		if (stack_a->data[i] > max)
			max = stack_a->data[i];
		i++;
	}
	/* And we return the len of the number -> how many iterations. 
		This is so fucking unefficient that hurts lol */
	return (ft_strlen(ft_itoa(max)));
}

int	get_digit_on_pos(int number, int pos)
{
	return (number / ft_pow(10, pos) % 10);
}

int	push_on_digit(t_stack *from, t_stack *to, int dig, int power)
{
	int	head;

	/* 
	* While we still have head and the digit on head that we are 
	checking corresponds with the digit currently being pushed.
	*/
	while (from->size && (get_digit_on_pos(from->data[from->size - 1], power) == dig))
	{
		print_stacks(from, to, pa);
		sleep(1);
		// Pb -> Pushes from a(from) to b(to)
		instructor(pb, from, to);
	}
	// head does not need to be pushed -> we have anchor
	/* 
		We will use this anchor to know when we have iterated the whole stack.
	*/
	head = from->data[from->size - 1];
	print_stacks(from, to, pa);
	instructor(ra, from, to);
	// iter the stack while head does not match curr head
	while (from->size && from->data[from->size - 1] != head)
	{
		ft_printf("Size: %d\n", from->size);

		if (get_digit_on_pos(from->data[from->size - 1], power) == dig)
		{
			// Push element to stack b
		print_stacks(from, to, pa);

			instructor(pb, from, to);
		}
		else
		{
			// else rotate a
			print_stacks(from, to, pa);

			instructor(ra, from, to);
			
		}
		sleep(1);

	}
		sleep(1);
	
	return (0);
}

void	sort_on_iter(int iter, t_stack *a, t_stack *b)
{
	int	power, dig;

	/* Get the power of ten to whatever iteration we have so we can check the digit that we need to*/
	power = ft_pow(10, iter);
	dig = 0;
	/* On even iterations we need to push from right stack into left stack */
	if (iter % 2 == 0)
	{
		while (dig < 10)
		{
			/* So for each digit we push it onto the other stack in order */
			push_on_digit(a, b, dig, power);
			dig++;
		}
	}
	/* And on odd iterations we need to push from left stack into right stack */
	else
	{
		while (dig < 10)
		{
			push_on_digit(b, a, dig, power);
			dig++;
		}
	}
}

int solver_stack(t_stack *a, t_stack *b)
{
	int iterations, iter;

	iterations = get_max_number(a);
	iter = 0;
	while(iter < iterations)
	{
		sort_on_iter(iter, a, b);
		iter++;
	}
	/* 
	 * With this we will get (unproven) 4 types of cases 
	 *	- Stack a full sorted, 
	 *	- Stack a full inverted sorted
	 *	- Stack b full sorted
	 *	- Stack b full inverted sorted
	*/
	
	return (0);
}
