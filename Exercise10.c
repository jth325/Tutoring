#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[20], t[20], min[20];

  // s, t 변수에 사용자 입력을 통해 문자열 대입
  printf("char 1 ? ");
  scanf("%s", s);
  printf("char 2 ? ");
  scanf("%s", t);

  // strcmp(src, dest) : src가 사전순으로 앞일경우 0보다 작은값 반환
  // strcpy(dest, src) : src의 문자열을 dest에 복사
  // 결과적으로 s, t 중 사전순으로 앞인 문자열이 min 에 복사
  if (strcmp(s, t) < 0) strcpy(min, s);
  else strcpy(min, t);

  printf("%s\n", min);
}
