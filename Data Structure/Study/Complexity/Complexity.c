#include <stdio.h>
#include <string.h>

/*
	复杂度
		1.算法的效率
		2.时间复杂度
		3.空间复杂度
		4.复杂度练习
*/

/**
	算法的效率
		1.衡量算法好坏
			a.一个程序的运行时间，依赖于算法的好坏和问题的输入规模，其中问题的输入规模是指输入量的多少，单一个输入量常表示为"N"。
			b.算法在编写成可执行程序后，运行时是需要消耗时间资源和空间资源的，因此就引出时间复杂度和空间复杂度，用于衡量一个算法的好坏。
			c.时间复杂度和额外空间复杂度是算法的流程决定的，而常数项时间是算法的实现细节决定的。
			d.在衡量一个算法的好坏时存在最坏情况、最好情况、平均情况，在实际中一般情况关注的是算法的最坏运行情况。
		2.复杂度的介绍
			a.常数时间的操作：所谓常数操作就是指固定时间的操作，比如算术操作、位运算、数组寻址操作等操作，也就是执行时间固定的操作都是常数时间的操作，而执行时间不固定的操作为非常数时间操作。
			b.时间复杂度主要衡量一个算法的运行快慢，也可以认为是计算常数操作共执行了多少次，并且它是衡量算法流程的复杂程度的一种指标，该指标只与数据量有关，与过程之外的优化无关。
			c.空间复杂度主要衡量一个算法运行所需要的额外空间。
		3.确定算法流程的总操作数量与样本数量之间的表达式关系
			a.想象这个算法流程所处理的数据状况，要按照最差情况来。
			b.把整个流程彻底拆分为一个个基本动作，保证每个动作都是常数时间的操作。
			c.假设数据量为"N"，看看基本动作的数量和"N"是什么关系。
*/

////算法的效率示例：计算"1 + 2 + 3 + 4 + ...+ 100"的总和。
//int main()
//{
//	////方法一：使用循环将"1 ~ 100"的数使用一个变量进行累加，得出结果。
//	//size_t sum = 0;
//	//for (size_t i = 1; i <= 100; i++)
//	//{
//	//	sum += i;//这一条语句一共执行了一百次。
//	//}
//	//printf("%zu\n", sum);
//	
//	////方法二：使用等差数列的求和公式直接计算出结果。
//	//size_t sum = ((1 + 100) * 100) / 2;//执行了一次。
//	//printf("%zu\n", sum);
//
//	//两方法总结：可以发现方法一的执行次数约为"N"次，但方法二执行次数只为一次，可以明显看出方法二优于方法一。
//
//	return 0;
//}

/**
	时间复杂度：即算法的渐进时间复杂度，简称为时间复杂度。
		1.时间复杂度的概念
			a.在进行算法分析时，语句总的执行次数"T(N)"是关于问题规模"N"的一个函数(数学层面)，进而分析"T(N)"随"N"的变化情况并确定"T(N)"的数量级。
			b.算法的时间复杂度，也就是算法的时间量度，记作"T(N) = O(f(N))"，大写的"O"，来体现算法时间复杂度的记法，即大"O"记法。
			c.大"O"记法随问题规模"N"的增大，算法执行时间的增长率和"f(N)"的增长率相同("f(N)"是问题规模"N"的某个函数)，也就是算法的渐进时间复杂度。
		2.推导大"O"阶方法：当处理的样本量很大时，可以发现低阶项和每一项的系数不是最重要的，而真正重要的是最高阶项是什么。
			a.用常数"1"取代运行时间中的所有加法常数。
			b.在修改后的运行次数函数中，只保留最高阶项。
			c.如果最高阶项存在且其系数不是"1"，则去除与这个项相乘的系数。
		3.常见的时间复杂度：https://zh.wikipedia.org/wiki/%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6。
			a.一般情况下，时间复杂度可以分为：常数阶、线性阶、对数阶、平方阶、"NlogN"阶、立方阶、指数阶、阶乘阶、"N"的"N"次方阶。
			b.常见的时间复杂度所耗费的时间从小至大以此是：常数阶 < 对数阶 < 线性阶 < "NlogN"阶 < 平方阶 < 立方阶 < 指数阶 < 阶乘阶 < "N"的"N"次方阶。
*/

////时间复杂度示例一：计算以下程序的时间复杂度。
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;//执行了"N * N"次。
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;//执行了"2 * N"次。
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;//执行了十次。
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int N = 0;
//	scanf_s("%d", &N);
//	Func1(N);//可以得知此函数的内的语句的总的执行次数"T(N)"大概执行了"(N * N) + (2 * N) + (10)"次，故时间复杂度为：O(N ^ 2)。(其中"^"符号表示次方)
//	return 0;
//}

////时间复杂度示例二：计算以下程序的时间复杂度。
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;//执行了"2 * N"次。
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;//执行了十次。
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int N = 0;
//	scanf_s("%d", &N);
//	Func2(N);//可以得知此函数的内的语句的总的执行次数"T(N)"大概执行了"(2 * N) + (10)"次，故时间复杂度为：O(N)。
//	return 0;
//}

////时间复杂度示例三：计算以下程序的时间复杂度。
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;//执行了"M"次。
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;//执行了"N"次。
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int N = 0;
//	int M = 0;
//	scanf_s("%d%d", &N, &M);
//	Func3(N, M);//当"M"远大于或远小于"N"时，时间复杂度是：O(M)或O(N)；当"M"和"N"相近时，时间复杂度是：O(M)或O(N)；一般情况下时，时间复杂度是：O(M + N)。
//	return 0;
//}

