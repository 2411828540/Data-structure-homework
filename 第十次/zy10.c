#include <stdio.h>
#include <stdlib.h>

// ��ȡ����������ֵ
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ��������л�������
void radixSort(int arr[], int n) {
    // ��ȡ��������������ȷ���������
    int max = getMax(arr, n);
    
    // �Ӹ�λ��ʼ�������鰴λ��������
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n]; // ��ʱ�洢�����Ľ��
        int count[10] = {0}; // �洢ÿ�����ֳ��ֵĴ���
        
        // ͳ��ÿ�����ֳ��ֵĴ���
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // ����ÿ������������λ��
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // �����ְ���������λ�ô洢�����������
        // ע�⣺����Ӻ���ǰ����ԭʼ������Ϊ�˱�֤������ȶ���
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // �������Ľ�����ƻ�ԭʼ������
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// ����
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("����ǰ�����飺");
	for (int i = 0; i < n; i++) {
	    printf("%d ", arr[i]);
	}
    
    // ��������л�������
    radixSort(arr, n);
    
    printf("\n���������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
