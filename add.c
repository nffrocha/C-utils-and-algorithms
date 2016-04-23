/* By CoolMaster 
The program crashes on some situations, i think that's a realloc() problem, i tried to figured it out but realloc() always return
not NULL altough the problem exist there:\ If you find the bug please warn me
coolmaster@ptlink.net

This program add two numbers of any kind of lenght, since each digit is stored in a char* the memory is the limit, it uses stacks
implemented with Linked Lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BFALSE 0
#define BTRUE !BFALSE

typedef int boolean;
int numeroElements;

typedef struct _stack {
		char *i;
		struct _stack *next;
} *STACK;

boolean push (STACK *top, char *n) {
	STACK new;
	if ((new = malloc(sizeof(STACK))) == NULL)
		return BFALSE;
	new->i = n;
	new->next = *top;
	*top = new;
	return BTRUE;
}

char *pop (STACK *top) {
	STACK poped;
	char *val;
	
	if (!*top)
		return NULL;
	if ((val = malloc((strlen((*top)->i) + 1) * sizeof(char))) == NULL)
		return NULL;
	strcpy(val, (*top)->i);
	poped = *top;
	*top = (*top)->next;
	free(poped->i);
	free(poped);
	
	return val;
}

char *leNumero() {
	int i, aloc = 5, c;
	char *buf;

	if ((buf = malloc(aloc * sizeof(char))) == NULL)
		return NULL;

	for (i = 0; (c = getchar()) != '\n'; i++) {
		if (i == aloc) {
			aloc += 5;
			if (realloc(buf, (aloc) * sizeof(char)) == NULL) {
				printf("FALHOU\n");
				free(buf);
				return NULL;
			}
		}
		buf[i] = c;
	}
	buf[i] = '\0';

	return buf;
}

char *soma (char *n1, char *n2) {
	char *buf, *ret;
	int len, len1 = strlen(n1), len2 = strlen(n2);
	int trans = 0, s;
	
	len = len1 > len2 ? len1 : len2;
	
	buf = malloc((len + 2) * sizeof(char));
	buf[len + 1] = '\0';
	
	while (len >= 0) {
		len1--;
		len2--;
		s = 0;
		if (len1 >= 0 && len2 >= 0)		
			s = (n1[len1] - '0') + (n2[len2] - '0');
		else if (len1 >= 0)
			s = n1[len1] - '0';
		else if (len2 >= 0)
			s = n2[len2] - '0';
		s += trans;
		trans = s / 10;
		
		buf[len] = s % 10 + '0';
		len--;		
	}
	
	if (*buf == '0') {
		ret = malloc(strlen(buf) * sizeof(char));
		strcpy(ret, buf+1);
		free(buf);
		return ret;
	}
	else
		return buf;		
}

int main () {
	int opc;
	char *numb1, *numb2, *res;
	STACK top = NULL;
	do {
		printf("Numero de elementos: %d\n", numeroElements);
		puts("1. Inserir");
		puts("2. Calcular");
		puts("3. Sair");
		printf("Introduza a opção: ");
		scanf("%d", &opc);
		while (getchar() != '\n')
			;
		switch (opc) {
			case 1: 
				if ((numb1 = leNumero()) == NULL) {
					printf("Impossivel ler numero\n");
					break;
				}
				if (!push(&top, numb1))
					puts("Impossivel inserir novo numero");
				else
					numeroElements++;
				break;
			case 2:
					if (numeroElements > 1) {
						numb1 = pop(&top);
						numb2 = pop(&top);
						res = soma(numb1, numb2);
						if (!res)
							puts("Não foi possivel calcular o resultado");
						else {
							printf("Soma: %s\n", res);
							if (!push(&top, res))
								puts("Impossivel por o calculo na stack");
							else
								numeroElements--;
						}
						if (numb1)
							free(numb1);
						if (numb2)
							free(numb2);
					}
					else if (top)
						printf("Soma: %s\n", top->i);
					else
						printf("Stack vazia\n");
					break;					
			case 3: break;
			default : puts("Opção invalida");
		}
	} while (opc != 3);
	return 0;
}
				
					
		
