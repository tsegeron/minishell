/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:00:10 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/16 22:35:12 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	ft_substrs_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_strlen_up(char const *str, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (str[start] == c)
		start++;
	while (str[start] != c && str[start++] != '\0')
		i++;
	return (i);
}

static char	**ft_get_array(char const *str, char c, int count)
{
	char	**array;
	size_t	lenstr;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	array = (char **) malloc ((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[count] = NULL;
	if (count == 0)
		return (array);
	while (count-- != 0)
	{
		while (str[i] == c)
			i++;
		lenstr = ft_strlen_up(str, i, c);
		array[a++] = ft_substr(str, i, lenstr);
		i += lenstr;
	}
	return (array);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	int		count;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	count = ft_substrs_count(str, c);
	array = ft_get_array(str, c, count);
	while (i < count - 1)
	{
		if (array[i] == NULL)
			break ;
		i++;
	}
	if (i < count - 1)
	{
		i = 0;
		while (i != count - 1)
			free (array[i++]);
		free(array);
		return (NULL);
	}
	return (array);
}
