#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, x;

  for (i = 0; i < 20; ++i)
  {
    // rand() : 시드에 맞는 정수를 반환 ,RAND_MAX : rand() 가 반환하는 정수의 최대값
    // 0 <= rand() / (RAND_MAX + 1) < 1, 1 <= rand() / (RAND_MAX + 1.0)) * 6 + 1 < 7
    // 결과적으로 x에는 1 ~ 6 범위의 정수가 대입된다, 해당 출력을 20번 반복한다
    x = (int)((rand() / (RAND_MAX + 1.0)) * 6 + 1);
    printf("%d\n", x);
  }
}
