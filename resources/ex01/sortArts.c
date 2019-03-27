/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:40:39 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/25 14:40:41 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

static int myCompare(const void* a, const void* b) 
{
	return (strcmp((*(struct s_art**)a)->name, (*(struct s_art**)b)->name)); 
} 

int		len_list(struct s_art **arts)
{
	int count;

	count = 0;
	while(arts[count])
		count++;
	return (count);
}

void  sortArts(struct s_art **arts)
{
	int len  = len_list(arts);
	qsort(arts, len, sizeof(const struct s_art **), myCompare);
}