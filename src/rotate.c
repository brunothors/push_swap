/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:47:21 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/10 17:55:13 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_stack(t_stack *stack);
static void	rev_rot_stack(t_stack *stack);

void	rotate(t_stack stk[2], int flag, int times)
{
	if ((flag == A && stk[A].len == 0) || (flag == B && stk[B].len == 0))
		return ;
	while (times--)
	{
		rot_stack(&stk[flag]);
		if (flag == A)
			ft_putendl_fd("ra", STDOUT_FILENO);
		else
			ft_putendl_fd("rb", STDOUT_FILENO);
	}
}

void	rev_rotate(t_stack stk[2], int flag, int times)
{
	if ((flag == A && stk[A].len == 0) || (flag == B && stk[B].len == 0))
		return ;
	while (times--)
	{
		rev_rot_stack(&stk[flag]);
		if (flag == A)
			ft_putendl_fd("rra", STDOUT_FILENO);
		else
			ft_putendl_fd("rrb", STDOUT_FILENO);
	}
}

static void	rot_stack(t_stack *stk)
{
	stk->tail->next = stk->head;
	stk->head->prev = stk->tail;
	stk->head = stk->head->next;
	stk->head->prev = NULL;
	stk->tail = stk->tail->next;
	stk->tail->next = NULL;
}

static void	rev_rot_stack(t_stack *stk)
{
	stk->head->prev = stk->tail;
	stk->tail->next = stk->head;
	stk->tail = stk->tail->prev;
	stk->tail->next = NULL;
	stk->head = stk->head->prev;
	stk->head->prev = NULL;
}
