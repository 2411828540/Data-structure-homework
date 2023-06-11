#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 20
//ע����һ���������赼����Ϣ��ֱ�Ӳ�����Ŀ���ɣ��˳�ʱ��ʹ��ѡ�� 7 ������Ϣ���ٴ�ʹ��ʱ��ʹ��ѡ�� 8 �����ϴ���Ϣ
typedef struct Student {
    int id;
    int nums;
    char type[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    int score;
    struct Student* next;
} Student;
//�����Ŀ
void add(Student** head_ptr) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new_student->next = NULL;
    printf("��������Ŀ����: ");
    scanf("%s", new_student->type);
    printf("��������Ŀid: ");
    scanf("%d", &new_student->id);
    printf("��������Ŀ����: ");
    scanf("%s", new_student->name);
    printf("��������Ŀ��ֵ: ");
    scanf("%d", &new_student->score);
    printf("��������Ŀ�������: ");
    scanf("%d", &new_student->nums);
    if (*head_ptr == NULL) {
        *head_ptr = new_student;
    } else {
        Student* current = *head_ptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }

    printf("CTF��Ŀ��ӳɹ�.\n");
}
//����
void sort(Student** head, int choice) {
    if (*head == NULL) {
        printf("����Ϊ��\n");
        return;
    }

    switch (choice) {
        case 1: // ���շ�ֵ��С��������
            Student *current, *index;
            for (current = *head; current->next != NULL; current = current->next) {
                for (index = current->next; index != NULL; index = index->next) {
                    if (current->score > index->score) {
                        int temp_score = current->score;
                        current->score = index->score;
                        index->score = temp_score;

                        int temp_nums = current->nums;
                        current->nums = index->nums;
                        index->nums = temp_nums;

                        int temp_id = current->id;
                        current->id = index->id;
                        index->id = temp_id;

                        char temp_type[MAX_NAME_LEN];
                        strcpy(temp_type, current->type);
                        strcpy(current->type, index->type);
                        strcpy(index->type, temp_type);

                        char temp_name[MAX_NAME_LEN];
                        strcpy(temp_name, current->name);
                        strcpy(current->name, index->name);
                        strcpy(index->name, temp_name);
                    }
                }
            }
            printf("���շ�ֵ�������.\n");
            break;
        case 2: // ���ս��������С��������
			Student *curren1, *index1;
            for (curren1 = *head; curren1->next != NULL; curren1 = curren1->next) {
                for (index1 = curren1->next; index1 != NULL; index1 = index1->next) {
                    if (curren1->nums > index1->nums) {
                        int temp_nums = curren1->nums;
                        curren1->nums = index1->nums;
                        index1->nums = temp_nums;

                        int temp_score = curren1->score;
                        curren1->score = index1->score;
                        index1->score = temp_score;

                        int temp_id = curren1->id;
                        curren1->id = index1->id;
                        index1->id = temp_id;

                        char temp_type[MAX_NAME_LEN];
                        strcpy(temp_type, curren1->type);
                        strcpy(curren1->type, index1->type);
                        strcpy(index1->type, temp_type);

                        char temp_name[MAX_NAME_LEN];
                        strcpy(temp_name, curren1->name);
                        strcpy(curren1->name, index1->name);
                        strcpy(index1->name, temp_name);
                    }
                }
            }
            printf("���ս�������������.\n");
            break;
        default:
            printf("��Ч��ѡ��\n");
    }
}

//ɾ����Ŀ
void delete_student(Student** head_ptr, int id) {
    if (*head_ptr == NULL) {
        printf("��Ŀδ�ҵ�.\n");
        return;
    }

    if ((*head_ptr)->id == id) {
        // The head is the student to delete
        Student* temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(temp);
        printf("�ѳɹ�ɾ����Ŀ\n");
        return;
    }

    // Traverse the list to find the student to delete
    Student* prev = *head_ptr;
    Student* current = (*head_ptr)->next;
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("��Ŀδ�ҵ�\n");
        return;
    }

    // Delete the student
    prev->next = current->next;
    free(current);
    printf("�ѳɹ�ɾ����Ŀ\n");
}

