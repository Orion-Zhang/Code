#include <stdio.h>//C语言的"io"流头文件，不包含命名空间，使用C++语言包含C语言的头文件可考虑使用不带".h"的头文件版本。
#include <stdlib.h>//即C语言中的"standard library"标准库函数头文件，不包含命名空间。
#include <iostream>//C++语言的"io"流头文件，其中包含"cin"对象和"cout"对象等声明。
#include <cstdio>//C语言头文件"stdio.h"的C++语言版本，此版包含了命名空间。
#include <ctime>//C语言头文件"time.h"的C++语言版本，此版包含了命名空间。

/*
	C++入门
		01.C与C++。
		02.C++关键字。
		03.命名空间。
		04.C++的输入和输出。
		05.缺省参数。
		06.函数重载。
		07.引用。
		08.内联函数。
		09."auto"关键字(C++11)。
		10.基于范围的"for"循环(C++11)。
		11.指针空值"nullptr"(C++11)。
*/

/**
	C与C++
		1.C语言是结构化和模块化的语言，适合较小规模的程序，但对于复杂的问题，规模较大的程序需要高度的抽象和建模时，使用C语言并不合适。
		2.C++语言是基于C语言而产生的，它既可以进行C语言的过程化程序设计，又可以进行以抽象数据类型为特点的基于对象的程序设计，还可以进行以面向对象思想的程序设计。
		3.C++语言是在C语言的基础之上容纳进去了面向对象编程的思想，并增加了许多的库以及编程范式等特性的一门语言。
			a.补充了C语言语法的不足，并且将C语言设计不合理的地方进行优化。
*/

////C的"Hello World!"示例
//int main()
//{
//	printf("Hello World!\n");//C++语言兼容C语言，故可在C++语言使用C语言的函数。
//	return 0;
//}

////C++的"Hello World!"示例一
//int main()
//{
//	std::cout << "Hello World!" << std::endl;//"std"是C++标准库的命名空间，其中包含C++标准库的类、函数和变量。
//	return 0;
//}

////C++的"Hello World!"示例二
//using namespace std;//编译指令，此处使用"using"关键字和"namespace"关键字结合展开了头文件中"std"命名空间下的相关的所有东西。
//
//int main()
//{
//	cout << "Hello World!" << endl;
//	return 0;
//}

////C++的"Hello World!"示例三
//using std::cout;//使用"using"关键字，使"cout"变量(对象)可用。
//using std::endl;//使用"using"关键字，使"endl"变量(对象)可用。
//
//int main()
//{
//	cout << "Hello World!" << endl;
//	return 0;
//}

/**
	C++关键字
		1.C语言共有"32"个关键字，而C++的每套标准关键词数量都可能不同：C++11前共有"63"个关键词，而C++11起共有"73"个关键词，往后标准的关键词数量变化见"3.C++的关键词总览"。
		2.关键字的细节将包含在各个章节中。
		3.C++的关键词总览：https://zh.cppreference.com/w/cpp/keyword。
*/

