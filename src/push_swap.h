/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:01:12 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/15 15:19:21 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libs/srclibs/42_libft/libft.h"
#include "../libs/srclibs/ft_printf/includes/ft_printf.h"
// GNL
char	*get_next_line(int fd);

# define MAX_INT_STR "2147483647"
# define MIN_INT_STR "-2147483648"

/* 
	How does my stack work?

	First of all, we need to understand the data structures:
	t_stack has: 
		data ->	# # # # # #
		size -> 6
	the HEAD of the stack is at the data[size - 1] position.

	And thats it haha.
*/


typedef struct s_stack{
	int	*data;
	int	size;
} t_stack;

typedef struct s_state
{
	t_stack			*stack_a;	// Stack a
	t_stack			*stack_b;	// Stack b
	int				checksum;	// Checksum for quick comparasion between states.
	unsigned char	operation;	// What operation has been taken to get to this state.
	t_state			*parent;	// Previous state
	int				cost;
} t_state;

// Porque me apetece 
typedef enum { false, true } t_bool;


// Step
# define sa 1
# define sb 2
# define ss 3
# define pa 4
# define pb 5
# define ra 6
# define rb 7
# define rr 8
# define rra 9
# define rrb 10
# define rrr 11
# define NUM_OPERATIONS 11
/* err_handler.c */
int check_args(int argc, char **argv);
int check_underflows(char *ch_int);
int check_overflows(char *ch_int);
int check_duplicates(int num, t_stack *stack, int expected_stack_size);
void ft_perror(char *msg);

/* stack_handler.c */
int parse_stack(t_stack *stack, int argc, char **argv);
int generate_empty_stack(t_stack *stack, int size);

/* stack_instrucitons.c interface */
void	instructor(int instruction, t_stack *stack_a, t_stack *stack_b);

/* solver */
int solver_stack(t_stack *stack_a, t_stack *stack_b);
// CHECKER

// checker_input.c
int	solve_instructions(t_stack *stack_a, t_stack *stack_b);

//DEBUG DELETE THIS AND FROM THE  MAKEFILE !!!!!!!!!!!!!!!! AAAAAAAAAAAAAASDASDASDADASDADASDASDASDADASDADASDASDASDASDASDASDASDASDADASDASD
void print_stacks(t_stack *stack_a, t_stack *stack_b, int instr);

/* lst instructions */
void	*ft_lstpopf(t_list **head);

#endif