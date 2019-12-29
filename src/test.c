#include <stdio.h>
#define RED "\033[0;31m"

#define RED "\033[0;31m"         /* 31 == red */
#define RED_BOLD "\033[1;31m"    /* 1 == bold */
#define GREEN "\033[0;32m"
#define GREEN_BOLD "\033[1;32m"
#define WHITE "\033[0;37m"
#define WHITE_BOLD "\033[1;37m"
#define BLUE "\033[0;34m"
#define BLUE_BOLD "\033[1;34m"
#define PURPLE "\033[0;35m"
#define PURPLE_BOLD "\033[1;35m"
#define YELLOW "\033[0;33m"
#define YELLOW_BOLD "\033[1;33m"
#define CYAN "\033[0;36m"
#define CYAN_BOLD "\033[1;36m"
#define REWIND "\x1B[0m"



void main(void){
    printf("%s hello word %s\n",RED,REWIND);
    puts("really");

}
