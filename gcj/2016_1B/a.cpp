#include <bits/stdc++.h>

using namespace std;

int cnt[256], ans[11];
char s[2016];
char num[][20] = {"ZERO",
"TWO",
"FOUR",
"SIX",
"EIGHT",
"ONE",
"THREE",
"FIVE",
"SEVEN",
"NINE" };
char key[] = {'Z', 'W', 'U', 'X', 'G', 'O', 'T', 'F', 'V', 'I'};
int val[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int main() {
  int tc;
  scanf("%d", &tc);
  for(int t = 1; t <= tc; t++) {
    scanf("%s", s);
    for(int i = 0; i<26; i++)
      cnt[i] = 0;
    for(int i = 0; i<10; i++)
      ans[i] = 0;
    int n = strlen(s);
    for(int i = 0; i<n; i++) {
      cnt[s[i]-'A']++;
    }
    for(int i = 0; i<10; i++) {
      int n = strlen(num[i]);
      ans[val[i]] = cnt[key[i]-'A'];
      for(int j = 0; j<n; j++)
        cnt[num[i][j]-'A'] -= ans[val[i]];
    }
    printf("Case #%d: ", t);
    for(int i = 0; i<10; i++) {
      while(ans[i]) {
        printf("%d", i);
        ans[i]--;
      }
    }
    printf("\n");
    cerr << "TC : " << t << endl;
  }

  return 0;
}