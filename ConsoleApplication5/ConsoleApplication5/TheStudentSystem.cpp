#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <process.h>
#define n 2//学校数目
#define m 1//男子项目数目
#define w 1//女子项目数目
#define null 0
typedef struct
{
	int itemnum; //项目编号
	int top; //取名次的数目
	int range[5]; //名次
	int mark[5]; //分数
}itemnode; //定义项目结点的类型
typedef struct
{
	int schoolnum; //学校编号
	int score; //学校总分
	int mscore; //男团体总分
	int wscore; //女团体总分
	itemnode c[m + w]; //项目数组
}headnode;//定义头结点类型
headnode h[n];//定义一个头结点数组
void inputinformation() //输入信息，建立系统
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
		printf("*****学校编号:");
		scanf_s("%d", &h[i].schoolnum);
		for (j = 0;j<m + w;j++)
		{ //初始化头结点 //输入头结点信息
			printf("*****项目编号:");
			scanf_s("%d", &h[i].c[j].itemnum);
			printf("*****取前3名or前5名:");
			scanf_s("%d", &h[i].c[j].top);

			printf("*****获得几个名次：");
			scanf_s("%d", &k); //输入项目信息
			for (s = 0;s<5;s++)
				h[i].c[j].range[s] = 0, h[i].c[j].mark[s] = 0; //初始化排名和分数
			for (s = 0;s<k;s++)
			{
				printf("*****名次:");
				scanf_s("%d", &h[i].c[j].range[s]); //输入所获名次信息
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
				//按取前三名还是取前五名分别记分
				if (j <= m - 1)
					h[i].mscore = h[i].mscore + h[i].c[j].mark[s];
				//是男子项目则记到男子分数里面去
				else
					h[i].wscore = h[i].wscore + h[i].c[j].mark[s];
				//是女子项目则记到女子项目里面去
			}
			printf("\n");
		}

	}

}
void output() //输出函数
{
	int choice, i, j, k;

	int remember[n];
	int sign;
	do
	{
		printf("*******************1.按学校编号输出.*******************\n");
		printf("*******************2.按学校总分输出.*******************\n");
		printf("*******************3.按男团总分输出.*******************\n");
		printf("*******************4.按女团总分输出.*******************\n");
		printf("\n\n******************* 请选择编号*************************\n\n:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: //按编号顺序输出
			for (i = 0;i < n;i++)
			{
				printf("\n\n*****学校编号:%d\n", h[i].schoolnum);
				printf("*****学校总分:%d\n", h[i].score);
				printf("*****男团总分:%d\n", h[i].mscore);
				printf("*****女团总分: %d\n\n\n", h[i].wscore);
			}
			break;
		case 2:// 用冒泡排序方法，用辅助数组记住头结点下标
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
				printf("\n\n*****学校编号：%d\n", h[remember[i]].schoolnum); printf("*****学校总分:%d\n", h[remember[i]].score);
				printf("*****男团总分:%d\n", h[remember[i]].mscore);
				printf("*****女团总分: %d\n\n\n", h[remember[i]].wscore);
				//按所记下标顺序输出
			} //按学校总分输出
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
				printf("\n\n*****学校编号:%d\n", h[remember[i]].schoolnum); printf("*****学校总分:%d\n", h[remember[i]].score);
				printf("*****男团总分:%d\n", h[remember[i]].mscore);
				printf("*****女团总分: %d\n\n\n", h[remember[i]].wscore);
			} //按男团总分输出 break;
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
				printf("\n\n*****学校编号:%d\n", h[remember[i]].schoolnum); printf("*****学校总分:%d\n", h[remember[i]].score);
				printf("*****男团总分:%d\n", h[remember[i]].mscore);
				printf("*****女团总分: %d\n\n\n", h[remember[i]].wscore);
			}
			break; //按女团总分输出
		}
			printf("请选择 2 继续,0 跳出\n");
			scanf_s("%d", &sign);
		}while (sign == 2); //循环执行输出语句
		exit(0);
	}

  void Inquiry() //查询函数 
	{
		int choice;
	int i, j, k, s;
	printf("\n*****1:按学校编号查询\n");
	printf("\n*****2:按项目编号查询\n");
	printf("\n\n*****请选择查询方式:"); //	提供两种查询方式
		scanf_s("%d",&choice);
	switch (choice)
	{
	case 1:
		do
		{
			printf("要查询的学校编号:");
			scanf_s("%d", &i);
			if (i>n)
				printf("错误：这个学校没有参加此次运动会!\n\n\n"); else
			{
				printf("要查询的项目编号:");
				scanf_s("%d", &j);
				if (j>m + w || j == 0)
					printf("此次运动会没有这个项目\n\n\n");
				//学校编号超出范围，则输出警告
				else
				{
					printf("这个项目取前 %d名,该学校的成绩如下:\n", h[0].c[j - 1].top);
					for (k = 0;k<5;k++)
						if (h[i - 1].c[j - 1].range[k] != 0)
							printf("名次:%d\n", h[i - 1].c[j - 1].range[k]); //输出要查询学校项目的成绩
				}
			}
			printf("请选择 2 继续 , 0 跳出\n");
			scanf_s("%d", &s);
			printf("\n\n\n");
		} while (s == 2); //循环执行输出语句 break;
	case 2:
		do
		{
			printf("要查询的项目编号:");
			scanf_s("%d", &s);
			if (s>m + w || s == 0)
				printf("此次运动会不包括这个项目.\n\n\n");
			//项目编号超出范围则输出警告
			else
			{
				printf("该项目取前 %d名,取得名次的学校\n", h[0].c[s - 1].top);
				for (i = 0; i<n;i++)
					for (j = 0;j<5;j++)
						if (h[i].c[s - 1].range[j] != 0)
							printf("学校编号:%d,名次:%d\n", h[i].schoolnum,
								h[i].c[s - 1].range[j]);
			} //输出该项目取得名次学校的成绩
			printf("\n\n\n继续 2,跳出 0\n");
			scanf_s("%d", &i);
			printf("\n\n\n");
		} while (i == 2);
		break;
	}
}

