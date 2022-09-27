/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:19:10 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/20 12:39:52 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_init_values(int mode, t_control *control)
{
	if (mode == 0)
	{
	control->stack_a = NULL;
	control->a_size = 0;
	control->a_moves = 0;
	control->stack_b = NULL;
	control->b_size = 0;
	control->error = 0;
	control->index_count = 1;
	control->total_moves = 0;
	}
	control->ra = 0;
	control->rb = 0;
	control->rr = 0;
	control->rra = 0;
	control->rrb = 0;
	control->rrr = 0;
}

void	ft_init_stack(int mode, t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (aux)
	{
		if (mode == 0)
			aux->index = 0;
		aux->ra = 0;
		aux->rb = 0;
		aux->rr = 0;
		aux->rra = 0;
		aux->rrb = 0;
		aux->rrr = 0;
		aux->moves = 0;
		aux = aux->next;
	}
}
