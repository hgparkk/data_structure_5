/*
프로그램 내용 : 연결된 큐의 값 출력
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct LinkedNode
{
	Element data;
	struct LinkedNode* link;
} Node;
Node* front = NULL;
Node* rear = NULL;

void error(char* str)
{
	printf("%s\n", str);
	exit(1);
}

int is_empty()
{
	return front == NULL;
}

void init_queue()
{
	front = rear = NULL;
}

int size()
{
	Node* p;
	int count = 0;
	for (p = front; p != NULL; p = p->link) count++;
	return count;
}

void enqueue(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty()) front = rear = p;
	else {
		rear->link = p;
		rear = p;
	}
}

Element dequeue()
{
	Node* p;
	Element e;

	if (is_empty())
		error(" 큐 공백 에러");

	p = front;
	front = front->link;
	if (front == NULL)rear = NULL;
	e = p->data;
	free(p);
	return e;
}

Element peek()
{
	if (is_empty())
		error(" 큐 공백 에러");
	return front->data;
}

void destroy_queue()
{
	while (is_empty() == 0)
		dequeue();
}

void print_queue(char* msg)
{
	Node* p;
	for (p = front; p != NULL; p = p->link)
	{
		if (p->data == 0)
			printf("NULL");
		else
			printf("%2d->", p->data);
	}
	printf("\n");
}

void main()
{
	int i;

	init_queue();
	int input = 0;
	while (input != -1) 
	{
		printf("양의 정수를 입력하세요(종료: -1): ");
		scanf("%d", &input);
		if (input == -1)
			enqueue(NULL);
		else
			enqueue(input);
	}
	print_queue("");
}