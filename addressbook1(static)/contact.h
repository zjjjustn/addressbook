#pragma once

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

void InitContact(Contact* pc);

void AddContact(Contact* pc);

void PrintContact(const Contact* pc);

void DelContact(Contact* pc);

void SearchContact(const Contact* pc);

void ModifyContact(Contact* pc);

void SortContact(Contact* pc);

void ClearContact(Contact* pc);