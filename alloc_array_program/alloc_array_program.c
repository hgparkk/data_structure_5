/*
프로그램 내용 : 동적 배열 생성 프로그램
실습일 : 2023.04.21
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int choice = 0;
	int* array = NULL;
	while (choice != -1)
	{
		printf("\n");
		printf("==============================\n");
		printf("1. 크기가 n인 동적 배열을 생성\n");
		printf("2. 배열을 난수로 채운다.\n");
		printf("3. 배열의 각 원소를 출력한다.\n");
		printf("4. 배열의 각 원소를의 합을 출력한다.\n");
		printf("5. 동적 할당 공간을 반납한다.\n");
		printf("==============================\n");
		printf("메뉴를 선택하시오:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			printf("\n");
			printf("n 입력 :");
			scanf("%d", &n);
			array = (int*)malloc(sizeof(int) * n);
			break;
		}
		case 2:
		{
			printf("\n");
			if (array == NULL)
			{
				printf("배열이 생성되지 않았습니다.\n");
			}
			else
			{
				long seed = time(NULL);
				srand(seed);
				for (int i = 0; i < n; i++)
				{
					int x = rand();
					array[i] = x;
				}
			}
			break;
		}
		case 3:
		{
			printf("\n");
			if (array == NULL)
			{
				printf("배열이 생성되지 않았습니다.\n");
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					printf("%d ", array[i]);
				}
				printf("\n");
			}
			break;
		}
		case 4:
		{
			printf("\n");
			if (array == NULL)
			{
				printf("배열이 생성되지 않았습니다.\n");
			}
			else
			{
				int sum = 0;
				for (int i = 0; i < n; i++)
				{
					sum += array[i];
				}
				printf("%d\n", sum);
			}
			break;
		}
		case 5:
		{
			printf("\n");
			if (array == NULL)
			{
				printf("배열이 생성되지 않았습니다.\n");
			}
			else
			{
				printf("%p\n", array);
			}
			break;
		}
		default:
		{
			if (choice == -1)
			{
			}
			else
			{
				printf("올바르지 않은 입력입니다.\n");
			}
		}
		}
	}
	printf("프로그램을 종료합니다.");
}