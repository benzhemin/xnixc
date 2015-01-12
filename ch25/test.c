#include <stdio.h>
#include <string.h>

char *str_chstr(char *str, char *key_str){
    char *find_str = NULL;

    while(str!=NULL && *str!='\0'){
        const char *tp_key = key_str;
        while(tp_key!=NULL && *tp_key!='\0'){
            if(*str == *tp_key)
                break;
            tp_key++;
        }

        if (tp_key!=NULL && *tp_key!='\0'){
        	find_str = str;
            break;
        }
        str++;
    }

    return find_str;
}

int main(void){
	char *str = "a/bbb///cc;xxx:yyy:";
	char *delim = ":;";

	char *find_str = str_chstr(str, delim);

	printf("%s\n", find_str);

	return 0;
}