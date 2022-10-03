/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:01:12 by jnaftana          #+#    #+#             */
/*   Updated: 2022/10/03 13:11:31 by jnaftana         ###   ########.fr       */
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

typedef struct s_stack{
	int	*data;
	int	size;
} t_stack;

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

/* err_handler.c */
int check_args(int argc, char **argv);
int check_underflows(char *ch_int);
int check_overflows(char *ch_int);
int check_duplicates(int num, int *stack, int stack_size);
void ft_perror(char *msg);

/* stack_handler.c */
int parse_stack(t_stack *stack, int argc, char **argv);
int generate_empty_stack(t_stack *stack, int size);

/* stack_instrucitons.c interface */
void instructor(int instruction, t_stack *stack_a, t_stack *stack_b);

// CHECKER

// checker_input.c
int	solve_instructions(t_stack *stack_a, t_stack *stack_b);

//DEBUG DELETE THIS AND FROM THE  MAKEFILE !!!!!!!!!!!!!!!! AAAAAAAAAAAAAASDASDASDADASDADASDASDASDADASDADASDASDASDASDASDASDASDASDADASDASD
void print_stacks(t_stack *stack_a, t_stack *stack_b, int instr);

#endif