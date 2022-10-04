/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:04:48 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/04 11:09:18 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exec_instr(int instr, t_stack *a, t_stack *b)
{
	instructor(instr, a, b);
	if (instr == sa)
		ft_printf("sa\n");
	else if (instr == sb)
		ft_printf("sb\n");
	else if (instr == ss)
		ft_printf("ss\n");
	else if (instr == pa)
		ft_printf("pa\n");
	else if (instr == pb)
		ft_printf("pb\n");
	else if (instr == ra)
		ft_printf("ra\n");
	else if (instr == rb)
		ft_printf("rb\n");
	else if (instr == rr)
		ft_printf("rr\n");
	else if (instr == rra)
		ft_printf("rra\n");
	else if (instr == rrb)
		ft_printf("rrb\n");
	else if (instr == rrr)
		ft_printf("rrr\n");
}