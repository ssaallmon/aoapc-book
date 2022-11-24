#include <cstdio>
#include <cstring>

const int maxl = 130;
char A[maxl], B[maxl];

int check() {
  int top = -1, m = strlen(A);
  for(int i = 0; i < m - 1; ++i) {
    if(A[i] == '(' || A[i] == '[') B[++top] = A[i];
    else if (A[i] == ')' && B[top] == '(' || A[i] == ']' && B[top] == '[') --top;
    else return 0;
  }
  return top < 0;
}

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  while(n--) {
    fgets(A, maxl, stdin);
    memset(B, 0, sizeof(B));
    puts(check() ? "Yes" : "No");
  }
  return 0;
}
