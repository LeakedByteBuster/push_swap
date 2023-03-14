/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:42:38 by mfouadi           #+#    #+#             */
/*   Updated: 2022/11/07 04:46:55 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Like all functions in <type.c> library, isalnum :
* returns 0 if the test is false
* 1 if the test is true
* OR the value of "EOF", which always will be a negative value (C Standard)
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
