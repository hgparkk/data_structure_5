/*
프로그램 내용 : 입력하는 정수로 동적 메모리 저장
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	printf("정수의 개수: ");
	scanf(" %d", &size);
	int* array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		printf("정수 #%d: ", i + 1);
		scanf(" %d", &array[i]);
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

