#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VEXNUM 9
#define INF 9999   //�����
int visited[VEXNUM];
struct Graph{//ͨ��ͼ�ζ���,���ڴ���ͼ�ε��ڽӾ�����ڽӱ�-ȫ�ֱ���
    int vexnum,arcnum,kind;//��������������ͼ���ͣ�1234-����ͼ������ͼ����������������
    char vexs[VEXNUM+1];   //�����ַ�����
    int arcs[30];          //����ֹ���±꼰Ȩֵ����
} graph={8,10,1,"ABCDEFGH",{0,1,0,0,2,0,0,5,0,1,3,0,2,6,0,3,4,0,3,6,0,5,6,0,5,7,0,6,7,0}};
//8�����㡢10���ߡ�����������������ΪABCDEFGH
//A-D,A-C,A-F,B-D,C-G,D-E,D-G,F-G,F-H,G-H
struct MGraph_Mat{//ͼ���ڽӾ���洢���ݶ���
    int vexnum,arcnum;     //������������
    char vexs[VEXNUM];     //��������
    int arcs[VEXNUM][VEXNUM];//�ڽӾ���
    int kind;              //ͼ����
};
struct arcnode{//�ڽӱ�-�߽��
    int adjvex,weight;//�ڽӱ��±ꡢȨֵ
    struct arcnode *nextarc; //��һ�߱�ָ��
};
struct vexnode{//������
    char vexdata;     //�����ַ�����
    struct arcnode *firstarc;//��һ���߱�ָ��
};
struct MGraph_Adj{//ͼ���ڽӱ�洢���ݶ���
    int vexnum,arcnum;//������������
    struct vexnode vexarr[VEXNUM];//����������
    int kind;         //ͼ����
};
void create_Mat(struct MGraph_Mat *g){      //����ͼ���ڽӾ���
    int i,j;
    g->vexnum=graph.vexnum;//������
    g->arcnum=graph.arcnum;//����
    g->kind=graph.kind;    //ͼ���ͣ�1234-����ͼ������ͼ����������������	
    for(i=0;i<=g->vexnum-1;i++)
        g->vexs[i]=graph.vexs[i];//�����ֵ�����ַ�
    for(i=1;i<=g->vexnum;i++)
	{
        for(j=1;j<=g->vexnum;j++)
		{							//������ͼ
                g->arcs[i-1][j-1]=0;  //�ڽӾ���ȫ����ʼֵΪ0
        }
    }
    for(i=0;i<=g->arcnum-1;i++)
	{								//����ͼ,һ���ߴ����������Ԫ��,��1
            g->arcs[graph.arcs[i*3]][graph.arcs[i*3+1]]=1;
            g->arcs[graph.arcs[i*3+1]][graph.arcs[i*3]]=1;//�ԳƵ�
        
    }
}
void create_Adj(struct MGraph_Adj *g){//����ȫ��ͨ��ͼ�ζ���graph������ͼ���ڽӱ�
    int i;
    struct arcnode *p=NULL;
    g->vexnum=graph.vexnum;//������
    g->arcnum=graph.arcnum;//����
    g->kind=graph.kind;//ͼ���ͣ�1234-����ͼ������ͼ����������������	
    for(i=0;i<=g->vexnum-1;i++){
        g->vexarr[i].vexdata=graph.vexs[i];//������㸳ֵ-�����ַ�
        g->vexarr[i].firstarc=NULL;//��һ���߳�ʼֵ�ÿ�
    }
    for(i=0;i<=g->arcnum-1;i++){//�����ߴ����߱���	
        p=(struct arcnode *)(malloc(sizeof(struct arcnode)));//����߱�ռ�
        p->adjvex=graph.arcs[i*3+1];//�߽��-���±�
        p->weight=graph.arcs[i*3+2];//�߽��-Ȩֵ
        p->nextarc=g->vexarr[graph.arcs[i*3]].firstarc;
        g->vexarr[graph.arcs[i*3]].firstarc=p;//��p��������ָ������֮��-ǰ��
        if(g->kind==1){//����������ͼ�����ٴ���һ�����		
            p=(struct arcnode *)(malloc(sizeof(struct arcnode)));
            p->adjvex=graph.arcs[i*3];//�߽��-���±�
            p->nextarc=g->vexarr[graph.arcs[i*3+1]].firstarc;
            g->vexarr[graph.arcs[i*3+1]].firstarc=p;//��p��������ָ������֮��-ǰ��
        }
    }
}
void print_Mat(struct MGraph_Mat g)
{									//��ʾ�ڽӾ���
    int i,j;
    printf("  ");
    for(i=0;i<=g.vexnum-1;i++)
        printf("%3c",g.vexs[i]);//��ʾ��һ��,���ڵ��ַ�
    printf("\n");
    for(i=0;i<=g.vexnum-1;i++)
	{								//����	
        printf("  %c  ",g.vexs[i]);//����ʾ�ַ�
        for(j=0;j<=g.vexnum-1;j++)
		{									//����		
            if(g.kind==1||g.kind==2)//ͼ
                printf("%d  ",g.arcs[i][j]);//��ʾ1��0
		}
        printf("\n");
    }
}
void print_Adj(struct MGraph_Adj g){//��ʾ�ڽӱ�
    int i;
    struct arcnode *p=NULL;
    printf("\n\n");
    for(i=0;i<=g.vexnum-1;i++){//���������	
        printf("  %d %c",i,g.vexarr[i].vexdata);//�±ꡢ�����ַ�
        p=g.vexarr[i].firstarc;//pָ���һ���߱���
        while(p){//����߱���ʾ		
            if(g.kind==1||g.kind==2)//�����ͼֻ��ʾ�����
                printf("->%d",p->adjvex);
            p=p->nextarc;//��һ�߱�
        }
        printf("\n");
    }
}
void BFS_Mat(struct MGraph_Mat g,int v) //������ȵݹ���
{
	int Lq[VEXNUM],i,j,f=0,r=0;
	printf("%c",g.vexs[v]);
	visited[v]=1;
	Lq[r++]=v;
	while(r!=f)
	{
		i=Lq[f++];
		for(j=0;j<=g.vexnum-1;j++)
		{
			if(g.arcs[i][j]!=0&&g.arcs[i][j]!=INF&&visited[j]==0)
			{
				printf(" %c ",g.vexs[j]);
				visited[j]=1;
				Lq[r++]=j;
			}
		}
	}
}
void BFSTraverse_Mat(struct MGraph_Mat g,int v) //���
{
	int i;
	memset(visited,0,sizeof(visited));
	printf("\n�ڽӾ�����������������");
	for(i=v;i<g.vexnum;i++)
		if(visited[i%g.vexnum]==0)
			BFS_Mat(g,i%g.vexnum);
}
void DFS_Mat(struct MGraph_Mat g,int v)
{
	int i;
	printf(" %c ",g.vexs[v]);
	visited[v]=1;
	for(i=0;i<=g.vexnum-1;i++)
	{
		if(g.arcs[v][i]!=0&&g.arcs[v][i]!=INF&&visited[i]==0)
			DFS_Mat(g,i);
	}
}
void DFSTraverse_Mat(struct MGraph_Mat g,int v)
{
	int i;
	memset(visited,0,sizeof(visited));
	printf("\n�ڽӾ������������������");
	for(i=v;i<g.vexnum+v-1;i++)
	{
		if(visited[i%g.vexnum]==0)
			DFS_Mat(g,i%g.vexnum);
	}
}

int main(){
    struct MGraph_Mat g;
    struct MGraph_Adj g1;
    create_Mat(&g);
    create_Adj(&g1);
    print_Mat(g);
	print_Adj(g1);
    DFSTraverse_Mat(g,3);
	BFSTraverse_Mat(g,3);
    
}
