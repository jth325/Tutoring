#include <stdio.h>
#include <stdlib.h>
int main() {
  char c, *ptr;
  int count;
  ptr = NULL;
  count = 0;
  // 개행문자(엔터) 를 받을때까지 문자를 입력받는다
  while ((c = getchar()) != '\n') {
    // 첫 할당이므로 문자(char) 하나만큼 메모리 할당을 받는다
    if (count == 0) ptr = (char*)malloc(1);
    // realloc 명령어를 통해 ptr이 가리키는 동적메모리의 크기를 재할당한다
    else ptr = (char*)realloc(ptr, count + 1);
    // 배열의 count번째 인덱스에 입력받은 문자 c 대입
    *(ptr + count) = c;
    // 배열을 가리키는 인덱스변수 count를 (+ 1) 해준다
    count++;
  }
  // 문자열의 마지막 문자는 '\0' 이 들어가야한다
  *(ptr + count) = '\0';
  printf("입력문자열 : %s 총 할당 메모리 : %d\n", ptr, count);
  free(ptr);
}
