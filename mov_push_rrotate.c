/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push_rrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:06:42 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/20 12:45:42 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_push(t_control *control, char c)
{
	t_list	*aux;

	if (c == 'b')
	{
		write(1, "pb\n", 3);
		aux = control->stack_a;
		control->stack_a = control->stack_a->next;
		ft_lstadd_front(&control->stack_b, aux);
		control->a_size--;
		control->b_size++;
	}
	else if (c == 'a')
	{
		write(1, "pa\n", 3);
		aux = control->stack_b;
		control->stack_b = control->stack_b->next;
		ft_lstadd_front(&control->stack_a, aux);
		control->a_size++;
		control->b_size--;
	}
	control->total_moves++;
}

static void	ft_rrotate_job(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next->next = *stack;
	*stack = aux->next;
	aux->next = NULL;
}

void	ft_rrotate(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "rra\n", 4);
		ft_rrotate_job(&control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "rrb\n", 4);
		ft_rrotate_job(&control->stack_b);
	}
	else if (c == 'r')
	{
		write(1, "rrr\n", 4);
		ft_rrotate_job(&control->stack_a);
		ft_rrotate_job(&control->stack_b);
	}
	control->total_moves++;
}
