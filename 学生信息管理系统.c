#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Header printf("ѧ��    ����    ����    �Ա�    ��������    �绰����     ��ͥ��ַ\n")
#define Print printf("%-8d%-8s%-8d%-8s%-10s  %-.0lf  %-20s\n",stu[p].StuNum,stu[p].StuName,stu[p].StuAge,stu[p].Sex,stu[p].BirthDate,stu[p].TeleNum,stu[p].Home)
struct StuSalary
{
	int StuNum;
	char StuName[6];
	int StuAge;
	char Sex[3];
	char BirthDate[10];
	double TeleNum;
	char Home[20];
}stu[100];
int saveflag=0;
//���˵� 

void Menu()
{
		printf("         **********ѧ����Ϣ����ϵͳ**********\n");
		printf("         *              ���˵�              *\n");
		printf("         * 1.���ѧ����Ϣ    2.��ʾѧ����Ϣ *\n");
		printf("         * 3.�޸�ѧ����Ϣ    4.ɾ��ѧ����Ϣ *\n");
		printf("         * 5.����ѧ����Ϣ    6.����ѧ����Ϣ *\n");
		printf("         *           7.�˳�ϵͳ             *\n");
		printf("         *********************Ver 1.0 *******\n");
		printf("         --��Ӧ�ý���ѧϰ����ʹ�ã��Ͻ�����--\n");	
		printf("         -------------���ս���Ȩ�鿪��������-\n");
}
//���ļ� 

int OpenFile(int cnt)
{
	FILE *fp;
	int i=0;
	fp=fopen("D:\\ѧ����Ϣ.dat","ab+");
	if(fp==NULL)
	{
		printf("��ʧ�ܣ�");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&stu[i],sizeof(struct StuSalary),1,fp)==1)
		{
			cnt++;
			i++;
		}
		
	}
	fclose(fp);
	return cnt;
}
//������Ϣ 

int Locate(int num,int cnt)
{
	int p=-1,i;
	for(i=0;i<cnt;i++)
	{
		if(stu[i].StuNum==num)
		{
			p=i;
			break;
		}
	}
	return p;
}
//�����Ϣ 

int Add(int cnt)
{
	int choice;
	int i,stuNumTemp,j,recordcnt;
	recordcnt=cnt;
	printf("��ʼ���ѧ����Ϣ...\n");
	for(i=cnt;i<100;i++)
	{
		printf("ѧ��ѧ�ţ�");
		scanf("%d",&stuNumTemp);
		for(j=0;j<i;j++)
		{
			if(stu[j].StuNum==stuNumTemp)
			{
				printf("ѧ��ѧ���ظ������������룺");
				scanf("%d",&stuNumTemp);
				j=-1;
			}
		}
		stu[i].StuNum=stuNumTemp;
		getchar();
		printf("ѧ������:");
		scanf("%s",&stu[i].StuName);
		printf("ѧ�����䣺"); 
		scanf("%d",&stu[i].StuAge);
		printf("ѧ���Ա�");
		scanf("%s",&stu[i].Sex);
		printf("�������£�");
		scanf("%s",&stu[i].BirthDate) ;
		printf("�绰����:"); 
		scanf("%lf",&stu[i].TeleNum);
		printf("��ͥסַ��");
		scanf("%s",&stu[i].Home);
		printf("�Ƿ��������? 1 ���� 0 �˳���");
		scanf("%d",&choice);
		recordcnt++;
		if(choice!=1)
			break;
	}
	saveflag=1;
	printf("��¼������ɣ���enter���������˵�...");
	getchar();
	getchar();
	return recordcnt;
}
//��ʾ��Ϣ 

void ShowRecord(int cnt)
{
	int i,p;
	if(cnt!=0)
	{
		Header;
		for(i=0;i<cnt;i++)
		{
			p=i;
			Print;
		}
	}
}
//�޸���Ϣ 

void Modify(int cnt)
{
	int stunum,p,stuNumTemp,j;
	printf("��ʼ�޸�ѧ����Ϣ...\n\n");
	printf("������Ҫ�޸�ѧ����ѧ�ţ�");
	scanf("%d",&stunum);
	p=Locate(stunum,cnt);
	if(-1==p)
	{
		printf("\nҪ�޸ĵ�ѧ����Ϣ�����ڣ���enter���������˵�...");
	}
	else
	{
		printf("Ҫ�޸ĵ�ѧ����Ϣ���£�\n");
		Header;
		Print;
		printf("����������ѧ����Ϣ��\n");
		printf("ѧ��ѧ�ţ�");
		scanf("%d",&stuNumTemp);
		for(j=0;j<cnt;j++)
		{
			if(stu[j].StuNum==stuNumTemp && j!=p)
			{
				printf("ѧ��ѧ���ظ������������룺");
				scanf("%d",&stuNumTemp);
				j=-1;
			}
		}
		stu[p].StuNum=stuNumTemp;
		getchar();
		printf("ѧ��������");
		scanf("%s",&stu[p].StuName);
		printf("ѧ������:");
		scanf("%d",&stu[p].StuAge);
		printf("ѧ���Ա�");
		scanf("%s",&stu[p].Sex);
		printf("�������£�");
		scanf("%s",&stu[p].BirthDate) ;
		printf("�绰����:"); 
		scanf("%lf",&stu[p].TeleNum);
		printf("��ͥסַ��");
		scanf("%s",&stu[p].Home);
		saveflag=1;
		printf("\nѧ����Ϣ�޸ĳɹ�����enter���������˵�...");
	}
	getchar();
	getchar();
}
//ɾ����Ϣ 

