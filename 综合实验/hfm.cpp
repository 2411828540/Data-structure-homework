#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
struct head {
	unsigned char b;	//��¼�ַ������������λ��
	long count;		//�ַ���Ȩֵ
	long parent, lch, rch;	//�����������ָ�����
	char bits[256];	//����洢���������������
} header[512], tmp;
void quick_sort(int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    struct head pivot = header[left];
    while (i < j) {
        while (i < j && header[j].count <= pivot.count) j--;
        header[i] = header[j];
        while (i < j && header[i].count >= pivot.count) i++;
        header[j] = header[i];
    }
    header[i] = pivot;
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}
void quick_sort2(int left, int right) {
	int i = left, j = right;
	int pivot = strlen(header[(left + right) / 2].bits);
	struct head tmp;
	while (i <= j) {
	while (strlen(header[i].bits) < pivot) i++;
	while (strlen(header[j].bits) > pivot) j--;
	if (i <= j) {
	tmp = header[i];
	header[i] = header[j];
	header[j] = tmp;
	i++; j--;
	}
}
if (left < j) quick_sort2(left, j);
if (i < right) quick_sort2(i, right);
}
void compress() {
	char filename[255], outputfile[255], buf[512];
	unsigned char c;
	long i, j, m, n, f;
	long min1, pt1, flength;
	FILE *ifp, *ofp;
	printf(" ���������ѹ���ļ�·����");
	scanf("%s", filename);
	ifp = fopen(filename, "rb");
	if (ifp == NULL) {
		printf("\n �ļ���ʧ��!\n\n");
		return;
	}
	printf(" ��������ѹ������ļ�����");
	scanf("%s", outputfile);
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL) {
		printf("\n ѹ���ļ�ʧ��!\n\n");
		return;
	}
	flength = 0;
	while (!feof(ifp)) {
		fread(&c, 1, 1, ifp);
		header[c].count++;    //�ַ��ظ�����Ƶ��+1
		flength++;            //�ַ�����ԭ�ļ�����+1
	}
	flength--;
	header[c].count--;
	for (i = 0; i < 512; i++) {
		if (header[i].count != 0) 
			header[i].b = (unsigned char)i;
		//��ÿ����������ֵ�����Ӧ��ASCII������һά����header[i]�У��ұ�����е��±��ASCII������˳���Ź�ϵ
		else header[i].b = 0;
		header[i].parent = -1;
		header[i].lch = header[i].rch = -1; //����ʼ��
	}
	quick_sort(0, 255);//��������
	for (i = 0; i < 256; i++) 
		if (header[i].count == 0) 
			break;
	n = i;     //�ⲿҶ�ӽ����Ϊn��ʱ���ڲ������Ϊn-1������������������Ҫ�Ľ����Ϊ2*n-1.
	m = 2 * n - 1;
	for (i = n; i < m; i++) { //������������
		min1 = 999999999; //Ԥ������Ȩֵ���������ֵ�������
		for (j = 0; j < i; j++) {
			if (header[j].parent != -1) continue;
			//parent!=-1˵���ý���Ѵ��ڹ��������У�����ѭ������ѡ���½��*/
			if (min1 > header[j].count) {
				pt1 = j;
				min1 = header[j].count;
				continue;
			}
		}
		header[i].count = header[pt1].count;
		header[pt1].parent = i; //����parent��ֵ����������ȷ�����н��֮��Ĺ�ϵ
		header[i].lch = pt1; //�������֧Ȩֵ��С
		min1 = 999999999;
		for (j = 0; j < i; j++) {
			if (header[j].parent != -1) continue;
			if (min1 > header[j].count) {
				pt1 = j;
				min1 = header[j].count;
				continue;
			}
		}
		header[i].count += header[pt1].count;
		header[i].rch = pt1; //�����ҷ�֧Ȩֵ��С
		header[pt1].parent = i;
	}
	for (i = 0; i < n; i++) { //���������ظ�ǰ׺����
		f = i;
		header[i].bits[0] = 0; //��������0
		while (header[f].parent != -1) {
			j = f;
			f = header[f].parent;
			if (header[f].lch == j) { //�����֧����0
				j = strlen(header[i].bits);
				memmove(header[i].bits + 1, header[i].bits, j + 1);
				//���δ洢���ӡ�0����1������
				header[i].bits[0] = '0';
			} else { //���ҷ�֧����1
				j = strlen(header[i].bits);
				memmove(header[i].bits + 1, header[i].bits, j + 1);
				header[i].bits[0] = '1';
			}
		}
	}
	fseek(ifp, 0, SEEK_SET); //���ļ���ʼλ����ǰ�ƶ�0�ֽڣ�����λ���ļ���ʼλ��
	fwrite(&flength, sizeof(int), 1, ofp);
	fseek(ofp, 8, SEEK_SET);
	buf[0] = 0; //���建����,���Ķ����Ʊ�ʾ
	f = 0;
	pt1 = 8;
	while (!feof(ifp)) {
		c = fgetc(ifp);
		f++;
		for (i = 0; i < n; i++) {
			if (c == header[i].b) break;
		}
		strcat(buf, header[i].bits);
		j = strlen(buf);
		c = 0;
		while (j >= 8) { //�Թ���������λ��������ѹ���洢
			for (i = 0; i < 8; i++) {
				if (buf[i] == '1') c = (c << 1) | 1;
				else c = c << 1;
			}
			fwrite(&c, 1, 1, ofp);
			pt1++;   //ͳ��ѹ�����ļ��ĳ���
			strcpy(buf, buf + 8); //һ���ֽ�һ���ֽ�ƴ��
			j = strlen(buf);
		}
		if (f == flength) break;
	}
	if (j > 0) { //�Թ���������λ��������ѹ���洢
		strcat(buf, "00000000");
		for (i = 0; i < 8; i++) {
			if (buf[i] == '1') c = (c << 1) | 1;
			else c = c << 1;
		}
		fwrite(&c, 1, 1, ofp);
		pt1++;
	}
	fseek(ofp, 4, SEEK_SET);
	fwrite(&pt1, sizeof(long), 1, ofp);
	fseek(ofp, pt1, SEEK_SET);
	fwrite(&n, sizeof(long), 1, ofp);
	for (i = 0; i < n; i++) {
		fwrite(&(header[i].b), 1, 1, ofp);
		c = strlen(header[i].bits);
		fwrite(&c, 1, 1, ofp);
		j = strlen(header[i].bits);
		if (j % 8 != 0) { //���洢��λ������8�ı�������0
			for (f = j % 8; f < 8; f++)
				strcat(header[i].bits, "0");
		}
		while (header[i].bits[0] != 0) {
			c = 0;
			for (j = 0; j < 8; j++) { //�ַ�����Ч�洢������8λ�������Чλ������ʵ�����ַ����������
				if (header[i].bits[j] == '1') c = (c << 1) | 1; //|1���ı�ԭλ���ϵġ�0����1��ֵ
				else c = c << 1;
			}
			strcpy(header[i].bits, header[i].bits + 8); //���ַ��ı��밴ԭ�ȴ洢˳������
			fwrite(&c, 1, 1, ofp);
		}
	}
	fclose(ifp);
	fclose(ofp);
	printf("\n ѹ���ļ��ɹ�!\n");
	return;
}
//��ѹ
void uncompress() {
	char filename[255], outputfile[255], buf[255], bx[255];
	unsigned char c;
	long i, j, m, n, f, p, l;
	long flength;
	FILE *ifp, *ofp;
	printf(" ����������Ҫ��ѹ�����ļ�·����");
	scanf("%s",filename);
	ifp = fopen(filename, "rb");
	if (ifp == NULL) {
		printf("\n �ļ���ʧ��!\n");
		return;
	}
	printf(" ���������ѹ������ļ�����");
	scanf("%s",outputfile);
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL) {
		printf("\n ��ѹ���ļ�ʧ��!\n");
		return;
	}
	fread(&flength, sizeof(long), 1, ifp); //��ȡԭ�ļ����ȣ����ļ����ж�λ
	fread(&f, sizeof(long), 1, ifp);
	fseek(ifp, f, SEEK_SET);
	fread(&n, sizeof(long), 1, ifp);
	for (i = 0; i < n; i++) {
		fread(&header[i].b, 1, 1, ifp);
		fread(&c, 1, 1, ifp);
		p = (long)c; //��ȡԭ�ļ��ַ���Ȩֵ
		header[i].count = p;
		header[i].bits[0] = 0;
		if (p % 8 > 0) m = p / 8 + 1;
		else m = p / 8;
		for (j = 0; j < m; j++) {
			fread(&c, 1, 1, ifp);
			f = c;
			itoa(f, buf, 2); //��fת��Ϊ�����Ʊ�ʾ���ַ���
			f = strlen(buf);
			for (l = 8; l > f; l--) {
				strcat(header[i].bits, "0");
			}
			strcat(header[i].bits, buf);
		}
		header[i].bits[p] = 0;
	}
	quick_sort2(0, n - 1);
	p = strlen(header[n - 1].bits);
	fseek(ifp, 8, SEEK_SET);
	m = 0;
	bx[0] = 0;
	while (1) { //ͨ������������ĳ��̣����ν��룬��ԭ����λ�洢��ԭ���ֽڴ洢
		while (strlen(bx) < (unsigned int)p) {
			fread(&c, 1, 1, ifp);
			f = c;
			itoa(f, buf, 2);
			f = strlen(buf);
			for (l = 8; l > f; l--) { //�ڵ��ֽ��ڶ���Ӧλ�ò�0
				strcat(bx, "0");
			}
			strcat(bx, buf);
		}
		for (i = 0; i < n; i++) {
			if (memcmp(header[i].bits, bx, header[i].count) == 0)break;
		}
		strcpy(bx, bx + header[i].count);   /*��ѹ���ļ��еİ�λ�洢��ԭ�����ֽڴ洢�ַ���
           �ַ�λ�ò��ı�*/
		c = header[i].b;
		fwrite(&c, 1, 1, ofp);
		m++;   //ͳ�ƽ�ѹ�����ļ��ĳ���
		if (m == flength) break; //flength��ԭ�ļ�����
	}
	fclose(ifp);
	fclose(ofp);
	printf("\n ��ѹ���ļ��ɹ�!\n");
	return;
}

int main() {
	int c;
	printf("****��ӭʹ�û��ڹ���������Ľ�ѹ������****\n");
	printf("��ѡ����:\n	|1.ѹ��|\n	|2.��ѹ|\n	|0.�˳�|\n");
	scanf("%d",&c);
	while (c) {
		if (c == 1) 
		{
			compress(); 
		}	
		else if (c == 2) 
		{
			uncompress();
		}
		else
		{
			printf("ѡ�����,����������:");
			scanf("%d",&c);
		}
		printf("�����ѡ�����:");
		scanf("%d",&c);
	}
	printf("\n��ӭ�´�ʹ�ã�");
	return 0;
}
