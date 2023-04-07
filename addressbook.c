#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
	int num;
	char name[20];
    char sex[20];
	char Tel[20];
	char position[20];
	char mail_address[20];
}Person;

typedef int ElemType;
typedef struct Node
{     
	Person data;
	struct Node *next;
}LinkNode,* LinkList;

LinkNode *CreateFromTail(){
	LinkList head;
	LinkNode *s,*r;
	char flag;
		flag='Y';   
	head=(LinkNode *)malloc(sizeof(LinkNode)); 
	head->next=NULL;
	r=head;               
	printf("开始创建：\n");
	while(flag=='Y'||flag=='y'){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		printf("姓名：\n");
		scanf(" %s",&s->data.name);
        printf("性别：\n");
        scanf("%s",&s->data.sex);
		printf("电话：\n");
		getchar();
		scanf(" %s",&s->data.Tel);
		printf("职位：\n");
		scanf(" %s",&s->data.position);
		printf("邮箱：\n");
		scanf(" %s",&s->data.mail_address);
		r->next=s;
		r=s;
		getchar();
		printf("继续输入吗？（Y/N）:");
		scanf(" %s",&flag);
	}
	r->next=NULL;             
	return head;              
}

void save(LinkList head){
	FILE* fp;
	LinkNode* p=head->next;
	int i=0;
	int n;
	n=ListLength(head);
	if((fp=fopen("D://www.txt","w+"))==NULL){
		printf("打开失败");
		exit(-1);
	}
	else{
		printf("\n");
	}
	for(i;i<n;i++){
		fprintf(fp,"%s\n",p->data.name);
		fprintf(fp,"%s\n",p->data.Tel);
		fprintf(fp,"%s\n",p->data.sex);
		fprintf(fp,"%s\n",p->data.position);
		fprintf(fp,"%s\n",p->data.mail_address);
		p=p->next;
	}
	printf("成功\n");
	fclose(fp);
}
int ListLength(LinkList head) 
{
    LinkList p;
    int length=0;
    p=head->next;
    while(p)
    { 
        length++;
        p=p->next;
    }
    return length;	
}

void OutputNode(LinkList head)
{
	LinkNode *p;
	p=head->next;                
	while(p!=NULL){
		printf("姓名：%s\n",p->data.name);
        printf("性别：%s\n",p->data.sex);
		printf("电话：%s\n",p->data.Tel);
		printf("职位：%s\n",p->data.position);
		printf("通信地址：%s\n",p->data.mail_address);
		p=p->next;
	}
}

void InsLinkList(LinkNode *p,char *name,char *sex,char *Tel,char *position,char *mail_address)
{  
	LinkNode *s;
	s=(LinkNode *)malloc(sizeof(LinkNode));
	strcpy(s->data.name,name);
    strcpy(s->data.sex,sex);
	strcpy(s->data.Tel,Tel);
	strcpy(s->data.position,position);
	strcpy(s->data.mail_address,mail_address);
	s->next=p->next;
	p->next=s;
}

int ListDelete(LinkList head,int i)
{ 
	int j=0;
	int length;
	LinkNode *p,*q;
    p=head;
    length=ListLength(head); 

    if(!p||i>length) 
    {
        return 0;
    }

    while(p&&j<i-1) 
    {
        p=p->next;
  	    j++;
    }

    q=p->next;  
    p->next=q->next; 
    return 1; 	
} 

void GetElem(LinkList head,int i,Person x)
{
	int j=1;
    int length;
    LinkList p;
    p=head->next;
    length=ListLength(head); 

    if(!p||i>length) 
    {
        printf("未找到！\n");
    }

    while(j<i)
    {
        p=p->next;
        j++;
    }

    x=p->data;
    printf("姓名：%s\n",x.name);
    printf("性别：%s\n",x.sex);
    printf("电话：%s\n",x.Tel);
    printf("职位：%s\n",x.position);
    printf("通信地址：%s\n",x.mail_address);
}

void menu()
{
	printf("===========欢迎改善通讯录============\n");
	printf("============1.增加联系人=============\n");
	printf("============2.删除联系人=============\n");
	printf("============3.查找联系人=============\n");
	printf("============4.打印通讯录=============\n");
	printf("============5.退出通讯录=============\n");
	printf("=====================================\n");
}

int main(){
	int i,j,location; 
	LinkList head;
	Person x,y;
	char Continue='y';
	char name[20];
    char sex[20];
	char Tel[20];
	char position[20];
	char mail_address[20];
	printf("是否要创建一个通讯录呢？（1/0）:\n");
	scanf("%d",&j);
	
    if(j==1)
	{
        head=CreateFromTail();
    }
	else 
    { 
		printf("期待下次见面！\n");
		return 0;
	}
	save(head);
	menu();

	while(1)
	{
        printf("请选择您的操作：\n");
        scanf("%d",&i);
        switch(i){
        case 1:printf("已选择1.增加联系人\n");
            printf("姓名：\n");
            scanf(" %s",&name);
            printf("性别：\n");
            scanf("%s",&sex);
            printf("电话：\n");
            getchar();
            scanf(" %s",&Tel);
            printf("职位：\n");
            scanf(" %s",&position);
            printf("通信地址：\n");
            scanf(" %s",&mail_address);
            InsLinkList(head,name,sex,Tel,position,mail_address);
            break;
        case 2:printf("已选择2.删除联系人");
            printf("\n输入要删除的位置：");
            scanf("%d",&location);ListDelete(head,location);
            break;
        case 3:printf("已选择3.查找联系人");
            printf("\n请输入查询位置:");
            scanf("%d",&location);
            GetElem(head,location,x);
            break;
        case 4:printf("已选择4.打印通讯录\n");
            OutputNode(head);
            break;
        case 5:printf("已选择5.退出通讯录\n");exit(0);
        default:printf("error\n");break;
	} 
	printf("是否继续对通讯录的操作(1/0)：");
	scanf(" %s",&Continue);
	}
	return 0;
}