/**
	命名空间：又称为名称空间，"std"是C++官方标准库的命名空间。
		01.在C++中，名称可以是变量、函数、结构、枚举、类以及类和结构的成员。
		02.命名空间的出现是为了解决在大型项目中，名称相互冲突的问题(名称空间问题)，C++标准中提供了名称空间工具，以便于更好地控制名称的作用域。
		03.使用命名空间的目的是对标识符的名称进行本地化，以避免命名冲突或名称污染。
		04.命名空间是可以嵌套的，并且在同一个项目中允许存在多个相同名称的命名空间，但编译器最后会合成进同一个命名空间中，但需要注意的是不同级(名字相同)的命名空间是不会合并的。
		05.一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中。
		06.命名空间可以是全局的，也可以位于另一个命名空间中，但是不能位于代码块中。
		07."using"关键字C++提供了两个机制，"using"声明使特定的标识符可用的功能，"using"编译指令使整个命名空间可用(结合"namespace"关键字)。
		08.在具有".h"后缀的头文件中是不支持名称空间的，故与C语言相关是不支持名称空间的，支持名称空间的C语言头文件是将".h"去除并在文件名最前方加上"c"。
			a.早期标准库将所有功能在全局域中实现，声明在".h"后缀的头文件中，使用时只需包含对应头文件即可，早期编译器依旧支持包含".h"后缀的C++头文件，其并不支持名称空间。
			b.后期的标准库因为有了名称空间工具，并为了和C语言的头文件进行区分，规定将C++的头文件不再带有后缀".h"。
			c.C++程序依旧可以使用老式C语言的头文件，但它也对老式C语言的头文件转换成C++头文件，有时C头文件的C版本和C++版本相同，而有时候新版本做了一些修改。
			d.这些被转换的头文件被重命名，去掉了后缀".h"(使之成为C++风格的头文件)，并在文件名称前面加上前缀"c"(表明来自于C语言)。
		09.使用命名空间的三种方式(见上方的三个"C++的"Hello World!"示例")
			a.命名空间名称以及作用域解析运算符。
			b.使用"using"关键字("using"声明)以及作用域解析运算符，将命名空间中某个名称引入。
			c.使用"using"("using"编译指令)关键字和"namespace"关键字，将命名空间中的所有名称引入(不推荐)。
		10.域
			a.实际上名称空间也属于域，但其其中所包含的各类名称是相当于在全局域中的，并可以理解成把这些名称包含在了一个空间内。
			b.局部变量或全局变量可理解成在局部域或全局域，两个域可声明或定义为相同的标识符(名称)的变量，但是同一个域不能定义同一个变量。
			c.编译器的默认的搜索规则是先在其局部域中搜索，无法找到则在全局域中搜索，但若在一个文件中变量的声明或定义在使用之后，是无法搜索到变量的。
			d.在某函数直接使用一个变量，是按照编译器的默认搜索规则搜索的，但若在其变量名前添加了"::"作用域解析运算符而不带名称空间，则直接在全局域中搜索变量。
			e.创建了名称空间后，与变量结合"::"作用域解析运算符，是将搜索规则改变成直接在此名称空间中搜索变量，若无法搜索到则报错。
			f.名称空间实际上是改变了变量的作用域，其生命周期并没有改变。
			g.局部变量是存放在内存中的栈上的，而名称空间内所定义或声明的变量是和全局变量一样存放在内存中的数据段(静态区)内的。
*/

////名称冲突示例
////int rand = 0;//编译器报错：将"rand"重新定义为不同类型的符号；此处就出现了名称冲突的问题，在C语言中是没办法解决类似这样的命名冲突问题的。
//
//int main()
//{
//	printf("%p\n", rand);//此处打印的是"stdlib.h"中的函数地址，若将全局变量"rand"的注释解除后再编译，会有声明与已在范围内使用声明的目标冲突的问题。
//	return 0;
//}

////使用"namespace"关键字创建命名空间示例一
//namespace Aoki
//{
//	int rand = 0;
//}
//
//int main()
//{
//	printf("%d\n", Aoki::rand);//使用"::"作用域解析运算符，通过"Aoki"这个名称空间访问到"rand"变量。
//	printf("%p\n", rand);
//	return 0;
//}

////使用"namespace"关键字创建命名空间示例二
//namespace N1
//{
//	int x = 5;
//	namespace N2
//	{
//		int y = 10;
//		namespace Test
//		{
//			int Add(int x, int y)
//			{
//				return x + y;
//			}
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", N1::N2::y);//通过"N1"访问到"N2"这个名称空间中的"y"变量。
//	printf("%d\n", N1::N2::Test::Add(N1::x, N1::N2::y));
//	return 0;
//}

////使用"namespace"关键字创建命名空间示例三
//namespace N1
//{
//	struct Node
//	{
//		int data;
//		struct N1* next;
//	};
//
//	namespace N2
//	{
//		struct Node
//		{
//			int data;
//			struct N2* prev;
//			struct N2* next;
//		};
//	}
//}
//
//int main()
//{
//	struct N1::Node Node1 = { 0 };
//	struct N1::N2::Node Node2 = { 0 };
//
//	struct N1::Node* pNode3 = nullptr;
//	struct N1::N2::Node* pNode4 = nullptr;
//
//	return 0;
//}

////使用"namespace"关键字创建命名空间示例四
//namespace N1
//{
//	int x = 5;
//	namespace N1
//	{
//		int y = 10;
//	}
//}
//
//int main()
//{
//	printf("%d\n", N1::x);
//	//printf("%d\n", N1::y);//错误语句。
//	printf("%d\n", N1::N1::y);//可以发现，即使名称空间的名字相同，但两个并不是同一级别的，所以并不会合并。
//	return 0;
//}

