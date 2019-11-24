#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main() {
  time_t tstart, tend;
  double diff;
  // time 함수는 함수를 호출할때의 시간을 정수로 변환하여 첫번째 인자에 대입한다
  time(&tstart);
  // 3초 대기한다
  sleep(3);
  time(&tend);
  // tstart 정의 시점, tend 정의 시점의 시간차이를 통해 sleep 이 몇초동안 작동했는지
  // 를 알아보는 로직이다
  diff = difftime(tend, tstart);
  printf("sleep time is %lf\n", diff);
}
