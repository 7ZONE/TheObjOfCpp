
#include<iostream>
#include <string>
#include<stdio.h>

#define MAX 1000//设置最大值
struct Student//创建Student结构体
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
	printf("欢迎进入学生成绩簿!");
	{
		PrintInterface();
		scanf("%d", &n);
	}
}
void PrintInterface()//菜单函数
{
	int n;
	while (1)
	{
		printf("\n -------------------------- ");
		printf("\n| 1、添加                  |\n");
		printf("\n| 2、修改                  |\n");
		printf("\n| 3、查学生成绩            |\n");
		printf("\n| 4、写入文本文件          |\n");
		printf("\n| 5、读取文本文件          |\n");
		printf("\n| 6、筛选各分数段学生      |\n");
		printf("\n| 0、退出                  |\n");
		printf("\n --------------------------   ");
		printf("\n选择操作:");
		scanf("%d", &n);
		switch (n) {
		case 1:
			if (Student_Insert())
				printf("\n添加成功...回车继续\n");
			else
				printf("\n添加失败...回车继续\n");
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
			printf("无此功能,请重新选择,按回车确定\n");
		}
	}
}

int Student_Insert()
{
	int i, n;
	printf("\n请输入所添加的学生人数:");
	scanf("%d", &n);
	if (StudentCount + n >= MAX)
		return 0;
	for (i = StudentCount; i < StudentCount + n; i++)//分别读入i个学生的成绩
	{
		printf("\n\t第%d个学生：\n", i - StudentCount + 1);
		printf("\n\t学生学号：");
		scanf("%s", &S[i].Number);

		printf("\n\t学生姓名：");
		scanf("%s", S[i].Name);
		printf("\n\tc课程成绩：");
		scanf("%d", &S[i].LessonMark);
		if (S[i].LessonMark<0 || S[i].LessonMark>100)
		{
			printf("输入错误,请重新输入!");
			return 0;
		}
	}
	StudentCount += n;
	return 1;
}
void edit()//修改谋个学生成绩信息
{
	int way = 0;
	printf("请选择修改的方式：/n");
	printf("1.按姓名修改/n");
	printf("2.按学号修改/n");
	scanf("%d", &way);
	switch (way)//选择要修改的信息  分别调用函数
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
	printf("\n输入所查学生信息（1.姓名   2.学号）选择：");
	scanf("%d", &x);
	if ((x == 1) || (x == 2))
	{
		if (x == 1)
		{
			printf("\n姓名：");
			getchar();
			fgets(a,sizeof(a),stdin);
			for (i = 0; i < StudentCount; i++)
			{
				if (0 == strcmp(S[i].Name, a))
				{
					printf("\n学号：%s\t姓名：%s\n", S[i].Number, S[i].Name);
					printf("c课程成绩\t\n");
					printf("-----------------------------------------------------\n");
					printf("%d", S[i].LessonMark);
					printf("\n\n");
				}
			}
		}
		else
		{
			printf("\n学号：");
			getchar();
			fgets(y,sizeof(y),stdin);
			for (i = 0; i < StudentCount; i++)
			{
				if (strcmp(S[i].Number, y) == 0)
				{
					printf("\n学号：%s\t姓名：%s\n", S[i].Number, S[i].Name);
					printf("c课程成绩\t\n");
					printf("-----------------------------------------------------\n");
					printf("%d", S[i].LessonMark);
					printf("\n\n");
					break;
				}
			}
		}
		printf("查找完毕...回车继续\n");
		getchar();
	}
	else
	{
		printf("选择错误...回车继续\n");
		getchar();
		return;
	}
}
void WriteFile()
{
	FILE *fp;
	int i;
	char a[100];
	printf("\n请输入写入的文件地址：\n\n地址输入格式：例如d:\\\\Student.txt：");//写入文件
	scanf("%s", &a);
	printf("\n写入中......\n");
	if (fp = fopen(a, "w"))
	{
		fprintf(fp, "%d\n", StudentCount);
		for (i = 0; i < StudentCount; i++)
		{
			fprintf(fp, "%s\t%s\t%d\n", S[i].Number, S[i].Name, S[i].LessonMark);
		}
		printf("\n写入完成...回车继续\n");
		fclose(fp);
	}
	else
	{
		printf("\n写入失败...回车继续\n");
	}
	getchar();
}
void ReadFile()
{
	FILE *fp;
	int  i;
	char  a[100];
	printf("\n请输入读取的文件地址：\n\n地址输入格式：例如d:\\\\student.txt：");
	scanf("%s", &a);
	printf("\n读取中......\n");
	if (fp = fopen(a, "r+"))
	{
		fscanf(fp, "%d", &StudentCount);
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%s%s%d", &S[i].Number, &S[i].Name, &S[i].LessonMark);
		}
		PrintMark();
		printf("\n读取成功...回车继续\n");
		fclose(fp);
	}
	else
	{
		printf("\n读取失败...回车继续\n");
	}
	getchar();
}
void Student_Select()//sort of the student score
{
	int j;
	for (j = 0;j<StudentCount;j++)
	{
		if (S[j].LessonMark >= 100)
			printf("错误信息!!!");
		if (S[j].LessonMark >= 90)
		{
			printf("90分以上的学生成绩信息：");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else if ((S[j].LessonMark<90) && (S[j].LessonMark >= 80))
		{
			printf("80分~89分的学生成绩信息：");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);

		}
		else if ((S[j].LessonMark<80) && (S[j].LessonMark >= 70))
		{
			printf("70分~79分的学生成绩信息：");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else if ((S[j].LessonMark<70) && (S[j].LessonMark >= 60))
		{
			printf("60分~69分的学生成绩信息：");
			printf("%s\t%s\t%d\n", S[j].Number, S[j].Name, S[j].LessonMark);
		}
		else
		{
			printf("60分以下的学生成绩信息:");
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
	printf("请输入要修改的学生姓名：");
	scanf("%s", &name);
	for (i = 0;i<StudentCount;i++)
	{
		if (strcmp(name, S[i].Name) == 0)
		{
			j = i;
		}
		break;
	}
	printf("\t姓名\t学号\t成绩\n");
	printf("%s\t%s\t%d\n", S[i].Name, S[i].Number, S[i].LessonMark);
	printf("请重新输入该学生信息");
	printf("姓名：");
	scanf("%s", &S[j].Name);
	printf("学号：");
	scanf("%s", &S[j].Number);
	printf("成绩：");
	scanf("%d", &S[j].LessonMark);
	printf("修改完毕");
}
void NumberChange()
{
	char id[60];
	int i = 0, j = 0;
	printf("请输入要修改的学生学号");
	scanf("%s", &id);
	for (i = 0;i<StudentCount;i++)
	{
		if (strcmp(id, S[i].Number) == 0)
		{
			j = i;
		}
		break;
	}
	printf("姓名\t学号\tc语言分数\t\n");
	printf("%s\t%s\t%d\n", S[i].Name, S[i].Number, S[i].LessonMark);
	printf("请重新输入该学生信息");
	printf("姓名：");
	scanf("%s", &S[j].Name);
	printf("学号：");
	scanf("%s", &S[j].Number);
	printf("成绩：");
	scanf("%d", &S[j].LessonMark);
	printf("修改完毕");
}