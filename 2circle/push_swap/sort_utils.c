/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:28:30 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 13:03:56 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exception(t_list **a)
{
	if ((*a)->next->next->n == 0)
	{
		r_logic(a, 'a');
		r_logic(a, 'a');
		s_logic(a, 'a');
		r_logic(a, 'a');
	}
	if ((*a)->next->next->n == 4)
	{
		rr_logic(a, 'a');
		rr_logic(a, 'a');
		s_logic(a, 'a');
	}
}

int	*get_sort_arr(t_list *lst)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit(EXIT_FAILURE);
	while (lst)
	{
		arr[i++] = lst->n;
		lst = lst->next;
	}
	sort_arr(arr, 0, len - 1);
	return (arr);
}

void	sort_arr(int *arr, int left, int right)
{
	int			i;
	int			j;
	const int	pivot = arr[(left + right) / 2];
	int			temp;

	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	if (left < j)
		sort_arr(arr, left, j);
	if (i < right)
		sort_arr(arr, i, right);
}

void	trans_to_index(t_list *a)
{
	int	*arr;
	int	i;
	int	len;

	len = ft_lstsize(a);
	arr = get_sort_arr(a);
	while (a)
	{
		i = 0;
		while (a->n != arr[i])
			i++;
		a->n = i;
		a = a->next;
	}
	free(arr);
}

int	check_sort(t_list *a, int len)
{
	int	i;

	i = 1;
	while (a->next && a->n < a->next->n)
	{
		a = a->next;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
