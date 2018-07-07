#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

long long a[N];
int cnt[N];
int val[N];

class ProductThreshold {
public:
	long long subarrayCount(int N, int limit, vector <int> Aprefix, int spread, int offset) {
		int p = Aprefix.size();
		for (int i = 0; i < p; ++i)
			a[i] = Aprefix[i];
		long long dua31 = 1LL << 31;
		long long seed = abs(a[p-1]);
		for (int i = p; i < N; ++i) {
			seed = (seed * 1103515245LL + 12345LL) % dua31;
			a[i] = (seed % spread) + offset;
		}
		// for (int i = 0; i < N; ++i)
		// 	cerr << a[i] << " ";
		// cerr << endl;
		int cur = 0, sum = 0;
		for (int i = 0; i < N; ++i) {
			cur += a[i] < 0;
			val[i] = cur & 1;
			// cerr << val[i] << " ";
			sum += val[i];
			cnt[i] = sum;
		}
		// cerr << endl;
		a[N] = 0;
		long long mul = 0, smul = 0;
		long long ans = 0;
		for (int i = 0, j = 0, k = 0; i < N; ++i) {
			// cerr << i << " ans = " << ans << endl;
			if (k < i) k = i;
			while (k < N && a[k] != 0) ++k;
			if (j <= i) {
				j = i;
				mul = 1;
			}
			ans += N-k;
			while (j < k && llabs(mul * a[j]) <= limit) {
				mul *= a[j];
				++j;
			}
			// cerr << i << " " << j << " " << k << " " << mul << " " << mul * a[j] << " " << limit << endl;
			ans += j-i;
			if (j == k) continue;
			int neg = (k > 0 ? cnt[k-1] : 0) - (j > 0 ? cnt[j-1] : 0);
			if (j > 0 && val[j-1])
				neg = k-j - neg;
			// cerr << ans << " " << neg << " ? " << (k-j-neg) << " " << mul << endl;
			if (mul < 0) {
				ans += (k-j-neg);
			}
			else {
				ans += (neg);
			}
			// cerr << ans << endl;
			if (j > i)
				mul /= a[i];
		}
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
		cout << "Testing ProductThreshold (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1530980223;
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
		ProductThreshold _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int limit = 5;
				int Aprefix[] = {1,2,3,-4,5};
				int spread = 1;
				int offset = 1;
				_expected = 13LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 1:
			{
				int N = 10;
				int limit = 8;
				int Aprefix[] = {2,2,2,2,2,2,2,2,2,2};
				int spread = 1;
				int offset = 47;
				_expected = 27LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 2:
			{
				int N = 20;
				int limit = 999888777;
				int Aprefix[] = {47};
				int spread = 7654321;
				int offset = 1;
				_expected = 21LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 3:
			{
				int N = 5;
				int limit = 8;
				int Aprefix[] = {3,0,3,0,3};
				int spread = 47;
				int offset = 47;
				_expected = 15LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 4:
			{
				int N = 1000;
				int limit = 1;
				int Aprefix[] = {-1};
				int spread = 1;
				int offset = 2;
				_expected = 1000LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 5:
			{
				int N = 100;
				int limit = 47;
				int Aprefix[] = {1};
				int spread = 1;
				int offset = 1;
				_expected = 5050LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			/*case 6:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}*/
			/*case 7:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}*/
			/*case 8:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
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
