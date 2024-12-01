#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSIZE 10
int main(){
    char text[] = "sample text for FIFO demo";
    char buf[BUFSIZE]; 
    mode_t mode = O_RDWR;
    printf("%d", mode);
    const char * fifo_fn = "fifo_fn";
    unlink(fifo_fn);
    int fd_fifo; //=open(fifo_fn, mode);
    //int res = mkfifo(fifo_fn, mode);
    int res = mknod(fifo_fn, 0755, 0);
    printf("%d %d\n", fd_fifo, res);
    if (fd_fifo=open(fifo_fn, mode, O_NDELAY) == -1)
    {
	fprintf(stderr, "Cannot open");
	exit(0);
	//int a = 1;
   }
	   fprintf(stdout, "OK\n");
    	   write(fd_fifo, text, strlen(text));
    if(read(fd_fifo, &buf, sizeof(buf)) == -1)
    {
	fprintf(stderr, "Cannot read");
    } else {
    	 printf("\n%s \n", buf);
    }
    //unlink(fifo_fn);
    return 0;
}
