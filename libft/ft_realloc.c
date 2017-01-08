/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:02:00 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/06 18:22:05 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new)
{
	void *tmp;

	tmp = ptr;
	if (!(ptr = malloc(sizeof(*ptr) * new)))
		return (NULL);
	ptr = ft_memmove(ptr, (const void *)tmp, (size > new) ? new : size);
	free(tmp);
	return (ptr);
}
