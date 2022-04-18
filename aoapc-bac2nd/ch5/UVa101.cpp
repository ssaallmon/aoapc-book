#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 30;
int n, pos[maxn];
stack<int> pile[maxn];

void clear_above(int p) {
  int pa = pos[p];
  while (!pile[pa].empty() && pile[pa].top() != p) {
    int pb = pile[pa].top();
    pile[pb].push(pb);
    pos[pb] = pb;
    pile[pa].pop();
  }
}

void pile_onto(int a, int b) {
  stack<int> t;
  int pa = pos[a], pb = pos[b];
  while (!pile[pa].empty()) {
    int p = pile[pa].top();
    t.push(p);
    pos[p] = pb;
    pile[pa].pop();
    if (p == a) break;
  }
  while (!t.empty()) {
    pile[pb].push(t.top());
    t.pop();
  }
}

void print() {
  for (int i = 0; i < n; ++i) {
    stack<int> t;
    while (!pile[i].empty()) {
      t.push(pile[i].top());
      pile[i].pop();
    }
    printf("%d:", i);
    while (!t.empty()) {
      printf(" %d", t.top());
      t.pop();
    }
    putchar('\n');
  }
}

int main() {
  int a, b;
  char s1[5], s2[5];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    pos[i] = i;
    pile[i].push(i);
  }
  while (scanf("%s", s1) && s1[0] != 'q') {
    scanf("%d%s%d", &a, s2, &b);
    if (pos[a] == pos[b]) continue;
    if (s1[0] == 'm') clear_above(a);
    if (s2[1] == 'n') clear_above(b);
    pile_onto(a, b);
  }
  print();
  return 0;
}
