/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:53:29 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/25 13:53:33 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
int  searchPrice(struct s_art **arts, char *name)\
{
	int		i;

	i = -1;
	while (arts[++i])
		if (strcmp(arts[i]->name, name) == 0)
			return(arts[i]->price);
	return (-1);
}