#include <string.h>
#include <stdio.h>

#define MAX 100

typedef struct {
	char item[MAX][20];
	int top;
}Stack;

void ini(Stack *p) {
	p->top = -1;
}

int isEmpty(Stack *p) {
	if(p->top == -1) 
		return 1;
	else
		return 0;
}

int isFull(Stack *p) {
	if(p->top == MAX-1)
		return 1;
	else
		return 0;
}

void push(Stack *p, char m[]) {
	if(isFull(p)==1) {
		printf("Não tem mais espaço para cadastrar outras matérias");
	} else {
		p->top++;
		strcpy(p->item[p->top], m);
	}
}

void pop(Stack *p) {
	char aux[20];
	if(isEmpty(p)==1) {
		printf("Erro! pilha de matérias vazia");
	} else {
		strcpy(aux, p->item[p->top]);
		p->top--;
		
	}
}

void show(Stack *p) {
	int i=0;
	if(isEmpty(p)==1) {
		printf("Erro! pilha de matérias vazia");
	} else {
		while(i <= p->top) {
			printf("%d. %s\n", i+1, p->item[i]);
			i++;
		}
	}
}



