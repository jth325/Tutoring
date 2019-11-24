#include <stdio.h>
#include <stdlib.h>

main()
{
  char c, *ptr;
  int count;

  ptr = NULL;
  count = 0;

  while ((c = getchar()) != '\n')
  {
    if (count == 0) ptr = (char*)malloc(1);
    else ptr = (char*)realloc(ptr, count + 1);
    *(ptr + count) = c;
    count++;
  }
  *(ptr + count) = '\0';

  printf("입력문자열 : %s 총 할당 메모리 : %d\n", ptr, count);
  free(ptr);
}
