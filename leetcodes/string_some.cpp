#include <iostream>
#include <stdio.h>
using namespace std;

/*
一些字符串的操作处理
 */
//左旋转操作字符串 abcdef ,2位——> cdefab
// abcdef -> ab,cdef->ba,fedc->cdefab

char* reverse(char*str, int k){
	int len = strlen(str);
	printf("%c\n", str[0]);
	int i=0, j=k-1;
	printf("%d, %d\n", i, j);
	char tmp;
	while (i<j){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
		printf("%s\n", str);
		printf("%d, %d\n", i, j);
	}
	// for(; i<j; ++i, --j){
		
	// }
	printf("%d, %d\n", i, j);
	printf("%s\n", str);
}

char* Reverse(char* SwapStr,int pos,int num)
{
	//pos：待旋转的字符串所在的首个字符位序 num:待旋转的字符串的最后一个字符位序    ---用于旋转字符串中的分治逆序旋转
	char temp;
	for (;pos<num;pos++,num--)
	{
		//这里头解决了旋转完字符串后字符位序会发生变化的问题----因为同时进行了首尾的移动
		temp = SwapStr[pos];
		SwapStr[pos] = SwapStr[num];
		SwapStr[num] = temp;
	}
	return SwapStr;
}

//反转字符串
char * reverse_k(char* str, int n, int k){
	k %= n;
	Reverse(str, 0, k-1);
	Reverse(str, k, n-1);
	Reverse(str, 0, n-1);
	return str;
}


char * reverse_my(char* str, int pos, int num){
	char tmp;
	for(; pos<num; pos++; num--){
		tmp = str[pos];
		str[pos] = str[num];
		str[num] = tmp;
	}
	return str
}


int main(){
	char str[] = "abcdef";
	printf("%s\n", str);
	// reverse(str, 2);
	
	reverse_k(str, 6, 2);

	// Reverse(str, 0, 2);
	printf("%s\n", str);
}
