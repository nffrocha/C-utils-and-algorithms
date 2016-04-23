#include <stdio.h>
#include <string.h>

#define STACK_SIZE 20

#define Boolean int
#define BFALSE 0
#define BTRUE !BFALSE

#define OPENBRACKETS "([{"
#define CLOSEBRACKETS ")]}"

int stack[STACK_SIZE];
int stackElements = 0;

/* Return 1 if stack is full or 0 if isn't */
Boolean stackOverflow (void) {
	return stackElements >= STACK_SIZE;
}

/* Return 0 if isn't empty, or 1 if it is */
Boolean stackEmpty (void) {
	return !stackElements;
}

/* Push one element into the stack, overflow need to be check before this function call */
void push (int n) {
	stack[stackElements++] = n;
}

/* 
	Pop an element from stack, return the element. if stack is empty need to be checked before this
	function call
*/
int pop (void) {
	return stack[--stackElements];
}

/* Return true if c is an open bracket */
Boolean isOpenBracket (int c) {
	return strchr(OPENBRACKETS, c) != NULL;
}

/* Return true if c is an close bracket */
Boolean isCloseBracket (int c) {
	return strchr(CLOSEBRACKETS, c) != NULL;
}

/* Return the open bracket of a given bracket */
int openBracket (int c) {
	int ret = 0;
	switch (c) {
		case ')' : ret = '('; break;
		case '}' : ret = '{'; break;
		case ']' : ret = '['; break;
	}
	return ret;
}

int main () {
	int c, pos = 1;
	Boolean erro = BFALSE;
	
	while ((c = getchar()) != '\n' && !erro) {
		if (isOpenBracket(c)) {
			if (stackOverflow()) {
				puts("Erro: Pilha cheia");
				erro = BTRUE;
			}
			else
				push(c);
		}
		else if (isCloseBracket(c)) {
			if (stackEmpty()) {
				printf("Erro: Tentar fechar parentises que não foram abertos, posição %d\n", pos);
				erro = BTRUE;
			}
			else {
				if (pop() != openBracket(c)) {
					printf("Sequencia incorrecta!! Erro na posição %d\n", pos);
					erro = BTRUE;
				}
			}
		}
		else if (c != ' ') {
			printf("Erro: Caracter invalido na posição %d\n", pos);
			erro = BTRUE;
		}
		pos++;			
	}
	if (!stackEmpty() && !erro)
		puts("Sequencia incorrecta, pilha não vazia");
	else if (!erro)
		puts("Sequencia correcta");
	return 0;
}
