/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:16:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/12 20:25:02 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// save a copy of a string
// Segfault when s1 == NULL

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr1;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	ptr1 = (char *)malloc(s1_len + NULL_CHAR);
	if (ptr1 == (void *)0)
		return (ptr1);
	while (*s1 != '\0')
		*ptr1++ = *s1++;
	*ptr1 = '\0';
	return (ptr1 - s1_len);
}
