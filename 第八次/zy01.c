#include "stdio.h"
void main()
{
	int a[100],n,i,j,k=1,max,he=0,cc=1,maxcc=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d,",&a[i]);
	max=a[0];
	i=0;
	while(i<=n-1)
	{
		he=0;
		for(j=1;j<=k&&i<=n-1;j++) //�ӱ���
			he=he+a[i++];  //���ú��
		if(he>max)
		{
			max=he;
			maxcc=cc;
		}
		k=k*2;
		cc++; //ccһֱΪ��ǰ���
	}
	printf("�����%d,����κ�%d\n",maxcc,max);
}
