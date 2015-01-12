#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL 	int
#define TRUE 	1
#define FALSE	0

typedef struct {
	char *url_host;
	// params list

} URL;

typedef struct{
	char *key;
	char *value;
} KVParam;

BOOL check_url_prefix(char *url){
	BOOL legal = FALSE;

	char *url_prefix[] = {"http://", "www", NULL};

	//check if url start with standard prefix
	char **url_prefix_ptr = url_prefix;
	while(*url_prefix_ptr!=NULL){
		char *find_str = strstr(url, *url_prefix_ptr);
		if (find_str!=NULL && find_str == url){
			legal = TRUE;
			break;
		}
		url_prefix_ptr++;
	}

	return legal;
}

//simply check if url has standard prefix
BOOL check_url_legal(char *url){
	return check_url_prefix(url);
}

void parse_url(char *url){
	if(check_url_legal(url) == FALSE){
		perror("url illegal");
		return;
	}

	char *host = NULL;
	char *params = NULL;

	//?
	char *host_param_svptr;
	char *param_split_svptr;
	char *param_kv_svptr;

	char *parse_str;

	printf("%s\n", url);

	for( ; ; url=NULL){
		parse_str = strtok_r(url, "?", &host_param_svptr);
		if (parse_str==NULL)
			break;

		printf("%s\n", parse_str);

		//parse params
		char *param_str;
		if (strchr(parse_str, '&')!=NULL){
			for( ; ; parse_str=NULL){
				param_str = strtok_r(parse_str, "&", &param_split_svptr);
				if (param_str == NULL)
					break;

				printf("-->%s\n", param_str);
				
				char *key = strtok_r(param_str, "=", &param_kv_svptr);
				char *value = strtok_r(NULL, "=", &param_kv_svptr);

				printf("======>key:%s\n", key);
				printf("======>value:%s\n", value);
			}
		}		
	}

}

int main(int argc, char *argv[]){
	char url1[] = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
	char url2[] = "http://www.baidu.com/s?wd=linux&cl=3";
	char *urls[] = { url1, url2, NULL};

	char **purls = urls;
	while(*purls != NULL){
		parse_url(*purls);
		purls++;
	}

	return 0;
}





















