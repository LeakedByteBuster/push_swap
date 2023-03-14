/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:38:33 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 20:25:28 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//compares two strings, not more than n characters

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	if (n == 0)
		return (0);
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i <= n - 1))
	{
		if (!(s1[i] == s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
