#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

////������������Ľ׳�
//int main()
//{
//	int a = 0; int sum = 1;
//	scanf_s("%d", &a);
//	for (int i = 1; i <= a; i++)
//	{
//		sum = i * sum;
//	}
//	printf("%d!=%d\n", a, sum);
//	return 0;
//}

////����1-10���������Ľ׳��ܺ�
//int main()
//{
//	int a = 0; int sum = 1;
//	for (int i = 1; i <= 10; i++)
//	{
//		sum = i * sum;
//		a = a + sum;
//		printf("%d!\t=\t%d\n", i, sum);
//	}
//	printf("\n1-10���������Ľ׳��ܺ�Ϊ��%d��\n", a);
//	return 0;
//}

////���ֲ���
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; int num = 117; int Left = 0; int Right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (Left<=Right)
//	{
//		int Middle = (Left + Right) / 2;
//		if (arr[Middle]<num)
//		{
//			Left = Middle + 1;
//		}
//		else if (arr[Middle]>num)
//		{
//			Right = Middle - 1;
//		}
//		else if (arr[Middle]=num)
//		{
//			printf("\n���ҵ����ֵ��±��ǣ�%d\n", Middle);
//			break;
//		}
//	}
//	if (Left>Right)
//	{
//		printf("\n�����޷��ҵ�������ֵ��±�\n");
//	}
//	return 0;
//}

////����ַ��������ƶ����м���
//int main()
//{
//	char arr1[] = "KilluaAoki"; char arr2[] = "##########"; int Left = 0; int Right = strlen(arr2) - 1;
//	printf("\n%s\n", arr2);
//	while (Left<=Right)
//	{
//		arr2[Left] = arr1[Left];
//		arr2[Right] = arr1[Right];
//		Sleep(500);system("cls");
//		Left++; Right--;
//		printf("\n%s\n", arr2);
//	}
//	return 0;
//}

////ģ���û���¼�龰����������������롣
//int main()
//{
//	int i = 0; char password[20] = { 0 };//88888888
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n��������������>>");
//		scanf_s("%s", password, 20);
//		if (strcmp(password,"88888888")==0)
//		{
//			printf("\n��ϲ������½�ɹ���\n");
//			break;	
//		}
//		else
//		{
//			printf("\n��������������������룡\n��ע�⣺�ۼƴ������ν��߳�����\n");
//		}
//	}
//	if (i==3)
//	{
//		printf("\n�����������3�Σ��߳�����\n");
//	}
//	return 0;
//}

////дһ����������Ϸ
////1. �Զ�����һ��1-100֮����������
////2. ������
////	a. �¶��ˣ�����Ϸ������
////	b. �´��ˣ��������´��˻��С�ˣ���������£�ֱ���¶�Ϊֹ��
////3. ��Ϸ����һֱ�棬�����˳���Ϸ��
//void menu()
//{
//	printf("****************************\n");
//	printf("********** 1.Play **********\n");
//	printf("********** 0.Exit **********\n");
//	printf("****************************\n");
//}
//
//void game()
//{
//	int num1 = rand() % 100 + 1; int num2 = 0;
//	//printf("%d\n", num1);
//	while (1)
//	{
//		printf("�������>>");
//		scanf_s("%d", &num2);
//		if (num2<num1)
//		{
//			printf("��С��\n");
//		}
//		else if (num2>num1)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("��ϲ��¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		default:
//			printf("�������������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}