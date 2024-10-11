#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<cstring>
#include<iostream>
using namespace std;
//节点结构体
typedef struct NODE
{
	int xh;
	char* name;
	char* phone;
	struct NODE* pNext;
}Node;
//分页结构体
typedef struct PAGE
{
	int TotalItem;
	int OnePageItem;
	int TotalPage;
	int CurrentPage;
} Page;

int g_menu_type = 0;
char g_key;
void InitInfo(Node** top,Node** end,int n);//初始化信息
char GetKey();//获取键盘数字输入

char* GetName();//获取名字
char* GetPhone();//获取电话号
int GetNumber();//获取编号
Node* GetNode();//获取一个节点

char* InputName();//输入一个名字
char* InputPhone();//输入一个电话号
int InputNumber();//输入一个编号
Node* InputNode();//输入一个节点

void LookTXL(Node* top);//查看
void QueryTXL(Node* top);//查询
void AddNode(Node** top,Node** end,Node* node);	//添加节点
void DelNode(Node** top,Node** end,int n);//删除节点
void DelTXL(Node** top,Node** end);//删除			
void UpDateTXL(Node* top);//修改
void Show(Node* top,Page* page);//显示
void ShowMenu(Page* page);
void ShowALL(Node* top);//全部显示
Page* InitPage(Node* top,int n);
void OperatePage(Page* page,Node* top);

