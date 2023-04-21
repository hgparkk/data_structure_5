/*
프로그램 내용 : 연결된큐 프로그램 예제
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

void print_queue(char msg[])
{
	Node* p;
	printf("%s[%2d]= ", msg, size());
	for (p = front; p != NULL; p = p->link)
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
	init_queue();
	enqueue(get_student(2018130007, "홍길동", "컴퓨터공학과"));
	enqueue(get_student(2018130100, "이순신", "기계공학과"));
	enqueue(get_student(2018130135, "김연아", "체육과"));
	enqueue(get_student(2018130135, "황희", "법학과"));
	print_queue("연결된 학생큐(4명 삽입)");
	dequeue();
	print_queue("연결된 학생큐(1명 삭제");
	destroy_queue();
}
