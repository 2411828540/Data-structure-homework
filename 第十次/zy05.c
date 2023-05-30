#include <stdio.h>

void shell_sort(int arr[], int n)
 {
    int gap = n / 2;  // ��ʼ������Ϊ���鳤�ȵ�һ��
    while (gap > 0) 
	{
        for (int i = gap; i < n; i++)
		 {
            int temp = arr[i];
            int j = i - gap;    //�ڵ�ǰ������
           		while (j >= 0 && arr[j] > temp) 
				{
                	arr[j + gap] = arr[j];
                	j -= gap;
            	}
            arr[j + gap] = temp;
        }
        gap /= 2;  // ��С����
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("����ǰ�����У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    shell_sort(arr, n);
    printf("\n���������У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
