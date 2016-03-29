/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int length(char* str){
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

int count_word_in_str_way_1(char *str, char *word){
	if (str != NULL && word != NULL){
		int i, flag = 0, count = 0;
		int len_word = length(word);
		for (i = 0; str[i]; i++){
			if (str[i] == word[0]){
				flag = 0;
				for (int k = 1,m = i+1; k < len_word; k++,m++){
					if (word[k] != str[m]){
						flag = 1;
						break;
					}
				}
				if (flag == 0){
					count++;
				}
			}
		}
		return count;
	}
	return 0;
}

int count_word_int_str_way_2_recursion(char *str, char *word,int start,int len_word){
	if (str[start] == '\0'){
		return 0;
	}
	else{
		if (str != NULL && word != NULL){
			int flag = 0;
			int count = 0;
			if (str[start] == word[0]){
				for (int k = 1, m = start + 1; k < len_word; k++, m++){
					if (str[m] != word[k]){
						flag = 1;
						break;
					}
				}
				if (flag == 0){
					return count + count_word_int_str_way_2_recursion(str, word, start + 1, len_word);
				}
			}
			else{
				return count_word_int_str_way_2_recursion(str, word, start + 1, len_word);
			}
		}
	}
	return 0;
}