int Del(int cnt)
{
	int stunum,p,i;
	printf("��ʼɾ��ѧ����Ϣ...\n\n");
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%d",&stunum);
	p=Locate(stunum,cnt);
	if(-1==p)
	{
		printf("\nҪɾ����ѧ����Ϣ�����ڣ���enter���������˵�...");	
	}
	else
	{
		printf("Ҫɾ����ѧ����Ϣ���£�\n\n");
		Header;
		Print;
		for(i=p;i<cnt-1;i++)
		{
			stu[i]=stu[i+1];
		}
		cnt--;
		saveflag=1;
		printf("\nѧ����Ϣ�޸ĳɹ�����enter���������˵�...");
	}
	getchar();
	getchar();
	return cnt;
}
//��ѯ��Ϣ 

void Query(int cnt)
{
	int choice=0,stunum,p,count=0,i;
	char stuname[13];
	printf("��ʼ��ѯѧ����Ϣ...\n");
	printf("��ѡ���ѯ��ʽ��1 ��ѧ��  2 ����������");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("������Ҫ��ѯѧ����ѧ�ţ�");
			scanf("%d",&stunum);
			p=Locate(stunum,cnt);
			if(-1==p)
			{
				printf("\n��ѯ��ѧ����Ϣ�����ڣ���enter���������˵�...");
			 } 
			 else
			 {
			 	printf("��ѯ��ѧ����Ϣ���£�\n\n");
			 	Header;
			 	Print;
			 	printf("\nѧ����Ϣ��ѯ��ɣ���enter���������˵�...");
			 }
			 getchar();
			 break;
		case 2:
			getchar();
			printf("������Ҫ��ѯѧ��������:");
			scanf("%s",&stuname);
			for(i=0;i<cnt;i++)
			{
				if(strcmp(stuname,stu[i].StuName)==0)
				{
					if(count==0)
					{
						Header;
					}
					p=i;
					Print;
					count++;
				}
			}
			if(0==count)
				printf("\n��ѯ��ѧ����Ϣ�����ڣ���enter���������˵�...");
			else
				printf("\nѧ����Ϣ��ѯ��ɣ���enter���������˵�...");
			break;
		default:
			printf("ѡ����󣬰�enter���������˵�...");
	}
	getchar();
}
//�������� 

void SaveFile(int cnt)
{
	FILE *fp;
	int i=0;
	if(1==saveflag)
	{
		fp=fopen("D:\\ѧ����Ϣ.dat","wb");
		for(;i<cnt;i++)
			fwrite(&stu[i],sizeof(struct StuSalary),1,fp);
		fclose(fp);
		saveflag=0;
	}
}
//�˳�ϵͳ 

void ExitSystem(cnt)
{
	int choice=0;
	if(1==saveflag)
	{
		printf("ѧ����Ϣ�б䶯���Ƿ񱣴����ݣ���1 �����˳�  2 �������˳�����");
		scanf("%d",&choice);
		if(1==choice)
		{
			SaveFile(cnt);
			printf("�ļ�����ɹ�����enter���������˵�...");
		 } 
	}
	else
	{
		printf("��enter���˳�ϵͳ...");
	}
	getchar();
	getchar();
	exit(0);
}
//������ 

void main()
{
	int choice=0,count=0;
	count=OpenFile(count);
	while(1)
	{
		system("cls");
		Menu();
		printf("���������ѡ��:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				count=Add(count);
				break;
				case 2:
				if(0==count)
					printf("��ǰû��ѧ����Ϣ����enter���������˵�...");
				else
				printf("��ʼ��ʾѧ����Ϣ...\n\n");
				printf("����ѧ����Ϣ���£�\n");
				ShowRecord(count);
				printf("\n��¼��ʾ��ɣ���enter���������˵�...");
				getchar();
				getchar();
				break;
				case 3:
				Modify(count);
				break;
				case 4:
				count=Del(count);
				break;
				case 5:
				Query(count);
				break;
				case 6:
				SaveFile(count);
				printf("�ļ�����ɹ�����enter���������˵�...");
				getchar();
				getchar();
				break;
				case 7:
				ExitSystem(count);
			default:
				printf("ѡ����󣬰�enter���������˵�...");
				getchar();
				getchar();
		}
	}
}
