/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:01:12 by jnaftana          #+#    #+#             */
/*   Updated: 2022/09/19 12:00:40 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libs/srclibs/42_libft/libft.h"
#include "../libs/srclibs/ft_printf/includes/ft_printf.h"

# define MAX_INT_STR "2147483647"
# define MIN_INT_STR "-2147483648"

/* err_handler.c */
int check_args(int argc, char **argv);
int check_underflows(char *ch_int);
int check_overflows(char *ch_int);
int check_duplicates(int num, int *stack, int stack_size);
void ft_perror(const char *msg);

#endif