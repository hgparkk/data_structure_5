/*
프로그램 내용 : 배열의 모든 요소 주소 출력
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>

void print_array(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", a[i]);
		printf("%p \n", &a[i]);
	}
}

int main()
{
	int a[10] = { 10, 30, 50, 40, 22, 23, 15, 18, 14, 60 };
	int len_a = sizeof(a) / sizeof(int);
	print_array(a, len_a);
}
