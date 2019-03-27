/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:42:29 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/26 14:42:31 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int myCompare(const void* a, const void* b) 
{
	return (strcmp((*(struct s_art**)a)->name, (*(struct s_art**)b)->name)); 
}

void		sortArts(struct s_art **arts, int len)
{
	qsort(arts, len, sizeof(const struct s_art **), myCompare);
}

int			binary_search(struct s_art **arts, int low, int higth, char *name)
{
	int		mid = 0;
	if (higth >= low && mid >= 0 && low >= 0)
	{
		mid = low + (higth - low) / 2;
		if (strcmp((arts[mid])->name, name) == 0)
			return mid;
		if (strcmp((arts[mid])->name, name) > 0)
			return binary_search(arts, low, mid - 1, name);
		return binary_search(arts, mid + 1, higth, name);
	}
	return (-1);
}

int			searchPrice(struct s_art **arts, int n, char *name)
{
	return (binary_search(arts, 0, n, name));
}