////域示例
//namespace Aoki
//{
//	int rand = 0;//相当于是把"rand"变量外套了一层"Aoki"名称空间，故不会与"rand"函数起冲突。
//}
//
////int rand = 0;//错误语句，会与"stdlib.h"头文件中的"rand"函数起冲突。
//
//int main()
//{
//	int rand = 5;//可以发现此条语句是没有问题的，并不会和"stdlib.h"头文件中的"rand"函数起冲突。
//
//	printf("%d\n", rand);//采用默认搜索规则，直接在局部域zhong找到了标识符为"rand"的变量，故此处结果为：5。
//
//	printf("%p\n", ::rand);//此处使用了"::"作用域解析运算符而不带名称空间，故搜索规则为直接在全局域中搜索"rand"标识符，也就是"stdlib.h"头文件中的"rand"函数，结果为"rand"函数的地址。
//
//	printf("%d\n", Aoki::rand);//"Aoki"名称空间与"rand"变量结合"::"作用域解析运算符，故搜索规则为搜索"Aoki"名称空间内的"rand"变量，故结果为：0。
//
//	//printf("%d\n", Aoki::test);//错误语句，名称空间"Aoki"中没有名为"test"的成员。
//
//	return 0;
//}

/**
	C++的输入和输出
		1.使用"cout"标准输出流(控制台)对象和"cin"标准输入流(键盘)对象时，需要包含"iostream"头文件，并且按照命名空间使用方法使用各个名称。
		2."cout"和"cin"都是全局的流对象，而"endl"是特殊的C++符号，表示换行输出(当然可以直接使用"\n"换行)，他们都包含在"iostream"头文件中。
		3."<<"为流插入运算符，">>"是流提取运算符。
		4.使用"cout"或"cin"进行输出或输入操作，可以自动识别变量类型，并不需要像"printf"或"scanf"输入输出时那样，需要手动指定格式化数据。
		5.实际上"cout"和"cin"分别是"ostream"和"istream"的类对象，"<<"和">>"也涉及运算符重载(C语言也是有运算符重载的情况的)。
*/

////C++的输入和输出示例
//int main()
//{
//	int x, y;
//	std::cin >> x >> y;//">>"：流提取运算符；可形象理解成"cin"对象从标准输入流提取数据流向"x"，再次重新从标准输入流提取流向"y"。
//	std::cout << x + y << std::endl;//"<<"：流插入运算符；可形象理解成输出也是一个流，即从程序流出的一系列字符，"cout"对象表示这种流，其对象属性包括流插入运算符，它可以将其右侧的信息插入到流中。
//	return 0;
//}

/**
	缺省参数：在声明或定义函数某个参数的时候为之指定一个默认值，在调用该函数的时候如果采用该默认值，你就无须指定该参数，即为缺省。
		1.全缺省：顾名思义就是声明或定义函数时，为每一个参数都给了一个默认值，所以在调用函数时可以全部缺省或者给定部分值。
		2.半缺省(部分缺省)：半缺省的函数参数，必须从右向左缺省，即从右向左依次给出默认值，不能间隔必须连续，并且不能越过最右边的变量进行缺省。
		3.缺省值必须是常量或者全局变量。
		4.缺省参数一般都在函数的声明处给出，缺省参数不能在函数声明和定义中同时出现，因为若恰巧声明和定义函数的两个位置的缺省参数的值不相同，那编译器便无法确认使用哪个缺省值。
		5.C语言是不支持缺省参数的。
*/

////全缺省示例
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	printf("a = %d  b = %d  c = %d\n", a, b, c);
//}
//
//int main()
//{
//	Func();//不传递任何实参给形参，并且"Func"函数是全缺省的，故"Func"函数的参数的值全部为其默认值。
//	Func(1);//只将值"1"传递给了"Func"函数的形参"a"变量，此函数的其他变量依旧是默认值。
//	Func(1, 2);//将值"1"和值"2"传递给了"Func"函数的形参"a"变量和形参"b"变量，此函数的其他变量依旧是默认值。
//	Func(1, 2, 3);//"Func"函数的所有形参都接收了实参的值。
//	//Func(1, , 2);//错误语句，不可以将实参间隔传递给形参。
//	return 0;
//}

