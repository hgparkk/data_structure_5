/*
프로그램 내용 : 연결된 스택을 이용한 회문 찾기
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Element;

typedef struct LinkedNode
{
	Element data;
	struct LinkedNode* link;
} Node;

Node* top = NULL;

void error(char str[])
{
	printf(stderr, "%s\n", str);
	exit(1);
}

int is_empty()
{
	return top == NULL;
}

void init_stack()
{
	top = NULL;
}

int size()
{
	Node* p;
	int count = 0;
	for (p = top; p != NULL; p = p->link) count++;
	return count;
}

void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;

	p->link = top;
	top = p;
}

Element pop()
{
	Node* p;
	Element e;
	if (is_empty())
		error("스택 공백 에러");
	p = top;
	top = p->link;
	e = p->data;
	free(p);
	return e;
}

Element peek()
{
	if (is_empty())
		error("스택 공백 에러");
	return top->data;
}

void destroy_stack()
{
	while (is_empty() == 0)
		pop();
}

void print_stack(char* msg)
{
	Node* p;
	printf("%s[%2d]=", msg, size());
	for (p = top; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

void check_palindrome(char expr[])
{
	char c;
	char renew[80];
	char reverse[80];
	int i = 0;
	int j = 0;
	init_stack();
	while (expr[i] != '\0')
	{
		c = expr[i++];
		if ((c >= 'A') && (c <= 'Z'))
		{
			c = c - 'A' + 'a';
			renew[j++] = c;
			push(c);
		}
		else if (c == '.' || c == ',' || c == '!' || c == '?' || c == ' ' || c == '\'')
		{

		}
		else
		{
			renew[j++] = c;
			push(c);
		}
	}
	renew[j] = '\0';
	i = 0;
	while (is_empty() == 0)
		reverse[i++] = pop();
	reverse[i] = '\0';
	if (strcmp(renew, reverse) == 0)
		printf("이 문자열은 회문입니다.");
	else
		printf("이 문자열은 회문이 아닙니다.");
}

int main(void)
{
	char expr[80];
	printf("문자열을 입력하세요 >>");
	scanf("%[^\n]", &expr);
	check_palindrome(expr);
}