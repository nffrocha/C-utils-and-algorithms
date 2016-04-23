/* Stack demonstration by Nelson Rocha <nffrocha@gmail.com>
   Version: 1.0 - 15/11/2003 
   
   The objective of this program is to demonstrate stacks and how to use them.
   Since polish inverted notation is by nature a good thing to implement in stacks it is implemented
   here for stack demonstration purpose. 
   Note that this isn't a good implementation of polish inverted notation, i don't even know the rules, sorry
   about that.
   
   This program is distributed under the terms of GNU GPL
*/

#include <stdio.h>
#include <ctype.h>


/* Implementation of Stack */

/* Stack elements */
#define STACKSIZE 20

int stack[STACKSIZE];
int stackElements = 0;


/* Push one element into the stack */
int push (int n) {
	if (stackElements < STACKSIZE)
		stack[stackElements++] = n;
	else
		return 0;
	return 1;
}

/* Pop the last element from stack and return it */
int *pop () {
	if (!stackElements)
		return NULL;
	return &stack[--stackElements];
}

/* Print the stack */
void printStack () {
	int i;
	for (i = 0; i < stackElements; i++)
		printf("%d\n", stack[i]);
}

/* Polish inverted notation implementation 
Examples:
1 + 2 | 1 2 +
1 + 2 * 3 | 1 2 3 * +
1 * (2 + 3) | 1 2 3 + *

*/

int getToken (int *ret) {
	int c;

	while ((c = getchar()) == ' ')
		;

	if (!isdigit(c))
		return c;
	
	*ret = c - '0';
	while (isdigit( (c = getchar()) ))
		*ret = *ret * 10 + c - '0';

	return 0;
}

/* It's not a good and generic function but it will work for demonstration 
In this implementation an expression like: 1 2 3 + will be evaluated to 1
because 1 and 5 will be on stack, no more operations will be done and since
program print stack[0] 1 will be printed, i don't now what really happen on a real polish inverted
notation expression.
And you need to give spaces to all expression parameters.
Only for positive numbers.
Note that operators will not be pushed to stack.
*/
int operation () {
	int token, ret, *first, *sec;
	while ((ret = getToken(&token)) != '\n') {
		if (!ret) {
			if (!push(token)) {
				puts("Stack overflow");
				return 0;
			}
		}
		else if (ret == '+' || ret == '-' || ret == '*' || ret == '/') {
			sec = pop(); /* pop the last element */
			first = pop(); /* pop the last-1 element */
			if (!first || !sec) {
				puts("Need more operands");
				return 0;
			}
			switch (ret) {
				case '+' :
					push(*first + *sec); /* add last with last-1 element and 
								push it into stack 
								note that *first and *sec in this section
								aren't part of stack anymore.
								*/
					break;
				case '-' :
					push(*first - *sec);
					break;
				case '*' :
					push(*first * *sec); 
					break;
				case '/' :
					if (!*sec) {
						puts("Can't divide by 0");
						return 0;
					}
					else
						push(*first / *sec);
					break;
			}
		}
		else {
			printf("Invalid character\n");
			return 0;
		}
	}
	return 1;	
}


int main () {
	if (operation())
		printf("Result: %d\n", stack[0]);
	printf("\nStack data:\n");
	printStack();
	return 0;
}


