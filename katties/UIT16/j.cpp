#include <bits/stdc++.h>

using namespace std;

char s[][50] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char p[][50] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char toUp(char c) {
  return c-'a' + 'A';
}
void print(int num, bool caps) {
  if(num < 20) {
    if(caps)
      printf("%c%s", toUp(s[num][0]), s[num]+1);
    else
      printf("%s", s[num]);
  }
  else {
    int a = num/10 - 2, b = num % 10;
    if(caps)
      printf("%c%s", toUp(p[a][0]), p[a]+1);
    else
      printf("%s", p[a]);
    if(b) {
      printf("-%s", s[b]);
    }
  }
}

string str;

int main() {
  while(getline(cin, str)) {
    stringstream ss;
    ss << str;
    ss >> str;
    if(str[0] >= '0' && str[0] <= '9')
      print(atoi(str.c_str()), true);
    else
      printf("%s", str.c_str());
    while(ss >> str) {
      printf(" ");
      if(str[0] >= '0' && str[0] <= '9')
        print(atoi(str.c_str()), false);
      else
        printf("%s", str.c_str());
    }
    printf("\n");
  }
  return 0;
}