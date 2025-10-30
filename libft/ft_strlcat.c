/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:59:33 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/06/29 18:28:23 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			dst_len;
	size_t			src_len;

	if (!dst || !src)
	{
		return (0);
	}
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	i = 0;
	while ((dst_len + i + 1) < size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
	{
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
