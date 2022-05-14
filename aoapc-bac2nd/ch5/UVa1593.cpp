#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int p[185];
vector<string> v[1005];

void print(const string &s, int len, char c) {
  cout << s;
  for(int i = 0; i < len - s.size(); ++i) putchar(c);
}

int main() {
  int n1 = 0;
  string s1, s2;
  while(getline(cin, s1)) {
    int i = 0;
    stringstream ss(s1);
    while(ss >> s2) {
      v[n1].push_back(s2);
      if(s2.size() > p[i]) p[i] = s2.size();
      ++i;
    }
    ++n1;
  }
  for(int i = 0; i < n1; ++i) {
    int n2 = v[i].size();
    for(int j = 0; j < n2; ++j)
      print(v[i][j], j == n2 - 1 ? v[i][j].size() : p[j] + 1, ' ');
    putchar('\n');
  }
  return 0;
}
