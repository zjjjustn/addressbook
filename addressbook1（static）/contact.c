#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	//内存设置函数 — memset() - 内存设置
	(pc->sz) = 0;
	memset(pc->data, 0, sizeof(pc->data));
	//pc->data 就相当于找到了整个数组，而整个数组可以使用数组名来表示，所以可以使用data来表示整个数组
	//即：pc->data  ===  data   ,,,数组名在第一个参数中没有&和sizeof，代表的是数组首元素的地址，第二个参数是把
	//每一个字节都设置成0，十进制的0，转为十六进制表示形式就是0x 00，，pc->data === data，数组名单独放在
	//sizeof中，代表的是整个数组，计算的是整个数组的大小，单位是字节也可以写成：MAX * sizeof（Contact）
}

//增加联系人
void AddContact(Contact* pc) 
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满、无法添加新的联系人\n");
		return; //返回类型是void，也可以写return，但是不能带出去返回值。
	}
	//通讯录未满，可以添加新成员，增加一个人的信息
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
	//在这里，[ ]的优先级等于->，，但是，data和[ ]是不可以先进行结合的，因为，这是在一个调用函数中，形参那部分接受到的只有指针变量pc
	//也就是说，如果后两者进行结合的话，系统根本就不知道data是什么东西，所以它结合出来是错误的，即，即使[ ]的优先级等于->，但是后两者不能
	//进行结合会出错，又因结合性从左到右所以，还是先让data和->进行结合，即先进行pc->data的操作，所以在结构体成员变量中找到了整个数组data
	//而整个数组可以使用数组名进行表示，知道了数组名就可以再通过下标对数组元素进行访问了。

}

//显示联系人信息
void PrintContact(const Contact* pc)
{
	assert(pc);
	//打印出所有人的信息，即sz个人的信息。
	int i = 0;
	//打印标题
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "名字", "年龄", "性别", "电话", "地址");// \t === tab
	//打印数据
	for (i = 0; i < (pc->sz); i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-50s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}

	//通过pc->data[i]找到数组data中下标为i的元素，即找到了一个变量，再通过点来访问该人的姓名等，，由于姓名是一个数组，找到的就是整个数组，整个
	//数组又可以使用数组名来表示，即：pc->data[i].name === name ，没有sizeof和&，代表数组首元素的地址,再通过%s进行打印字符串，除了年龄是一个变量，其他的都是数组，和name同理。

}


//因为该函数只是为了满足删除，查找，修改功能的需要，而这三个功能对应的函数的实现都会在该 .c 文件内进行实现，所以，对于这个函数
//只需要在该 .c 文件内执行即可，不许要暴露给别人，，所以，在前面加上static，就固定了该函数只在目前所在的 .c 文件内进行工作即可。
//static 修饰函数，本质上是改变了函数的链接属性。
static int Find_By_Name(const Contact* pc, char name[])//数组形式接收，数组形式接受的话就不考虑const的使用了。
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//相等
	//第一个参数先找到整个数组，可以使用数组名来表示，不是特例，即代表数组首元素的地址，第二个参数也不是特例，也是数组首元素的地址。
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
	//删除某个人的信息
	printf("请输入要删除人员的姓名：>");
	scanf("%s", name);
	//1、查找要删除的人
	//不管是删除还是查找还是修改，都需要使用到查找这个功能，所以就单独把该功能拿出来封装一个函数；
	int pos = Find_By_Name(pc, name);//一级指针传参和数组名传参
	//不存在该人
	if (pos == -1)
	{
		printf("要删除的人员不存在\n");
		return;
	}
	//2、存在该人员，要进行删除，把数组该位置上的人员删除之后，数组后面的人员依次往前移动一个位置。
	int i = 0;
	for (i = pos; i < (pc->sz - 1); i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	//pc->sz -= 1;
	pc->sz--;
	//如果想删除最后一个，是删除不掉的，因为，如果10个元素，最后一个下标为9，判断条件是<9，，所以不进入循环，但是
	//循环后面还有pc->sz--,,成员个数少了1，再显示人员信息的时候，访问不到最后一个人员了，，即使没删掉，也访问不掉，
	//最后的结果和删掉最后一个人员的效果是一样的。
	//假设MAX=3，把最后一个元素删除，本质上并没有从数组中删除掉，而是因为sz减1，打印的时候不访问最后一个元素，看起来和删除的效果是一样的，现在由于
	//看起来删了，本质上没删去，如果再添加新元素会怎么样呢？
	//因为删除完之后，元素个数就会减去1，由原来的3变成了2，，再添加新元素的时候，就会直接把新元素的内容放在下标为2的位置上，这样的话，即使之前的最后一个元素
	//没删去，也会被新的元素覆盖掉，添加完之后元素个数加1，再打印出来就是添加成员后的信息，是对的。
	printf("删除联系人员成功\n");
}

//查找联系人信息
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	//查找某个人的信息
	printf("请输入要查找人员的姓名：>");
	scanf("%s", name);
	int pos = Find_By_Name(pc, name);
	//要查找的人员不存在
	if (pos == -1)
	{
		printf("要查找的人员不存在\n");
		return;
	}
	
	//2、存在该人员，找出之后并打印出该成员的信息
	//打印标题
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-50s\n", "名字", "年龄", "性别", "电话", "地址");// \t === tab
	//打印数据
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
	//修改某个人的信息
	printf("请输入要修改人员的姓名：>");
	scanf("%s", name);
	int pos = Find_By_Name(pc, name);
	//要修改的人员不存在
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

