#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* str_chs(char *str, char *keys){
    char *end_str = str+strlen(str);
    char *find_str = end_str;

    char *occurs;
    while(keys!=NULL && *keys!='\0'){
        occurs = strchr(str, *keys);

        if(occurs!=NULL && occurs<end_str){
        	find_str = occurs;
        }
        keys++;
    }

    if (find_str == end_str){
    	return NULL;
    }
    return find_str;
}

char *strtok_impl(const char *str, const char *delim){
    static char *next_str = NULL;
    if (str != NULL)
		next_str = (char *)str;

	if (next_str==NULL || *next_str=='\0'){
		return NULL;
	}

	char *cur_str = next_str;
	char *find_str = cur_str;

	if (strlen(delim)){
		for(find_str=str_chs(cur_str, delim);
			find_str!=NULL && find_str==cur_str;
			++cur_str, find_str=str_chs(cur_str, delim));
	}

	if(find_str==NULL || find_str==cur_str){
		next_str = cur_str+strlen(cur_str);
	}else{
		*find_str = '\0';
		next_str = find_str+1;
	}

	return cur_str;
}

int main(void){
    char str[] = "root:x::0:root:/root:/bin/bash:";
    char *token;

    token = strtok_impl(str, ":");
    printf("%s\n", token);

    while((token=strtok_impl(NULL, ":")) != NULL){
        printf("%s\n", token);
    }

    return 0;
}
