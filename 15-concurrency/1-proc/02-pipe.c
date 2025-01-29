#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd = open("out.txt", O_CREAT, 0644); // … or a call to pipe() or socket()
  if (0 > fd) printf("error"); // Handle errors.

  int r1 = dup2(fd, 1) ;
  int r2 = close(fd) ;

  execl("/usr/bin/cat", "cat", NULL);
}
