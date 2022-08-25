// 사용자로부터 입력받은 정수 3개의 평균값을 화면에 출력하라
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int z;
	int average;

	printf("첫 번째 숫자를 입력하시오:");
	scanf("%d", &x);

	printf("두 번째 숫자를 입력하시오:");
	scanf("%d", &y);

	printf("세 번째 숫자를 입력하시오:");
	scanf("%d", &z);

	average = (x + y + z)/3 ;
	printf("세 수의 평균= %d \n", average);

	return 0;
}