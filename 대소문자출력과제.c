#include <stdio.h>

int main()
{
    char c;

    printf("문자를 입력하시오:");

    for (int i = 0; i < 5; i++) {
        scanf_s(" %c", &c, 1);

        if (c >= 'a' && c <= 'z')
            printf("소문자입니다\n");
        else if (c >= 'A' && c <= 'Z')
            printf("대문자입니다.\n");
        else
            printf("영문자가 아닙니다\n");
    }

    return  0;
}