#include <stdio.h>//����ͷ�ļ�����ݼ�Ctrl+F5���벢���С�

//int main()
//{
//	printf("��ӡ�ĵ�һ������\n");//printf - �⺯�� - ����Ļ�ϴ�ӡ��Ϣ�ģ�printf ��ʹ����Ҫ����ͷ�ļ� stdio.h��
//	printf("��ӡ�ĵڶ�������\n");//\nΪ���е���˼��
//	printf("��ӡ�ĵ���������\n");
//	return 0;
//}

//int main()
//{
//	printf("%d\n",sizeof(char));//��ӡ�ַ��������͵Ĵ�С����ӡһ������ - %d��sizeof - �ؼ��� - ������ - �������ͻ��߱�����ռ�ռ�Ĵ�С-��λΪ�ֽ�byte��
//	printf("%d\n",sizeof(short));//��ӡ�����͵Ĵ�С��
//	printf("%d\n",sizeof(int));//��ӡ���͵Ĵ�С��
//	printf("%d\n",sizeof(long));//��ӡ�����͵Ĵ�С��C���Ա�׼�涨sizeof(long)>=sizeof(int)������long��int��С��Ϊ4�ֽڡ�
//	printf("%d\n",sizeof(long long));//��ӡ�������͵Ĵ�С��
//	printf("%d\n",sizeof(float));//��ӡ�����ȸ������Ĵ�С��
//	printf("%d\n",sizeof(double));//��ӡ˫���ȸ������Ĵ�С��
//	return 0;
//}

//int main()
//{
//	printf("Aoki\n");
//	int age = 18;//����һ�������ĸ�ʽ������ ����������=0���߲���ֵ��
//	float weight = 60.5;
//	age = age + 1;//�ı���ı�����
//	printf("%d\n", age);//֤�������ǿ��Ա��ı�ġ�
//	weight = weight + 5;
//	printf("%lf\n", weight);//��ӡһ�������� - %lf��
//	return 0;
//}

//int a = 100;//ȫ�ֱ������������ⲿ����ġ�
//int main()
//{
//	int a = 10;//�ֲ��������������ڲ�����ġ�
//	printf("%d\n", a);//��ȫ�ֱ����;ֲ�����������ͬ������£��ֲ��������ȣ��������ȫ�ֱ����;ֲ�����������д��һ���ġ�
//	return 0;
//}

////дһ��������2�������ĺ͡�
//int main()
//{
//	int num = 0;
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d %d", &num1,&num2);//scanf���������뺯����
//	num = num1 + num2;//Ҫ����scanf�����档
//	//printf("%d", num1);
//	//printf("+");
//	//printf("%d", num2);
//	//printf("=");
//	//printf("%d\n", num);
//	printf("%d+%d=%d\n", num1,num2,num);
//	return 0;
//}

//��ӡ100~200֮�������
//int main()
//{
//	int a = 0;
//	int c = 0;
//	for (a = 100; a < 200; a++)
//	{
//		int b = 0;
//		for (b = 2; b < a; b++)
//		{
//			if (a%b==0)
//			{
//				break;
//			}
//		}
//		if (a==b)
//		{
//			printf("%d ", a);
//			c++;
//		}
//	}
//	printf("\n����һ����%d��\n", c);
//}