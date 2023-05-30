#include <stdio.h>

void insertion_sort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
	{
        int j = i;
        int temp = arr[j];  //�������ǰ��С�ģ������źõ�����������С�ͻ�
        while (j > 0 && temp < arr[j - 1]) 
		{
            arr[j] = arr[j - 1];  // ��������Ԫ�����κ���
            j--;
        }
        arr[j] = temp;  // ��������Ԫ�ز��뵽��ȷ��λ��
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("����ǰ�����У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertion_sort(arr, n);
    printf("\n���������У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
