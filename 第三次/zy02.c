#include "stdio.h"
#include "stdlib.h"
typedef struct two{
	int data;
	struct two *prior;
	struct two *next;
}link,*Linkp;
Linkp ini (Linkp head)
{
	int i;
	head=(Linkp)malloc(sizeof(link));
	Linkp q=head,c;
	for(i=1;i<10;i++)
	{
		c=(Linkp)malloc(sizeof(link));
		c->data=2*i;
		q->next=c;
		c->prior=q;
		q=c;
	}
	head->prior=NULL;
	q->next=NULL;
	return head;
}
Linkp insert(Linkp head,int x,int c)
{
	Linkp q=head;
	int i=1;
	for(;i<=x;i++)
	{
		q=q->next;
	}
	Linkp p=(Linkp)malloc(sizeof(link));
	p->data=c;
	p->next=q;
	q->prior->next=p;
	p->prior=q->prior;
	q->prior=p;	
	return head;
}
void delet(Linkp head,int x)
{
	Linkp q=head;
	int i=1;
	for(;i<=x;i++)
	{
		q=q->next;
	}
	q->prior->next=q->next;
	q->next->prior=q->prior;
	free(q);
}
void print(Linkp head)
{
	Linkp p=head;
	printf("������ʾΪ��\n");
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
	printf("������ʾΪ��\n");
	while(p->prior!=NULL)
	{
		printf("%d ",p->data);
		p=p->prior;
	}
	
}
void print1(Linkp head)
{
	Linkp p=head;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
}

void main()
{
	Linkp head;
	head=ini(head);
	print(head);
	printf("\n�ڵ�2��λ�ò�������144:\n");
	print1(insert(head,2,144));
	printf("\nɾ���ڶ���Ԫ��:\n");
	delet(head,2);
	print1(head);
	free(head);
}
