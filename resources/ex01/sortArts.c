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
#include <string.h>
#include "header.h"

// void  sortArts(int *arts);
// void  sortInt(int *arts);
// int		len_list(struct s_art **arts);


static int myCompare(const void* a, const void* b) 
{ 
  	// struct s_art *p1 = *(struct s_art**)a;
  	// struct s_art *p2 = *(struct s_art**)b;
  	// printf("LINE = %s\n", p1->name);
  	// printf("LINE = %s\n", p2->name);
  	// printf("LINE = %s\n", (const char*)a);
  	// printf("LINE = %s\n", b);

    // setting up rules for comparison 



    return (strcmp((*(struct s_art**)a)->name, (*(struct s_art**)b)->name)); 
} 

// int compare(const void * a, const void * b) 
// { 
//     return ( *(int*)a - *(int*)b ); 
// } 

// int		main()
// {
// 	// int *arr;

// 	// arr = (int*)malloc(sizeof(int) * 7);

// 	// arr[0] = 4;
// 	// arr[1] = 7;
// 	// arr[2] = 1;
// 	// arr[3] = 3;
// 	// arr[4] = 5;
// 	// arr[5] = 2;
// 	// arr[6] = 6;
// 	// for(int i = 0; i < 7; i++)
// 	// {
// 	// 	printf("%i\n", arr[i]);
// 	// }
// 	// // sortInt(arr);
// 	// printf("\n");
// 	// for(int i = 0; i < 7; i++)
// 	// {
// 	// 	printf("%i\n", arr[i]);
// 	// }

// 	char **list;

// 	list = (char**)malloc(sizeof(char*) * 5);

// 	list[0] = strdup("abc"); 
// 	list[1] = strdup("aabc"); 
// 	list[2] = strdup("("); 
// 	list[3] = strdup("aaa"); 
// 	list[4] = NULL;

// 	for(int i = 0; list[i]; i++)
// 		printf("%s\n", list[i]);
// 	// sortArts(list);
// 	printf("\n");
// 	// mergesort(list, 4, sizeof(char), sort("-d"));
// 	// sort(list[1], list[4]);
// 	qsort(list, 4, sizeof(const char*), myCompare); 
// 	for(int i = 0; list[i]; i++)
// 		printf("%s\n", list[i]);

// }



// int		main(void)
// {

// }


int		len_list(struct s_art **arts)
{
	int count;

	count = 0;
	while(arts[count])
		count++;
	printf("LEN = %i\n", count);
	return (count);
}

void  sortArts(struct s_art **arts)
{
	int len  = len_list(arts);
	qsort(arts, len, sizeof(const struct s_art **), myCompare);
	// qsort(arts, len, sizeof(const struct s_art **), myCompare);
}



// void  sortInt(int *arts)
// {
// 	mergesort(arts, 7, sizeof(int), compare);
// }