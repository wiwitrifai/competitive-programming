#include <bits/stdc++.h>

using namespace std;

class MeanMedian {
public:
	int minEffort(int needMean, int needMedian, vector <int> d) {
		sort(d.begin(), d.end());
		int n = d.size();
		int k = (n + 1) / 2;
		long long ans = 0, cnt = 0;
		vector<int> score(n, 0);
		long long need = 1LL * needMean * n;
		for (int i = 0; i < k; ++i) {
			ans += 1LL * d[i] * needMedian;
			score[i] = needMedian;
			cnt += needMedian;
		}
		for (int i = 0; i < n && cnt < need; ++i) {
			while (score[i] < 10 && cnt < need) {
				++score[i];
				++cnt;
				ans += d[i];
			}
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
		cout << "Testing MeanMedian (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1570719683;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MeanMedian _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int needMean = 2;
				int needMedian = 4;
				int d[] = {30, 25, 20};
				_expected = 180;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int needMean = 4;
				int needMedian = 4;
				int d[] = {30, 25, 20};
				_expected = 260;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int needMean = 10;
				int needMedian = 3;
				int d[] = {1, 4, 3, 2, 1};
				_expected = 110;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int needMean = 0;
				int needMedian = 0;
				int d[] = {1000};
				_expected = 0;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int needMean = 8;
				int needMedian = 3;
				int d[] = {4, 8, 12, 16, 18, 20, 22, 23, 24};
				_expected = 1046;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int needMean = ;
				int needMedian = ;
				int d[] = ;
				_expected = ;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int needMean = ;
				int needMedian = ;
				int d[] = ;
				_expected = ;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int needMean = ;
				int needMedian = ;
				int d[] = ;
				_expected = ;
				_received = _obj.minEffort(needMean, needMedian, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
