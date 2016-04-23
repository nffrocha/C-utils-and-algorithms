/* 
 Mywc -c 1.0 by Nelson Rocha <nffrocha@gmail.com>
 This program is distributed under the terms of GNU General Public License (GNU GPL)

 This is a Binary Tree implementation to count the number of times a word is repeated 
 in a file.
 
 Release date: somewhere in 04/2003
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFLEN 256


typedef int boolean;
#define BFALSE 0
#define BTRUE !BFALSE

static const char *IGNORAPALAVRAS[] = {
	"o",
	"a",
	"à",
	"e",
	"é",
	"de",
	"da",
	"dá",
	"do",
	"das",
	"dos",
	NULL
};

typedef struct node {
	char *s;
	int n;
	struct node *left;
	struct node *right;
} TREE;

boolean isIgnoredWord (char *s) {
	int i;

	for (i = 0; IGNORAPALAVRAS[i] && strcmp(IGNORAPALAVRAS[i], s); i++)
		;
		
	return IGNORAPALAVRAS[i] == NULL ? BFALSE : BTRUE;
}

int readLine(char *s, size_t len, FILE *fp) {
        char c;
        int i;
     
	for (i = 0, len /= sizeof(char); (c = getc(fp)) != '\n' && i < len && c != EOF; i++)
		if (!ispunct(c))
	               *(s++) = tolower(c);
        *s = '\0';
	
        return i;
}

TREE *addnode (TREE *node, char *s) {
	int retcmp;
	
	if (!node) {
		if ((node = malloc(sizeof(TREE))) == NULL)
			return NULL;
		node->s = strdup(s);
		node->left = node->right = NULL;
		node->n = 1;
	}
	else {
		retcmp = strcmp(node->s, s);
		if (retcmp > 0) 
			node->left = addnode(node->left, s);
		else if (retcmp < 0)
			node->right = addnode(node->right, s);
		else
			node->n++;
	}
	return node;
}

void inOrderLs (TREE *root) {
	if (!root)
		return;

	if (root->left)
		inOrderLs(root->left);

	printf("%s %d\n", root->s, root->n);

	if (root->right)
		inOrderLs(root->right);
}
	
int main (int argc, char *argv[]) {
	FILE *fx;
	char buf[BUFLEN], *tok, *pbuf;
	TREE *root = NULL;

	if (argc < 2) {
		puts("Invalid syntax: command <file>");
		return 1;
	}
	if ((fx = fopen(argv[1], "r")) == NULL)
		puts("Unable to open file");

	while (!feof(fx)) {
		readLine(buf, sizeof(buf), fx);
		pbuf = buf;
		tok = strtok(pbuf, " ");
		while (tok) {
			if (!isIgnoredWord(tok))
				root = addnode(root, tok);
			tok = strtok(NULL, " ");
		}
		
	}
	fclose(fx);
	inOrderLs(root);
	
	return 0;
}
