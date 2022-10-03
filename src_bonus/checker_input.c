/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:34:16 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 12:28:26 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int parse_instr(char *unp_instr)
{
	int instr;
	const char *c_instr[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr", NULL};

	instr = 0;
	while (c_instr[instr])
	{
		// If we found a match
		if (!ft_strncmp(c_instr[instr], (const char *)unp_instr, ft_strlen(c_instr[instr])))
			return (instr + 1);
		instr++;
	}
	return (-1);
}

int exec_instr(int instr, t_stack *stack_a, t_stack *stack_b)
{
	instructor(instr, stack_a, stack_b);
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
			free(unparsed_instr);
			return (-1);
		}
		exec_instr(instr, stack_a, stack_b);
		unparsed_instr = get_next_line(STDIN_FILENO);
	}
	return (0);
}