#include <cstdio>
#include <algorithm>

int S[20], N, M;
long long P, p;

int main() {
  while(~scanf("%d", &N)) {
    P = 0;
    for(int i = 0; i < N; ++i) scanf("%d", &S[i]);
    for(int i = 0; i < N; ++i) {
      for(int j = i; j < N; ++j) {
        p = 1;
        for(int k = i; k <= j; ++k) p *= S[k];
        P = std::max(P, p);
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", ++M, P);
  }
  return 0;
}
