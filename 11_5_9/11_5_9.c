#include <stdio.h>

////�˷��ھ����ϵ��£�
//int main()
//{
//	int a = 0;
//	for ( a = 1; a <= 9; a++)
//	{
//		int b = 0;
//		for ( b = 1; b <= a; b++)
//		{
//			printf("%d*%d=%2d ", b, a, a * b);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////�˷��ھ����µ��ϣ�
//int main()
//{
//	int a = 0;
//	for ( a = 9; a >= 1; a--)
//	{
//		int b = 0;
//		for ( b = 1; b <=a  ; b++)
//		{
//			printf("%d*%d=%2d ", a, b, a * b);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////�ж�1000��-2000��֮�������
//int main()
//{
//	int a = 0;
//	int b = 4;
//	int c = 100;
//	int d = 400;
//	int e = 0;
//	for ( a = 1000; a <= 2000; a++)
//	{
//		if (a%b==0)
//		{
//			if (a%c!=0)
//			{
//				printf("%d ", a);
//				e++;
//			}
//			if (a%d==0)
//			{
//				printf("%d ", a);
//				e++;
//			}
//		}
//	}
//	printf("\n����һ����%d��", e);
//	return 0;
//}

////�ж�1000��-2000��֮������꣨�Ż���
//int main()
//{
//	int a = 0;
//	int b = 0;
//	for ( a = 1000; a <= 2000; a++)
//	{
//		if ((a%4==0) && (a%100!=0) || (a%400==0))
//		{
//			printf("%d ", a);
//			b++;
//		}
//	}
//	printf("\n����ĸ���Ϊ%d ", b);
//	return 0;
//}