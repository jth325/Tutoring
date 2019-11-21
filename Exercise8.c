#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, x;

  for (i = 0; i < 20; ++i)
  {
    x = (int)((rand() / (RAND_MAX + 1.0)) * 6 + 1);
    printf("%d\n", x);
  }
}
