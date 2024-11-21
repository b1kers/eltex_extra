#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  printf("Будет выполнена программа %s...\n\n",
         argv[0]);
  printf("Выполняется %s", argv[0]);
  int ec = execl("hello", "sample", NULL);
  printf("%d\n", ec);
  return 0;
}
