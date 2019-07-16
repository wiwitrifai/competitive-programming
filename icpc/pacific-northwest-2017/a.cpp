#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int len = (int) s.length();
  bool bisa = true;
  for(int i = 0; i < len - 1 && bisa; ++i){
    if(s[i] == s[i + 1]) bisa = false;
  }
  
  puts(bisa ? "Odd." : "Or not.");
  return 0;
}