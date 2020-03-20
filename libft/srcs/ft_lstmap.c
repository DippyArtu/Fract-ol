/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:20:38 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *fresh_new;
	t_list *fresh_prev;

	fresh = NULL;
	if (lst && f)
	{
		fresh = (*f)(lst);
		fresh_prev = fresh;
		lst = lst->next;
		while (lst)
		{
			fresh_new = (*f)(lst);
			fresh_prev->next = fresh_new;
			fresh_prev = fresh_new;
			lst = lst->next;
		}
		fresh_prev->next = NULL;
	}
	return (fresh);
}
