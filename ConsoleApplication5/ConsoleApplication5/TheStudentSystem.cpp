#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <process.h>
#define n 2//ѧУ��Ŀ
#define m 1//������Ŀ��Ŀ
#define w 1//Ů����Ŀ��Ŀ
#define null 0
typedef struct
{
	int itemnum; //��Ŀ���
	int top; //ȡ���ε���Ŀ
	int range[5]; //����
	int mark[5]; //����
}itemnode; //������Ŀ��������
typedef struct
{
	int schoolnum; //ѧУ���
	int score; //ѧУ�ܷ�
	int mscore; //�������ܷ�
	int wscore; //Ů�����ܷ�
	itemnode c[m + w]; //��Ŀ����
}headnode;//����ͷ�������
headnode h[n];//����һ��ͷ�������
void inputinformation() //������Ϣ������ϵͳ
{
	int i, j, k, s;
	for (i = 0;i<n;i++)
	{
		h[i].score = 0;
		h[i].mscore = 0;
		h[i].wscore = 0;
	}
	for (i = 0;i<n;i++)
	{
		printf("*****ѧУ���:");
		scanf_s("%d", &h[i].schoolnum);
		for (j = 0;j<m + w;j++)
		{ //��ʼ��ͷ��� //����ͷ�����Ϣ
			printf("*****��Ŀ���:");
			scanf_s("%d", &h[i].c[j].itemnum);
			printf("*****ȡǰ3��orǰ5��:");
			scanf_s("%d", &h[i].c[j].top);

			printf("*****��ü������Σ�");
			scanf_s("%d", &k); //������Ŀ��Ϣ
			for (s = 0;s<5;s++)
				h[i].c[j].range[s] = 0, h[i].c[j].mark[s] = 0; //��ʼ�������ͷ���
			for (s = 0;s<k;s++)
			{
				printf("*****����:");
				scanf_s("%d", &h[i].c[j].range[s]); //��������������Ϣ
				if (h[i].c[j].top == 3)
					switch (h[i].c[j].range[s])
					{
					case 0: h[i].c[j].mark[s] = 0;
						break;
					case 1: h[i].c[j].mark[s] = 5;
						break;
					case 2: h[i].c[j].mark[s] = 3;
						break;
					case 3: h[i].c[j].mark[s] = 2;
						break;
					}
				else
					switch (h[i].c[j].range[s])
					{
					case 0: h[i].c[j].mark[s] = 0;
						break;
					case 1: h[i].c[j].mark[s] = 7;
						break;
					case 2: h[i].c[j].mark[s] = 5;
						break;
					case 3: h[i].c[j].mark[s] = 3; 
						break;
					case 4: h[i].c[j].mark[s] = 2;
						break;
					case 5: h[i].c[j].mark[s] = 1; 
						break;
					}
				h[i].score = h[i].score + h[i].c[j].mark[s];
				//��ȡǰ��������ȡǰ�����ֱ�Ƿ�
				if (j <= m - 1)
					h[i].mscore = h[i].mscore + h[i].c[j].mark[s];
				//��������Ŀ��ǵ����ӷ�������ȥ
				else
					h[i].wscore = h[i].wscore + h[i].c[j].mark[s];
				//��Ů����Ŀ��ǵ�Ů����Ŀ����ȥ
			}
			printf("\n");
		}

	}

}
void output() //�������
{
	int choice, i, j, k;

	int remember[n];
	int sign;
	do
	{
		printf("*******************1.��ѧУ������.*******************\n");
		printf("*******************2.��ѧУ�ܷ����.*******************\n");
		printf("*******************3.�������ܷ����.*******************\n");
		printf("*******************4.��Ů���ܷ����.*******************\n");
		printf("\n\n******************* ��ѡ����*************************\n\n:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: //�����˳�����
			for (i = 0;i < n;i++)
			{
				printf("\n\n*****ѧУ���:%d\n", h[i].schoolnum);
				printf("*****ѧУ�ܷ�:%d\n", h[i].score);
				printf("*****�����ܷ�:%d\n", h[i].mscore);
				printf("*****Ů���ܷ�: %d\n\n\n", h[i].wscore);
			}
			break;
		case 2:// ��ð�����򷽷����ø��������סͷ����±�
			for (i = 0;i < n;i++)
				remember[i] = i;
			for (i = 0;i < n;i++)
			{
				for (j = i + 1;j < n;j++)
					if (h[remember[i]].score < h[j].score)
						k = remember[i];
				remember[i] = remember[j], remember[j] = k;
			}
			for (i = 0;i < n;i++)
			{
				printf("\n\n*****ѧУ��ţ�%d\n", h[remember[i]].schoolnum); printf("*****ѧУ�ܷ�:%d\n", h[remember[i]].score);
				printf("*****�����ܷ�:%d\n", h[remember[i]].mscore);
				printf("*****Ů���ܷ�: %d\n\n\n", h[remember[i]].wscore);
				//�������±�˳�����
			} //��ѧУ�ܷ����
			break;
		case 3:
			for (i = 0;i < n;i++)
				remember[i] = i;
			for (i = 0;i < n;i++)
			{
				for (j = i + 1;j < n;j++)
					if (h[remember[i]].mscore < h[j].mscore)
						k = remember[i];remember[i] = remember[j];remember[j] = k;
			}
			for (i = 0;i < n;i++)
			{
				printf("\n\n*****ѧУ���:%d\n", h[remember[i]].schoolnum); printf("*****ѧУ�ܷ�:%d\n", h[remember[i]].score);
				printf("*****�����ܷ�:%d\n", h[remember[i]].mscore);
				printf("*****Ů���ܷ�: %d\n\n\n", h[remember[i]].wscore);
			} //�������ܷ���� break;
		case 4:
			for (i = 0;i < n;i++)
				remember[i] = i;
			for (i = 0;i < n;i++)
			{
				for (j = i + 1;j < n;j++)
					if (h[remember[i]].wscore < h[j].wscore)
						k = remember[i];
				remember[i] = remember[j];remember[j] = k;
			}
			for (i = 0;i < n;i++)
			{
				printf("\n\n*****ѧУ���:%d\n", h[remember[i]].schoolnum); printf("*****ѧУ�ܷ�:%d\n", h[remember[i]].score);
				printf("*****�����ܷ�:%d\n", h[remember[i]].mscore);
				printf("*****Ů���ܷ�: %d\n\n\n", h[remember[i]].wscore);
			}
			break; //��Ů���ܷ����
		}
			printf("��ѡ�� 2 ����,0 ����\n");
			scanf_s("%d", &sign);
		}while (sign == 2); //ѭ��ִ��������
		exit(0);
	}

  void Inquiry() //��ѯ���� 
	{
		int choice;
	int i, j, k, s;
	printf("\n*****1:��ѧУ��Ų�ѯ\n");
	printf("\n*****2:����Ŀ��Ų�ѯ\n");
	printf("\n\n*****��ѡ���ѯ��ʽ:"); //	�ṩ���ֲ�ѯ��ʽ
		scanf_s("%d",&choice);
	switch (choice)
	{
	case 1:
		do
		{
			printf("Ҫ��ѯ��ѧУ���:");
			scanf_s("%d", &i);
			if (i>n)
				printf("�������ѧУû�вμӴ˴��˶���!\n\n\n"); else
			{
				printf("Ҫ��ѯ����Ŀ���:");
				scanf_s("%d", &j);
				if (j>m + w || j == 0)
					printf("�˴��˶���û�������Ŀ\n\n\n");
				//ѧУ��ų�����Χ�����������
				else
				{
					printf("�����Ŀȡǰ %d��,��ѧУ�ĳɼ�����:\n", h[0].c[j - 1].top);
					for (k = 0;k<5;k++)
						if (h[i - 1].c[j - 1].range[k] != 0)
							printf("����:%d\n", h[i - 1].c[j - 1].range[k]); //���Ҫ��ѯѧУ��Ŀ�ĳɼ�
				}
			}
			printf("��ѡ�� 2 ���� , 0 ����\n");
			scanf_s("%d", &s);
			printf("\n\n\n");
		} while (s == 2); //ѭ��ִ�������� break;
	case 2:
		do
		{
			printf("Ҫ��ѯ����Ŀ���:");
			scanf_s("%d", &s);
			if (s>m + w || s == 0)
				printf("�˴��˶��᲻���������Ŀ.\n\n\n");
			//��Ŀ��ų�����Χ���������
			else
			{
				printf("����Ŀȡǰ %d��,ȡ�����ε�ѧУ\n", h[0].c[s - 1].top);
				for (i = 0; i<n;i++)
					for (j = 0;j<5;j++)
						if (h[i].c[s - 1].range[j] != 0)
							printf("ѧУ���:%d,����:%d\n", h[i].schoolnum,
								h[i].c[s - 1].range[j]);
			} //�������Ŀȡ������ѧУ�ĳɼ�
			printf("\n\n\n���� 2,���� 0\n");
			scanf_s("%d", &i);
			printf("\n\n\n");
		} while (i == 2);
		break;
	}
}