int main()
{
	Node* top = NULL;
	Node* end = NULL;
	//Page* page = NULL;
	//初始化信息
	InitInfo(&top,&end,49);
	
	char key;
	
	while(1)
	{
		printf("1.查看通讯录\n");
		printf("2.查询通讯录\n");
		printf("3.添加通讯录\n");
		printf("4.删除通讯录\n");
		printf("5.修改通讯录\n");
		printf("6.退出通讯录\n");
		//获取键盘数字输入
		key = GetKey();
		switch(key)
		{
			case '1':
				g_menu_type = 1;
				LookTXL(top);
				break;
			case '2':
				g_menu_type = 2;
				QueryTXL(top);
				break;
			case '3':
				g_menu_type = 3;
				AddNode(&top,&end,InputNode());
				break;
			case '4':
				g_menu_type = 4;
				DelTXL(&top,&end);
				break;
			case '5':
				g_menu_type = 5;
				UpDateTXL(top);
				break;
			case '6':
				return 0;
				break;
			default:
				printf("请输入正确的数字！\n");
				break;
		}
	}
	return 0;
}
char GetKey()//获取键盘数字输入
{
	char c,v;
	int a = 0;
	//int a;scanf("%d",&a);//123\n，把123赋给a，输入缓冲区中还有一个\n，应该取出来，getchar（）
	//无 || a == 0的情况：若输入缓冲区中已经存在一个\n，则循环直接退出，v为一个垃圾值，返回它没意义
	while((c=getchar()) != '\n' || a == 0)
	{
		v = c;
		a = -1;
	}
	return v;
}
char* GetName()//获取名字
{
	char name[6]={0};
	char* p = (char*)malloc(6);
	for(int i = 0;i<5;i++)
	{
		name[i] = 'a'+rand()%26;
	}
	strcpy(p, name);//
	/*
strcpy_s(b, a)
意思是将a拷贝给b,但是一定要保证b装的下a，否则会报错
void main()
{
	 char str[10], str1[9];
	for(int i=0; i<9;i++)
	{
		str1[i] ='a';
	 }
	 strcpy_s(str, sizeof(str), str1);
 }
上述代码运行时异常。为什么会出现异常？
strcpy_s是根据'\0'判断源字符串结束的
代码中的str1[9]的9个数组成员都被赋值为'a'，没有结束符'\0'，
因此strcpy_s在复制完str1的9个字符后还在继续赋值其后的内存，
并且最终复制的字符数大于了目标缓冲区的长度10，因此引发此断言失败。

问题出在程序语句（见下）：
strcpy_s(p,strlen(p1),p1);
strcpy_s(p1,strlen(p2),p2);
strcpy_s(p2,strlen(p),p);
其中，字符串p1和p2分别指向某个字符串，p是定义的一个字符数组。问题出现在对strlen()的使用，这个函数计算的字符串长度是不包括'\0’的，
所以在设置第二个参数（缓冲区长度）时，就会出现异常，因为在拷贝时需要将字符串的结束标志也要一同拷贝过去，
所以，上面提示Buffer is too small就表明第二个参数设置的值小于源字符串。
所以解决方法就是：将strlen(p1)修改为strlen(p1)+1，如下图，修改后调试通过。
strcpy_s(p,strlen(p1)+1,p1);
strcpy_s(p1,strlen(p2)+1,p2);
strcpy_s(p2,strlen(p)+1,p);

	*/
	return p;

	//char* name = (char*)malloc(8);
	//int i;
	//char c[2] = {0};
	//*name = 0;
	//for(i = 1;i<=7;i++)
	//{
	//	c[0] = rand()%26+97;
	//	strcat_s(name,8,c);
	//}
	//return name;
}
char* GetPhone()//获取电话号
{
	char phone[11]={0};
	char* p = (char*)malloc(12);
	switch(rand()%4)
	{
		case 0:
			strcpy(p,"131");
			//phone要拷贝到的地方，phone的大小，要拷贝的字符串，到\0结束，所以第三个参数不能大于第一个参数
			break;
		case 1:
			strcpy(p,"156");
			break;
		case 2:
			strcpy(p,"136");
			break;
		case 3:
			strcpy(p,"188");
			break;		
	}
	for(int i=0;i<8;i++)
	{
		//_itoa_s(rand()%10,c,2,10);
		//数字变为字符，数字，要变成字符串的地址，字符串的大小，几进制
		phone[i] = rand()%10+'0';
	}
	strcat(p, phone);
	return p;
/*
	int i;
	char* phone = (char*)malloc(12);
	char c[2];
	switch(rand()%4)
	{
		case 0:
			strcpy_s(phone,12,"156");
			break;
		case 1:
			strcpy_s(phone,12,"135");
			break;
		case 2:
			strcpy_s(phone,12,"131");
			break;
		case 3:
			strcpy_s(phone,12,"188");		
			break;
	}
	for(i = 1;i<=8;i++)
	{
		_itoa_s(rand()%10,c,2,10);
		strcat_s(phone,12,c);
	}
	return phone;*/

}
int GetNumber()//获取编号
{
	static int i = 0;
	i++;
	return i;
}
char* InputName()//输入一个名字
{
	/*char c;
	char* name = (char*)malloc(7);
	while((c = getchar() ) != '\n')
	{
	}
	return name;*/

	//注意的问题：长名字空间不够怎么解决
	char c;
	int count = 0;
	int size = 5;
	char* str = (char*)malloc(size);
	char* newStr = NULL;
	char* jStr = str;
	while((c = getchar() ) != '\n')
	{
		count++;
		*str++ = c;
		if(count+1 == size)
		{
			*str = '\0';
			size += 5;
			newStr = (char*)malloc(size);
			strcpy(newStr,jStr);
			free(jStr);
			jStr = newStr;
			str = jStr+count;
		}
	}
	*str = 0;
	return jStr;
	
	
}
char* InputPhone()//输入一个电话号
{
	char c;
	char* phone = (char*)malloc(13);
	char* bj = phone;
	while((c = getchar() ) != '\n')
	{
		*phone = c;
		phone++;
	}
	*phone = 0;
	return bj;
}
int InputNumber()//输入一个编号
{
	int n;
	scanf("%d",&n);
	getchar();
	return n;
}
Node* InputNode()//输入一个节点
{
	Node* node = (Node*)malloc(sizeof(Node));
	printf("请输入一个名字：\n");
	node->name = InputName();
	printf("请输入一个电话号：\n");
	node->phone = InputPhone();
	printf("请输入一个学号：\n");
	node->xh = InputNumber();
	node->pNext = NULL;
	return node;
}
Node* GetNode()//获取一个节点
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->name = GetName();
	node->phone = GetPhone();
	node->xh = GetNumber();
	node->pNext = NULL;
	return node;
}
void InitInfo(Node** top,Node** end,int n)//初始化信息
{
	int i;
	srand((unsigned int)time(0));//每次运行程序得到的随机数据都不一样
	for(i = 0;i < n;i++)
	{
		//添加节点
		AddNode(top,end,GetNode());
	}
	
}
void AddNode(Node** top,Node** end,Node* node)	//添加
{
	//链表为空
	if(*top == NULL)
	{
		*top = node;
		*end = node;
	}
	//头插入 新来的作为头指针
	//(*top)->pNext = node;
	//尾插入 新来的作为尾指针
	else
	{
		(*end)->pNext = node;
		*end = node;
	}
}
void DelNode(Node** top,Node** end,int n)//删除			
{
	Node* temp = *top;
	Node* del = NULL;
	//ShowALL(temp);
	/*printf("请输入您要删除的学号：\n");*/
	//========================此处有问题，应该接收数字，输入双位数出错=====================================
	/*int n = 0;
	scanf("%d",&n);
	getchar();
	*/
	/*int n = 0;
	n = atoi(InputName());*/
	/*int n = InputNumber();*/

	//头删除
	if(temp->xh == n)
	{
		del = temp;
		temp = temp->pNext;
		free(del);
		del = NULL;
		*top = temp;
		/*ShowALL(*top);*/
		return;
	}
	//中间删除
	while(temp->pNext != NULL)
	{
		if(temp->pNext->xh  == n)
		{
			del = temp->pNext;
			temp->pNext = temp->pNext->pNext;
			free(del);
			del = NULL;
			//判断是否为尾节点
			if(temp->pNext == *end)
			{
				*end = temp;
			}
			
			//ShowALL(*top);
			return;
		}
		temp = temp->pNext;
	}
	
}
void LookTXL(Node* top)//查看
{
	
	Page* page = InitPage(top,20);
	OperatePage(page,top);	
}
void QueryTXL(Node* top)//查询
{
	char* keyword = (char*)malloc(12);
	Node* bj = top;
	Node* node = NULL;
	Node* del = NULL;
	Node* newTop = NULL;
	Node* newEnd = NULL;
	//若为模糊查询，应该怎么写代码？？？
	while(1)
	{
		while(1)
		{
			printf("请输入您要查询的关键字：\n");
			keyword = InputName();
			printf("按y确定，其他请重新输入：\n");
			if(GetKey() == 'y')
				break;
			else
			{
				free(keyword);
				keyword = NULL;
			}
		}
		bj = top;
		newTop = NULL;
		newEnd = NULL;

		while(bj)
		{
			if(strncmp(bj->name,keyword,strlen(keyword)) == 0 || strncmp(bj->phone,keyword,strlen(keyword)) == 0)
			{
				node = (Node*)malloc(sizeof(Node));
				node->xh = bj->xh;
				node->phone = bj->phone;
				node->name = bj->name;
				node->pNext = NULL;
				//将所有查询到的节点，放到一个新的链表上
				AddNode(&newTop,&newEnd,node);
			}
			bj = bj->pNext;
		}
		if(newTop == NULL)
			printf("没找到！\n");
		else
		{
			LookTXL(newTop);
			//删除查询到的所有结果
			while(newTop)
			{
				del = newTop;
				newTop = newTop->pNext;
				free(del);
				del = NULL;
				newEnd = NULL;
			}
		}
		if(g_key == 'c')
			continue;
		if(g_key == 'd' && g_menu_type == 4)
			return;
		if(g_key == 'u' && g_menu_type == 5)
			return;
		if(g_key == 'b')
			return;
	}
}
void DelTXL(Node** top,Node** end)//删除	
{
	int xh;
	char key;
	while(1)
	{
		printf("请查询您所要删除的学号！\n");
		QueryTXL(*top);
		if(g_key == 'b')
			return;
		printf("请输入您要删除的学号：\n");
		xh = atoi(InputName());
		DelNode(top,end,xh);
		printf("按y继续删除，其他键返回主菜单！\n");
		key = GetKey();
		if(key == 'y')
			;
		else
			return;
	}
	
	
	
}
void UpDateTXL(Node* top)//修改
{
	int xh;
	char key = 0;
	Node* bj = top;
	while(1)
	{
		printf("请查询您要修改的信息：\n");
		QueryTXL(top);
		if(g_key == 'b')
			return;
		printf("请输入您要修改的信息的编号：\n");
		xh = atoi(InputName());
		bj = top;
		while(bj)
		{
			if(bj->xh == xh)
			{
				printf("请输入编号%d的新名字",bj->xh);
				bj->name = InputName();
				printf("请输入编号%d的新电话号码",bj->xh);
				bj->phone = InputPhone();
				printf("按y继续修改，其他键返回主菜单！\n");
				key =GetKey();
				if(key == 'y')
					break;
				else
					return;
			}
			bj=bj->pNext;		
		}
		if(bj == NULL)
			printf("没找到您要修改的信息！\n");		
	}
}
void ShowALL(Node* top)//全部显示
{
	printf("学号\t名字\t电话号\t\n");
	while(top)
	{
		printf("%d\t%s\t%s\t\n",top->xh,top->name,top->phone);
		top = top->pNext;
	}
}
void Show(Node* top,Page* page)//显示单页信息
{
	int count =0;
	int begin = (page->CurrentPage-1) * page->OnePageItem + 1;
	int end = page->CurrentPage * page->OnePageItem;
	printf("学号\t名字\t电话号\t\n");
	while(top)
	{
		count++;
		if(count >= begin && count <= end)
			printf("%d\t%s\t%s\t\n",top->xh,top->name,top->phone);
		top = top->pNext;
	}

}
void ShowMenu(Page* page)
{
	switch(g_menu_type)
	{
		case 1:
			printf("共%d条 共%d页 当前第%d页 上一页(w) 下一页(s) 返回(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;
		case 2:
			printf("共%d条 共%d页 当前第%d页 上一页(w) 下一页(s) 继续查询(c) 返回(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;		
		case 4:
			printf("共%d条 共%d页 当前第%d页 上一页(w) 下一页(s) 删除(d) 返回(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;
		case 5:
			printf("共%d条 共%d页 当前第%d页 上一页(w) 下一页(s) 修改(u) 返回(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
	}
	
}
Page* InitPage(Node* top,int OnePageItem)
{
	//计算出当前链表中分页的信息
	//包括分页的总数目、一页显示的个数、总页数、当前页
	Page* page = (Page*)malloc(sizeof(Page));
	page->CurrentPage = 0;
	page->OnePageItem = OnePageItem;
	page->TotalItem = 0;
	while(top)
	{
		page->TotalItem++;
		top = top->pNext;
	}
	page->TotalPage = page->TotalItem % page->OnePageItem == 0 ? page->TotalItem / page->OnePageItem : page->TotalItem / page->OnePageItem + 1;
	//优先级从高到低顺序：->	/	==	?:	= 
	return page;
}
void OperatePage(Page* page,Node* top)
{
	char key = 's';
	while(key != 'b')
	{
		switch(key)
		{
			case 's':
				if(page->CurrentPage == page->TotalPage)
					printf("已经是最后一页了！\n");
				else
				{
					page->CurrentPage++;
					Show(top,page);
					ShowMenu(page);
				}
				break;
			case 'w':
				if(page->CurrentPage == 1)
					printf("已经是第一页了！\n");
				else
				{
					page->CurrentPage--;
					Show(top,page);
					ShowMenu(page);
				}

				break;
			case 'b':
				return;
				break;
			case 'c':
			case 'd':
			case 'u':
				break;
			default:
				printf("输入错误，请重新输入：\n");
				break;
		}
		g_key = key = GetKey();
		if(key == 'c' || key == 'd' || key == 'u')
			return;//break;均可，都是终止循环，退出循环体
	}
}
