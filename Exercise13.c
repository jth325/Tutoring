#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#define TABLESIZE 5
int compare(const void* ap, const void* bp) {
  return (*(int*)ap - *(int*)bp);
}
int main() {
  int table[TABLESIZE] = {4, 2, 1, 5, 3};
  int i;
  // 퀵정렬(quick sort) 를 수행하는 함수이다, 분할 정복 알고리즘을 사용하여
  // 평균적으로 매우 빠른속도가 장점인 정렬이다
  qsort(table, TABLESIZE, sizeof(int), compare);
  // 정렬된 테이블을 출력한다
  for (i = 0; i < TABLESIZE; ++i) printf("%d ", table[i]);
  printf("\n");
}
