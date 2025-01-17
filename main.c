#include "header.h"

int main(){
    getcwd(path, sizeof(path));
    char *line = malloc(sizeof(*line)*DEFAULT_LINE_SIZE);
    int line_size = DEFAULT_LINE_SIZE;
    if(line == NULL){
        fprintf(stderr, RED "Memory reallocation failed\n" RESET);
        exit(1);}
    char **args = malloc(sizeof(*args));
    int args_size = DEFAULT_ARGS_SIZE;
    if(args == NULL){
        fprintf(stderr, RED "Memory reallocation failed\n" RESET);
        exit(1); }
    int status = 1;

    printf("\n%s%sWelcome to %sNeoshell%s  ~ Created by %s@LM012%s ~\n" RESET, BOLD, CYAN, YELLOW, CYAN, YELLOW, CYAN);
    do{
        Display_UserHostname();
        printf(BLUE "%s$ " RESET, path);
        line = Read_Line(line, &line_size);
        args = Get_Arguments(line, args, &args_size);
        status = Execute(args);
    }while(status);
    
    free(line);
    free(args);
    return 0;
}