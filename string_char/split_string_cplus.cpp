#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

/*
失败的函数！
 */
void split(const std::string &s, std::vector<std::string> &sv, const char* delim = " "){
	sv.clear();
	char * buffer = new char[s.size() + 1];
	std::copy(s.begin(), s.end(), buffer);
	char *p = std::strtok(NULL, delim);
	do {
		sv.push_back(p);
	}while ((p=std::strtok(NULL, delim)));
	return;
}

int main_split() {
    std::string s("abc:def::ghi");
    std::vector<std::string> sv;

    split(s, sv, ":");

    for (std::vector<std::string>::const_iterator iter = sv.begin();
                                                   iter != sv.end();
                                                             ++iter) {
        std::cout << *iter << std::endl;
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main_just_strtok()
{
	char str[] = "now , is the time for all , good men to come to the , aid of their country";
	char *delims = ",";
	char *result = NULL;
	result = strtok(str, delims);
	while (result != NULL){
		printf("result is \"%s\"\n", result);
		result = strtok(NULL, delims);
	}
	return 0;
}


/*
看到一个例子
http://garypan.iteye.com/blog/669073
是360面试的时候面试官给出的函数表头样式
 */
char ** cSplit(char * string, char spliter){
	//分割后字符串数量
	int num = 0;
	int i = 0;
	int size = strlen(string);
	for (; i<size; i++){
		if ((string[i] != spliter) && (string[i+1] == spliter || string[i+1] == '\0')){
			num ++;
		}
	}
	//分配空间
	char ** cStrings = (char**)malloc(sizeof(char*)*(num+1));
	int j = 0;
	for (; j<=num; j++){
		//初始化指针数组
		cStrings[j] = 0;
	}
	//保存分割后的字符串
	char * buffer = (char*)malloc(sizeof(char) * (size+1));
	int l = 0;
	for (; l < size+1; l++){
		buffer[l] = 0;
	}
	int counter = 0, k=0;
	for(; k<size; k++){
		if (string[k] != spliter){
			int i=0;
			int j = k;
			while(string[j] != spliter && string[j] != '\0'){
				buffer[i++] = string[j++];
			}
			buffer[i] = '\0';
			printf("%s\n", buffer);
			cStrings[counter] = (char*)malloc(sizeof(char) * i);
			strcpy(cStrings[counter++], buffer);
			k = k+i;
		}
	}
	free(buffer);
	return cStrings;
}

int main_csplit(){
	// char * str= "this, is a, bad, day!";
	// char delims = ',';
	// cSplit(str, delims);
	// 
	char str[] = "hello";
	char *s = str;
	// char str[] = s;  wrong
	for (int i=0; i<strlen(str); i++){
		printf("%c\n", *s++);
	}
	printf("%s\n", str);
	printf("%d\n", strlen(str));
}


/*
int main()
{
	char *c="abcdef";
	char d[]="abcdef";
	char e[]={'a','b','c','d','e','f'};

	printf("%d %d\n",sizeof(c),strlen(c));
	printf("%d %d\n",sizeof(d),strlen(d));
	printf("%d %d\n",sizeof(e),strlen(e));
}
*/
/*
8 6
7 6
6 12
 */

int main_test(){
	std::string s = "hello, my name is world, hello, my name is OK";
	std::string pat = "hello";
	int pos = s.find(pat, 1);
	std::cout<<"pos:"<<pos<<std::endl;

	return 0;
}

/*
继续尝试分割字符串
 */

std::vector<std::string> split_v(const std::string &str, const std::string & pattern){
	std::vector<std::string> res;
	if (str == ""){
		return res;
	}
	std::string strs = str + pattern;
	size_t pos = strs.find(pattern);
	size_t plen = pattern.size();
	while(pos != strs.npos){
		std::string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已经分割的字符
		strs = strs.substr(pos+plen, strs.size());
		pos = strs.find(pattern);
	}

	return res;
}


int main(){
	std::string str = "hello, my ,name ,is, world, my family is happy, my hometone";
	std::string pat = "my";
	std::vector<std::string> res = split_v(str, pat);

	for (std::vector<std::string>::iterator iter = res.begin(); iter != res.end(); iter++){
		std::cout<<*iter<<std::endl;
	}
	return 0;
}
