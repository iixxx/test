#include<stdio.h>

指针和数组笔试题
int main()
{
	return 0;
}
//a-int*         整形指针
//&a-int(*)[4]   数组指针    数组的地址，
//&a[0]+1->&a[1]

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };


	printf("%d\n", sizeof(arr));//arr是数组名，单独放在sizeof内部，计算的是数组的总大小，单位是字节  6
	printf("%d\n", sizeof(arr + 0));//arr是数组名，并非单独放在sizeof内部，arr表示首元素地址，arr+0表示还是首元素地址，地址就是4/8个字节
	printf("%d\n", sizeof(*arr));//arr是首元素的地址，*arr就是首元素，sizeof计算首元素大小  1
	printf("%d\n", sizeof(arr[1]));//arr[1]是数组第二个元素，sizeof（arr[1])计算的是第二个元素的大小  1
	printf("%d\n", sizeof(&arr));//取数组的地址，也是地址   4/8
	printf("%d\n", sizeof(&arr+1));//取的是数组的地址，+1跳过整个数组，但还是地址   4/8
	printf("%d\n", sizeof(&arr[0]+1));//取首元素的地址+1，跳过一个字符，指向‘b'的地址  4/8   （只是只指向地址，没有非法访问）    
	return 0;
}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	//strlrn求字符串长度  
	//字符串的结束标志是'\0'  ASCII是0

	printf("%d\n", strlen(arr));//随机值 此时arr是首元素的地址，直到找到\0截至，arr中没有\0，所以\0的位置是随机的，所以是随机值
	printf("%d\n", strlen(arr + 0));//随机值  同上，虽越界，但只是看看，没有访问
	printf("%d\n", strlen(*arr));//error   *arr 是首元素'a’97,strlen将97当作地址，error，会造成非法访问
	printf("%d\n", strlen(arr[1]));//error  第二个元素，98，非法访问
	printf("%d\n", strlen(&arr));//随机值   数组的地址，也是指向数组的其实位置
	printf("%d\n", strlen(&arr+1));//随机值   跳过整个数组，比&arr少6个
	printf("%d\n", strlen(&arr[0]+1));//随机值


	return 0;
}

int main()
{
	char arr[] = "abcdef";
	//a b c d e f \0

	printf("%d\n", sizeof(arr));//7  计算整个数组
	printf("%d\n", sizeof(arr + 0));//4\8  首元素的地址
	printf("%d\n", sizeof(*arr));//1  对首元素解引用
	printf("%d\n", sizeof(arr[1]));//1 数组第二个字符
	printf("%d\n", sizeof(&arr));//4\8   整个数组的地址
	printf("%d\n", sizeof(&arr + 1));//4\8   跳过整个数组的地址
	printf("%d\n", sizeof(&arr[0] + 1));//4\8   跳过第一个字符的地址，还是地址


	//a b c d e f \0

	printf("%d\n", strlen(arr));//6  首元素地址
	printf("%d\n", strlen(arr + 0));//6  首元素地址
	printf("%d\n", strlen(*arr));//error  *arr 是首元素  a  97,strlen将97当作地址
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值   跳过整个数组
	printf("%d\n", strlen(&arr[0] + 1));//5
	



	return 0;
}

int main()
{
	const char* p = "abcdef";
	//a b c d e f \0


	printf("%d\n", sizeof(p));//4\8  一个指针变量的大小 地址
	printf("%d\n", sizeof(p + 1));//4\8   跳过地址
	printf("%d\n", sizeof(*p));//1   解引用char只能访问 一个字节
	printf("%d\n", sizeof(p[0]));//1   p[0] == *(p+0) == *p
	printf("%d\n", sizeof(&p));//4\8   取p的地址
	printf("%d\n", sizeof(&p + 1));//4\8  取p的地址+1，跳过p的整个地址，但总归是个地址
	printf("%d\n", sizeof(&p[0] + 1));//  4\8  b的地址

	//p[0] == *(p + 0) == *p
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//随机值
	printf("%d\n", strlen(&p + 1));//随机值
	printf("%d\n", strlen(&p[0] + 1));//5   取的是b的地址
}

int main()
{
	//二维数组也是数组，a就也是数组名
	int a[3][4] = { 0 };
	/* 0 1 2 3
	0
	1
	2*/
	//sizeof内部表达式不参与计算sizeof(num=a+2);cv
	printf("%d\n", sizeof(a));//48    a是二维数组的数组名，计算的是整个数组，单位字节
	printf("%d\n", sizeof(a[0][0]));//4    a没有单独出现，a是一个
	printf("%d\n", sizeof(a[0]));//16    a[0]是第一行的整个数组
	printf("%d\n", sizeof(a[0]+1));//4/8    a[0]没有单独出现，所以是第一行的首元素地址==&a[0][0]  +1==&a[0][1]
	printf("%d\n", sizeof(*(a[0]+1)));//4   对地址解引用，大小是4个字节
	printf("%d\n", sizeof(a + 1));//4/8    二维数组的首元素就是第一行的地址，也就是一维数组的地址，+1跳过一行，第二行的地址，也是地址
	//a - &a[0]
	//a+1 - &a[1]
	printf("%d\n", sizeof(*(a + 1)));//16   a+1是第二行的地址，解引用就是找到第二行，计算的就是第二行的大小
	//*(a+1) - a[1]
	printf("%d\n", sizeof(&a[0] + 1));//4/8   取第一行的地址，+1就是第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));//16   第二行的地址解引用，计算整个第二行大小
	printf("%d\n", sizeof(*a));//16     第一行的地址解引用
	printf("%d\n", sizeof(a[3]));//16   int[4]虽然没有第四行，但是类型确定所以大小就是确定的
	return 0;
}