////时间复杂度示例四：计算以下程序的时间复杂度。
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;//执行了一百次。
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int N = 0;
//	scanf_s("%d", &N);
//	Func4(N);//时间复杂度为：O(1)。
//	return 0;
//}

////时间复杂度示例五：计算"strchr"函数的时间复杂度。
//int main()
//{
//	char* str = "KilluaAoki";
//	printf("%s\n", strchr(str, 'A'));//可得知此函数是定位字符串中第一次出现的字符，需遍历字符串，故时间复杂度为：O(N)，其中"N"为字符串的长度。
//	return 0;
//}

////时间复杂度示例六：计算以下程序中"BubbleSort"函数的时间复杂度。
//void Swap(int* ptr1, int* ptr2)
//{
//	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
//}
//
//void BubbleSort(int* a, size_t n)
//{
//	if (a == NULL || n < 2)
//	{
//		return;
//	}
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, size);//根据冒泡排序的思想分析，可得知此算法的时间复杂度是：O(N ^ 2)，尽管在此处的函数中进行了优化(因要按照最坏情况得知时间复杂度)。(其中"^"符号表示次方)
//	//得知此算法的流程，可进行模糊化处理，从而得知时间复杂度。
//	//冒泡排序的开始是要将"N"个元素的数据之间进行比较，相邻两数谁大谁向右移动，移动的操作是常数阶的操作，但其要比较"N - 1"次。
//	//冒泡排序的下一步是将"N - 1"个元素之间进行比较，需要比较"N - 2"次。
//	//由此反复，直至最后是下标为"0"和下标为"1"的元素进行比较，需要比较"1"次。
//	//可发现比较的次数相加是等差数列的求和，故只保留最高阶项后(计算大"O"记法)，得知时间复杂度是：O(N ^ 2)。
//	
//	for (size_t i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	
//	return 0;
//}

////时间复杂度示例七：计算"BinarySearch"函数的时间复杂度。
//int BinarySearch(int* a, int n, int x)
//{
//	int begin = 0;
//	int end = n - 1;
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);//可得知此函数(二分查找)的思想是每次都会进行折半的查找，故此函数的时间复杂度为：O(longN)。
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

////时间复杂度示例八：计算"Fac"函数的时间复杂度。
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//	return Fac(N - 1) * N;//可发现递归了"N + 1"次，故此函数的时间复杂度为：O(N)。
//}

////时间复杂度示例九：计算"Fib"函数的时间复杂度。
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);//根据递归的层数可大致计算得知递归了"2 ^ N"次，故此函数的时间复杂度为：O(2 ^ N)。(其中"^"符号表示次方)(画图推导)
//}

/**
	空间复杂度：一个算法或程序的空间复杂度定性地描述该算法或程序运行所需要的存储空间大小，即临时占用存储空间大小的量度，也是额外空间复杂度的简写。
		1.空间复杂度的表示方法：与时间复杂度类似，空间复杂度通常也使用大"O"记号渐进法表示。
		2.不计入空间复杂度的情况：当算法或程序的流程中，需要额外的空间，才计入空间复杂度。
			a.作为输入参数的空间，不算额外空间。
			b.作为输出结果的空间，也不算额外空间。
		3.计算空间复杂度：函数运行时所需要的栈空间(存储参数、局部变量、一些寄存器信息等)在编译期间已经确定好了，因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定。
			a.当只开辟了有限的几个变量，则额外空间复杂度为常数阶。
			b.空间是可以重复利用的，不累计，但是时间是不能重复的，所以需要累计。
*/

////空间复杂度示例一：计算以下程序中"F1"函数的空间复杂度。
//void F1(int N)
//{
//	int a = 0;//在栈上开辟了一个空间存放变量，故此条语句的空间复杂度为：O(1)。
//	int* p = (int*)malloc(sizeof(int) * N);//在堆上动态开辟了"N"个空间，并在栈上开辟了一个空间存放变量，故此条语句的空间复杂度为：O(N)与O(1)。
//	printf("%p,%p\n", &a, &p);//可以发现两次调用地址都是一样的，可以得知空间是可以重复利用的。
//	if(p == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	free(p);
//}
//
//int main()
//{
//	F1(10);
//	F1(10);//两次调用后，"F1"函数共开辟了"N + 2"个额外空间，故"F1"函数的空间复杂度为：O(N)。
//	return 0;
//}

////空间复杂度示例二：计算"BubbleSort"函数的空间复杂度。
//void BubbleSort(int* a, size_t n)//只开辟了有限的几个变量，故此函数的空间复杂度为：O(1)。
//{
//	if (a == NULL || n < 2)
//	{
//		return;
//	}
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}

////空间复杂度示例三：计算"Fibonacci"函数的空间复杂度。
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));//此函数动态开辟了"N + 1"个空间，故空间复杂度为：O(N)。
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}

////空间复杂度示例四：计算"Fac"函数的空间复杂度。
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//	return Fac(N - 1) * N;//递归调用了"N + 1"次，开辟了"N + 1"个栈帧，每个栈帧使用了常数个空间，故空间复杂度为：O(N)。
//}

////空间复杂度示例五：计算"Fib"函数的空间复杂度。
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);//根据递归的层数可大致计算得知递归了"2 ^ N"次，但递归的层数是"N"层，开辟了"N"个栈帧，空间是重复利用的，每个栈帧使用了常数个空间，故此函数的空间复杂度为：O(N)。
//}