////半缺省示例
//void Func(int a, int b, int c = 30)//注意必须从右向左依次缺省，不可以间隔必须连续，并且不能越过最右边的变量进行缺省。
//{
//	printf("a = %d  b = %d  c = %d\n", a, b, c);
//}
//
//int main()
//{
//	//Func();//错误语句，至少要再传递两个值给"Func"函数的形参"a"变量和形参"b"变量。
//	//Func(1);//错误语句，至少要再传递一个值给"Func"函数的形参"b"变量。
//	Func(1, 2);//将值"1"和值"2"传递给了"Func"函数的形参"a"变量和形参"b"变量，此函数的形参"c"变量是默认值。
//	Func(1, 2, 3);//"Func"函数的所有形参都接收了实参的值。
//	//Func(1, , 2);//错误语句，不可以将实参间隔传递给形参。
//	return 0;
//}

/**
	函数重载：C++允许在同一个作用域中声明几个功能类似的同名函数，这些函数的形参列表不同，常用来处理实现功能类似，但数据类型不同的问题。
		1.函数同名，是因为形参列表不同而实现重载，但是函数不能基于返回值类型不同实现重载。
			a.形参的类型不同。
			b.形参的个数不同。
			c.形参的类型顺序不同，注意不是形参变量名的顺序。
		2.C语言不支持函数重载，而C++支持。
			a.自动识别类型的本质是函数重载支持的。
			b.函数重载的原理是函数名字修饰规则。
			c.在编译期间，面对同名的函数，编译器会通过自身的函数名修饰规则从而修饰函数名，达到函数重载的目的。
			d.C语言中同名的函数是没有办法进行区分的，因为其函数名唯一，则对应的地址就唯一，编译后函数名依旧没有改变。
			e.C++通过函数修饰规则来区分函数，只要参数不同修饰出来的名字就不一样，就支持了函数重载。
			f.不同编译器下，函数修饰规则也不相同。
		3.返回值不同，而其它相同是不构成重载的。
			a.返回值不同，不构成重载的原因并不是因为函数名修饰规则。
			b.返回值不同，不构成重载的原因是调用函数并不指定返回值类型，就会产生二义性，故无法区分要调用哪一个函数。
*/

////函数重载示例一：形参的类型不同。
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	std::cout << Add(5, 5) << std::endl;
//	std::cout << Add(5.55, 4.44) << std::endl;
//	return 0;
//}

////函数重载示例二：形参的个数不同。
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Add(int x, int y, int z)
//{
//	return x + y + z;
//}
//
//int main()
//{
//	std::cout << Add(5, 5) << std::endl;
//	std::cout << Add(5, 2, 3) << std::endl;
//	return 0;
//}

////函数重载示例三：形参的类型顺序不同。
//void Test(int x, char y)
//{
//	std::cout << "Test(int x, char y)" << std::endl;
//}
//
//void Test(char x, int y)
//{
//	std::cout << "Test(char x, int y)" << std::endl;
//}
//
//int main()
//{
//	Test(0, 'A');
//	Test('A', 0);
//	return 0;
//}

////函数重载示例四：函数重载结合缺省参数。
//void Test()
//{
//	std::cout << "Test()" << std::endl;
//}
//
//void Test(char x = 'A', int y = 10)
//{
//	std::cout << "Test(char x, int y)" << std::endl;
//}
//
//int main()
//{
//	//Test();//错误语句，具有二义性，因不知道要调用哪一个函数。
//	Test('A');
//	Test('A', 100);
//	return 0;
//}

