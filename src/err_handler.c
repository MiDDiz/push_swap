/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:55 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 14:47:23 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Prints in std_err msg*/
void ft_perror(char *msg)
{
	ft_putstr_fd(msg, 2);
}

// The second checks accepts negative integers, only if they have the minus sign at the begining.
int check_ints(int argc, char **argv)
{
	int i;
	char *argument;
	i = 1;

	while (i < argc)
	{
		argument = argv[i];
		while (*argument)
		{
			if (!ft_isdigit(*argument++) || (argument == argv[i] && *argument == '-'))
				return (1);
		}
		i++;
	}
	return (0);
}

// Checking for num of args, and every arg is digit.
int check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_perror("Error\n");
		return (-1);
	}
	if (check_ints(argc, argv))
	{
		ft_perror("Error\n");
		return (-2);
	}
	return (0);
}

int check_overflows(char *ch_int)
{
	int i;
	int len;

	len = ft_strlen(ch_int);
	if (*ch_int == '0' && len != 1)
		return (-1);
	if (len > 10)
		return (-1);
	if (len == 10)
	{
		i = 0;
		while (i < len)
		{
			if (MAX_INT_STR[i] < ch_int[i])
				return (-1);
			if (MAX_INT_STR[i] == ch_int[i])
				i++;
			else
				return (0);
		}
	}
	return (0);
}

int check_underflows(char *ch_int)
{
	int i;
	int len;

	if (ch_int[1] == '0')
		return (-1);
	len = ft_strlen(ch_int);
	if (len > 11)
		return (-1);
	if (len == 11)
	{
		i = 0;
		while (i < len)
		{
			if (MIN_INT_STR[i] < ch_int[i])
				return (-1);
			if (MIN_INT_STR[i] == ch_int[i])
				i++;
			else
				return (0);
		}
	}
	return (0);
}

int check_duplicates(int num, t_stack *stack, int expected_size)
{
	int i;

	i = expected_size;
	//ft_printf("num: %d i:%d\n", num, i);
	while(i > expected_size - stack->size)
	{
		
		//ft_printf("\tPos %d: %d\n",i,  stack->data[i - 1]);
		
		if (num == stack->data[i - 1])
			return (-1);
		i--;
	}
	return (0);
}