void writedata() //�����ݴ洢���ļ���
{
	FILE *report;
	errno_t err;
	int i;
	if ((err = fopen_s(&report,"sportsdata.txt", "w")) !=0)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}

	for (i = 0;i<n;i++)
		fwrite(&h[i], sizeof(headnode), 1, report);
	fclose(report);
} //��ͷ����д��
void readdata() //�����ļ������ݵĺ���
{
	FILE *report;
	errno_t err;

	int i, j, k, s;
	if ((err = fopen_s(&report, "sportsdata.txt", "r")) != 0)
	{
		printf("file can not be opened\n");
		exit(1);
	}
	for (i = 0;i<n;i++)
	{
		printf("******ѧУ���:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******ѧУ�ܷ�:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******�����ܷ�:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******Ů���ܷ�:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("\n\n\n");
		_getch();
		for (j = 0;j<m + w;j++)
		{
			printf("******��Ŀ���:");
			fread(&k, sizeof(int), 1, report);
			printf("%d\n", k);
			printf("******��ȡ��������:");
			fread(&k, sizeof(int), 1, report);
			printf("%d\n", k);
			for (s = 0;s<5;s++)
			{
				fread(&k, sizeof(int), 1, report);
				if (k != 0)
					printf("******����:"),
					printf("%d\n", k);
			}
			for (s = 0;s<5;s++)
			{
				fread(&k, sizeof(int), 1, report);
				if (k != 0) printf("******����:"),
					printf("%d\n", k);
			}
		}
		printf("\n\n\n");
		getchar();
	}
	fclose(report); //�ر��ļ�
} //���ն�һ�����ݾ����һ�����ݵķ�ʽ��ʾ��������
void main()
{
	int choice;
	printf("======================��ӭʹ��======================\n"); printf("\n\n*****************�˶������ͳ��ϵͳ********************\n");
	printf("\n\n********************1.������Ϣ*************************\n");
	printf("********************2.�����Ϣ*************************\n");
	printf("********************3.��ѯ��Ϣ*************************\n");
	printf("********************4.������Ϣ*************************\n");
	printf("********************5.�˳�ϵͳ*************************\n\n\n");
	printf("================================================\n\n");
	printf("********��ѡ��Ҫʵ�ֲ���ı��:\n\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		inputinformation();
		writedata();
		readdata();
		main();
	case 2:
		output();
		main();
	case 3:
		Inquiry();
		main();
	case 4:
		readdata();
		main();
	case 5:
		exit(0);
	default:
		exit(0);
	}
}