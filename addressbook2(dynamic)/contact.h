#pragma once

//头文件的包含
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

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人信息
void AddContact(Contact* pc);

//打印联系人信息
void PrintContact(Contact* pc);

//删除联系人信息
void DelContact(Contact* pc);

//查找联系人信息
void SearchContact(const Contact* pc);

//修改联系人信息
void ModifyContact(Contact* pc);

//排序联系人信息
void SortContact(Contact* pc);

//清空联系人信息
void ClearContact(Contact* pc);

//释放通讯录动态内存
void DestroyContact(Contact* pc);
