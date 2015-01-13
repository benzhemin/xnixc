#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_header(char *header){

    char *sys_include = "/usr/include/";
    char cwd_include[256];

    getcwd(cwd_include, sizeof(cwd_include));

    //standard library
    char path[256] = {0};
    if (strchr(header, '<') || strchr(header, '>')){
        char *inc_str = strtok(header+1, "<>");
        sprintf(path, "%s%s", sys_include, inc_str);
    }
    //custom header
    else if (strchr(header, '"')){
        char *inc_str = strtok(header+1, "\"");
        sprintf(path, "%s/%s", cwd_include, inc_str);
    }

    FILE *fp = fopen(path, "r");
    if (fp != NULL){
        fclose(fp);
    }else{
        strcat(path, ": cannot find");
    }
    puts(path);
}

void print_headers(char *file_name){

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL){
        perror("file not found!");
        exit(0);
    }

    char inc_buf[256];

    while(fscanf(fp, "#include %s\n", inc_buf)){
        //strcat(inc_buf, "\n");
        //fputs(inc_buf, stdout);

        parse_header(inc_buf);

    }

    fclose(fp);
}

int main(int argc, char *argv[]){
    if (argc < 2){
        perror("file name must be specified!");
        exit(0);
    }

    print_headers(argv[1]);

    return 0;
}
