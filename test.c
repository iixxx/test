#include<stdio.h>

ָ������������
int main()
{
	return 0;
}
//a-int*         ����ָ��
//&a-int(*)[4]   ����ָ��    ����ĵ�ַ��
//&a[0]+1->&a[1]

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };


	printf("%d\n", sizeof(arr));//arr������������������sizeof�ڲ����������������ܴ�С����λ���ֽ�  6
	printf("%d\n", sizeof(arr + 0));//arr�������������ǵ�������sizeof�ڲ���arr��ʾ��Ԫ�ص�ַ��arr+0��ʾ������Ԫ�ص�ַ����ַ����4/8���ֽ�
	printf("%d\n", sizeof(*arr));//arr����Ԫ�صĵ�ַ��*arr������Ԫ�أ�sizeof������Ԫ�ش�С  1
	printf("%d\n", sizeof(arr[1]));//arr[1]������ڶ���Ԫ�أ�sizeof��arr[1])������ǵڶ���Ԫ�صĴ�С  1
	printf("%d\n", sizeof(&arr));//ȡ����ĵ�ַ��Ҳ�ǵ�ַ   4/8
	printf("%d\n", sizeof(&arr+1));//ȡ��������ĵ�ַ��+1�����������飬�����ǵ�ַ   4/8
	printf("%d\n", sizeof(&arr[0]+1));//ȡ��Ԫ�صĵ�ַ+1������һ���ַ���ָ��b'�ĵ�ַ  4/8   ��ֻ��ָֻ���ַ��û�зǷ����ʣ�    
	return 0;
}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	//strlrn���ַ�������  
	//�ַ����Ľ�����־��'\0'  ASCII��0

	printf("%d\n", strlen(arr));//���ֵ ��ʱarr����Ԫ�صĵ�ַ��ֱ���ҵ�\0������arr��û��\0������\0��λ��������ģ����������ֵ
	printf("%d\n", strlen(arr + 0));//���ֵ  ͬ�ϣ���Խ�磬��ֻ�ǿ�����û�з���
	printf("%d\n", strlen(*arr));//error   *arr ����Ԫ��'a��97,strlen��97������ַ��error������ɷǷ�����
	printf("%d\n", strlen(arr[1]));//error  �ڶ���Ԫ�أ�98���Ƿ�����
	printf("%d\n", strlen(&arr));//���ֵ   ����ĵ�ַ��Ҳ��ָ���������ʵλ��
	printf("%d\n", strlen(&arr+1));//���ֵ   �����������飬��&arr��6��
	printf("%d\n", strlen(&arr[0]+1));//���ֵ


	return 0;
}

int main()
{
	char arr[] = "abcdef";
	//a b c d e f \0

	printf("%d\n", sizeof(arr));//7  ������������
	printf("%d\n", sizeof(arr + 0));//4\8  ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));//1  ����Ԫ�ؽ�����
	printf("%d\n", sizeof(arr[1]));//1 ����ڶ����ַ�
	printf("%d\n", sizeof(&arr));//4\8   ��������ĵ�ַ
	printf("%d\n", sizeof(&arr + 1));//4\8   ������������ĵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));//4\8   ������һ���ַ��ĵ�ַ�����ǵ�ַ


	//a b c d e f \0

	printf("%d\n", strlen(arr));//6  ��Ԫ�ص�ַ
	printf("%d\n", strlen(arr + 0));//6  ��Ԫ�ص�ַ
	printf("%d\n", strlen(*arr));//error  *arr ����Ԫ��  a  97,strlen��97������ַ
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ   ������������
	printf("%d\n", strlen(&arr[0] + 1));//5
	



	return 0;
}

int main()
{
	const char* p = "abcdef";
	//a b c d e f \0


	printf("%d\n", sizeof(p));//4\8  һ��ָ������Ĵ�С ��ַ
	printf("%d\n", sizeof(p + 1));//4\8   ������ַ
	printf("%d\n", sizeof(*p));//1   ������charֻ�ܷ��� һ���ֽ�
	printf("%d\n", sizeof(p[0]));//1   p[0] == *(p+0) == *p
	printf("%d\n", sizeof(&p));//4\8   ȡp�ĵ�ַ
	printf("%d\n", sizeof(&p + 1));//4\8  ȡp�ĵ�ַ+1������p��������ַ�����ܹ��Ǹ���ַ
	printf("%d\n", sizeof(&p[0] + 1));//  4\8  b�ĵ�ַ

	//p[0] == *(p + 0) == *p
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//���ֵ
	printf("%d\n", strlen(&p + 1));//���ֵ
	printf("%d\n", strlen(&p[0] + 1));//5   ȡ����b�ĵ�ַ
}

int main()
{
	//��ά����Ҳ�����飬a��Ҳ��������
	int a[3][4] = { 0 };
	/* 0 1 2 3
	0
	1
	2*/
	//sizeof�ڲ����ʽ���������sizeof(num=a+2);cv
	printf("%d\n", sizeof(a));//48    a�Ƕ�ά���������������������������飬��λ�ֽ�
	printf("%d\n", sizeof(a[0][0]));//4    aû�е������֣�a��һ��
	printf("%d\n", sizeof(a[0]));//16    a[0]�ǵ�һ�е���������
	printf("%d\n", sizeof(a[0]+1));//4/8    a[0]û�е������֣������ǵ�һ�е���Ԫ�ص�ַ==&a[0][0]  +1==&a[0][1]
	printf("%d\n", sizeof(*(a[0]+1)));//4   �Ե�ַ�����ã���С��4���ֽ�
	printf("%d\n", sizeof(a + 1));//4/8    ��ά�������Ԫ�ؾ��ǵ�һ�еĵ�ַ��Ҳ����һά����ĵ�ַ��+1����һ�У��ڶ��еĵ�ַ��Ҳ�ǵ�ַ
	//a - &a[0]
	//a+1 - &a[1]
	printf("%d\n", sizeof(*(a + 1)));//16   a+1�ǵڶ��еĵ�ַ�������þ����ҵ��ڶ��У�����ľ��ǵڶ��еĴ�С
	//*(a+1) - a[1]
	printf("%d\n", sizeof(&a[0] + 1));//4/8   ȡ��һ�еĵ�ַ��+1���ǵڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));//16   �ڶ��еĵ�ַ�����ã����������ڶ��д�С
	printf("%d\n", sizeof(*a));//16     ��һ�еĵ�ַ������
	printf("%d\n", sizeof(a[3]));//16   int[4]��Ȼû�е����У���������ȷ�����Դ�С����ȷ����
	return 0;
}

