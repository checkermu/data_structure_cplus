/* memcpy example */
#include <stdio.h>
#include <string.h>
 
struct {
  char name[40];
  int age;
} person, person_copy;//person, person_copy 为结构体成员如此只有这两个可以使用这两个成员可以使用这个结构体


char * strtock_ss(char * str, const char * delim){
	char * sbegin, *send;
	static char * ssave = "";

	sbegin = str?str:ssave;
	printf("first sbegin:%s\n", sbegin);
	int len1 = strspn(sbegin, delim);
	printf("len1 is :%d\n", len1);
	sbegin += len1;
	printf("second sbegin:%s\n", sbegin);
	if(*sbegin == '\0'){
		ssave = "";
		return NULL;
	}
	int len2 = strcspn(sbegin, delim);
	printf("len2 is :%d\n", len2);
	send = sbegin + len2;
	printf("first send:%s\n", send);
	if (*send != '\0'){
		printf("*send:%c\n", *send);
		*send++ = '\0';
	}
	ssave = send;
	printf("third sbegin:%s\n", sbegin);
	return sbegin;
}



int main(){
	char * str = "my - website-is www.-be-.com";
	char * delim = "-";
	char * temp = strtock_ss(str, delim);
	while(temp != NULL){
		printf("%s\n", temp);
		temp = strtock_ss(NULL, delim);
	}

	return 0;
}





// int main_memcpy ()
// {
//   char myname[] = "Pierre de Fermat";
 
//   /* using memcpy to copy string: */
//   memcpy ( person.name, myname, strlen(myname)+1 );//把myname复制给person.name
//   person.age = 46;
 
//   /* using memcpy to copy structure: */
//   memcpy ( &person_copy, &person, sizeof(person) );
 
//   printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

//   char str1[] = "i am not happy";
//   printf("%d\n", sizeof(str1));
//   printf("%d\n", strlen(str1));

// char *string1 = "123DC84567890"; 
// char *string2 = "DC8"; 
// int length; 

// length = strspn(string1, string2); 
// printf("Character where strings differ is at position %d\n", length); 
// return 0; 
// }