void modify_student(Student* head) {
    int id, choice,new_nums,new_score;

    printf("������Ҫ�޸���ĿID��: ");
    scanf("%d", &id);

    // Find the student to modify
    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("��Ŀδ�ҵ�\n");
        return;
    }

    // Modify the student's details
    printf("1. ����\n");
    printf("2. ��ֵ\n");
    printf("3. ����\n");
    printf("4. �������\n");
    printf("��������Ҫ�޸ĵ�ѡ�:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("���µ����ơ�: ");
            scanf("%s", current->name);
            break;
        case 2:
            printf("���µķ�ֵ��: ");
            scanf("%d", &new_score);
            current->score = new_score;
            break;
        case 3:
            printf("���µķ���: ");
            scanf("%s", current->type);
            break;
        case 4:
            printf("���µĽ�����: ");
            scanf("%d", &new_nums);
            current->nums = new_nums;
            break;        
        default:
            printf("**ѡ����Ч**\n");
            return;
    }

    printf("\n��Ŀ�޸ĳɹ�\n");
}
//����
int find(Student* head, int id) {
    // Traverse the list to find the student
    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    } else {
    	printf("�����ҵ���Ŀ��ϢΪ��\n");
        printf("\n����[%s],����[%s],��ֵ[%d],�������[%d]\n", current->type, current->name, current->score,current->nums);
        return 1;
    }
}
//���
void display(Student* head) {
    if (head == NULL) {
        printf("No students to display.\n");
    } else {
    	printf("|----------|----|----------|----------|----------|\n");
        printf("|%-10s|%-4s|%-10s|%-10s|%-10s|\n", "����", "ID", "����", "����", "�������");
        printf("|----------|----|----------|----------|----------|\n");

        // Traverse the list and print each student
        Student* current = head;
        while (current != NULL) {
            printf("|[%-8s]|%4d|%-10s|%-10d|%-10d|\n", current->type,current->id, current->name, current->score,current->nums);
            current = current->next;
        }
        printf("|----------|----|----------|----------|----------|\n");
    }
}
void save_link(Student* head) {
    FILE* fp;
    fp = fopen("ctf.txt", "w");
    if (fp == NULL) {
        printf("File open error!\n");
        exit(1);
    }

    Student* p = head;
    while (p != NULL) {
        fwrite(p, sizeof(*p), 1, fp);
        p = p->next;
    }

    fclose(fp);
    printf("CTF��Ŀ�ѳɹ����浽�ļ��С�\n");
}

void load_link(Student** head) {
    FILE* fp;
    fp = fopen("ctf.txt", "rb");
    if (fp == NULL) {
        printf("File open error!\n");
        exit(1);
    }

    Student temp;
    while (fread(&temp, sizeof(temp), 1, fp) != 0) {
        Student* new_node = (Student*)malloc(sizeof(Student));
        if (new_node == NULL) {
            printf("Memory allocation error!\n");
            exit(1);
        }

        memcpy(new_node, &temp, sizeof(temp));
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
        } else {
            Student* p = *head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new_node;
        }
    }

    fclose(fp);
    printf("CTF��Ŀ�Ѵ��ļ��м��ء�\n");
}

int main() {
    Student* head = NULL;
    int choice, id,cho;

    while (1) {
    	printf("\n		******��ӭʹ��CTF��Ŀ����ϵͳ******\n");
    	printf("                  	�����o�ޡ�");
    	printf("\n			***ѡ������***\n");
        printf("\n			|��1�������Ŀ|\n");
        printf("			|��2��ɾ����Ŀ|\n");
        printf("			|��3���޸���Ŀ|\n");
        printf("			|��4��������Ŀ|\n");
        printf("			|��5����Ŀ����|\n");
        printf("			|��6��������Ŀ|\n");
        printf("			|��7��������Ϣ|\n");
        printf("			|��8����ȡ��Ϣ|\n");
        printf("			|��9���˳�����|\n");
        printf("��������ѡ�: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(&head);
                break;
            case 2:
                printf("��������Ŀid: ");
                scanf("%d", &id);
                delete_student(&head, id);
                break;
            case 3:
                modify_student(head);
                break;
            case 4:
                printf("��������Ŀid: ");
                scanf("%d", &id);
                if (find(head, id)) {
                    printf("\n*****���ҳɹ�*****\n");
                } else {
                    printf("\n��Ŀ������Ŷ\n");
                }
                break;
            case 6:
                display(head);
                break;
            case 5:
                printf("����������ʽ��\n1����ֵ\n2���������\n");
                scanf("%d",&cho);
                sort(&head,cho);
                break;
            case 7:
            	save_link(head);
            	break;
            case 8:
            	load_link(&head); 
				break;           
            case 9:
                printf("��ӭ�������߲���:https://blog.byzhb.top\n");
                return 0;
            default:
                printf("ѡ��������������룡\n");
        }
    }
}
