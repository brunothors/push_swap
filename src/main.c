/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:01:35 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:13 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack stk[2]);
static int	pplt_stack(char **argv, t_stack stk[2]);
static void	check_int(char *nbr, t_stack stk[2]);
static void	check_dup(int nbr, t_stack stk[2]);

int	main(int argc, char **argv)
{
	t_stack	stk[2];

	if (argc < 2)
		return (EXIT_FAILURE);
	init_stack(stk);
	pplt_stack(argv, stk);
	init_sort(stk);
	clear_stacks(stk);
}

static void	init_stack(t_stack stk[2])
{
	stk[A].len = 0;
	stk[A].head = NULL;
	stk[A].tail = NULL;
	stk[B].len = 0;
	stk[B].head = NULL;
	stk[B].tail = NULL;
}

static int	pplt_stack(char **argv, t_stack stk[2])
{
	long		nbr;

	while (*(++argv))
	{
		check_int(*argv, stk);
		nbr = ft_atol(*argv);
		if (nbr < -2147483648 || nbr > 2147483647)
			error_exit(stk);
		check_dup(nbr, stk);
		stack_add_tail(&stk[A], dblst_new((int) nbr));
	}
	return (0);
}

static void	check_int(char *nbr, t_stack stk[2])
{
	size_t	len;

	if (!(*nbr))
		error_exit(stk);
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '\0')
		error_exit(stk);
	while (*nbr == '0')
		nbr++;
	len = 0;
	while (*nbr)
	{
		if (ft_isdigit(*nbr))
			nbr++;
		else
			error_exit(stk);
		if (++len > 10)
			error_exit(stk);
	}
}

static void	check_dup(int nbr, t_stack stk[2])
{
	t_dbnode	*temp;

	temp = stk[0].head;
	while (temp)
	{
		if (temp->nbr == nbr)
			error_exit(stk);
		temp = temp->next;
	}
}
