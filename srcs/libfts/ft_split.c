<<<<<<< HEAD
#include "../../hdrs/minishell.h"

static int	ft_counter_words(const char *str, char c)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] == c)
			index++;
		if (str[index] != c && str[index] != '\0')
			count++;
		while (str[index] != c && str[index] != '\0')
			index++;
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:00:10 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
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
>>>>>>> merge
	}
	return (count);
}

<<<<<<< HEAD
static int	ft_len_str(const char *str, int index, char c)
{
	int	len;

	len = 0;
	while (str[index] == c)
		index++;
	while (str[index] != c && str[index++] != '\0')
		len++;
	return (len);
}

static char	**ft_mem_str(int counter_words, const char *str, char c)
{
	char	**ptr;
	char	*string;
	int		index_char;
	int		index_str;
	int		len;

	index_char = 0;
	index_str = 0;
	ptr = (char **)malloc(sizeof(char *) * (counter_words + 1));
	if (!ptr)
		return (NULL);
	ptr[counter_words] = NULL;
	if (counter_words == 0)
		return (ptr);
	while (index_str < counter_words)
	{
		while (str[index_char] == c)
			index_char++;
		len = ft_len_str(str, index_char, c);
		string = ft_substr(str, index_char, len);
		ptr[index_str++] = ft_strdup(string);
		free(string);
		index_char += len;
	}
	return (ptr);
}

static	char	**ft_free_ptr(int counter_words, char **ptr)
{
	int	count;

	count = 0;
	while (count < counter_words - 1)
		free(ptr[count++]);
	free(ptr);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**ptr;
	int		counter_words;
	int		count;

	if (!str)
		return (NULL);
	count = 0;
	counter_words = ft_counter_words(str, c);
	ptr = ft_mem_str(counter_words, str, c);
	if (!ptr)
		return (NULL);
	while (count < counter_words - 1)
	{
		if (ptr[count] == NULL)
			break ;
		count++;
	}
	if (count < counter_words - 1)
		return (ft_free_ptr(counter_words, ptr));
	return (ptr);
=======
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
>>>>>>> merge
}
