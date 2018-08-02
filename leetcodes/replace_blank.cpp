#include <iostream>
using namespace std;

/*
去除字符串中多余的空格，例如"I___am_____a______student."
(下划线表示空格哈，打多个空格显示的还是一个），最后输出”I am a student.”
 */

/*
思路：定义两个指针，next和tail，一个在前面寻找非空格的字符，另外一个在后面一步步的移动，
把后面的字符全部转移到前面来，为了去除多余的空格，也就是有多个或者一个空格的地方要留一个空格。
 */


char * deletespace(char* str){
	char * tail = str;
	char * next = str;

	while(*next){
		// if(*next != ' '){//查找不是空格的字符
		// 	*tail = *next;
		// 	tail++;
		// }
		if (*next == ' ' && *(next+1) == ' '){//只保留一个空格的判断，当前为空格，且前一个不为空格。
			*tail = *next;
			tail++;
		}
		next++;
	}
	*tail='\0';
	return str;

}



char * delete2(char *str){
	int pos = 0;
	int i=0;
	for(i = 0; str[i] != '\0';) {
		if(str[i]!=' ')//当不是空格时，将原字符串复制到新的字符串中去
		{
		          while(str[i]!=' ' && str[i]!='\0'){
		          	str[pos++]=str[i++];
		          }
		}
		if(str[i]==' ' )//当出现空格时
		{
		    if(i!=0) //该空格没有出现在字符串首位置，原字符串保留一个空格，若空格出现在原字符串首位置，不用保留一个空格
		       str[pos++]=str[i++];
		    while(str[i]==' '){//跳跃过多余空格
		       i++;
		    }
		}

	 }
	 if(str[pos-1]==' ')//处理原字符串尾部的空格
	    str[pos-1]='\0';
	 else
	   str[pos]='\0';
	return str;
}

char* delete3(char * str){
	int i=0;
	int pos = 0;
	cout<<"OK"<<endl;
	while(str[i] != '\0'){
		if (str[i] != ' '){//不是空格要都赋值过去
			while(str[i] != ' ' && str[i] != '\0'){
				str[pos++] = str[i++];
			}
		}
		if (str[i] == ' '){//出现空格的时候
			if(i != 0){//不是首位，则源字符串保留一个空格，出现首位，不用保留
				str[pos++] = str[i++];
			}
			// str[pos++] = str[i++]; //是不是首位都保留一个
			while(str[i] == ' '){//跳过多余空格
				i++;
			}
		}
	}
	// 最后处理尾部
	if(str[pos-1] == ' '){
		str[pos-1] = '\0';
	}else{
		str[pos] = '\0';
	}
	// str[pos] = '\0';
	return str;
}



int main(){
	char str[] = " i   am          a student.    ";
	// char *res = deletespace(str);
	char *res = delete3(str);
	cout << res << endl;

	return 0;
}



