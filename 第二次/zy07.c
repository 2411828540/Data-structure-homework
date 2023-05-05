#include "stdio.h"
#include "stdlib.h"
typedef struct xs{
	int cj;
	struct xs *next;
}xxs,*LinkList;
void InsertSort(LinkList p){
	if(p->next==NULL||p->next->next==NULL)  //������Ϊ�ջ���������ֻ��һ��Ԫ�� ����
		return ;
		LinkList pre=p;  //ָ���ź����ǰ���ڵ�
		LinkList unsort=p->next->next;
		LinkList s=p->next;
		s->next=NULL;
		s=unsort;
		while(s){

			unsort=s->next;

			while(pre->next!=NULL&&pre->next->cj<=s->cj)
				pre=pre->next;
			s->next=pre->next;
			pre->next=s;
			pre=p;
			s=unsort;
		}
}
void chooses(LinkList head) //ѡ������
{	 
	LinkList q,p,r;
	int s;
	for(p=head->next;p!=NULL;p=p->next)
	{
		r=p;
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(q->cj<r->cj)
			{	 
				r=q;      //һһ�Ƚϣ�r����Сֵ�Ľ��ָ�룬���������ݻ���
			}
		}
		if(r->cj!=p->cj)
		{
			s=r->cj;
			r->cj=p->cj;		//������λ�û�����С�ĵ�ǰ�棬��ĵ�����	
			p->cj=s;
		}
	} 
}
LinkList InitList(LinkList L,int n,int a[])
{
    int cj;
    L = (LinkList)malloc(sizeof(xxs));
    L->next = NULL;
    LinkList head = L;
    head->next=L->next;

    for(int i = 0;i<n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(xxs));
		p->cj = a[i];
        p->next = L->next;
        L->next = p;
        L=L->next;
    }

    return head;
}
LinkList re(LinkList la)
{
	LinkList ld,lz;
	ld = (LinkList)malloc(sizeof(xxs));
	lz=la->next;
	ld->next = NULL;
	while(lz)
	{
		LinkList lj = (LinkList)malloc(sizeof(xxs));
		lj->cj=lz->cj;
		lj->next=ld->next;
		ld->next=lj;
		lz=lz->next;	
	}
	return ld;
	
}
void print(xxs *p)
{
	
    LinkList head = p->next;
    while(head)
	{
        printf("%d ",head->cj);
        head=head->next;
    }
    printf("\n");
	
}
void main()
{
	int n=10;
	int a[10]={6,5,4,9,8,7,1,2,3,10};
	LinkList la;
	la=InitList(la,10,a);
	printf("��תǰ:\n");
	print(la);
	printf("��ת��:\n");
	print(re(la));
	printf("����ʽ����:\n");
	InsertSort(la);
	print(la);
	printf("ѡ��ʽ����:\n");
	la=InitList(la,10,a);
	la=re(la);
	chooses(la);
	print(la);
	printf("\n");
}
