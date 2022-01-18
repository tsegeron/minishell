#include "../../hdrs/minishell.h"

size_t	ft_lstsize(t_list **lst)
{
	t_list	*lst_step;
	size_t		size;

	size = 0;
	lst_step = *lst;
	while (lst_step)
	{
		size++;
		lst_step= lst_step->next;
	}
	return (size);
}