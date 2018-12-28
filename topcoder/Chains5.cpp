#include <bits/stdc++.h>

using namespace std;

class Chains5 {
public:
	int construct(vector <int> x, vector <int> y, int n, int seed, int a, int b, int c, int m) {
		vector<pair<int, int> > vp;		
		while (x.size() < n) {
	    seed = (1LL * a * seed + b) % c;
	    int newx = seed % m;
	    seed = (1LL * a * seed + b) % c;
	    int newy = seed % m;
	    if (newx > newy)
        swap( newx, newy );
      x.push_back(newx);
      y.push_back(newy);
		}
		int emp = 0;
		for (int i = 0; i < n; ++i) {
			if (x[i] == y[i])
				++emp;
			else
				vp.emplace_back(x[i], -y[i]);
		}
		sort(vp.begin(), vp.end());
		multiset<int> ms, msnow;
		int ans = 0;
		int now = -1;
		for (auto it : vp) {
			if (now != it.first) {
				now = it.first;
				for (int z : msnow)
					ms.insert(z);
				msnow.clear();
			}
			auto ims = ms.lower_bound(-it.second), inow = msnow.upper_bound(-it.second);
			if (ims != ms.end() && inow != msnow.end()) {
				if (*ims < *inow)
					ms.erase(ims);
				else
					msnow.erase(inow);
			}
			else if (ims != ms.end()) {
				ms.erase(ims);
			}
			else if (inow != msnow.end()) {
				msnow.erase(inow);
			}
			else
				++ans;
			msnow.insert(-it.second);
		}
		return ans = max(ans, emp);
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
		cout << "Testing Chains5 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1545965686;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Chains5 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1, 2, 1};
				int y[] = {7, 4, 10};
				int n = 3;
				int seed = 0;
				int a = 0;
				int b = 0;
				int c = 1;
				int m = 1;
				_expected = 1;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}
			case 1:
			{
				int x[] = {1, 2};
				int y[] = {7, 14};
				int n = 2;
				int seed = 0;
				int a = 0;
				int b = 0;
				int c = 1;
				int m = 1;
				_expected = 2;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}
			case 2:
			{
				int x[] = {1, 2, 3, 3, 0};
				int y[] = {2, 3, 4, 4, 9};
				int n = 5;
				int seed = 0;
				int a = 0;
				int b = 0;
				int c = 1;
				int m = 1;
				_expected = 4;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}
			case 3:
			{
				int x[] = {};
				int y[] = {};
				int n = 0;
				int seed = 0;
				int a = 0;
				int b = 0;
				int c = 1;
				int m = 1;
				_expected = 0;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}
			case 4:
			{
				int x[] = {10};
				int y[] = {20};
				int n = 7;
				int seed = 47;
				int a = 100;
				int b = 1;
				int c = 1073741824;
				int m = 1000000;
				_expected = 4;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int m = ;
				_expected = ;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int m = ;
				_expected = ;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int m = ;
				_expected = ;
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), n, seed, a, b, c, m); break;
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
