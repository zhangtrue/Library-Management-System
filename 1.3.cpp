#include <iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
int t;
typedef struct Book//ͼ��Ľṹ��
{
	char ISBN[10];//���
	char name[20];//����
	int num;      //���
	int sale;     //������
	int price;    //�۸�
}Book;
typedef struct BLNode//Book������
{
	Book data;
	struct BLNode *next;
}BLNode,*LinkBLNode;
int InitList(LinkBLNode &L)//��ʼ��
{
	L=new BLNode;
	L->next=NULL;
	return OK;
}
void New_Book(LinkBLNode &L)//��ʼ��__��ֵ
{
	LinkBLNode p,r,s;
	r=L;
	p=new BLNode;
	strcpy(p->data.ISBN,"001");
	strcpy(p->data.name,"Ӣ��");
	p->data.num=0;
	p->data.price=10;
	p->data.sale=5;
	p->next=NULL;
	r->next=p;
	s=new BLNode;
	strcpy(s->data.ISBN,"002");
	strcpy(s->data.name,"����");
	s->data.num=5;
	s->data.price=16;
	s->data.sale=2;
	r->next->next=s;
	r->next->next->next=NULL;


}
BLNode *LocateElem(LinkBLNode L)//����ͼ����Ϣ
{
	LinkBLNode p;char e[20];
	p=L->next;
	cout<<"�������ISBN��";
	cin>>e;
	while(strcmp(p->data.ISBN,e)&&p!=NULL)
	p=p->next;
	return p;

}
void Num_Book(LinkBLNode L)//����������ͼ����Ϣ
{
	LinkBLNode p;
	p=L->next;
	cout<<"������ͼ����ϢΪ��"<<endl;
	while(p)
	{		
		if(p->data.num==0)
		{
			cout<<"���:"<<p->data.ISBN<<endl;
			cout<<"����:"<<p->data.name<<endl;
			cout<<"�۸�:"<<p->data.price<<endl<<endl;
		}
		p=p->next;
	}
}
void Buy_Book(LinkBLNode &L)//����ͼ��
{
	LinkBLNode p;char e[20];
	p=L->next;
	cout<<"�������ISBN��";
	cin>>e;
	while(strcmp(p->data.ISBN,e)&&p!=NULL)
	{p=p->next;break;}
	if(!p) cout<<"����ʧ�ܣ���ͼ�鲻����"<<endl;
	else{
		if(p->data.num==0) cout<<"����ʧ�ܣ���ͼ����Ϊ0"<<endl;
		else {cout<<"����ɹ�"<<endl; p->data.num--;p->data.sale++;}
	}
	
}
int menu()
{
	int n;
	cout<<"---��ӭ��¼����ͼ������ϵͳ---"<<endl<<endl;
	cout<<"��ѡ�����¼����ݣ�"<<endl;
	cout<<"1.�˿�"<<"\t"<<"2.�̼�"<<"\t0.�˳�ϵͳ"<<endl;
	cin>>n; return n;
}
int menu_client()
{
	int n;
	cout<<"---��ӭ��¼����ͼ������ϵͳ���˿ͣ�---"<<endl<<endl;
	cout<<"��ѡ������Ҫ�Ĺ��ܣ�"<<endl;
	cout<<"1.��ѯͼ������Ϣ"<<endl;
	cout<<"2.��ѯ������ͼ����Ϣ"<<endl;
	cout<<"3.ͼ�鹺��"<<endl;
	cout<<"4.������һ����"<<endl;
	cout<<"0.�˳�ϵͳ"<<endl;
	cin>>n;return n;

}
int Switch_client(int n,LinkBLNode &L)
{
	LinkBLNode S;
	switch(n)
	{
	case 1:  if(S=LocateElem(L))
			   cout<<"��ͼ��Ŀ��ʣ��Ϊ;"<<S->data.num<<endl;
		     else cout<<"��ͼ�鲻����"<<endl; break;
	case 2:  Num_Book(L);break;
	case 3:  Buy_Book(L);break;
	case 4:  t=0;break;
	case 0:  cout<<"�����˳�...���Ժ�"<<endl;exit(0);break;
	default: cout<<"�������...�����˳�ϵͳ"<<endl;exit(0);
	}
	return OK;
}
void Sale_Book(LinkBLNode &L)//ͼ���������
{
	LinkBLNode p;
	p=L->next;
	cout<<"�������Ϊ:"<<endl;
	while(p!=NULL)
	{
		cout<<"��ţ�"<<p->data.ISBN<<endl;
		cout<<"������"<<p->data.name<<endl;
		cout<<"��棺"<<p->data.num<<endl;
		cout<<"�۸�"<<p->data.price<<endl;
		cout<<"������"<<p->data.sale<<endl<<endl;
		p=p->next;
	}
}
void PutIn_Book(LinkBLNode &L)//¼��ͼ����Ϣ
{
	LinkBLNode p,r;int i,j;
	cout<<"���������ݵĸ�����";
	cin>>i;
	r=L;
	while(r->next){r=r->next;}
	for(j=0;j<i;j++)
	{
		p=new BLNode;
		printf("\n\n��ţ�");
		scanf("%s",p->data.ISBN);
		printf("������");
		scanf("%s",&p->data.name);
		printf("��棺");
		scanf("%d",&p->data.num);
		printf("�۸�");
		scanf("%d",&p->data.price);
		printf("������");
		scanf("%d",&p->data.sale);
		p->next=NULL;
		r->next=p;
		r=p;
	}
}
int Amend_Book(LinkBLNode &L)//�޸�ͼ����Ϣ
{
	LinkBLNode p;
	if(!(p=LocateElem(L))) return 0;
	cout<<"�������޸ĺ������"<<endl;
	cout<<"���Ϊ��";
	cin>>p->data.ISBN;
	cout<<"����Ϊ��";
	cin>>p->data.name;
	cout<<"���Ϊ��";
	cin>>p->data.num;
	cout<<"�۸�Ϊ��";
	cin>>p->data.price;
	cout<<"����Ϊ��";
	cin>>p->data.sale;
	return OK;
}
int Delete_Book(LinkBLNode &L)//ɾ��ͼ����Ϣ
{
	LinkBLNode p,q;int j,i;
	p=L;j=0;
	cout<<"������ɾ��λ�ã�\n";
	cin>>i;
	while((p->next)&&(j<i-1))
	{p=p->next;++j;}
	if(!(p->next)||(j>i-1)) return 0;
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<"ɾ���ɹ�"<<endl;
	return OK;
}
int menu_store()
{
	int n;
	cout<<"---��ӭ��¼����ͼ������ϵͳ���̼ң�---"<<endl<<endl;
	cout<<"��ѡ������Ҫ�Ĺ��ܣ�"<<endl;
	cout<<"1.��ѯͼ������Ϣ"<<endl;
	cout<<"2.��ѯ������ͼ����Ϣ"<<endl;
	cout<<"3.ͼ���������"<<endl;
	cout<<"4.¼��ͼ����Ϣ"<<endl;
	cout<<"5.�޸�ͼ����Ϣ"<<endl;
	cout<<"6.ɾ��ͼ����Ϣ"<<endl;
	cout<<"7.������һ����"<<endl;
	cout<<"0.�˳�ϵͳ"<<endl;
	cin>>n;return n;
}
int Switch_store(int n,LinkBLNode &L)
{
	LinkBLNode S;
	switch(n)
	{
	case 1:  if(S=LocateElem(L))
			   cout<<"��ͼ��Ŀ��ʣ��Ϊ;"<<S->data.num<<endl;
		     else cout<<"������"<<endl; break;
	case 2:  Num_Book(L);break;
	case 3:  Sale_Book(L);break;
	case 4:  PutIn_Book(L);break;
	case 5:  Amend_Book(L);break;
	case 6:  Delete_Book(L);break;
	case 7:  t=0;break;
	case 0:  cout<<"�����˳�...���Ժ�"<<endl;exit(0);break;
	default: cout<<"�������...�����˳�ϵͳ"<<endl;exit(0);
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
		case 0:  cout<<"�����˳�...���Ժ�"<<endl;exit(0);break;
		default: cout<<"�������...�����˳�ϵͳ"<<endl;exit(0);
		}
	}
	return 0;
}
