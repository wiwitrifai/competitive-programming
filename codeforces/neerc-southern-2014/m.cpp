#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <stack>

#define maximum(a,b) (a > b ? a : b)
#define minimum(a,b) (a < b ? a : b)
#define gcd(a,b) (a == 0 ? b : gcd(b%a, a))
#define pow(a,b) (b == 0 ? 1 : a*pow(a, b-1))

typedef long long ll;

using namespace std;

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
template <class T>
inline long long to_longlong (const T& t)
{
    std::stringstream ss;
    long long val;
    ss.str(t);
    ss >> val;
    return val;
}

//#define OFFLINE_TESTING

const int max1 = 1000;
const int max2 = 26+5;
int arr[max1][max2];
int line[max1][max2];
int row[max1][max2];

int main() {
    ios_base::sync_with_stdio(false);
    #ifdef OFFLINE_TESTING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    char c;
    string s;
    
    cin >> n;
    cin.get(c);
    
    for (int i = 0; i < max1; i++) {
        for (int j = 0; j < max2; ++j) {
            arr[i][j] = 0;
            line[i][j] = 0;
            row[i][j] = 0;
        }
    }
    
    
    int x = 0, y;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            switch(s[j]) {
                case '{': ++x; break;
                case '}':
                    for (int k = 0; k < max2; ++k) {
                        arr[x][k] = 0;
                        line[x][k] = 0;
                        row[x][k] = 0;
                    }
                     --x; break;
                case ' ': break;
                default:
                    y = s[j]-'a'+1;
                    bool flag = true;
                    for (int k = x; flag && k >= 0; --k) {
                        if (arr[k][y]) {
                           flag = false;
                           cout << i+1 << ":" << j+1 << ": warning: shadowed declaration of " << s[j] << ", the shadowed position is " << line[k][y] << ":" << row[k][y] << endl;
                        }
                    }
                    arr[x][y] = y;
                    line[x][y] = i+1;
                    row[x][y] = j+1;
            }
        }
    }
    
    #ifdef OFFLINE_TESTING
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}