/**
	引用
		1.引用概念
			a.引用是C++新增的一种复合类型，它是已定义的变量的别名(另一个名称)。
			b.引用与被引用的变量共用一块内存空间，并且编译器不会为引用变量开辟内存空间。
			c.创建引用变量的方式："类型说明符"& "引用变量名(对象名)" = "已定义的变量名"。
			d.引用类型必须与被引用的变量类型一致，除非被引用的变量被"const"关键字修饰，因其涉及权限相关问题。
			e.左值参数是可被引用的数据对象，例如：变量、数组元素、结构体成员、引用和解除引用的指针。
			f.右值(非左值)参数是不可被引用的数据对象，例如：字面常量(用引号括起来的字符串除外)和包含多项的表达式，在C++11中，新增了右值引用，并且左值参数也是右值参数的子集。
			g.常规变量和"const"变量都可视为左值，但常规变量可被修改，而"const"变量不可被修改。
		2.引用特性
			a.在声明引用变量时必须进行初始化。
			b.一个变量可以有多个引用。
			c.引用变量一旦与一个实体关联起来，就无法再改变，即无法再引用其他实体。
		3.常引用：在引用变量前加上"const"关键字，即可创建常引用，并且常引用可以引用常量，也可以引用变量。
			a.权限相关问题：在指针和引用赋值中，权限可以缩小或平移，但是不能放大。
			b.当发生类型转换时，C++将生成临时变量，而临时变量具有常属性。
		4.使用场景
			a.作为函数参数传递
				a'.如果函数调用的参数不是左值或与相应的"const"引用参数的类型不匹配，则C++将创建类型正确的匿名临时变量，将函数调用的参数的值传递到该变量，并让参数引用该变量。
				b'.如果实参与引用参数不匹配，C++将生成临时变量，而临时变量具有常属性。(当前，仅当参数为"const"引用时，C++才允许这样做)
				c'.在引用形参中，应尽量使用"const"的理由
					a''.可以避免无意中修改了数据导致的错误。
					b''.使函数能够处理"const"和非"const"实参，否则只能处理非"const"实参。
					c''.使函数能够正确生成并使用临时变量。
			b.作为函数返回值
				a'.关于函数具有返回值时，产生临时变量的问题，详见：https://szza.github.io/2021/03/03/C++/RVO/。
				b'.当函数返回时，出了函数作用域，如果返回变量(对象)还在(未被销毁)，则可以使用引用返回，如果已经被销毁了，则必须使用传值返回，并且接收返回值时需要注意权限问题。
		5.不同情况下的效率比较
			a.传值和传引用效率比较
				a'.以值作为函数参数时，在传参期间，函数不会直接传递实参，而是传递实参的一份临时拷贝，用值作为参数效率是非常低下的，尤其是当参数非常大时，效率就更低。
			b.值和引用的作为返回值类型的效率比较
				a'.以值作为函数返回值时，在返回期间，函数不会将变量本身直接返回，而是返回变量的一份临时拷贝，用值作为返回值效率是非常低下的，尤其是当返回值非常大时，效率就更低。
		6.引用和指针的区别
			a.语法概念和底层实现上的区别
				a'.在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间。
				b'.在底层实现上实际是有空间的，因为引用是按照指针方式来实现的(反编译后对比代码)。
			b.引用概念上定义一个变量的别名，而指针存储一个变量地址。
			c.引用必须初始化，而指针可以不初始化。
			d.引用一旦初始化后，就不能再改变引用的对象，而指针可以改变指向的对象。
			e.引用没有空引用的概念，但是指针有空指针的概念。
			f."sizeof"中的含义不同：以引用计算的结果为引用类型的大小，但以指针计算的结果始终是地址空间所占字节个数。
			g.引用自增自减的含义不同：引用自增自减的含义是对引用的对象自增自减，而指针自增自减的含义是对指针本身加减一个指针类型的大小。
			h.有多级指针的概念，但是没有多级引用的概念。
			i.访问引用的对象时，不需要解引用，直接使用引用变量即可，而指针需要解引用才能访问指针指向的对象。
			j.引用相比指针使用起来更安全。
*/

////引用示例一：创建引用变量。
//int main()
//{
//	int a = 10;
//
//	int& b = a;//创建了一个引用变量"b"，引用变量"b"与变量"a"共用一块内存空间。
//	std::cout << "a = " << a << std::endl;
//	std::cout << "b = " << b << std::endl;//可以发现引用变量"b"与变量"a"的值是一样的。
//	std::cout << "&a = " << &a << std::endl;
//	std::cout << "&b = " << &b << std::endl;//可以发现引用变量"b"与变量"a"共用一块内存空间。
//
//	b = 20;
//	std::cout << "a = " << a << std::endl;//通过引用变量"b"修改变量"a"的值。
//	std::cout << "b = " << b << std::endl;
//	std::cout << "&a = " << &a << std::endl;
//	std::cout << "&b = " << &b << std::endl;
//
//	return 0;
//}

