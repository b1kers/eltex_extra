#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h> 
#include <errno.h>

void * thread_body(void * param) {
     pthread_t thread_id = pthread_self();
     printf("Thread started! %ld\n", thread_id);

     sleep(10);
     printf("Thread finished\n");
}

/*
 * creates thread with default attributes and no parameters
 * sleeps enough time to ensure that thread will print his message
 * (under reasonable conditions)
 */
int main(int argc, char *argv[]) {
    pthread_t thread;
    int code;
    //int i;
    for (int i = 0; i<6527; i++){
    code=pthread_create(&thread, NULL, thread_body, NULL);
    if (code!=0) {
	if (code==EAGAIN){
		printf("Thread quota exceed by %d\n", i);
	}
        char buf[256];
        strerror_r(code, buf, sizeof buf);
        fprintf(stderr, "%s: creating thread: %s\n", argv[0], buf);
        exit(1);
    }
    }
    sleep(12);
    
    return (EXIT_SUCCESS);
} 
