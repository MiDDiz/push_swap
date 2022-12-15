/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ida.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:31:28 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/15 15:37:49 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_dfs
{
	int		new_threshold;
	t_state	*found;
}	t_dfs;


int	get_heuristics(t_state	*state){
	
}

int64_t	generateStateCheckSum(t_state *state){
	int64_t	checksum;
	int i;

	checksum = 0;
	i = 0;
	while (i < state->stack_a->size)
	{
		checksum = checksum ^ state->stack_a->data[i];
		i++;
	}
	i = 0;
	while (i < state->stack_b->size)
	{
		checksum = checksum ^ state->stack_b->data[i];
		i++;
	}
	return (checksum);
}

void	constructChild(t_state *parent, t_state *child, int oper){
	child->parent = parent;
	cloneStack(parent->stack_a, child->stack_a);
	cloneStack(parent->stack_b, child->stack_b);
	child->operation = oper;
	instructor(oper, child->stack_a, child->stack_b);
	child->cost = parent->cost + 1;
	/* CON IDA* NOS LA PELA EL CHECKSUM!! */
	child->checksum = generateStateCheckSum(child);
}
/* hay que chequear que los hijos se pueden genear con la opeación  YA LO HACEMOS ABAJO-> no se puede pushear de a si a esta vacio .ej.*/
t_state	**generate_childs(t_state *parent){
	/* Gen children list with t_state structs */
	int	i;
	t_state	**children;

	i = 0;
	children = (t_state**) malloc(sizeof(t_state *) * (NUM_OPERATIONS + 1));
	while (i < NUM_OPERATIONS)
	{
		children[i] = (t_state *)malloc(sizeof(t_state));
		/* fill children*/ 
		constructChild(parent, children[i], i + 1);
	}
	return (children);
}
/*
t_dfs	dfs(t_state *parent, int threshold)
{
	t_dfs dfs_return;
	int	f_parent;
	int	min;
	t_state	**temp_nodes;

	dfs_return.found = NULL;
	f_parent = parent->cost + get_heuristics(parent);
	if (f_parent > threshold)
	{
		dfs_return.new_threshold = f_parent;
		return dfs_return;
	}
	if (is_goal(parent)){
		dfs_return.found = parent;
		return dfs_return;
	}
	min = INT32_MAX;
	temp_nodes = generate_childs(parent);

}
*/

void append_ordered(t_list **open, t_state *child){
	/* **open porque el head puede cambiar */
	t_state 
}

void	append_children_to_open(t_list	**open, t_state **children)
{
	while (*children)
	{
		if (validate_children(*children))
		{
			append_ordered(open, *children);
		}
		children++;
	}
}

t_dfs	dfs(t_state *parent, int threshold)
{
	t_list	*open;
	t_bool	success;
	t_state	*state;
	t_state **children;
	t_state	*final_state;
	t_dfs	dfs_return;

	open = ft_lstnew(parent);
	success = false;
	while (open && !success)
	{
		state = (t_state *)ft_lstpopf(&open); // on first iteration, open is now null
		if (state->cost < threshold)
		{
			children = generate_childs(state);
			final_state = check_final_states(children);
			if (final_state)
			{
				dfs_return.found = final_state;
				dfs_return.new_threshold = 0;
				return (dfs_return);
			}
			append_children_to_open(&open, children)
		}
	}
	
}




int	*ida(t_state	*initial_state){
	int		threshold;
	t_dfs	dfs_return;	

	threshold = get_heuristics(initial_state);
	while (1)
	{
		dfs_return = dfs(initial_state, threshold);
		if (dfs_return.found == NULL)
		{
			threshold
		}
		/* continue algo */
	}
	
}