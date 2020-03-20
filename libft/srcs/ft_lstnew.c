/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:21:45 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	char	*str;

	str = (char *)content;
	ptr = (t_list *)malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	if (!content)
	{
		ptr = ft_lstnull(ptr);
		return (ptr);
	}
	ptr->content = (char *)malloc(content_size);
	if (ptr->content == NULL)
		return (NULL);
	ptr->content = ft_strcpy(ptr->content, (char *)str);
	ptr->content_size = content_size;
	ptr->next = NULL;
	return (ptr);
}
