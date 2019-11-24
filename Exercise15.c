#include <stdio.h>
#include <search.h>
#include <string.h>
#define TABLESIZE 50
struct node {
  char* name;
  int age;
};
int compare(const void* cp1, const void* cp2) {
  return strcmp(((struct node*)cp1)->name, ((struct node*)cp2)->name);
}
void print_node(const void* nodeptr, VISIT order, int level) {
  // preorder(전위운행) 방식으로 로직을 수행한다는 의미이다
  if (order == preorder || order == leaf)
    // node 포인터의 주소를 받았으므로 (struct node**) 형변환이 필요하다
    printf("이름 = %-20s, 나이 = %d\n", (*(struct node**)nodeptr)->name, (*(struct node**)nodeptr)->age);
}
char nametable[TABLESIZE * 20];
struct node nodetable[TABLESIZE], *root = NULL;
int main() {
  char* nameptr = nametable;
  struct node* nodeptr = nodetable, node** ret;
  int i = 0;
  while (scanf("%s%d", nameptr, &nodeptr->age) != EOF && i++ < TABLESIZE) {
    nodeptr->name = nameptr;
    // tsearch 함수는 트리에 찾으려는 데이터가 있을경우 해당 포인터변수의 주솟값을 반환
    ret = (struct node**)tsearch((void*)nodeptr, (void**)&root, compare);
    printf("\"%s\"님이 ", (*ret)->name);
    if (*ret == nodeptr) printf("트리에 추가되었습니다\n");
    else printf("트리에 이미 존재합니다\n");
    // 저장되있는 문자열을 건너뛰고 다음 공간을 활용하기 위해 포인터 연산을 한다
    nameptr += strlen(nameptr) + 1;
    // nodetable 의 다음 인덱스를 참조하기 위해 포인터 연산을 한다
    nodeptr++;
  }
  // 이진트리를 방문하는 함수, 첫번째 인자로 탐색할 트리의 루트노드 주소를 넘기고
  // 두번째 인자로 트리를 방문하는 동작이 정의된 함수 포인터를 넘겨준다
  twalk((void*)root, print_node);
}
