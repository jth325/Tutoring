#include <stdio.h>
#include <stdlib.h>
int main() {
  int max ,i;
  int* ptr;
  printf("배열의 원소 개수는? ");
  scanf("%d", &max);
  // 입력받은 값 만큼 int형 메모리를 생성
  ptr = (int*)malloc(max * sizeof(int));
  if (ptr == NULL) exit(-1);
  // 생성된 배열의 크기만큼 int 형 정수값 대입
  for (i = 0; i < max; i++) scanf("%d", &ptr[i]);
  printf("입력 숫자 리스트 : ");
  // 배열의 모든 값을 출력
  for (i = 0; i < max; ++i) printf("%d ", *(ptr + i));
  printf("\n");
  // 동적 메모리 할당 제거
  free((int*)ptr);
}
