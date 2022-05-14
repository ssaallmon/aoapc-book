#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

const string fmt = "+-*";
string s, key, val;
map<string, string> dict[2];
set<string> ans[3];

void init() {
  dict[0].clear();
  dict[1].clear();
  for(int i = 0; i < 3; ++i) ans[i].clear();
}

void find_out() {
  for(auto &i : dict[0]) {
    key = i.first;
    if(dict[1].count(key)) {
      if (dict[0][key] != dict[1][key]) ans[2].insert(key);
      dict[1].erase(key);
    } else ans[1].insert(key);
  }
  for(auto &i : dict[1]) ans[0].insert(i.first);
}

void print_ans() {
  int ok = 1;
  for(int i = 0; i < 3; ++i) {
    if(ans[i].empty()) continue;
    ok = 0;
    cout << fmt[i];
    for(auto &j : ans[i]) cout << j << (j == *ans[i].rbegin() ? '\n' : ',');
  }
  if(ok) cout << "No changes\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    init();
    for(int i = 0; i < 2; ++i) {
      cin >> s;
      for(int j = 0; j < s.size(); ++j)
        if (s[j] == ':' || s[j] == ',' || s[j] == '{' || s[j] == '}') s[j] = ' ';
      stringstream ss(s);
      while(ss >> key >> val) dict[i][key] = val;
    }
    find_out();
    print_ans();
    putchar('\n');
  }
  return 0;
}
