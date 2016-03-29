/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

int  length1(char* str){
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

char * get_last_word(char * str){
	if (str != NULL || str == ""){
		// {"abc is a word","he he","   ","d ab   ","  x","asd324","","a"};
		int start, end;
		int len = length1(str);
		int temp = len - 1;
		while (str[temp] == ' ' && temp>=0){
			temp--;
		}
		if (temp == 0){
			return "";
		}
		end = temp;
		while (temp >= 0){
			if (str[temp] == ' '){
				break;
			}
			temp--;
		}
		if (temp == -1){
			start = 0;
		}
		else{
			start = temp + 1;
		}
		char* res = (char*)malloc(sizeof(char)*(end - start + 1));
		int ptr = 0;
		for (int i = start; i <= end; i++){
			res[ptr++] = str[i];
		}
		res[ptr] = '\0';
		return res;
	}
	return NULL;
}
