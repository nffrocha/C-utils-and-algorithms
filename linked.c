/* Linked lists implementation by Nelson Rocha <nffrocha@gmail.com>
   Purpose: educational issues 
   Release date: 09/11/2003 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
	char *nome;
	int idade;
	struct record *next; /* the pointer that will point to next struct */
} *Dados;

/* Function to insert an element to the top (head) of the list */
int inserirTop (char *nome, int idade, Dados *rec) {
	Dados head = *rec;
	
	*rec = (Dados) malloc(sizeof(Dados));
	if (*rec == NULL)
		return 0;
	
	(*rec)->nome = nome;
	(*rec)->idade = idade;
	
	(*rec)->next = head;
	
	return 1;
}

/* Function to insert an element to the tail (end) of the list 
   In this function i loop through all elements and get a reference to the last element, it's possible
   to do this in other way, just maintain always a reference to the end of list   
*/
int inserirFim (char *nome, int idade, Dados *rec) {
	Dados prev, new, cur = *rec;
	
	while (cur) {
		prev = cur;
		cur = cur->next;
	}
	
	cur = prev;
	
	new = (Dados) malloc(sizeof(Dados));
	if (new == NULL)
		return 0;
		
	new->nome = nome;
	new->idade = idade;
	
	new->next = NULL;
	cur->next = new;
	
	return 1;
}

/* Insert to the list order by idade */
int inserirOrdem (char *nome, int idade, Dados *rec) {
	Dados prev, new, cur;
	
	if (*rec == NULL) /* first element */
		return inserirTop(nome, idade, rec);

	cur = *rec;
	prev = NULL;
	
	while (cur) {
		if (cur->idade > idade) {
			new = (Dados) malloc(sizeof(Dados));
			if (new == NULL)
				return 0;
				
			new->nome = nome;
			new->idade = idade;
			
			new->next = cur;
			if (prev)
				prev->next = new;
			else
				*rec = new;
			
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	
	return inserirFim(nome, idade, rec); /* last element */
}

/* Delete all elements from list */
void freeRecord (Dados *rec) {
	Dados next, cur = *rec;
	
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	
	*rec = NULL;
}

/* This is a bit diferent from normal pop implementation, in normal pop the last element will be popped
here it's the first element popped and returned */
Dados pop (Dados *rec) {
	Dados poped, next;
	
	next = (*rec)->next;
	
	poped = (Dados) malloc(sizeof(Dados));
	if (poped == NULL)
		return NULL;
	
	poped->nome = (*rec)->nome;
	poped->idade = (*rec)->idade;
	
	free(*rec);
	*rec = next;
	
	return poped;
}

/* Delete an element from list, the first argument is the name to search and erase */
int apagar (char *nome, Dados *rec) {
	Dados cur, prev;
	
	cur = prev = *rec;
	
	while (cur) {
		if (!strcmp(cur->nome, nome)) {
			if (*rec == cur) {
				cur = cur->next;
				free(*rec);
				*rec = cur;
			}
			else {
				prev->next = cur->next;
				free(cur);
			}
			return 1;
				
		}
		prev = cur;
		cur = cur->next;
	}
	
	return 0;
}

int main () {
	Dados cur = NULL;
	inserirOrdem("Nelson", 62, &cur);
	inserirOrdem("Katatonia", 16, &cur);
	inserirOrdem("Eternal", 52, &cur);
	inserirOrdem("Tragedy", 50, &cur);
	pop(&cur);
	/* List all elements */
	while (cur) {
		printf ("%s %d\n", cur->nome, cur->idade);
		printf ("-------\n");
		cur = cur->next;
	}
	return 0;
}

/* note that arguments that pass the struct need to pass by reference (&) */
