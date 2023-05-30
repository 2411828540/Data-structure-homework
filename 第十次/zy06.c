#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;  // ��Ǳ����Ƿ����˽���
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;  // �������û�з������������Ѿ����򣬿�����ǰ����
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("����ǰ�����У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    bubble_sort(arr, n);
    printf("\n���������У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
