/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:15:48 by jnaftana          #+#    #+#             */
/*   Updated: 2022/09/19 12:04:17 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We pass the stack for, in case of error, be able to free it. Also to check it there is duplicates.
int parse_int(char *ch_int, int *stack, int stack_size)
{
	int res;

	if ((ch_int[0] != '-' && check_overflows(ch_int)) || 
		(ch_int[0] == '-' && check_underflows(ch_int)))
	{
		free(stack);
		ft_perror("Error\n");
		exit (-1);
	}
	res = ft_atoi(ch_int);
	if (check_duplicate(res, stack))
	{
		free(stack);
		ft_perror("Error\n");
		exit (-1);
	}
	return res;
}


int parse_stack(int **stack, int argc, char **argv)
{
	int i;

	*stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!*stack)
	{
		ft_perror("Error\n");
		return (-1);
	}
	i = 0;
	while (i < argc)
	{
		*stack[i] = parse_int(argv[i + 1], stack, i);
		i++;
	}
}