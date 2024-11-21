#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   char pid[255];
   fork();
   fork(); // 2
   fork(); // 2 * 2
   fork(); // 2 * 2 * 2
   fork(); // 2 * 2 * 2 *2
   sprintf(pid, "PID : %d\n",getpid()); // 2 * 2 * 2 * 2 * 2
   write(STDOUT_FILENO, pid, strlen(pid)); //2 * 2 * 2 * 2 * 2
   sleep(5); 
   exit(0);
}
