#include <cstdio>
#include <queue>
using namespace std;

struct Job {
  int id, priority;
  Job(int i, int j) : id(i), priority(j) {}
};
int n, m;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int num = 0;
    queue<Job> q;
    priority_queue<int> pq;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      int j;
      scanf("%d", &j);
      pq.push(j);
      q.push(Job(i, j));
    }
    while (q.front().id != m || q.front().priority != pq.top()) {
      if (q.front().priority == pq.top()) {
        ++num;
        q.pop();
        pq.pop();
      } else {
        q.push(q.front());
        q.pop();
      }
    }
    printf("%d\n", ++num);
  }
  return 0;
}