////引用示例二：引用变量的特性。
//int main()
//{
//	int a = 10;
//	int& b = a;//创建了一个引用变量"b"，引用变量"b"与变量"a"共用一块内存空间。
//	int& c = a;//一个变量可以有多个引用。
//	//int& d;//错误语句，引用变量必须进行初始化。
//	std::cout << "a = " << a << std::endl;
//
//	int e = 20;
//	b = e;//此行语句的意思是将变量"e"的值通过引用变量"b"赋值给变量"a"，而不是改变引用变量"b"引用的目标。
//	std::cout << "a = " << a << std::endl;
//
//	return 0;
//}

////引用示例三：常引用的权限问题。
//int main()
//{
//	int a = 10;
//	int& ra = a;//权限平移，变量"a"是可读可写的，引用变量"ra"也是可读可写的。
//	const int& cra = a;//权限缩小，变量"a"是可读可写的，引用变量"cra"是只读的。
//	//int& rcra = cra;//错误语句，权限放大，引用变量"rcra"是可读可写的，引用变量"cra"是只读的。
//
//	ra = 20;//变量"ra"可以修改变量"a"的值。
//	//cra = 20;//错误语句，不能修改变量"a"的值，因为引用变量"cra"是只读的。
//
//	const int b = 20;
//	a = b;//此行语句是把变量"b"的值赋值给变量"a"，变量"a"是可读可写的，变量"b"是只读的，故此行语句是合法的。
//	a = 30;//此行语句是把常量"30"赋值给变量"a"，变量"a"是可读可写的，常量"30"是只读的，故此行语句是合法的。
//	//int& rb = b;//错误语句，权限放大，引用变量"rb"是可读可写的，变量"b"是只读的。
//	const int& crb = b;//权限平移，变量"b"是只读的，引用变量"crb"也是只读的。
//
//	const int& c = 10;//此行语句使用常引用变量"c"引用了一个常量"10"，引用变量"c"是只读的，常量"10"是只读的，故此行语句是合法的。
//	//int& d = 10;//错误语句，权限放大，常量"10"是只读的，引用变量"b"是可读可写的。
//
//	return 0;
//}

////引用示例四：引用具有常属性的变量(临时变量)。
//int main()
//{
//	double pi1 = 3.1415926;
//
//	std::cout << "pi1 = " << pi1 << std::endl;
//
//	std::cout << "(int)pi1 = " << (int)pi1 << std::endl;//强制类型转换，会产生临时变量(观察反汇编可发现是寄存器)，此时打印的是临时变量的值。
//
//	int pi2 = pi1;//隐式类型转换，可能会有精度损失，同样会产生临时变量，此时是将临时变量的值赋值给变量"pi2"。
//
//	int pi3 = (int)pi1;//强制类型转换，产生临时变量，此时是将临时变量的值赋值给变量"pi3"。
//
//	//int& rpi1 = pi1;//错误语句，编译报出警告：对"int"类型的非常量左值引用不能绑定到不相关类型"double"的值。
//
//	const int& cpi1 = pi1;//此处"cpi1"引用的对象其实是一个临时变量(发生隐式类型转换)，而临时变量的值是"pi1"的整数部分，并且临时变量是只读的(具有常属性)，故此行语句是合法的。
//
//	const int& a = 10;//常量"10"是只读的，引用变量"a"是只读的，故此行语句是合法的，并且不会产生临时变量。
//
//	return 0;
//}

////引用示例五：将引用作为函数参数传递，交换两个变量。
//void Swap1(int* px, int* py)
//{
//	int temp = *px;
//	*px = *py;
//	*py = temp;
//}
//
//void Swap2(int& rx, int& ry)
//{
//	int temp = rx;
//	rx = ry;
//	ry = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	Swap1(&a, &b);//传递的是变量"a"和变量"b"的地址，交换函数内部通过指针修改了变量"a"和变量"b"的值。
//	printf("a = %d, b = %d\n", a, b);
//
//	Swap2(a, b);//传递的是变量"a"和变量"b"的引用，交换函数内部通过引用修改了变量"a"和变量"b"的值。
//	printf("a = %d, b = %d\n", a, b);
//
//	return 0;
//}

