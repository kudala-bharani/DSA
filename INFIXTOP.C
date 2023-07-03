#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 40
char stack [STACK_MAX_SIZE];

int top = -1;


int isEmpty() {
	if(top == -1)
	return 1;
	return 0;
}

void push(char x) {
	stack[++top] = x;
}


char pop() {
	if(isEmpty())
	return -1;
	else
	return stack[top--];
}


int priority(char x) {
	if(x == '(')
	return 0;
	else if(x == '+' || x == '-')
	return 1;
	else if(x == '*' || x == '/' || x == '%')
	return 2;
	else 
	return -1;
}

void convertInfix(char * e) {
	char x,postex[100];
	int j = 0;
	while(*e != '\0')
	{
		if(isalpha(*e))
		postex[j++] = *e;
		else if(*e == '(')
		push(*e);
		else if(*e == ')')
		{
			while((x = pop()) != '(')
			postex[j++] = x;
		}
		else
		{
			if(priority(*e) == -1)
			{
				printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed.\n");
				return;
			}
			while(priority(stack[top]) > priority(*e))
			postex[j++] = pop();
			push(*e);
		}
		e++;
	}
	while(!isEmpty())
	{
		char x;
		x = pop();
		if(x == '(')
		{
			printf("Invalid infix expression : unbalanced parenthesis.\n");
			return;
		}
		postex[j++] = x;
	}
	printf("Postfix expression : %s\n",postex);
}

void main() 
{
	char exp[200];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e = exp;
	convertInfix(e);
	getch();
}