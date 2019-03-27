/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:41:33 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/26 19:41:35 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

#define HASH 128 

size_t hash(char *input) //return hash result
{
	size_t	index = 0;

	while(*input)
	{
		index = index * HASH + (unsigned char)(*input);
		input++;
	}
	printf("%i\n", index);
	return (index);
}

struct s_dict *dictInit(int capacity) //initialize the dictionnary, given as parameter the capacity of the array.
{
	struct s_dict *dict = NULL;
	if (!(dict = (struct s_dict*)malloc(sizeof(struct s_dict))))
		return NULL;
	if (!(dict->items = (struct s_item **)malloc(sizeof(struct s_item*) * capacity + 1)))
		return NULL;
	for(int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	dict->capacity = capacity;
	return dict;
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) //add one element in the dictionnary, if FAIL return 0, otherwise 1
{
	
	if(dict && key && value)
	{
		if (dict->items)
		{
			size_t i = hash(key) % dict->capacity;
			if (!dict->items[i])
			{
				if (!(dict->items[i] = (struct s_item*)malloc(sizeof(struct s_item))))
					return (0);
				(dict->items[i])->key = strdup(key);
				(dict->items[i])->value = value;
				(dict->items[i])->next = NULL;
			}
			else
			{
				struct s_item *tmp;
				tmp = dict->items[i];
				while(tmp->next)
					tmp = tmp->next;
				if (!(tmp->next = (struct s_item*)malloc(sizeof(struct s_item))))
					return (0);
				tmp = tmp->next;
				tmp->key = strdup(key);
				tmp->value = value;
				tmp->next = NULL;

				dict->items[i] = value;
			}

		}
		else
			return (0);
		return (1);
	}
	else
		return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) //find one element in the dictionnary, if not found, return NULL
{
	if (dict && key)
	{
		if (dict->items)
		{
			size_t	index = hash(key) % dict->capacity;
			if(dict->items[index])
			{
				struct s_item *tmp = dict->items[index];
				while(tmp)
				{
					if (strcmp(tmp->key, key) == 0)
						return tmp->value;
					tmp = tmp->next;
				}
			}
			else
				return NULL;
		}
	}	
	

}

int searchPrice(struct s_dict *dict, char *name)
{
	return (dictSearch(dict, key)->price);
}