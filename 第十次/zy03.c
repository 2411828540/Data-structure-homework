#include <stdio.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i; 
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[min_index]) {
                min_index = j;  
            }
        }//ѭ������С�±�        ���������ұ�����С�ģ����С�ͻ�
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;// ��δ���򲿷ֵ���СԪ�ؽ����������򲿷ֵ�ĩβ
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("����ǰ�����У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    selection_sort(arr, n);
    printf("\n���������У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
