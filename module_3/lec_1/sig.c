#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void term_handler(int i) {
	printf ("Terminating\n");
	exit(EXIT_SUCCESS);
}
int main(int argc, char ** argv) {
struct sigaction sa;
sigset_t newset;
sigemptyset(&newset);
sigaddset(&newset, SIGHUP);
//sigprocmask(SIG_BLOCK, &newset, 0);
sa.sa_handler = term_handler;
sigaction(SIGTERM, &sa, 0);
printf("My pid is %i\n", getpid());
printf("Waiting...\n");
sigwait(&newset, SIGALRM);
while(1) sleep(1);
return EXIT_FAILURE;
}
