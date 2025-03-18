/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:23:23 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/10 03:17:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbnode	*dblst_new(int nbr)
{
	t_dbnode	*lst;

	lst = malloc(sizeof(t_dbnode));
	if (!lst)
		return (NULL);
	lst->nbr = nbr;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void	stack_add_tail(t_stack *stack, t_dbnode *new)
{
	if (stack->head == NULL && stack->tail == NULL)
	{
		stack->head = new;
		stack->tail = new;
		stack->len = 1;
	}
	else if (stack && stack->head && stack->tail && new)
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
		stack->len++;
	}
}

void	stack_free(t_stack *stack)
{
	t_dbnode	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = (stack->head)->next;
		free(temp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->len = 0;
}

void	error_exit(t_stack stk[2])
{
	clear_stacks(stk);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	clear_stacks(t_stack stk[2])
{
	if (stk[A].len > 0)
		stack_free(&stk[A]);
	if (stk[B].len > 0)
		stack_free(&stk[B]);
}
