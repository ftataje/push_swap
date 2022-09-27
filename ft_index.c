/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:35:16 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/20 12:36:31 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index_min(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;

	stack = control->stack_a;
	while (stack)
	{
		check = 0;
		aux = control->stack_a;
		while (aux)
		{
			if (stack->content > aux->content && aux->index == 0)
				check = 1;
			aux = aux->next;
		}
		if (check == 0 && stack->index == 0)
		{
			stack->index = control->index_count++;
			break ;
		}
		stack = stack->next;
	}
}

void	ft_index(t_control *control)
{
	int	loops;

	loops = control->a_size;
	while (loops--)
		ft_index_min(control);
}