void writedata() //把数据存储在文件中
{
	FILE *report;
	errno_t err;
	int i;
	if ((err = fopen_s(&report,"sportsdata.txt", "w")) !=0)
	{
		printf("不能打开文件\n");
		exit(1);
	}

	for (i = 0;i<n;i++)
		fwrite(&h[i], sizeof(headnode), 1, report);
	fclose(report);
} //按头结点块写入
void readdata() //读出文件中数据的函数
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
		printf("******学校编号:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******学校总分:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******男团总分:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("******女团总分:");
		fread(&k, sizeof(int), 1, report);
		printf("%d\n", k);
		printf("\n\n\n");
		_getch();
		for (j = 0;j<m + w;j++)
		{
			printf("******项目编号:");
			fread(&k, sizeof(int), 1, report);
			printf("%d\n", k);
			printf("******所取名次数量:");
			fread(&k, sizeof(int), 1, report);
			printf("%d\n", k);
			for (s = 0;s<5;s++)
			{
				fread(&k, sizeof(int), 1, report);
				if (k != 0)
					printf("******名次:"),
					printf("%d\n", k);
			}
			for (s = 0;s<5;s++)
			{
				fread(&k, sizeof(int), 1, report);
				if (k != 0) printf("******分数:"),
					printf("%d\n", k);
			}
		}
		printf("\n\n\n");
		getchar();
	}
	fclose(report); //关闭文件
} //按照读一个数据就输出一个数据的方式显示数据内容
void main()
{
	int choice;
	printf("======================欢迎使用======================\n"); printf("\n\n*****************运动会分数统计系统********************\n");
	printf("\n\n********************1.输入信息*************************\n");
	printf("********************2.输出信息*************************\n");
	printf("********************3.查询信息*************************\n");
	printf("********************4.调用信息*************************\n");
	printf("********************5.退出系统*************************\n\n\n");
	printf("================================================\n\n");
	printf("********请选择要实现步骤的编号:\n\n");
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