/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:15:48 by jnaftana          #+#    #+#             */
/*   Updated: 2022/09/20 20:35:45 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We pass the stack for, in case of error, be able to free it. Also to check it there is duplicates.
int parse_int(char *ch_int, t_stack *stack)
{
	int res;

	if ((ch_int[0] != '-' && check_overflows(ch_int)) || 
		(ch_int[0] == '-' && check_underflows(ch_int)))
	{
		free(stack->data);
		ft_perror("Error\n");
		exit (-1);
	}
	res = ft_atoi(ch_int);
	if (check_duplicates(res, stack->data, stack->size))
	{
		free(stack->data);
		ft_perror("Error\n");
		exit (-1);
	}
	return res;
}


int parse_stack(t_stack *stack, int argc, char **argv)
{
	stack->data = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack->data)
	{
		ft_perror("Error\n");
		return (-1);
	}
	stack->size = 0;
	while (stack->size < argc)
	{
		stack->data[stack->size] = parse_int(argv[stack->size + 1], stack);
		stack->size++;
	}
	return(0);
}

int generate_empty_stack(t_stack *stack, int size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
	{
		ft_perror("Error\n");
		return (-1);
	}
	stack->size = size;
	return(0);
}