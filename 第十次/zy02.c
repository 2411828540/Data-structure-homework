#include <stdio.h>

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) 
	{
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  
        }
        if (target < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;  
}

int main() {
    int arr[] = {5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n, index;
    printf("������Ҫ���ҵ����֣�");
    scanf("%d", &n);
    index = binary_search(arr, 0, 10, n);
    if (index >= 0) {
        printf("���� %d �������е�λ���ǣ�%d\n", n, index + 1);
    } else {
        printf("���� %d û���������г��ֹ���\n", n);
    }
    return 0;
}
