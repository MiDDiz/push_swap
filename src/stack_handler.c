/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:15:48 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/04 11:02:24 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We pass the stack for, in case of error, be able to free it. Also to check it there is duplicates.
int parse_int(char *ch_int, t_stack *stack, int expected_size)
{
	int res;

	if ((ch_int[0] != '-' && check_overflows(ch_int)) || 
		(ch_int[0] == '-' && check_underflows(ch_int)))
	{
		free(stack->data);
		ft_perror("Erroes\n");
		exit (-1);
	}
	res = ft_atoi(ch_int);
	if (check_duplicates(res, stack, expected_size))
	{
		free(stack->data);
		ft_perror("Errores\n");
		exit (-1);
	}
	return res;
}


int parse_stack(t_stack *stack, int argc, char **argv)
{
	int i;

	stack->data = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack->data)
	{
		ft_perror("Errores\n");
		return (-1);
	}
	stack->size = 0;
	i = argc - 1;
	while (stack->size < argc - 1)
	{
		stack->data[i - 1] = parse_int(argv[stack->size + 1], stack, argc - 1);
		i--;
		stack->size++;
	}
	return(0);
}

int generate_empty_stack(t_stack *stack, int size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
	{
		ft_perror("Errores\n");
		return (-1);
	}
	stack->size = 0;
	return(0);
}

void	exec_instr(int instr, t_stack *a, t_stack *b)
{
	char *str_instr;

	str_instr = ft_itoa(instr);
	ft_printf("%s\n", str_instr);
	instructor(instr, a, b);
}