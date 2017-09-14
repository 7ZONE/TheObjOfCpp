
#include<iostream>
#include <string>
#include<stdio.h>

#define MAX 1000//�������ֵ
struct Student//����Student�ṹ��
{
	char Name[100];
	char Number[100];
	int LessonCount;
	int LessonMark;
};
struct Student S[MAX];
int StudentCount = 0;
void PrintInterface();
int Student_Insert();
void edit();
void Student_Search();
void WriteFile();
void ReadFile();
void Student_Select();
void PrintMark();
void NameChange();
void NumberChange();
int main()
{
	int n;
	printf("��ӭ����ѧ���ɼ���!");
	{
		PrintInterface();
		scanf("%d", &n);
	}
}
void PrintInterface()//�˵�����
{
	int n;
	while (1)
	{
		printf("\n -------------------------- ");
		printf("\n| 1�����                  |\n");
		printf("\n| 2���޸�                  |\n");
		printf("\n| 3����ѧ���ɼ�            |\n");
		printf("\n| 4��д���ı��ļ�          |\n");
		printf("\n| 5����ȡ�ı��ļ�          |\n");
		printf("\n| 6��ɸѡ��������ѧ��      |\n");
		printf("\n| 0���˳�                  |\n");
		printf("\n --------------------------   ");
		printf("\nѡ�����:");
		scanf("%d", &n);
		switch (n) {
		case 1:
			if (Student_Insert())
				printf("\n��ӳɹ�...�س�����\n");
			else
				printf("\n���ʧ��...�س�����\n");
			break;

		case 2:
			edit();
			break;

		case 3:
			Student_Search();
			break;

		case 4:
			WriteFile();
			break;
		case 5:
			ReadFile();
			break;
		case 6:

			Student_Select();
			break;

		case 0:
			exit(1);
			break;
		default:
			printf("�޴˹���,������ѡ��,���س�ȷ��\n");
		}
	}
}

