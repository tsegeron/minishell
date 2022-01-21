<<<<<<< HEAD
#include "../../hdrs/minishell.h"

static char	*ft_help(void)
{
	char	*ptr;

	ptr = (char *)malloc(1);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned int	lenstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	lenstr = ft_strlen(ptr);
	if (lenstr < start)
		ptr = ft_help();
	else
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		ptr = (char *)malloc(sizeof(char) * len + 1);
		if (ptr == NULL)
			return (NULL);
		while (i != len && s[start] != '\0')
			ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:11:36 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1 || len == 0)
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *) malloc (len * sizeof(char) + 1);
	if (sub)
	{
		while (i != len && *s)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub[i] = '\0';
	}
	return (sub);
>>>>>>> merge
}
