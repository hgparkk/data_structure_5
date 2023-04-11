/*
프로그램 내용 : 동적 메모리 할당 예제
실습일 : 2023.04.11
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char name[20];
	char dept[32];
}Student;

void test1(Student s);
void test2(Student* s);
Student test3(Student s);

int main(void)
{
	Student s1;
	Student* ps;

	s1.id = 10;
	strcpy(s1.name, "Park");
	strcpy(s1.dept, "Computer Eng.");
	ps = (Student*)malloc(sizeof(Student));
	*ps = s1;
	printf("ps->id:%d,ps->name:%s,ps->dept:%s\n", ps->id, ps->name, ps->dept);
	test1(*ps);
	printf("ps->id:%d,ps->name:%s,ps->dept:%s\n", ps->id, ps->name, ps->dept);
	test2(ps);
	printf("ps->id:%d,ps->name:%s,ps->dept:%s\n", ps->id, ps->name, ps->dept);
	*ps = test3(*ps);
	printf("ps->id:%d,ps->name:%s,ps->dept:%s\n", ps->id, ps->name, ps->dept);
	free(ps);
	return 0;
}

void test1(Student s) {
	s.id = 20;
}

void test2(Student* s) {
	s->id = 20;
}

Student test3(Student s) {
	s.id = 30;
	return s;
}