#include <iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
int t;
typedef struct Book//图书的结构体
{
	char ISBN[10];//书号
	char name[20];//书名
	int num;      //库存
	int sale;     //销售量
	int price;    //价格
}Book;
typedef struct BLNode//Book单链表
{
	Book data;
	struct BLNode *next;
}BLNode,*LinkBLNode;
int InitList(LinkBLNode &L)//初始化
{
	L=new BLNode;
	L->next=NULL;
	return OK;
}
void New_Book(LinkBLNode &L)//初始化__赋值
{
	LinkBLNode p,r,s;
	r=L;
	p=new BLNode;
	strcpy(p->data.ISBN,"001");
	strcpy(p->data.name,"英语");
	p->data.num=0;
	p->data.price=10;
	p->data.sale=5;
	p->next=NULL;
	r->next=p;
	s=new BLNode;
	strcpy(s->data.ISBN,"002");
	strcpy(s->data.name,"高数");
	s->data.num=5;
	s->data.price=16;
	s->data.sale=2;
	r->next->next=s;
	r->next->next->next=NULL;


}
BLNode *LocateElem(LinkBLNode L)//查找图书信息
{
	LinkBLNode p;char e[20];
	p=L->next;
	cout<<"请输入的ISBN：";
	cin>>e;
	while(strcmp(p->data.ISBN,e)&&p!=NULL)
	p=p->next;
	return p;

}
void Num_Book(LinkBLNode L)//查找已售完图书信息
{
	LinkBLNode p;
	p=L->next;
	cout<<"已售完图书信息为："<<endl;
	while(p)
	{		
		if(p->data.num==0)
		{
			cout<<"书号:"<<p->data.ISBN<<endl;
			cout<<"书名:"<<p->data.name<<endl;
			cout<<"价格:"<<p->data.price<<endl<<endl;
		}
		p=p->next;
	}
}
void Buy_Book(LinkBLNode &L)//购买图书
{
	LinkBLNode p;char e[20];
	p=L->next;
	cout<<"请输入的ISBN：";
	cin>>e;
	while(strcmp(p->data.ISBN,e)&&p!=NULL)
	{p=p->next;break;}
	if(!p) cout<<"购买失败，该图书不存在"<<endl;
	else{
		if(p->data.num==0) cout<<"购买失败，该图书库存为0"<<endl;
		else {cout<<"购买成功"<<endl; p->data.num--;p->data.sale++;}
	}
	
}
int menu()
{
	int n;
	cout<<"---欢迎登录网上图书销售系统---"<<endl<<endl;
	cout<<"请选择你登录的身份："<<endl;
	cout<<"1.顾客"<<"\t"<<"2.商家"<<"\t0.退出系统"<<endl;
	cin>>n; return n;
}
int menu_client()
{
	int n;
	cout<<"---欢迎登录网上图书销售系统（顾客）---"<<endl<<endl;
	cout<<"请选择你需要的功能："<<endl;
	cout<<"1.查询图书库存信息"<<endl;
	cout<<"2.查询已售完图书信息"<<endl;
	cout<<"3.图书购买"<<endl;
	cout<<"4.返回上一界面"<<endl;
	cout<<"0.退出系统"<<endl;
	cin>>n;return n;

}
int Switch_client(int n,LinkBLNode &L)
{
	LinkBLNode S;
	switch(n)
	{
	case 1:  if(S=LocateElem(L))
			   cout<<"该图书的库存剩余为;"<<S->data.num<<endl;
		     else cout<<"该图书不存在"<<endl; break;
	case 2:  Num_Book(L);break;
	case 3:  Buy_Book(L);break;
	case 4:  t=0;break;
	case 0:  cout<<"正在退出...请稍后"<<endl;exit(0);break;
	default: cout<<"输入错误...即将退出系统"<<endl;exit(0);
	}
	return OK;
}
void Sale_Book(LinkBLNode &L)//图书销售情况
{
	LinkBLNode p;
	p=L->next;
	cout<<"销售情况为:"<<endl;
	while(p!=NULL)
	{
		cout<<"书号："<<p->data.ISBN<<endl;
		cout<<"书名："<<p->data.name<<endl;
		cout<<"库存："<<p->data.num<<endl;
		cout<<"价格："<<p->data.price<<endl;
		cout<<"销量："<<p->data.sale<<endl<<endl;
		p=p->next;
	}
}
void PutIn_Book(LinkBLNode &L)//录入图书信息
{
	LinkBLNode p,r;int i,j;
	cout<<"请输入数据的个数：";
	cin>>i;
	r=L;
	while(r->next){r=r->next;}
	for(j=0;j<i;j++)
	{
		p=new BLNode;
		printf("\n\n书号：");
		scanf("%s",p->data.ISBN);
		printf("书名：");
		scanf("%s",&p->data.name);
		printf("库存：");
		scanf("%d",&p->data.num);
		printf("价格：");
		scanf("%d",&p->data.price);
		printf("销量：");
		scanf("%d",&p->data.sale);
		p->next=NULL;
		r->next=p;
		r=p;
	}
}
int Amend_Book(LinkBLNode &L)//修改图书信息
{
	LinkBLNode p;
	if(!(p=LocateElem(L))) return 0;
	cout<<"请输入修改后的数据"<<endl;
	cout<<"书号为：";
	cin>>p->data.ISBN;
	cout<<"书名为：";
	cin>>p->data.name;
	cout<<"库存为：";
	cin>>p->data.num;
	cout<<"价格为：";
	cin>>p->data.price;
	cout<<"销量为：";
	cin>>p->data.sale;
	return OK;
}
int Delete_Book(LinkBLNode &L)//删除图书信息
{
	LinkBLNode p,q;int j,i;
	p=L;j=0;
	cout<<"请输入删除位置：\n";
	cin>>i;
	while((p->next)&&(j<i-1))
	{p=p->next;++j;}
	if(!(p->next)||(j>i-1)) return 0;
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<"删除成功"<<endl;
	return OK;
}
int menu_store()
{
	int n;
	cout<<"---欢迎登录网上图书销售系统（商家）---"<<endl<<endl;
	cout<<"请选择你需要的功能："<<endl;
	cout<<"1.查询图书库存信息"<<endl;
	cout<<"2.查询已售完图书信息"<<endl;
	cout<<"3.图书销售情况"<<endl;
	cout<<"4.录入图书信息"<<endl;
	cout<<"5.修改图书信息"<<endl;
	cout<<"6.删除图书信息"<<endl;
	cout<<"7.返回上一界面"<<endl;
	cout<<"0.退出系统"<<endl;
	cin>>n;return n;
}
int Switch_store(int n,LinkBLNode &L)
{
	LinkBLNode S;
	switch(n)
	{
	case 1:  if(S=LocateElem(L))
			   cout<<"该图书的库存剩余为;"<<S->data.num<<endl;
		     else cout<<"不存在"<<endl; break;
	case 2:  Num_Book(L);break;
	case 3:  Sale_Book(L);break;
	case 4:  PutIn_Book(L);break;
	case 5:  Amend_Book(L);break;
	case 6:  Delete_Book(L);break;
	case 7:  t=0;break;
	case 0:  cout<<"正在退出...请稍后"<<endl;exit(0);break;
	default: cout<<"输入错误...即将退出系统"<<endl;exit(0);
	}
	return OK;
}
main()
{
	LinkBLNode L;
	InitList(L);
	New_Book(L);
	while(1)
	{
		switch(t=menu())
		{
		case 1:while(t)
			   {Switch_client(menu_client(),L);}break;
		case 2:while(t){Switch_store(menu_store(),L);}break;
		case 0:  cout<<"正在退出...请稍后"<<endl;exit(0);break;
		default: cout<<"输入错误...即将退出系统"<<endl;exit(0);
		}
	}
	return 0;
}
