/*
프로그램 내용 : 포인터를 이용한 연결된큐 프로그램 예제
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct Student
{
	int id;
	char name[32];
	char dept[32];
}Student;
typedef Student Element;
typedef struct LinkedNode
{
	Element data;
	struct LinkedNode* link;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
}Queue;

void error(char* str)
{
	printf("%s\n", str);
	exit(1);
}

int is_empty(Queue* q)
{
	return q->front == NULL;
}

void init_queue(Queue* q)
{
	q->front = q->rear = NULL;
}

int size(Queue* q)
{
	Node* p;
	int count = 0;
	for (p = q->front; p != NULL; p = p->link) count++;
	return count;
}

void enqueue(Queue* q, Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty(q)) q->front = q->rear = p;
	else {
		q->rear->link = p;
		q->rear = p;
	}
}

Element dequeue(Queue* q)
{
	Node* p;
	Element e;

	if (is_empty(q))
		error(" 큐 공백 에러");

	p = q->front;
	q->front = q->front->link;
	if (q->front == NULL)q->rear = NULL;
	e = p->data;
	free(p);
	return e;
}

Element peek(Queue* q)
{
	if (is_empty(q))
		error(" 큐 공백 에러");
	return q->front->data;
}

void destroy_queue(Queue* q)
{
	while (is_empty(q) == 0)
		dequeue(q);
}

void print_queue(Queue* q, char msg[])
{
	Node* p;
	printf("%s[%2d]= ", msg, size(q));
	for (p = q->front; p != NULL; p = p->link)
		printf("\n\t%-15d %-10s %-20s", p->data.id, p->data.name, p->data.dept);
	printf("\n");
}

Student get_student(int id, char* name, char* dept)
{
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);
	return s;
}

void main()
{
	Queue q;
	init_queue(&q);
	enqueue(&q,get_student(2018130007, "홍길동", "컴퓨터공학과"));
	enqueue(&q, get_student(2018130100, "이순신", "기계공학과"));
	enqueue(&q, get_student(2018130135, "김연아", "체육과"));
	enqueue(&q, get_student(2018130135, "황희", "법학과"));
	print_queue(&q, "연결된 학생큐(4명 삽입)");
	dequeue(&q);
	print_queue(&q, "연결된 학생큐(1명 삭제");
	destroy_queue(&q);
}