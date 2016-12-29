#include <bits/stdc++.h>

using namespace std;

class TreeDistanceConstruction {
public:
	vector <int> construct(vector <int> d) {
		vector< pair< int, int > > dd;
    int n = d.size();
    if (n == 1)
      return vector<int>();
    if (n == 2) {
      if (d[0] != 1 || d[1] != 1)
        return vector<int>();
      vector< int > ret;
      ret.push_back(0);
      ret.push_back(1);
      return ret;
    }
    for (int i = 0; i < n; i++) {
      dd.push_back(make_pair(d[i], i));
    }
    sort(dd.begin(), dd.end());
    int mi = dd[0].first, ma = dd[n-1].first;
    bool ok = true;
    if (mi+mi == ma) {
      if (dd[0].first == dd[1].first)
        ok = false;
      else {
        int cnt = 0;
        int now = mi+1;
        for (int i = 1; i < n; i++) {
          if (now == dd[i].first) {
            cnt++;
          }
          else {
            if (cnt < 2)
              ok = false;
            cnt = 1;
            now++;
          }
        }
        if (cnt < 2)
          ok = false;
      }
    }
    else if (mi + mi - 1 == ma) {
      if (dd[2].first == mi)
        ok = false;
      else {
        int cnt = 0;
        int now = mi;
        for (int i = 0; i < n; i++) {
          if (now == dd[i].first) {
            cnt++;
          }
          else {
            if (cnt < 2)
              ok = false;
            cnt = 1;
            now++;
          }
        }
        if (cnt < 2)
          ok = false;
      }
    }
    else
      ok = false;
    if (!ok)
      return vector<int>();
    vector<int> ret, id, used;
    id.assign(n, -1);
    used.assign(n, 0);
    vector< pair< int, int > > res;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (last != -1 && d[last] < dd[i].first) {
        ret.push_back(last);
        last = dd[i].second;
        ret.push_back(last);
        id[dd[i].first] = last;
      }
      if (last == -1) {
        last = dd[i].second;
        id[dd[i].first] = last;
      }
      used[last] = 1;
    }
    last = ret[0];
    for (int i = 0; i < n; i++) if (!used[dd[i].second]) {
      if (d[last] < dd[i].first || dd[i].first == mi) {
        ret.push_back(last);
        last = dd[i].second;
        ret.push_back(last);
        used[last] = 1;
      }
    }
    for (int i = 0; i < n; i++) if (!used[i]) {
      ret.push_back(i);
      ret.push_back(id[d[i]-1]);
    }
    return ret;
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
		cout << "Testing TreeDistanceConstruction (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483048991;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeDistanceConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {3,2,2,3};
				int __expected[] = {1, 2, 1, 0, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {1,2,2,2};
				int __expected[] = {0, 1, 0, 2, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {1,1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {1,1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
