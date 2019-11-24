#include <stdio.h>
#include <search.h>
#include <string.h>

#define TABLESIZE 50

struct info {
  int id, age;
};

int main()
{
  char nametable[TABLESIZE * 20];
  char *nameptr = nametable;
  struct info infotable[TABLESIZE];
  struct info* infoptr = infotable;
  ENTRY item, *found;
  char name[30];
  int i = 0;

  (void)hcreate(TABLESIZE);
  while (scanf("%d%d%d", nameptr, &infoptr->id, &infoptr->age) != EOF && i++ < TABLESIZE)
  {
    item.key = nameptr;
    item.data = (char*)infoptr;

    (void)hsearch(item, ENTER);

    nameptr += strlen(nameptr) + 1;
    infoptr++;
  }

  item.key = name;
  while (scanf("%s", item.key) != EOF)
  {
    if ((found = hsearch(item, FIND)) != NULL)
    {
      printf("found %s, id=%d, age=%d\n", found->key, ((struct info*)found->data)->id, ((struct info*)found->data)->age);
    }
    else
    {
      printf("no such employee %s\n", name);
    }
  }
}
