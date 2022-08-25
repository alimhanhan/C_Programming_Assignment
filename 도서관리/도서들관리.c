#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BOOK 
{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};

typedef struct BOOK BOOK;
int register_book(BOOK* book_list, int* nth);
int search_book(BOOK* book_list, int total_num_book);
int print_book_list(BOOK* book_list, int total_num_book);
int retrieve_book_info(BOOK** book_list, int* total_num_book);
char compare(char* str1, char* str2);

int main() 
{
    int user_choice;        
    int num_total_book = 0;

    BOOK* book_list;
    int i;

    printf("도서관의 최대 보관가능 책 수는? : ");
    scanf("%d", &user_choice);

    book_list = (BOOK*)malloc(sizeof(BOOK) * user_choice);

    while (1) {
        printf("=======================================================\n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책 검색 \n");
        printf("2. 책 추가 \n");
        printf("3. 책들의 내용을 book_list.txt 에 출력 \n");
        printf("4. 책들의 내용을 book_list.txt 에서 불러옴 \n");
        printf("5. 책들의 목록을 출력 \n");
        printf("6. 도서관 나가기 \n");
        printf("=======================================================\n");

        printf("작업을 고르시오 : ");
        scanf("%d", &user_choice);

        if (user_choice == 1) 
        {
            search_book(book_list, num_total_book);
        }
        else if (user_choice == 2) 
        {
           register_book(book_list, &num_total_book);
        }
        else if (user_choice == 3) 
        {
            print_book_list(book_list, num_total_book);
        }
        else if (user_choice == 4) 
        {
          retrieve_book_info(&book_list, &num_total_book);
        }
        else if (user_choice == 5) 
        {
            for (i = 0; i < num_total_book; i++) {
                printf("%s // %s // %s // ", book_list[i].book_name,
                    book_list[i].auth_name, book_list[i].publ_name);
                if (book_list[i].borrowed == 0)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
        else if (user_choice == 6)
        {
            break;
        }
    }

    free(book_list);
    return 0;
}
int print_book_list(BOOK* book_list, int total_num_book) {
    FILE* fp = fopen("book_list.txt", "w");
    int i;

    if (fp == NULL) {
        printf("출력 오류 ! \n");
        return -1;
    }

    fprintf(fp, "%d\n", total_num_book);

    for (i = 0; i < total_num_book; i++) {
        fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name,
            book_list[i].publ_name);
        if (book_list[i].borrowed == 0)
            fprintf(fp, "NO\n");
        else
            fprintf(fp, "YES\n");
    }

    printf("출력 완료! \n");
    fclose(fp);

    return 0;
}
char compare(char* str1, char* str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;

    return 0;
}

int retrieve_book_info(BOOK** book_list, int* total_num_book) {
    FILE* fp = fopen("book_list.txt", "r");
    int total_book;
    int i;
    char str[10];

    if (fp == NULL) {
        printf("지정한 파일을 찾을 수 없습니다! \n");
        return -1;
    }
    fscanf(fp, "%d", &total_book);
    (*total_num_book) = total_book;

    free(*book_list);
    (*book_list) = (BOOK*)malloc(sizeof(BOOK) * total_book);

    if (*book_list == NULL) {
        printf("\n ERROR \n");
        return -1;
    }
    for (i = 0; i < total_book; i++) 
    {
        fscanf(fp, "%s", (*book_list)[i].book_name);
        fscanf(fp, "%s", (*book_list)[i].auth_name);
        fscanf(fp, "%s", (*book_list)[i].publ_name);
        fscanf(fp, "%s", str);

        if (compare(str, "YES")) {
            (*book_list)[i].borrowed = 1;
        }
        else if (compare(str, "NO")) {
            (*book_list)[i].borrowed = 0;
        }
    }

    fclose(fp);
    return 0;
}

int register_book(BOOK* book_list, int* nth) {
    printf("책 이름 : ");
    scanf("%s", book_list[*nth].book_name);

    printf("책 저자 : ");
    scanf("%s", book_list[*nth].auth_name);

    printf("책 출판사 : ");
    scanf("%s", book_list[*nth].publ_name);

    book_list[*nth].borrowed = 0;
    (*nth)++;

    return 0;
}

int search_book(BOOK* book_list, int total_num_book) {
    int user_input;
    int i;
    char user_search[30];

    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 제목 \n");
    printf("2. 저자 \n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);

    printf("검색 결과 \n");

    if (user_input == 1) 
    {
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].book_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }

    }
    else if (user_input == 2) 
    {
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].auth_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }

    }

    return 0;
}