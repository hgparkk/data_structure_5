/*
프로그램 내용 : 변수의 주소 출력
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>

void print_address(int* px)
{
	printf("%d\n", *px);
	printf("%p\n", px);
}

int main()
{
	int x = 10;
	printf("%d\n", x);
	printf("%p\n", &x);
	print_address(&x);
}
