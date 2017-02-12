#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int a[N][N];
int solve(int l, int r, int depth, bool rev) {
	if (r-l <= 2)
		return depth;
	int x = depth, y = x+1, z = x+2;
	if (rev)
		swap(x, y);
	int mid = (l + r) / 2;
	if ((mid - l + 1) & 1)
		mid++;
	for (int i = l; i <= mid; i += 2)
		a[x][i] = 1;
	for (int i = mid + 2; i <= r; i += 2)
		a[x][i] = 1;
	for (int i = l+1; i <= mid; i += 2)
		a[y][i] = 1;
	for (int i = mid + 3; i <= r; i += 2)
		a[y][i] = 1;
	a[z][mid+1] = 1;
	for (int i = l+1; i < mid; i += 2)
		a[z][i] = mid+1);
	int ret = 0;
	ret = max(ret, solve(l, mid, depth+3, rev));
	ret = max(ret, solve(mid+1, r, depth+3, rev^1));
	return ret;
}

class CoprimeNeighbors {
public:
	vector<long long> findAny(int N) {
		
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
		cout << "Testing CoprimeNeighbors (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486955268;
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
		CoprimeNeighbors _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				long long __expected[] = {14, 25 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			case 1:
			{
				int N = 3;
				long long __expected[] = {1000000000000000000, 1, 1000000000000000000 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			case 2:
			{
				int N = 6;
				long long __expected[] = {14, 39, 80, 63, 26, 105 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			/*case 3:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
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
