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
}
