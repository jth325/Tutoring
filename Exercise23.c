#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
int main() {
  double cticks;
  clock_t tcstart, tcend;
  struct tms tmstart, tmend;
  int i, a = 1, b = 2, c;
  // clock_t를 반환한다. 이는 리눅스가 부팅된시간부터 지금까지 경과된 시간값을 갖는다
  // 또한 인자로 받은 tms 구조체에 프로세스가 호출한 명령을 수행하기 위해 소비된 시간을 갖는
  // tms_utime 변수와 프로세스의 명령을 시스템차원에서 실행하는데 소비된 시간을 갖는
  // tms_stime 변수를 대입한다
  if ((tcstart = times(&tmstart)) == -1) exit(1);
  printf("Fraction of CPU time used is %d\n", tcstart);
  printf("CPU time spent executing process is %d\n", tmstart.tms_utime);
  printf("CPU time spent in the system is %d\n", tmstart.tms_stime);
  // 계산(의미는 없는 계산) 을 10000000번 진행한다
  for (i = 0; i < 10000000; ++i) c = a + b;
  // 위에서 했듯이 tcend, tmend 시간관련 데이터를 대입한다
  if ((tcend = times(&tmend)) == -1) exit(1);
  printf("Fraction of CPU time used is %d\n", tcend);
  printf("CPU time spend executing process is %d\n", tmend.tms_utime);
  printf("CPU time spend in the system is %d\n", tmend.tms_stime);
  // 해당 프로세스가 수행되는 동안 걸린시간을 어림잡아 계산한다.
  // tmstart가 정의된 시점, tmend 가 정의된 시점의 시간 차이를 통해 계산을 한다
  cticks = tmend.tms_utime + tmend.tms_stime - tmstart.tms_utime - tmstart.tms_stime;
  printf("Total CPU time is %f seconds \n", cticks / 100.f);
  printf("Fraction of CPU time used is %f\n", cticks / (tcend - tcstart));
}
