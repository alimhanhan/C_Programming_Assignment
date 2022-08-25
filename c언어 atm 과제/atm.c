# define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>

char name;
int save(int amount);
int draw(int amount);
int my_money = 0;
int balance;
int main(void)
{
    int menu, money;
    while (1)
    {
        printf("메뉴를 선택하세요: (1)입금, (2)인출, (3)종료 (4)잔고 확인: ");
        scanf("%d", &menu);

        if (menu == 1)
        {
            printf("저축할 금액: ");
            scanf("%d", &money);
            printf("현재 잔액은 %d입니다.\n", save(money));
        }
        else if (menu == 2)
        {
            printf("출금할 금액: ");
            scanf("%d", &money);
            printf("현재 잔액은 %d입니다.\n", draw(money));
        }
        else if (menu == 4)
        {
            printf("성함을 입력해주세요: ");
            scanf("%s", &name);
            printf("%s님의 통장 잔액은 %f원입니다.\n", &name, &balance);
        }
        else if (menu == 3)
            break;
        else continue;
    }
    return 0;

}
int save(int amount)
{
    my_money += amount;
    return my_money;
}
int draw(int amount)
{
    my_money -= amount;
    return my_money;
}