#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

const char* ans[] = {
    "impossible",     "stack",    "queue",    "not sure",
    "priority queue", "not sure", "not sure", "not sure",
};
int cmd, x, idx, ok[3];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    ok[0] = ok[1] = ok[2] = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &cmd, &x);
      if (cmd == 1) {
        s.push(x);
        q.push(x);
        pq.push(x);
      } else {
        if (s.empty() || s.top() != x) ok[0] = 0;
        if (q.empty() || q.front() != x) ok[1] = 0;
        if (pq.empty() || pq.top() != x) ok[2] = 0;
        s.pop();
        q.pop();
        pq.pop();
      }
    }
    idx = ok[0] | (ok[1] << 1) | (ok[2] << 2);
    printf("%s\n", ans[idx]);
  }
  return 0;
}
