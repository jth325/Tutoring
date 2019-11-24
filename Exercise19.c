#include <stdio.h>
#include <string.h>
int main() {
  char srcstr[] = "This is a test string";
  char dststr[25], *ptr;
  int ret;
  // dststr 에 srcstr 문자열 복사, 널문자까지 넣기위해 (+ 1) 를 해준다
  memcpy(dststr, srcstr, strlen(srcstr) + 1);
  printf("dststr is \"%s\"\n", dststr);
  // srcstr 5번째 인덱스부터 이후 5개 인덱스에 'a' 문자를 대입한다
  memset(srcstr + 5, 'a', 5);
  printf("srcstr is \"%s\"\n", srcstr);
  // 두 메모리 블록이 같으면 0, 다를경우 처음으로 다른 바이트를 (unsigned char) 로 해석
  // 하였을때 그 값이 srcstr 보다 크면 0보다 작은값, 아니면 0보다 큰값을 반환한다
  // srcstr 5번째 인덱스가 ' ', dstsr 5번째 인덱스가 'a' 이므로 0보다 작은값을 반환한다
  ret = memcmp(srcstr, dststr, strlen(srcstr));
  if (ret > 0) printf("srcstr is greater than dststr\n");
  else if (ret == 0) printf("srcstr is equal to dststr\n");
  else printf("srcstr is less than dststr\n");
  // memchr 함수는 두번째 인자에 해당하는 값이 첫번째 인자가 가리키는 메모리에 소속되어
  // 있는지 확인하는 함수. 찾을 경우 해당 주소를 반환, 또는 NULL 을 반환한다
  ptr = memchr(dststr, ' ', strlen(dststr));
  if (ptr != NULL) printf("First space was at position %d\n", ptr - dststr + 1);
  else printf("Space was not found\n");
}
