#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct Card {
  char rank, suit;
  Card(char c1, char c2) : rank(c1), suit(c2) {}
  bool operator==(const Card &c) const {
    return rank == c.rank || suit == c.suit;
  }
};

vector<stack<Card>> pile;
int cnt, right[53], left[53];

void link(int L, int R) {
  right[L] = R;
  left[R] = L;
}

int find(int idx, int step) {
  while (idx && step--) idx = left[idx];
  return idx;
}

void accordian(int idx) {
  if (!idx) return;
  int pos = 0;
  for (int i = idx; i; i = right[i]) {
    for (int j = 3; j > 0; j -= 2) {
      int k = find(i, j);
      if (k && pile[k].top() == pile[i].top()) {
        pile[k].push(pile[i].top());
        pile[i].pop();
        pos = k;
        if (pile[i].empty()) {
          --cnt;
          link(left[i], right[i]);
        }
        break;
      }
    }
    if (pos) break;
  }
  accordian(pos);
}

int main() {
  char s[3];
  while (scanf("%s", s) && strcmp(s, "#")) {
    pile.resize(53);
    pile[1].push(Card(s[0], s[1]));
    for (int i = 2; i < 53; ++i) {
      scanf("%s", s);
      pile[i].push(Card(s[0], s[1]));
      link(i - 1, i);
    }
    cnt = 52;
    link(0, 1);
    link(52, 0);
    accordian(right[0]);
    printf("%d pile%sremaining:", cnt, cnt > 1 ? "s " : " ");
    for (int i = right[0]; i; i = right[i]) printf(" %d", pile[i].size());
    pile.clear();
    putchar('\n');
  }
  return 0;
}