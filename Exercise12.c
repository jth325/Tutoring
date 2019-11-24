#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#define TABLESIZE 5
int compare(const void* ap, const void* bp) {
  return (*(int*)ap - *(int*)bp);
}
int main() {
  size_t n = TABLESIZE;
  int table[TABLESIZE] = {1, 2, 3, 4, 5};
  int item = 6, *ptr;
  // 정렬되있는 배열을 대상으로 이진탐색(bineary search)를 수행하는 함수이다
  // 이진탐색의 경우 탐색을 가운데 인덱스부터 시작
  // 현재 탐색하고 있는 인덱스의 값보다 찾으려는 값이 작으면 좌측 중앙, 아니면 우측 중앙
  // 으로 이동하면서 탐색을 보다 빠르게 수행한다
  ptr = (int*)bsearch(&item, table, n, sizeof(int), compare);
  // bsearch 함수는 찾으려는 값이 없을경우 NULL 값을 리턴한다
  // 그 결과를 조건문 (!ptr) 을 통해 구분을 한다
  if (!ptr) printf("%d is not in the table(1 - %d)\n", item, n);
  else printf("%d is in the table(1 - %d)\n", *ptr, n);
}
