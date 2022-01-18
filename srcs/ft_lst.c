#include "../hdrs/minishell.h"

static t_storylst 	*ft_storylst_new(char *str)
{
	t_storylst	*story;

	story = (t_storylst *) malloc(sizeof (t_storylst));
	if (story == NULL)
		return (NULL);
	story->str = ft_strdup(str);
	if (!story->str)
		return (NULL);
	story->next = NULL;
	return (story);
}

int	ft_storylst_lstclear(t_storylst **lst_step, int status)
{
	t_storylst	*lst_step_step;
	t_storylst	*swap;

	lst_step_step = *lst_step;
	while (lst_step_step)
	{
		swap = (lst_step_step)->next;
		free(lst_step_step);
		lst_step_step = swap;
	}
	*lst_step = NULL;
	if (status)
		return (1);
	else
		return (0);
}

int	ft_storylst_add_back(t_storylst **lst_step, char *str)
{
	t_storylst	*lst_step_step;

	if (!*lst_step)
	{
		*lst_step = ft_storylst_new(str);
		if (!*lst_step)
			return (1);
	}
	else
	{
		lst_step_step = *lst_step;
		while (lst_step_step->next)
			lst_step_step = lst_step_step->next;
		lst_step_step->next = ft_storylst_new(str);
		if (!lst_step_step->next)
			return (1);
	}
	return (0);
}
