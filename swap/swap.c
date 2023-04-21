/*
프로그램 내용 : 두 값 바꾸기
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>

void swap(int* p1, int* p2)
{
	int tmp1 = *p1;
	int tmp2 = *p2;
	*p1 = tmp2;
	*p2 = tmp1;
}

int main()
{
	int x = 10;
	int y = 20;
	swap(&x, &y);
	printf("x=%d, y=%d\n", x, y);
}
