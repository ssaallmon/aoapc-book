#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Book {
  string at, tt;  // at: author, tt: title
  Book(string at, string tt) : at(at), tt(tt) {}
};
vector<Book> v;
vector<int> n, stat;
unordered_map<string, int> m;

int cmp(const int i, const int j) {
  return v[i].at < v[j].at || v[i].at == v[j].at && v[i].tt < v[j].tt;
}

int main() {
  string s;
  while (getline(cin, s) && s[0] != 'E') {
    int i = s.find("by");
    n.push_back(v.size());
    v.push_back(Book(s.substr(i + 3), s.substr(0, i - 1)));
  }
  stat.resize(n.size(), 2);
  sort(n.begin(), n.end(), cmp);  // indirect ordination
  for (int i = 0; i < n.size(); ++i) m[v[n[i]].tt] = i;
  while (getline(cin, s) && s[0] != 'E') {
    if (s[0] == 'S') {
      for (int i = 0; i < n.size(); ++i) {
        if (stat[i]) continue;
        stat[i] = 2;
        int first = 0;
        cout << "Put " << v[n[i]].tt;
        for (int j = i - 1; j >= 0; --j) {
          if (stat[j] == 2) {
            cout << " after " + v[n[j]].tt << '\n';
            first = 1;
            break;
          }
        }
        if (!first) cout << " first\n";
      }
      cout << "END\n";
    } else
      --stat[m[s.substr(s.find(' ') + 1)]];
  }
  return 0;
}