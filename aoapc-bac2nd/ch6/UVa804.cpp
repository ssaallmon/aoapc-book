#include <cstdio>
#include <vector>

const int maxn = 105;
int NP, NT, NF, p[maxn];
std::vector<int> ip[maxn], op[maxn];  // ip: input place, op: output place

void init() {
  for (int i = 0; i < maxn; ++i) {
    ip[i].clear();
    op[i].clear();
  }
}

int main() {
  int kase = 0;
  while (scanf("%d", &NP) && NP) {
    init();
    int dead = 0, num = 0;
    for (int i = 1; i <= NP; ++i) scanf("%d", &p[i]);  // begin from 1
    scanf("%d", &NT);
    for (int i = 0; i < NT; ++i) {
      int j;
      while (scanf("%d", &j) && j)
        j < 0 ? ip[i].push_back(-j) : op[i].push_back(j);
    }
    scanf("%d", &NF);
    for (int i = 0; i < NF; ++i, ++num) {
      dead = 1;
      for (int j = 0; j < NT; ++j) {
        int fire = 1;
        for (int k = 0; k < ip[j].size(); ++k) {
          if (--p[ip[j][k]] < 0) {
            while (k >= 0) ++p[ip[j][k--]];
            fire = 0;
            break;
          }
        }
        if (fire) {
          for (int k = 0; k < op[j].size(); ++k) ++p[op[j][k]];
          dead = 0;
          break;
        }
      }
      if (dead) break;
    }
    printf("Case %d: %s after %d transitions\nPlaces with tokens:", ++kase, dead ? "dead" : "still live", num);
    for (int i = 1; i <= NP; ++i)
      if (p[i]) printf(" %d (%d)", i, p[i]);
    puts("\n");
  }
  return 0;
}
