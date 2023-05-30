#include <stdio.h>

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;  // �ݹ��������

    int i = left, j = right, pivot = arr[left];  // ��׼Ԫ��ȡ����ߵ�Ԫ��
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;  // ���������ҵ���һ��С�ڻ�׼Ԫ�ص�λ��
        if (i < j) arr[i++] = arr[j];

        while (i < j && arr[i] <= pivot) i++;  // ���������ҵ���һ�����ڻ�׼Ԫ�ص�λ��
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;  // ����׼Ԫ�ع�λ

    quick_sort(arr, left, i - 1);   // ����������н��еݹ����
    quick_sort(arr, i + 1, right);  // ���Ҳ������н��еݹ����
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("����ǰ�����У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\n���������У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