int Student_Insert()
{
	int i, n;
	printf("\n����������ӵ�ѧ������:");
	scanf("%d", &n);
	if (StudentCount + n >= MAX)
		return 0;
	for (i = StudentCount; i < StudentCount + n; i++)//�ֱ����i��ѧ���ĳɼ�
	{
		printf("\n\t��%d��ѧ����\n", i - StudentCount + 1);
		printf("\n\tѧ��ѧ�ţ�");
		scanf("%s", &S[i].Number);

		printf("\n\tѧ��������");
		scanf("%s", S[i].Name);
		printf("\n\tc�γ̳ɼ���");
		scanf("%d", &S[i].LessonMark);
		if (S[i].LessonMark<0 || S[i].LessonMark>100)
		{
			printf("�������,����������!");
			return 0;
		}
	}
	StudentCount += n;
	return 1;
}
void edit()//�޸�ı��ѧ���ɼ���Ϣ
{
	int way = 0;
	printf("��ѡ���޸ĵķ�ʽ��/n");
	printf("1.�������޸�/n");
	printf("2.��ѧ���޸�/n");
	scanf("%d", &way);
	switch (way)//ѡ��Ҫ�޸ĵ���Ϣ  �ֱ���ú���
	{
	case 1:
		NameChange();
		break;
	case 2:
		NumberChange();
		break;
	default:printf("");
		break;
	}
}
void Student_Search()//search the student
{
	int x;
	char y[100];
	char a[100];
	int i;
	printf("\n��������ѧ����Ϣ��1.����   2.ѧ�ţ�ѡ��");
	scanf("%d", &x);
	if ((x == 1) || (x == 2))
	{
		if (x == 1)
		{
			printf("\n������");
			getchar();
			fgets(a,sizeof(a),stdin);
			for (i = 0; i < StudentCount; i++)
			{
				if (0 == strcmp(S[i].Name, a))
				{
					printf("\nѧ�ţ�%s\t������%s\n", S[i].Number, S[i].Name);
					printf("c�γ̳ɼ�\t\n");
					printf("-----------------------------------------------------\n");
					printf("%d", S[i].LessonMark);
					printf("\n\n");
				}
			}
		}
		else
		{
			printf("\nѧ�ţ�");
			getchar();
			fgets(y,sizeof(y),stdin);
			for (i = 0; i < StudentCount; i++)
			{
				if (strcmp(S[i].Number, y) == 0)
				{
					printf("\nѧ�ţ�%s\t������%s\n", S[i].Number, S[i].Name);
					printf("c�γ̳ɼ�\t\n");
					printf("-----------------------------------------------------\n");
					printf("%d", S[i].LessonMark);
					printf("\n\n");
					break;
				}
			}
		}
		printf("�������...�س�����\n");
		getchar();
	}
	else
	{
		printf("ѡ�����...�س�����\n");
		getchar();
		return;
	}
}
void WriteFile()
{
	FILE *fp;
	int i;
	char a[100];
	printf("\n������д����ļ���ַ��\n\n��ַ�����ʽ������d:\\\\Student.txt��");//д���ļ�
	scanf("%s", &a);
	printf("\nд����......\n");
	if (fp = fopen(a, "w"))
	{
		fprintf(fp, "%d\n", StudentCount);
		for (i = 0; i < StudentCount; i++)
		{
			fprintf(fp, "%s\t%s\t%d\n", S[i].Number, S[i].Name, S[i].LessonMark);
		}
		printf("\nд�����...�س�����\n");
		fclose(fp);
	}
	else
	{
		printf("\nд��ʧ��...�س�����\n");
	}
	getchar();
}
void ReadFile()
{
	FILE *fp;
	int  i;
	char  a[100];
	printf("\n�������ȡ���ļ���ַ��\n\n��ַ�����ʽ������d:\\\\student.txt��");
	scanf("%s", &a);
	printf("\n��ȡ��......\n");
	if (fp = fopen(a, "r+"))
	{
		fscanf(fp, "%d", &StudentCount);
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%s%s%d", &S[i].Number, &S[i].Name, &S[i].LessonMark);
		}
		PrintMark();
		printf("\n��ȡ�ɹ�...�س�����\n");
		fclose(fp);
	}
	else
	{
		printf("\n��ȡʧ��...�س�����\n");
	}
	getchar();
}
void Student_Select()//sort of the student score
{
	int j;
	for (j = 0;j<StudentCount;j++)
	{
		if (S[j].LessonMark >= 100)
			printf("������Ϣ!!!");
		if (S[j].LessonMark >= 90)
		{
			printf("90�����ϵ�ѧ���ɼ���Ϣ��");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else if ((S[j].LessonMark<90) && (S[j].LessonMark >= 80))
		{
			printf("80��~89�ֵ�ѧ���ɼ���Ϣ��");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);

		}
		else if ((S[j].LessonMark<80) && (S[j].LessonMark >= 70))
		{
			printf("70��~79�ֵ�ѧ���ɼ���Ϣ��");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else if ((S[j].LessonMark<70) && (S[j].LessonMark >= 60))
		{
			printf("60��~69�ֵ�ѧ���ɼ���Ϣ��");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else
		{
			printf("60�����µ�ѧ���ɼ���Ϣ:");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
	}
}
void PrintMark()
{
	int i;
	for (i = 0;i<StudentCount; i++)
	{
		printf("%s\t%s\t%d\n", S[i].Number, S[i].Name, S[i].LessonMark);
	}
}
void NameChange()
{
	char name[60];
	int i = 0, j = 0;
	printf("������Ҫ�޸ĵ�ѧ��������");
	scanf("%s", &name);
	for (i = 0;i<StudentCount;i++)
	{
		if (strcmp(name, S[i].Name) == 0)
		{
			j = i;
		}
		break;
	}
	printf("\t����\tѧ��\t�ɼ�\n");
	printf("%s\t%s\t%d\n", S[i].Name, S[i].Number, S[i].LessonMark);
	printf("�����������ѧ����Ϣ");
	printf("������");
	scanf("%s", &S[j].Name);
	printf("ѧ�ţ�");
	scanf("%s", &S[j].Number);
	printf("�ɼ���");
	scanf("%d", &S[j].LessonMark);
	printf("�޸����");
}
void NumberChange()
{
	char id[60];
	int i = 0, j = 0;
	printf("������Ҫ�޸ĵ�ѧ��ѧ��");
	scanf("%s", &id);
	for (i = 0;i<StudentCount;i++)
	{
		if (strcmp(id, S[i].Number) == 0)
		{
			j = i;
		}
		break;
	}
	printf("����\tѧ��\tc���Է���\t\n");
	printf("%s\t%s\t%d\n", S[i].Name, S[i].Number, S[i].LessonMark);
	printf("�����������ѧ����Ϣ");
	printf("������");
	scanf("%s", &S[j].Name);
	printf("ѧ�ţ�");
	scanf("%s", &S[j].Number);
	printf("�ɼ���");
	scanf("%d", &S[j].LessonMark);
	printf("�޸����");
}