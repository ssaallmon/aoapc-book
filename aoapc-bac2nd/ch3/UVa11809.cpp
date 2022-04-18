#include <cmath>
#include <cstdio>
#include <cstring>

const float EPS = 1e-4;

int B;
double A, a[10][35];
long long b[10][35];

void init() {
  for (int i = 0; i < 10; ++i)
    for (int j = 1; j < 31; ++j) {
      double d = log10(1 - pow(2, -1 - i)) + (pow(2, j) - 1) * log10(2);
      b[i][j] = d;
      a[i][j] = pow(10, d - b[i][j]);
    }
}

void print_ans() {
  for (int i = 0; i < 10; ++i)
    for (int j = 1; j < 31; ++j)
      if (b[i][j] == B && fabs(A - a[i][j]) < EPS) {
        printf("%d %d\n", i, j);
        return;
      }
}

int main() {
  init();
  char F[30];
  while (scanf("%s", F) && strcmp(F, "0e0")) {
    *strchr(F, 'e') = ' ';
    sscanf(F, "%lf%d", &A, &B);  // A * 10^B = C * 2^D;
    print_ans();
  }
  return 0;
}
