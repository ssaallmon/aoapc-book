#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Book {
  string A, T;
  Book(string A, string T) : A(A), T(T) {}
  bool operator < (const Book& rhs) const {
    return A < rhs.A || A == rhs.A && T < rhs.T;
  }
};

int main() {
  string s;
  vector<Book> v;
  map<string, int> m;
  while(getline(cin, s) && s[0] != 'E') {
    int i = s.find("by");
    m[s.substr(0, i-1)] = 2;
    v.push_back(Book(s.substr(i+3), s.substr(0, i-1)));
  }
  sort(v.begin(), v.end());
  while(getline(cin, s) && s[0] != 'E') {
    if(s[0] == 'S') {
      for(int i = 0; i < v.size(); ++i) {
        if(!m[v[i].T]) {
          int pre = -1;
          m[v[i].T] = 2;
          cout << "Put " << v[i].T;
          for(int j = 0; j < i; ++j)
            if(m[v[j].T] == 2) pre = j;
          cout << (pre == -1 ? " first\n" : " after " + v[pre].T + '\n');
        }
      }
      puts("END");
    } 
    else m[s.substr(s.find(' ')+1)]--;
  }
  return 0;
}