////引用示例六：将引用作为函数返回值，以下示例为未定义行为。
//int& Count()
//{
//	int n = 0;//局部变量，函数执行完毕后会被销毁，即函数内所使用的内存空间的使用权被归还，数据可能留存，但不再受保护(可能会被覆盖)。
//	std::cout << "&n = " << &n << std::endl;//打印局部变量"n"的地址。
//	return (++n);//返回变量"n"的引用后，变量"n"的生命周期结束。
//}
//
//void Func()
//{
//	int n = 10;
//	std::cout << "&n = " << &n << std::endl;//打印局部变量"n"的地址，会发现与函数"Count"中的局部变量"n"的地址相同(不一定)。
//}
//
////int& Err_Count()
////{
////	int n = 0;
////	return n;//编译器(Clion)直接报错：对"int"类型的非常量左值引用不能绑定到"int"类型的临时值。
////}
//
//int main()
//{
//	int& ret = Count();//此时返回的是一个临时变量的引用，"Count"函数执行完毕后，临时变量的生命周期结束，临时变量的值被销毁，此时"ret1"的值是不确定的。
//	std::cout << "ret = " << ret << std::endl;//不同的编译器可能会打印出不同的值，可能会打印出未被覆盖的值"1"，但是一定会打印出一个不合法的值。
//	std::cout << "ret = " << ret << std::endl;//不同的编译器可能会打印出不同的值，但是一定会打印出一个不合法的值。
//	Func();
//	std::cout << "ret = " << ret << std::endl;//不同的编译器可能会打印出不同的值，但是一定会打印出一个不合法的值。
//	std::cout << "&ret = " << &ret << std::endl;//打印变量"ret"的地址，实际上就是打印了局部变量"n"的地址，可能会发现与函数"Count"中的局部变量"n"的地址相同(不一定)。
//	return 0;
//}

////引用示例七：将引用作为函数返回值，对于"引用示例六"的正确用法。
//int Count1()
//{
//	static int n = 0;
//	std::cout << "&n = " << &n << std::endl;
//	return ++n;
//}
//
//int& Count2()
//{
//	static int n = 0;//静态变量，存放于内存中的静态区(数据段)，"Count2"函数执行完毕后，静态变量的生命周期不会结束，"n"的值会一直保留。
//	std::cout << "&n = " << &n << std::endl;
//	return ++n;
//}
//
//int main()
//{
//	int ret1 = Count1();
//	int ret2 = Count2();
//	std::cout << "ret1 = " << ret1 << std::endl;
//	std::cout << "ret2 = " << ret2 << std::endl;
//	return 0;
//}

////引用示例八：将引用作为函数的参数，并结合常引用。
//void Func1(int& n)
//{
//	std::cout << "Func1(n) = " << n << std::endl;
//}
//
//void Func2(const int& n)
//{
//	std::cout << "Func2(n) = " << n << std::endl;
//}
//
//int main()
//{
//	int a = 0;
//	int& ra = a;
//	Func1(a);//权限平移，传入函数"Func1"的是变量"a"的引用，函数"Func1"中的形参"n"是变量"a"的别名，函数"Func1"中对形参"n"的操作，实际上就是对变量"a"的操作。
//	Func1(ra);//权限平移，传入函数"Func1"的是变量"ra"的引用，而变量"ra"实际上是变量"a"的别名，那么函数"Func1"中的形参"n"也是变量"a"的别名，函数"Func1"中对形参"n"的操作，实际上就是对变量"a"的操作。
//	Func2(a);//权限缩小，传入函数"Func2"的是变量"a"的常引用，函数"Func2"不能对常引用形参"n"进行修改，也代表函数"Func2"不能对变量"a"进行修改。
//	Func2(ra);//权限缩小，传入函数"Func2"的是变量"ra"的常引用，而变量"ra"实际上是变量"a"的别名，那么函数"Func2"中的形参"n"也是变量"a"的常引用，函数"Func2"不能对常引用形参"n"进行修改，也代表函数"Func2"不能对变量"a"进行修改。
//
//	const int b = 0;
//	//Func1(b);//错误语句，权限放大，变量"b"是只读的，而函数"Func1"中的形参"n"是可读可写的，不能将只读的变量"b"的引用传递给可读可写的形参"n"。
//	Func2(b);//权限平移，变量"b"是只读的，而函数"Func2"中的形参"n"也是只读的。
//
//	//Func1(0);//错误语句，权限放大，常量"0"是只读的，而函数"Func1"中的形参"n"是可读可写的。
//	Func2(0);//权限平移，常量"0"是只读的，而函数"Func2"中的形参"n"也是只读的。
//
//	return 0;
//}

