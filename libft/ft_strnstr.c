/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:13:05 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/06/18 17:02:23 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	if (!big || !little)
	{
		return (NULL);
	}
	if (*little == '\0')
	{
		return ((char *)big);
	}
	l = ft_strlen(little);
	i = 0;
	while (big[i] && (i + l <= len))
	{
		if (ft_strncmp(&big[i], little, l) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
