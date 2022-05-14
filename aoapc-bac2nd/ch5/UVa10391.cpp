#include <iostream>
#include <string>
#include <set>
using namespace std;

string word;
set<string> dict;

int main() {
  while(cin >> word) dict.insert(word);
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
    if(it->size() == 1) continue;
    for(int i = 1; i < it->size(); ++i) {
      if(dict.count(it->substr(0, i)) && dict.count(it->substr(i))) {
        cout << *it << '\n';
        break;
      }
    }
  }
  return 0;
}
