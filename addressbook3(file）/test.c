#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//定义结构体类型
#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 12
#define ADDR_MAX 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INCREASE_SZ 2

//创建通讯录
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//动态版本
typedef struct Contact
{
	PeoInfo* data;//存放人的信息，维护通讯录的指针
	int sz;//记录通讯录中实际联系人的个数
	int capacity;//当前通讯录的容量
}Contact;


#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (NULL == pc->data)
	{
		printf("InitContact: :%s\n", strerror(errno));
		return;
	}
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);
}

void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pfRead = fopen("Contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };

	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);

		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(Contact* pc)
{
	if (pc->capacity == pc->sz)
	{
		PeoInfo* prt = (PeoInfo*)realloc(pc->data, (pc->capacity + INCREASE_SZ) * sizeof(PeoInfo));
		if (NULL == prt)
		{
			printf("AddContact: :%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = prt;
			pc->capacity += INCREASE_SZ;
			printf("增容成功\n");
		}
	}
}

//增加联系人信息
void AddContact(Contact* pc)
{
	assert(pc);

	CheckCapacity(pc);
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加联系人信息成功\n");

}

void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//打印联系人信息
void PrintContact(Contact* pc)
{
	assert(pc);
	if (0 == pc->sz)
	{
		printf("通讯录为空\n");
		return;
	}
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-50s\n", pc->data[i].name,
			pc->data[i].age, pc->data[i].sex,
			pc->data[i].tele, pc->data[i].addr);
	}
}

static int Find_By_NAME(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
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
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法删除信息\n");
		return;
	}
	else
	{
		printf("请输入要删除联系人的姓名：>");
		scanf("%s", name);

		int pos = Find_By_NAME(pc, name);
		if (pos == -1)
		{
			printf("要删除的联系人不存在\n");
			return;
		}
		int i = 0;
		for (i = pos; i < (pc->sz - 1); i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除联系人信息成功\n");
	}

}

//查找联系人信息
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找联系人的姓名：>");
	scanf("%s", name);

	int pos = Find_By_NAME(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}

	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-50s\n", pc->data[pos].name,
		pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);

}

//修改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改联系人的姓名：>");
	scanf("%s", name);

	int pos = Find_By_NAME(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
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

//排序联系人信息
static int cmp_Per_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_Per_by_name);
	PrintContact(pc);
}

//清空联系人信息
void ClearContact(Contact* pc)
{
	assert(pc);
	InitContact(pc);
	printf("清空成功\n");
}


void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("Contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//以二进制的形式写入文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}

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
			SaveContact(&Con);
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

