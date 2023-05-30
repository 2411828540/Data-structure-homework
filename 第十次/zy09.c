#include <stdio.h>

// �ϲ�����������������
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // ������ʱ����
    int left_arr[n1], right_arr[n2];
    
    // �����ݸ��Ƶ���ʱ������
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];
    
    // �ϲ���ʱ�����е�Ԫ�ص�ԭ������
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    
    // ��δ�ϲ���ʣ��Ԫ�ظ��Ƶ�ԭ������
    while (i < n1) {
        arr[k] = left_arr[i];
        i++, k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++, k++;
    }
}

// �鲢����ݹ麯��
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // �ָ�
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        
        // �ϲ�
        merge(arr, left, mid, right);
    }
}

// ����
int main() {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6},q;
    printf("����ǰ�����У�");
    for(q=0;q<9;q++)
    {
		printf("%d ",arr[q]);
	}
	printf("\n");
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    merge_sort(arr, 0, n - 1);
    
    printf("����������: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
