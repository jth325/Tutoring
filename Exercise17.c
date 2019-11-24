#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[10];
  int mid, final;
};

int main()
{
  int stu_num, i, sum;
  float avg;
  struct student* stu_ptr;

  printf("학생 수는 ? " );
  scanf("%d", &stu_num);

  stu_ptr = (struct student*)malloc(stu_num * sizeof(struct student));

  if (stu_ptr == NULL) exit(-1);

  fflush(stdin);
  for (i = 0; i < stu_num; ++i)
  {
    printf("%d번째 학생의 이름 : ", i + 1);
    scanf("%s", stu_ptr[i].name);
    printf("%d번째 학생의 중간, 기발 : ", i + 1);
    scanf("%d%d", &stu_ptr[i].mid, &stu_ptr[i].final);
    fflush(stdin);
  }

  printf("[성적리스트]\n");
  printf("이름\t중간\t기말\t총점\t평균\n");
  for (i = 0; i < stu_num; i++)
  {
    sum = stu_ptr[i].mid + stu_ptr[i].final;
    avg = sum / 2;
    printf("%s\t%d\t%d\t%d\t%4.2f\n", stu_ptr[i].name, stu_ptr[i].mid, stu_ptr[i].mid, stu_ptr[i].final, sum, avg);
  }

  free((struct student*)stu_ptr);
}
