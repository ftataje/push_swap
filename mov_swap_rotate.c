/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:29:23 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/20 12:39:21 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_swap_job(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = aux->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	ft_swap(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "sa\n", 3);
		ft_swap_job(&control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "sb\n", 3);
		ft_swap_job(&control->stack_b);
	}
	else if (c == 's')
	{
		write(1, "ss\n", 3);
		ft_swap_job(&control->stack_a);
		ft_swap_job(&control->stack_b);
	}
	control->total_moves++;
}

static void	ft_rotate_job(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = *stack;
	*stack = (*stack)->next;
	aux->next->next = NULL;
}

void	ft_rotate(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "ra\n", 3);
		ft_rotate_job(&control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "rb\n", 3);
		ft_rotate_job(&control->stack_b);
	}
	else if (c == 'r')
	{
		write(1, "rr\n", 3);
		ft_rotate_job(&control->stack_a);
		ft_rotate_job(&control->stack_b);
	}
	control->total_moves++;
}
