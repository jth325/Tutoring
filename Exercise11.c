#include <stdio.h>
#include <search.h>
#define TABLESIZE 5
int compare(const void* ap, const void* bp) {
	// 값이 같을경우 0, 다를경우 0이 아닌값을 반환한다
	return (*(int*)ap - *(int*)bp);
}
int main() {
  size_t n = TABLESIZE;
  int table[TABLESIZE] = {1, 2, 3, 4, 5};
  int item, *ptr;
  item = 6;
	// void *lsearch(const void *key, void *table, size_t *table_size, size_t element_size, int (*compare)(const void *, const void *));
	// table 에서 key 값을 찾으면 해당 주솟값 반환, 찾지 못할경우 table 에 새로 key 값을 추가한 후에 해당 주솟값 반환
	// table_size : 매개변수를 통해 함수 내에서 배열의 크기를 판별, 배열의 크기가 늘어날 경우 값을 증가시킨다 (원본 변경)
	// element_size : 한 개 요소의 크기를 정의 (바이트 단위)
	// compare : 함수 포인터, 인자로 요소내에서 비교할 두 대상을 넘겨준다, 0이 반환될경우 같음, 0이 아닌값이 반환될경우 다름을 의미하는 함수를 넘겨준다
  ptr = (int*)lsearch(&item, table, &n, sizeof(int), compare);
	// 만약 테이블에 새로운 값이 들어왔을 경우 ptr 에 들어오는 주소는 table 주소에 TABLE_SIZE * sizeof(int) 값을 더한것이다
	// 따라서 ptr >= table + n 일 경우 새로운 값이 들어왔다, 즉 찾으려는 값이 없었다는 것을 알 수 있다
  if (ptr >= table + n) printf("%d is not in the table(1 - %d), but added\n", item, n);
  else printf("%d is in the table(1 - %d)\n", *ptr, n);
  item = 7;
	// void *lfind(const void *key, void *table, size_t *table_size, size_t element_size, int (*compare)(const void *, const void *));
	// lsearch 함수와 달리, 찾으려는 값이 없을경우 NULL 값을 반환한다
  ptr = (int*)lfind(&item, table, &n, sizeof(int), compare);
	// ptr == NULL 일 경우 찾으려는 값이 없다는 것을 알 수 있다
  if (ptr == NULL) printf("%d is not in the table(1 - %d)\n", item, n);
  else printf("%d is in the table(1 - %d)\n", *ptr, n);
}
