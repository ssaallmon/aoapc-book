#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

void solve(string& s) {
  for(auto& c : s) {
    if(isupper(c)) c = tolower(c);
    else if(!isalpha(c)) c = ' ';
  }
}

int main() {
  string s;
  stringstream ss;
  set<string> dict;
  while(getline(cin, s)) {
    solve(s); ss << s;
    while(ss >> s) dict.insert(s);
    ss.clear();
  }
  for(auto& word : dict) cout << word << '\n';
  return 0;
}
