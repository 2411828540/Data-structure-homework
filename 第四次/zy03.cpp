#include "stdio.h"
#include <stack>
using namespace std;
#define M 7
#define N 7
typedef struct{
	int y,x; //�У���
}PostType;
typedef struct{
	int ord; //��ǰλ����·���ϵ����
	PostType seat; //��ǰ����
	int di; //����һ����ķ���
}SELemType;
int Pass(int maze[M][N],PostType curpos)
{
	if(maze[curpos.y][curpos.x]==0) //��ͨ����һ����֮0
	 	return 1;
	else 
		return 0;
}
void FootPrint(int maze[M][N],PostType curpos)
{
	maze[curpos.y][curpos.x]=2; //���߹�����ͨ�����㼣2
}
void MarkPrint(int maze[M][N],PostType curpos)
{
	maze[curpos.y][curpos.x]=3; //���߹�����ͬ�������㼣3
}
PostType NextPos(PostType curpos,int i)
{
	PostType cpos=curpos;
	switch(i) //1,2,3,4 �ң��£�����
	{
		case 1 : cpos.x+=1; break;
		case 2 : cpos.y+=1; break;
		case 3 : cpos.x-=1; break;
		case 4 : cpos.y-=1; break;
	}
	return cpos;
}
void MazePath(int mg[M][N])
{
	stack<SELemType> z,t;
	int curstep;  //��ǰ����
	PostType curpos={1,1},end={5,5};
	SELemType e;
	
	curstep=1; //̽����һ��
	do
	{
		if(Pass(mg,curpos))
		{
			FootPrint(mg,curpos);
			e.ord=curstep;
			e.seat=curpos;
			e.di=1;
			z.push(e);
			if(curpos.x==end.x&&curpos.y==end.y)
			{
				break;
			}
			else
			{
				curpos=NextPos(curpos,1);
				curstep++;
			}
		}
		else
		{
			if(!z.empty())
			{
				e=z.top();
				z.pop();
				while(e.di==4&&!z.empty())
				{
					MarkPrint(mg,e.seat);
					e=z.top();
					z.pop();
					curstep--;
				}
				if(e.di<4)
				{
					e.di++;
					z.push(e);
					curpos=NextPos(e.seat,e.di);
				}
			}
		}
	}while(!z.empty());
	if(!z.empty())
	{
		printf("success!");
		while(!z.empty())
		{
			e=z.top();
			z.pop();
			t.push(e);
		}
		printf("\nscz:\n");
		while(!t.empty())
		{
			e=t.top();
			printf("%2d-(%d,%d)-%d\n",e.ord,e.seat.y,e.seat.x,e.di);
			t.pop();
		}
	}
	else
		printf("no success!");
}
int main()
{
	int maze[M][N]={
		{1,1,1,1,1,1,1},
		{1,0,0,0,1,0,1},
		{1,0,1,1,1,0,1},
		{1,0,0,0,0,0,1},
		{1,0,1,0,1,1,1},
		{1,0,0,0,0,0,1},
		{1,1,1,1,1,1,1}
		};
	MazePath(maze);
}
