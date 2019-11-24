#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

int main()
{
  double cticks;
  clock_t tcstart, tcend;
  struct tms tmstart, tmend;
  int i, a = 1, b = 2, c;

  if ((tcstart = times(&tmstart)) == -1) exit(1);

  printf("Fraction of CPU time used is %d\n", tcstart);
  printf("CPU time spent executing process is %d\n", tmstart.tms_utime);
  printf("CPU time spent in the system is %d\n", tmstart.tms_stime);

  for (i = 0; i < 10000000; ++i) c = a + b;
  if ((tcend = times(&tmend)) == -1) exit(1);

  printf("Fraction of CPU time used is %d\n", tcend);
  printf("CPU time spend executing process is %d\n", tmend.tms_utime);
  printf("CPU time spend in the system is %d\n", tmend.tms_stime);

  cticks = tmend.tms_utime + tmend.tms_stime - tmstart.tms_utime - tmstart.tms_stime;

  printf("Total CPU time is %f seconds \n", cticks / 100.f);
  printf("Fraction of CPU time used is %f\n", cticks / (tcend - tcstart));
}
