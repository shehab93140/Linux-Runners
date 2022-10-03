#include<stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
char * buf[100];
char * ptr =getcwd(*buf,100);
printf("%s",ptr);
printf("\n");
}


