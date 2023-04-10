#include"contact.h"

menu()
{
	printf("********************************************\n");
	printf("*********   1.add       2.del      *********\n");
	printf("*********   3.search    4.modify   *********\n");
	printf("*********   5.sort      6.print    *********\n");
	printf("*********   7.clear     0.exit     *********\n");
	printf("********************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
	CLEAR
};


int main()
{

	int input = 0;

	//创建通讯录
	Contact Con;
	//初始化通讯录
	InitContact(&Con);

	do
	{
		menu();
		printf("请输入你的选项：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&Con);
			break;
		case DEL:
			DelContact(&Con);
			break;
		case SEARCH:
			SearchContact(&Con);
			break;
		case MODIFY:
			ModifyContact(&Con);
			break;
		case SORT:
			SortContact(&Con);
			break;
		case PRINT:
			PrintContact(&Con);
			break;
		case CLEAR:
			ClearContact(&Con);
			break;
		case EXIT:
			DestroyContact(&Con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}
