/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:34:16 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/04 10:28:47 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int parse_instr(char *unp_instr)
{
	int instr;
	const char *c_instr[] = {"sa\0", "sb\0", "ss\0", "pa\0", "pb\0", "ra\0", "rb\0", "rr\0", "rra\0", "rrb\0", "rrr", NULL};

	if (ft_strlen(unp_instr) - 1 < 2 || ft_strlen(unp_instr) - 1 > 3)
		return (-1);
	instr = 0;
	while (c_instr[instr])
	{
		// If we found a match we pass the execution: ft_strlen * 1 bc unp_instr has \n at the back.
		if (!ft_strncmp(c_instr[instr], (const char *)unp_instr, ft_strlen(unp_instr) - 1))
			return (instr + 1);
		instr++;
	}
	return (-1);
}

int exec_instr(int instr, t_stack *stack_a, t_stack *stack_b)
{
	//DELETE THIS
	instructor(instr, stack_a, stack_b);
	print_stacks(stack_a, stack_b, instr);
	return (0);
}

int	solve_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*unparsed_instr;
	int		instr;

	unparsed_instr = get_next_line(STDIN_FILENO);
	while (unparsed_instr != NULL)
	{
		instr = parse_instr(unparsed_instr);
		if (instr < 0)
		{
			ft_perror("Error\n");
			free(unparsed_instr);
			return (-1);
		}
		exec_instr(instr, stack_a, stack_b);
		unparsed_instr = get_next_line(STDIN_FILENO);
	}
	return (0);
}