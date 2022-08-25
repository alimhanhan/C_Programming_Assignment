#include <stdio.h>
#include <stdlib.h>

int main(void) 

{
	int x; 
	
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &x); 
	
	printf("백의 자리수 : %d\n", x / 100); 
	
	printf("십의 자리수 : %d\n", x % 100 / 10); 
	
	printf("일의 자리수 : %d\n", x % 10); return 0; 

}