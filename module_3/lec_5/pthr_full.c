#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* !!! NEVER USE THIS IN PRODUCTION ENVIRONMENT!!!! */
/* Behavior of this code implementation-dependent 
 * using this code "as is" will result in race condition */

void * thread_body(void *unused) {
	pthread_t self;
	int code;
	self=pthread_self();	

	code=pthread_join(pthread_self(), NULL);

	//printf("Error %d = %d \n", code, EDEADLK);
	printf("Joining self before detach, error code=%d, message %s\n", code,
strerror(code));

     /* NEVER USE THIS CODE IN PRODUCTION ENVIRONMENT */
	pthread_detach(self);
	code=pthread_join(pthread_self(), NULL);
	// EINVAL
	//printf("Error %d = %d \n", code, EINVAL);
	printf("Joining self after detach, error code=%d, message %s\n", code,
strerror(code));
	return NULL;
}

int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, &thread_body, NULL);
	pthread_exit(&thread);
	return 0;
}

