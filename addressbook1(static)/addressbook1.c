#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000

typedef struct addbook
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}addbook;

typedef struct Contact
{
    addbook data[MAX];
    int sz;
}Contact;

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	(pc->sz) = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//增加联系人
void AddContact(Contact* pc) 
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满、无法添加新的联系人\n");
		return; 
	}

	printf("请输入名字：>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->sz].age)); 
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].sex); 
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->sz].tele); 
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加联系人成功\n");


}

//显示联系人信息
void PrintContact(const Contact* pc)
{
	assert(pc);
	
	int i = 0;
	
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "名字", "年龄", "性别", "电话", "地址");// \t === tab
	
	for (i = 0; i < (pc->sz); i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-50s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}


}


static int Find_By_Name(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)

		{
			return i;
		}
	}
	return -1;
}

//删除联系人信息
void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空、不可以再进行删除操作\n");
		return;
	}

	printf("请输入要删除人员的姓名：>");
	scanf("%s", name);

	int pos = Find_By_Name(pc, name);
	
	if (pos == -1)
	{
		printf("要删除的人员不存在\n");
		return;
	}

	int i = 0;
	for (i = pos; i < (pc->sz - 1); i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	
	pc->sz--;

	printf("删除联系人员成功\n");
}

//查找联系人信息
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };

	printf("请输入要查找人员的姓名：>");
	scanf("%s", name);
	int pos = Find_By_Name(pc, name);
	
	if (pos == -1)
	{
		printf("要查找的人员不存在\n");
		return;
	}
	

	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "名字", "年龄", "性别", "电话", "地址");// \t === tab
	
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-50s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);

}

//修改指定联系人的信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	
	printf("请输入要修改人员的姓名：>");
	scanf("%s", name);
	int pos = Find_By_Name(pc, name);
	
	if (pos == -1)
	{
		printf("要修改的人员不存在\n");
		return;
	}
	else
	{
		printf("请输入修改后人员的名字：>");
		scanf("%s", pc->data[pos].name);
		printf("请输入修改后人员的年龄：>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入修改后人员的性别：>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入修改后人员的地址：>");
		scanf("%s", pc->data[pos].addr);
		printf("请输入修改后人员的电话：>");
		scanf("%s", pc->data[pos].tele);
		printf("修改联系人员信息成功\n");
	}
}


int cmp_Per_by_name(const void* e1, const void* e2)
{
	return strcmp(((addbook*)e1)->name, ((addbook*)e2)->name);
}


void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(addbook), cmp_Per_by_name);
	PrintContact(pc);
}


void ClearContact(Contact* pc)
{
	assert(pc);
	InitContact(pc);
	printf("清空成功\n");
}


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