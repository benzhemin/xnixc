#include <stdio.h>
#include <stdlib.h>

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

char *strtok_r_impl(char *str, char *delim, char **plast_str){
	char *next_str = str;
	if(str == NULL)
		next_str = *plast_str;
	
	if(next_str==NULL || *next_str=='\0')
		return NULL;

	char *cur_str = next_str;
	char *find_str = cur_str;

	if(strlen(delim)){
		for(find_str=str_chs(cur_str, delim);
			find_str!=NULL && find_str==cur_str;
			++cur_str, find_str=str_chs(cur_str, delim));
	}

	if(find_str==NULL||find_str==cur_str){
		next_str = cur_str+strlen(cur_str);
	}else{
		*find_str = '\0';
		next_str = find_str+1;
	}

	*plast_str = next_str;

	return cur_str;
}


int main(int argc, char *argv[]){
    char *str1, *str2, *token, *subtoken;
    char *saveptr1, *saveptr2;
    int j;

    if(argc != 4){
        fprintf(stderr, "Usage:%s string delim subdelim\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(j=1, str1=argv[1]; ;j++, str1=NULL){
        token = strtok_r_impl(str1, argv[2], &saveptr1);
        if(token == NULL){
            break;
        }
        printf("%d: %s\n", j, token);

        for(str2=token; ;str2=NULL){
            subtoken = strtok_r_impl(str2, argv[3], &saveptr2);
            if(subtoken == NULL){
                break;
            }
            printf("--> %s\n", subtoken);
        }
    }

    exit(EXIT_FAILURE);
}




















