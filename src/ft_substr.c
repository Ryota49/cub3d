/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:42:16 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/29 19:04:14 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*sub_string(char const *s, char *li_s, unsigned int st, size_t l)
{
	size_t	i;

	i = 0;
	while (s[st] && i < l)
	{
		li_s[i] = s[st];
		st++;
		i++;
	}
	li_s[i] = '\0';
	return (li_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*little_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if (s == 0 || start > ft_strlen((char *)s))
	{
		little_s = malloc(sizeof(char));
		if (!little_s)
			return (NULL);
		little_s[0] = '\0';
		return (little_s);
	}
	little_s = malloc(sizeof(char) * len + 1);
	if (!little_s)
		return (NULL);
	little_s = sub_string(s, little_s, start, len);
	return (little_s);
}
