#include <unistd.h>
#include <stdio.h>
//int pipe(int *fd);
//
//
int main(){
    int pipefd[2];
    pipe(pipefd);
    pipe(pipefd);
    pipe(pipefd);
    printf("%d %d\n",pipefd[0], pipefd[1]);
    return 0;
}