////引用示例九：将引用作为函数的返回值，并结合常引用。
//int Count1()
//{
//	static int n = 0;
//	std::cout << "n = " << n << std::endl;
//	return ++n;
//}
//
//int& Count2()
//{
//	static int n = 0;
//	std::cout << "n = " << n << std::endl;
//	return ++n;
//}
//
//int main()
//{
//	int retCount1 = Count1();//函数"Count1"的返回值是变量"n"的值，期间产生了临时变量，并将变量"n"的值赋值给了临时变量，然后再将临时变量的值赋值给变量"retCount1"。
//	int retCount2 = Count2();//函数"Count2"的返回值是变量"n"的引用(产生临时变量不再赘述)，再产生临时变量以满足类型转换，并将新生成的临时变量的值赋值给变量"retCount2"。
//
//	//int& ret1 = Count1();//错误语句，权限放大，函数"Count1"的返回值是变量"n"的值(产生临时变量不再赘述)，临时变量的值是只读的，而引用"ret1"是可读可写的，不能将只读的返回值的引用传递给可读可写的引用。
//	const int& ret2 = Count1();//权限平移，函数"Count1"的返回值是变量"n"的值(产生临时变量不再赘述)，临时变量的值是只读的，而常引用"ret2"也是只读的。
//
//	int& ret3 = Count2();//权限平移，函数"Count2"的返回值是变量"n"的引用(产生临时变量不再赘述)，此时临时变量是变量"n"的引用，并且是可读可写的，再将其传递给引用"ret3"(可读可写)。
//	const int& ret4 = Count2();//权限缩小，函数"Count2"的返回值是变量"n"的引用(产生临时变量不再赘述)，此时临时变量是变量"n"的引用，并且是可读可写的，再将其传递给常引用"ret4"(只读)。
//
//	return 0;
//}

////引用示例十：传值和传引用效率比较。
//struct A
//{
//	int a[100000];
//};
//
//void TestFunc1(A a)
//{
//
//}
//
//void TestFunc2(A& a)
//{
//
//}
//
//void TestRefAndValue()
//{
//	A a;
//
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//
//	//以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//
//	//分别计算两个函数运行结束后的时间
//	std::cout << "TestFunc1(A)-time:" << end1 - begin1 << std::endl;
//	std::cout << "TestFunc2(A&)-time:" << end2 - begin2 << std::endl;
//}
//
//int main()
//{
//	TestRefAndValue();//以引用作为函数参数的效率要比以值作为函数参数的效率高。
//	return 0;
//}

////引用示例十一：值和引用的作为返回值类型的效率比较。
//struct A
//{
//	int a[100000];
//};
//
//A a;
//
////值返回
//A TestFunc1()
//{
//	return a;
//}
//
////引用返回
//A& TestFunc2()
//{
//	return a;
//}
//
//void TestReturnByRefOrValue()
//{
//	//以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//	{
//		TestFunc1();
//	}
//	size_t end1 = clock();
//
//	//以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//	{
//		TestFunc2();
//	}
//	size_t end2 = clock();
//
//	//计算两个函数运算完成之后的时间
//	std::cout << "TestFunc1()-time:" << end1 - begin1 << std::endl;
//	std::cout << "TestFunc2()-time:" << end2 - begin2 << std::endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();//以引用作为函数的返回值类型的效率要比以值作为函数的返回值类型的效率高。
//	return 0;
//}

////引用示例十二：引用和指针在语法概念和底层实现上的区别。
//int main()
//{
//	int a = 10;
//
//	//以下代码反汇编后可以发现：引用实际是有空间的，因为引用是按照指针方式来实现的。
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//
//	//以下代码可以发现：引用和指针在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间。
//	std::cout << "&a = " << &a << std::endl;
//	std::cout << "&ra = " << &ra << std::endl;
//
//	return 0;
//}

////引用示例十三：引用结合缺省参数和函数重载。
//void TestFunc(int& a)
//{
//	printf("TestFunc(int& a = %d)\n", a);
//}
//
//void TestFunc(const int& a = 10)
//{
//	printf("TestFunc(const int& a = %d)\n", a);
//}
//
//int main()
//{
//	//以下代码调用的是"void TestFunc(int& a)"函数
//	int a = 0;
//	int& ra = a;
//	TestFunc(a);
//	TestFunc(ra);
//
//	//以下代码调用的是"void TestFunc(const int& a = 10)"函数
//	TestFunc();
//	TestFunc(100);
//
//	return 0;
//}