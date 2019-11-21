#include <stdio.h>
#include <math.h>

int main(void)
{
  double x;

  printf("%10s %10s %10s %15s %20s\n", "x", "log(x)", "sqrt(x)", "exp(x)", "pow(10.0, x)");

  for (x = 1; x <= 10; x++)
  {
    // x, log x, x의 제곱근, e의 x제곱, 10.0의 x제곱 값을 반복 출력 (1 <= x <= 10)
    printf("%10.5f %10.5f %10.5f %15.5f %20.5f\n", x, log(x), sqrt(x), exp(x), pow(10.0, x));
  }
}
