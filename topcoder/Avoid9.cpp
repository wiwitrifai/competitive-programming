#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[10], cnt[10];

int inv(int x, int y) {
	int z = 18- x-y;
	while (z >= 9) z -= 9;
	return z;
}

int solve(int id = 0) {
	if (id == 9) {
		int ret = 0;
		for (int i = 0; i < 9; i++)
			ret += b[i];
		return ret;
	}
	b[id] = 0;
	int res = solve(id+1);
	if (cnt[id] == 0 && a[id] > 0) {
		for (int i = 0; i < id; i++)
			if (b[i])
				cnt[inv(i, id)]++;
		b[id] = 1;
		res = max(res, solve(id+1));
		if (cnt[id] == 0 && a[id] > 1) {
			cnt[inv(id, id)]++;
			b[id] = a[id];
			res	= max(res, solve(id+1));
			cnt[inv(id, id)]--;
		}
		for (int i = 0; i < id; i++)
			if (b[i])
				cnt[inv(i, id)]--;
	}
	return res;
}


class Avoid9 {
public:
	int maxSizeOf9Free(vector <int> A) {
		memset(a, 0, sizeof a);
		for (int x : A)
			a[x % 9]++;
		for (int i = 0; i < 9; i++){
			if (((i * 3) % 9) == 0)
				a[i] = min(a[i], 2);
		}
		int ans = solve(0);
		if (ans < 3) ans = -1;
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
		cout << "Testing Avoid9 (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1504897547;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Avoid9 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {6, 9, 5, 3};
				_expected = 3;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {6, 9, 18, 3, 15, 12};
				_expected = 4;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1, 10, 7, 19, 16, 28, 9, 46, 0, 37};
				_expected = 8;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {3, 12, 30, 6, 21, 4, 15, 9};
				_expected = 5;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {600308, 404694, 939932, 748673, 891293, 706905, 978182, 625631, 708003, 977632, 828206, 972547, 
				          184606, 929681, 237869, 610370, 559760, 939323, 272684, 162248, 168143, 753163, 302535, 153367, 
				          568583, 750868, 735416, 97724, 620300, 509987, 129310, 993312, 323413, 676205, 629534, 894380, 1791, 
				          499727, 751959, 456281};
				_expected = 23;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {12, 93, 48};
				_expected = -1;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {993320, 112864, 892808, 821699, 227492, 901628, 467512, 142654, 810125};
				_expected = 9;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maxSizeOf9Free(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
