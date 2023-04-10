#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
    printf("********************************\n");
    printf("*****  1.add     2.del     *****\n");
    printf("*****  3.search  4.modify  *****\n");
    printf("*****  5.sort    6.print   *****\n");
    printf("*****  7.clear   8.exit    *****\n");
    printf("********************************\n");

}

enum Option
{
    EXIT,ADD,DEL,SEARCH,MODIFY,SORT,PRINT,CLEAR
};

int main()
{
    int input = 0;
    Contact addressbook;

    InitContact(&addressbook);

    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:
                AddContact(&addressbook);
                break;
            case DEL:
                DelContact(&addressbook);
                break;
            case SEARCH:
                SearchContact(&addressbook);
                break;
            case MODIFY:
                ModifyContact(&addressbook);
                break;
            case SORT:
                SortContact(&addressbook);
                break;
            case PRINT:
                PrintContact(&addressbook);
            case CLEAR:
                ClearContact(&addressbook);
            case EXIT:
                printf("退出通讯录\n");
                break;
            default:
                printf("选择错误，请重新选择：>");
                break;
        }


    } while (input);

    return 0;
    


}