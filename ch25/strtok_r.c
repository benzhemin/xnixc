#include <stdio.h>
#include <stdlib.h>
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

char *strtok_r_impl(char *str, const char *delim, char **last_str){
    char *last = str;
    if(str == NULL){
        last = *last_str;
    }

    if(last==NULL || *last == '\0')
        return NULL;
    
    char *cur_str = last;
    char *find_str = cur_str;

    if(strlen(delim) > 0){
        for(find_str=str_chstr(cur_str, delim);
            find_str!=NULL && find_str==cur_str;
            cur_str=cur_str+1, find_str=str_chstr(cur_str, delim));
    }

    if(find_str==NULL || find_str==cur_str){
        last = cur_str+strlen(cur_str);
    }else{
        *find_str = '\0';
        last = find_str+1;
    }

    *last_str = last;

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
