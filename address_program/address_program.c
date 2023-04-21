/*
프로그램 내용 : 연락처 저장 프로그램
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address
{
	char name[80];
	char num[160];
}Address;

int main()
{
	int size;
	char name[80];
	char num[160];
	printf("주소의 개수: ");
	scanf(" %d", &size);
	Address* add_array = (Address*)malloc(sizeof(Address) * size);
	for (int i = 0; i < size; i++)
	{
		printf("이름을 입력하시오: ");
		scanf("%s", name);
		strcpy(add_array[i].name, name);
		printf("휴대폰 번호를 입력하시오: ");
		scanf("%s", num);
		strcpy(add_array[i].num, num);
	}
	for (int i = 0; i < size; i++)
	{
		printf("====================\n");
		printf("이름     휴대폰 번호\n");
		printf("====================\n");
		printf("%s   %s\n", add_array[i].name, add_array[i].num);
	}
	printf("====================\n");
}

