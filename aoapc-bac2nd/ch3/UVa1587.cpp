#include <algorithm>
#include <cstdio>
using namespace std;

struct Pallet {
  int w, h;
  bool operator<(const Pallet& p) const {
    return w < p.w || (w == p.w && h < p.h);
  }
} p[6];

int is_box() {
  int x = p[0].w, y = p[0].h, z = p[2].h;  // x <= y <= z
  if ((p[2].w != x || p[2].h != z) || (p[4].w != y || p[4].h != z)) return 0;
  for (int i = 0; i < 6; i += 2)
    if (p[i].w != p[i + 1].w || p[i].h != p[i + 1].h) return 0;
  return 1;
}

int main() {
  while (scanf("%d%d", &p[0].w, &p[0].h) == 2) {
    for (int i = 1; i < 6; ++i) scanf("%d%d", &p[i].w, &p[i].h);
    for (int i = 0; i < 6; ++i)
      if (p[i].w > p[i].h) swap(p[i].w, p[i].h);
    sort(p, p + 6);
    printf("%s\n", is_box() ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}