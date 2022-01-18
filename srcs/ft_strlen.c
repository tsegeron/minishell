#include "../hdrs/minishell.h"
/* Функция подсчета символов (char) в констатной строке (str);
 */
size_t ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*	Фунция подсчета указветлей типа (char *) в массиве указателей (char **);
 *	При возвращении 0 значения выводтися ошибка. Либо (char **), либо (char **)[1] ссылается на NULL;
 */
size_t	ft_len_array(char **array)
{
	size_t	len;

	len = 0;
	if (array)
		while (array[len])
			len++;
	return (len);
}
