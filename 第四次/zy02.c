#include <stdio.h>
#include <stdlib.h>

#define ini_size 100
#define increment 10

typedef struct {
    int *base;
    int front;
    int rear;
    int size;
} sqqueue;

int ini(sqqueue *q) {
    q->base = (int *) malloc(ini_size * sizeof(int));
    if (!q->base) {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
    q->front = q->rear = 0;
    q->size = ini_size;
    return 1;
}

void destory(sqqueue *q) {
    free(q->base);
    q->base = NULL;
}

void clear(sqqueue *q) {
    q->front = q->rear = 0;
    printf("��������ա�\n");
}

int ifempty(sqqueue *q) {
    return (q->front == q->rear) ? 1 : 0;
}

int length(sqqueue *q) {
    return (q->rear - q->front + q->size) % q->size;
}

int getfront(sqqueue *q, int *e) {
    if (ifempty(q)) {
        printf("����Ϊ�գ��޷���ȡ��ͷԪ�ء�\n");
        return 0;
    }
    *e = q->base[q->front];
    printf("��ͷԪ��Ϊ��%d\n", *e);
    return 1;
}

int dequeue(sqqueue *q, int *e) {
    if (ifempty(q)) {
        printf("����Ϊ�գ��޷����г����в�����\n");
        return 0;
    }
    *e = q->base[q->front];
    q->front = (q->front + 1) % q->size;
    printf("����Ԫ��Ϊ��%d\n", *e);
    return 1;
}

int enqueue(sqqueue *q, int e) {
    if ((q->rear + 1) % q->size == q->front) {
        int *newbase = (int *) realloc(q->base, (q->size + increment) * sizeof(int));
        if (!newbase) {
            printf("�ڴ����ʧ�ܣ��޷���������в�����\n");
            return 0;
        }
        q->base = newbase;
        if (q->rear < q->front) {
            int i;
            for (i = q->rear; i < q->size; i++) {
                q->base[i + q->size] = q->base[i];
            }
            q->rear += q->size;
        }
        q->size += increment;
        printf("���������ݡ�\n");
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % q->size;
    printf("���Ԫ��Ϊ��%d\n", e);
    return 1;
}

void queuetraverse(sqqueue *q) {
    if (ifempty(q)) {
        printf("����Ϊ�գ��޷����ж��б���������\n");
        return;
    }
    printf("����Ԫ��Ϊ��");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf(" %d", q->base[i]);
    }
    printf("\n");
}

void main() {
    int i, e;
    sqqueue q;
    ini(&q);
    printf("�����ѳ�ʼ��Ϊһ���ն��С�\n");
    for (i = 9; i >=1 ; i--) {
        enqueue(&q, i);
    }
    printf("ԭʼ����Ϊ:\n");
    queuetraverse(&q);
    printf("���еĳ���Ϊ: %d\n", length(&q));
    getfront(&q, &e);
    printf("ִ�л�ȡ��ͷԪ�ز�����");
    printf("���еĳ���Ϊ: %d\n", length(&q));
    printf("������:\n");
    while (!ifempty(&q)) {
        dequeue(&q, &e);
    }
    clear(&q);
    destory(&q);
    printf("���������١�\n");
}
