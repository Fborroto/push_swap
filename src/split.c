/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:06 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/22 17:02:00 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countstr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}

static char	**ft_strings(char **s2, char const *s, char c)
{
	int	i[2];
	int	count;

	i[0] = 0;
	count = 0;
	while (s[i[0]])
	{
		if (s[i[0]] == c)
			i[0]++;
		else
		{
			i[1] = 0;
			while (s[i[0]] && s[i[0]] != c)
			{
				i[1]++;
				i[0]++;
			}
			s2[count] = (char *)malloc(sizeof(char) * (i[1] + 1));
			if (!s2[count])
				return (0);
			ft_strcpy(s2[count], s + (i[0] - i[1]), i[1] + 1);
			count++;
		}
	}
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;

	if (!s)
		return (0);
	size = ft_countstr(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	split = ft_strings(split, s, c);
	split[size] = 0;
	return (split);
}
