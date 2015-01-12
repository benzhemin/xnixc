/*
 * 每隔一秒向test.txt写入一行当前时间
 * 序号并能接上次的序号
 * 时间格式 1 2009-7-30 15:16:42
 *
 * 获取时间调用time()函数
 *
 * localtime将时间戳转为本地时间
 *
 * sleep控制程序休眠多少秒
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define LINE_MAX_SIZE 256

void log_date(){
    FILE *fp = fopen("test.txt", "a+");
    if (fp == NULL){
        perror("open file error");
        exit(0);
    }
    rewind(fp);

    char buf[LINE_MAX_SIZE] = {0};
    //last log sequence
    int line_mark = 0;

    while(fgets(buf, LINE_MAX_SIZE, fp)!=NULL);

    if(strlen(buf) != 0){
        sscanf(buf, "%d", &line_mark);
        line_mark++;
    }

    while(1){

        time_t time_since_1970 = time(NULL);
        struct tm *tm_st_ptr = localtime(&time_since_1970);

        int year = tm_st_ptr->tm_year + 1900;
        int month = tm_st_ptr->tm_mon + 1;
        int day = tm_st_ptr->tm_mday;

        int hour = tm_st_ptr->tm_hour;
        int minute = tm_st_ptr->tm_min;
        int seconds = tm_st_ptr->tm_sec;

        fprintf(fp, "%d %d-%d-%d %d:%d:%d\n", line_mark, year, month, day, hour, minute, seconds);
        fflush(fp);

        line_mark++;

        sleep(1);
    }

    fclose(fp);
}

int main(void){
    log_date();

    return 0;
}
