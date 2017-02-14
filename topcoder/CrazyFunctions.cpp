#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

class CrazyFunctions {
public:
  int count(int n, int k) {
    long long ans = 1;
    for (int i = n-k+1; i <= n; i++)
    	ans = (ans * i) % mod;
    for (int i = 0; i < n-k-1; i++)
    	ans = (ans * n) % mod;
    if (k < n)
	    ans = (ans * k) % mod;
    return ans;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc == 1) 
  {
    cout << "Testing CrazyFunctions (500.0 points)" << endl << endl;
    for (int i = 0; i < 20; i++)
    {
      ostringstream s; s << argv[0] << " " << i;
      int exitCode = system(s.str().c_str());
      if (exitCode)
        cout << "#" << i << ": Runtime Error" << endl;
    }
    int T = time(NULL)-1487049783;
    double PT = T/60.0, TT = 75.0;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << endl;
    cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
    cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
  }
  else
  {
    int _tc; istringstream(argv[1]) >> _tc;
    CrazyFunctions _obj;
    int _expected, _received;
    time_t _start = clock();
    switch (_tc)
    {
      case 0:
      {
        int n = 2;
        int k = 1;
        _expected = 2;
        _received = _obj.count(n, k); break;
      }
      case 1:
      {
        int n = 2;
        int k = 2;
        _expected = 2;
        _received = _obj.count(n, k); break;
      }
      case 2:
      {
        int n = 1;
        int k = 1;
        _expected = 1;
        _received = _obj.count(n, k); break;
      }
      case 3:
      {
        int n = 3;
        int k = 1;
        _expected = 9;
        _received = _obj.count(n, k); break;
      }
      case 4:
      {
        int n = 3;
        int k = 3;
        _expected = 6;
        _received = _obj.count(n, k); break;
      }
      case 5:
      {
        int n = 5;
        int k = 3;
        _expected = 900;
        _received = _obj.count(n, k); break;
      }
      case 6:
      {
        int n = 5000;
        int k = 5000;
        _expected = 541108809;
        _received = _obj.count(n, k); break;
      }
      /*case 7:
      {
        int n = ;
        int k = ;
        _expected = ;
        _received = _obj.count(n, k); break;
      }*/
      /*case 8:
      {
        int n = ;
        int k = ;
        _expected = ;
        _received = _obj.count(n, k); break;
      }*/
      /*case 9:
      {
        int n = ;
        int k = ;
        _expected = ;
        _received = _obj.count(n, k); break;
      }*/
      default: return 0;
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
    if (_received == _expected)
      cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
    else
    {
      cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
      cout << "           Expected: " << _expected << endl;
      cout << "           Received: " << _received << endl;
    }
  }
}

// END CUT HERE
