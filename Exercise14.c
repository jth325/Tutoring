#include <stdio.h>
#include <search.h>
#include <string.h>
#define TABLESIZE 4
struct info {
  int id, age;
};
int main() {
  char nametable[TABLESIZE * 20], *nameptr = nametable, name[30];
  struct info infotable[TABLESIZE], *infoptr = infotable;
  ENTRY item, *found;
  int i = 0;
  // 인자로 받은 정수만큼 해쉬테이블 요소 생성
  hcreate(TABLESIZE);
  // 해쉬테이블에 들어갈 키 및 두개의 값을 입력받는다. 입력이 끝날때까지 또는 테이블의 크기만큼 입력받을때까지 반복한다
  while (scanf("%s %d %d", nameptr, &infoptr->id, &infoptr->age) != EOF && i++ < TABLESIZE - 1) {
    // 해쉬테이블에 데이터를 넣기위해 ENTRY 구조체에 입력받은 키, 값을 삽입한다
    item.key = nameptr; item.data = (char*)infoptr;
    // item 의 key 와 같은 데이터를 해쉬테이블에서 찾고 그 포인터를 반환한다, 찾으려는 key 가 없을경우 새로 데이터를 추가한다
    hsearch(item, ENTER);
    // 문자열이 저장된 인덱스들을 건너뛰고 그 다음 인덱스에 문자열을 저장하도록 포인터연산을 한다
    nameptr += strlen(nameptr) + 1;
    // infotable 의 다음 인덱스를 참조하기 위한 포인터 연산을 한다
    infoptr++;
  }
  // key 가 name 문자열의 주소를 가리키게하며, 찾으려는 키 값을 입력받는다
  item.key = name;
  while (scanf("%s", item.key) != EOF) {
    // 찾으려는 키값을 못찾을 경우 NULL 이 반환된다
    if ((found = hsearch(item, FIND)) != NULL)
      printf("found %s, id=%d, age=%d\n", found->key, ((struct info*)found->data)->id, ((struct info*)found->data)->age);
    else printf("no such employee %s\n", name);
  }
}
