#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOOL    int
#define TRUE    1
#define FALSE   0

static char *xml_cmt_fmt        = "<-- %s -->";
static char *xml_elem_start     = "<%s>";
static char *xml_elem_end       = "</%s>";

void parse_ini(FILE *rd_fp, FILE *wr_fp){

    char line_buf[256] = {0};

    BOOL sec_in = FALSE;
    char sec_buf[256] = {0};
    while(fgets(line_buf, sizeof(line_buf), rd_fp) != NULL){

        char *pb;
        for(pb=line_buf; *pb==' '; pb++);

        if (*pb == '\n'){
            fputc(*pb, wr_fp);
            continue;
        }

        char *tp;
        for(tp=line_buf; *tp!='\0'; tp++){
            if (*tp == '\n'){
                *tp = '\0';
            }
        }

        //elem
        if(isalpha(*pb) || isdigit(*pb)){

            char *key = strtok(line_buf, "= ");
            char *value = strtok(NULL, "= ");

            char xml_elem_fmt_buf[256];
            sprintf(xml_elem_fmt_buf, "\t%s%s%s", xml_elem_start, "%s", xml_elem_end);

            fprintf(wr_fp, xml_elem_fmt_buf, key, value, key);
            fputc('\n', wr_fp);

        }else{
            if (sec_in){
                fprintf(wr_fp, xml_elem_end, sec_buf);
                fputc('\n', wr_fp);
                sec_in = FALSE;
            }
            //comments
            if (*pb == ';'){
                char cmt_buf[256];
                fprintf(wr_fp, xml_cmt_fmt, pb+1);
                fputc('\n', wr_fp);
            }
            //section
            else if (*pb == '['){
                sec_in = TRUE;
                char *sec = strtok(pb+1, "[]");
                strcpy(sec_buf, sec);
                fprintf(wr_fp, xml_elem_start, sec_buf);
                fputc('\n', wr_fp);
            }
        }
    }

    if (sec_in){
        fprintf(wr_fp, xml_elem_end, sec_buf);
        fputc('\n', wr_fp);
    }
}

void configuration(char *file_name){
    FILE *rd_fp = fopen(file_name, "r");
    if (rd_fp == NULL){
        perror("open file error");
        exit(0);
    }

    char name_output[20] = {0};
    char *file_prefix = strtok(file_name, ".");
    strcpy(name_output, file_prefix);
    strcat(name_output, ".xml");

    FILE *wr_fp = fopen(name_output, "w");
    if (wr_fp == NULL){
        perror("open file error");
        exit(0);
    }

    parse_ini(rd_fp, wr_fp);

    fclose(wr_fp);
    fclose(rd_fp);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        perror("parse file must be specified");
        exit(0);
    }

    configuration(argv[1]);

    return 0;
}
