/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:08:36 by cormiere          #+#    #+#             */
/*   Updated: 2023/10/16 19:08:38 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	size_t			i;
	size_t			j;
	char			*joined_str;

	joined_str = malloc(len_s1 + len_s2 + 1);
	if (!joined_str)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		joined_str[i] = s1[i];
	j = -1;
	while (++j < len_s2)
	{
		joined_str[i] = s2[j];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != (unsigned char)c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	total_size = count * size;
	ptr = malloc(total_size);
	if (count != 0 && total_size / count != size)
		return (NULL);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	target;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == target)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
