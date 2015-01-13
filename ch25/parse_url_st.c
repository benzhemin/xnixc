#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

typedef struct{
    char *raw_url;
    char *url_host;
    linklist *param_list;
} url_st;

typedef struct{
    char *key;
    char *value;
} param_st;


BOOL check_url(char *url_str){
    char* url_prefix[] = {"http://", "www"};
    unsigned up_len = ARRAY_LEN(url_prefix);

    BOOL legal = FALSE;

    for(int i=0; i<up_len; i++){
        char *occur = strstr(url_str, url_prefix[i]);
        if (occur!=NULL && occur==url_str){
            legal = TRUE;
            break;
        }
    }

    return legal;
}

void cp_str(char **dst, char *src){
    if (src == NULL){
        *dst = NULL;
        return;
    }

    char *str = malloc(strlen(src)+1);
    strcpy(str, src);
    *dst = str;
}

url_st* parse_url(char *url_str){
    if (!check_url(url_str)){
        return NULL;
    }

    url_st *url = malloc(sizeof(url_st));
    cp_str(&url->raw_url, url_str);
    url->param_list = create_linklist(sizeof(param_st));

    char *hp_split_svptr, *param_split_svpt, *kv_split_svptr;

    for(; ; url_str=NULL){
        char *url_parse = strtok_r(url_str, "?", &hp_split_svptr);
        if (url_parse == NULL)
            break;

        if (strstr(url_parse, "www") || strstr(url_parse, "http")){
            cp_str(&url->url_host, url_parse);
        }else{

            for(; ; url_parse=NULL){
                char *param_parse = strtok_r(url_parse, "&", &param_split_svpt);
                if (param_parse == NULL)
                    break;

                char *param_key = strtok_r(param_parse, "=", &kv_split_svptr);
                char *param_value = strtok_r(NULL, "=", &kv_split_svptr);

                param_st *param = malloc(sizeof(param_st));
                cp_str(&param->key, param_key);
                cp_str(&param->value, param_value);

                insert_linklist(url->param_list, param);

            }
        }
    }

    return url;
}

void print_url(url_st *url){
    puts(url->raw_url);
    puts(url->url_host);

    node_st *p = url->param_list->header;

    while(p != NULL){
        param_st *param = p->pelem;
        fprintf(stdout, "\t%s=%s\n", param->key, param->value);
        fflush(stdout);

        p = p->next;
    }
}

void destory_param(void *pelem){
    param_st *param = pelem;

    free(param->key);
    free(param->value);
    free(param);
}

void destory_url(void *pelem){
    url_st *url = pelem;
    free(url->raw_url);
    free(url->url_host);

    destory_linklist(url->param_list, destory_param);
    free(url);
}

int main(int argc, char *argv[]){
    char url1[] = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
    char url2[] = "http://www.baidu.com/s?wd=linux&cl=3";
    char *urls[] = { url1, url2, NULL};

    linklist *L = create_linklist(sizeof(url_st));

    char **purls = urls;
    while(*purls != NULL){
        url_st *url = parse_url(*purls);
        insert_linklist(L, url);

        purls++;
    }

    node_st *p = L->header;
    while (p != NULL){
        print_url(p->pelem);
        p = p->next;
    }

    destory_linklist(L, destory_url);

    return 0;
}
