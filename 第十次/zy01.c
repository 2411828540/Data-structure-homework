#include "stdlib.h"
#include "stdio.h"
int search(int arr[], int n) 
{
    for (int i = 0; i < 11; i++)
	{
        if (arr[i] == n) 
		{
			printf("�ڵ�%d��λ��",i);
            return 1;  
        }
    }
    return 0; 
}
int main()
{
	int arr[11]={15,13,19,21,37,56,64,75,80,88,92},pos,n;
	printf("����������\n");
	scanf("%d",&n);
	pos=search(arr,n);
	if(pos)
	{
		printf("�ҵ���");
	}
	else{
		printf("û�ҵ�");
	}
	return 0;
}
