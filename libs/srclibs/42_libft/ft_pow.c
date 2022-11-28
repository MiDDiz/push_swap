/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:26:11 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/28 12:32:42 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns x to the positive power of y
	Does not handle overflows!
	Returns a int64_t -> 
*/
int64_t	ft_pow(int x, uint32_t y)
{
	if (y == 0)
		return (1);
	else if ((y % 2) == 0)
		return (ft_pow (x, y / 2) * ft_pow (x, y / 2));
	else
		return (x * ft_pow (x, y / 2) * ft_pow (x, y / 2));
}
