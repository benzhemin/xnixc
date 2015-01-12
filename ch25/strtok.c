#include <stdio.h>
#include <string.h>

static char *str_chstr(char *str, char *key_str){
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

char *strtok_impl(char *str, const char *delim){
	//内部静态变量，保存下次strtok的起始位置
	static char *next_str = NULL;
	
	//第一次调用，初始化next_str
	if(str != NULL)	
		next_str = str;
	
	//起始为NULL，或起始值遇到字符串末尾
	if(next_str==NULL || *next_str=='\0')
		return NULL;

	//定义当前查找指针
	char *cur_str = next_str;
	//指向查到delim的指针
	char *find_str = cur_str;
	
	//delim不为空串
	if (strlen(delim) != 0){
		//对于重复出现的delim，token要忽略
		//跳过重复的delim字符  
		for(find_str=str_chstr(cur_str, delim); 
			find_str!=NULL && find_str==cur_str; 
			cur_str=cur_str+1, find_str=str_chstr(cur_str, delim));	
	}
	
	//如果没有找到token || find_str没有被设置(delim为空的情况)
	if (find_str==NULL || find_str==cur_str){
		//定位下次next_str出现的位置
		next_str = cur_str+strlen(cur_str);
	}else{
		//找到token，设置字符串末尾
		*find_str = '\0';

		//定位next_str位置
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