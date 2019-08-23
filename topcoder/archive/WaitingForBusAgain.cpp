#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector<double> poly[N];
void multpOne(vector<double> & p, double a, double b) {
	int n = p.size();
	p.push_back(0);
	for (int i = n; i > 0; --i) {
		p[i] = p[i-1] * a + p[i] * b;
	}
	p[0] *= b;
}

double a[N], b[N];

void dnc(int l, int r, vector<double> cur) {
	if (l == r) {
		poly[l] = cur;
		return;
	}
	int mid = (l + r) >> 1;
	vector<double> right = cur;
	for (int i = mid+1; i <= r; ++i) {
		multpOne(right, a[i], b[i]);
	}
	dnc(l, mid, right);
	vector<double> left = cur;
	for (int i = l; i <= mid; ++i)
		multpOne(left, a[i], b[i]);
	dnc(mid+1, r, left);
} 

class WaitingForBusAgain {
public:
	double expectedBus(vector <int> f) {
		int n = f.size(), m = f[0];
		for (int i = 0; i < n; ++i)
			m = min(m, f[i]);
		for (int i = 0; i < n; ++i) {
			a[i] = (double)m / f[i];
			b[i] = 1 - a[i];
		}
		dnc(0, n-1, {1});
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			double cur = 0;
			for (int j = 0; j < (int)poly[i].size(); ++j) {
				cur += poly[i][j] / (j + 1);
			}
			ans += cur * i * m / f[i];
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
		cout << "Testing WaitingForBusAgain (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1562430096;
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
		WaitingForBusAgain _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int f[] = {8,8,8,8};
				_expected = 1.5;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 1:
			{
				int f[] = {1,2,3};
				_expected = 0.5;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 2:
			{
				int f[] = {3,2,1};
				_expected = 1.5000000000000002;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 3:
			{
				int f[] = {3,1,4,1,5,9,2,6,5,3,5};
				_expected = 3.7044469870664325;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 4:
			{
				int f[] = {26, 19548, 19299, 19431, 39568, 19476, 19726, 19530, 19613,
				          19529, 19679, 19552, 19706, 19505, 19666, 19349, 19755, 19424,
				          19486, 19596, 19439, 19500, 19639, 19520, 19472, 19675, 19602,
				          19552, 19933, 19424, 19316, 19497, 19582, 19531, 19679, 19742,
				          19896, 19365, 20083, 19542, 19827, 19583, 19592, 19593, 19661,
				          19340, 19403, 19664, 19690, 19655, 19727, 19661, 19528, 19836,
				          19819, 19414, 19770, 19500, 19653, 19613, 19579, 19794, 19668,
				          19729, 19428, 19477, 19733, 19641, 19680, 19594, 19667, 19878,
				          19571, 19627, 19576, 19422, 19521, 19512, 19481, 19620, 19364,
				          19487, 19740, 19627, 19795, 19353, 19251, 19865, 19710, 19597,
				          19610, 19710, 19491, 19598, 19650, 19828, 19726, 19810, 19766,
				          19692};
				_expected = 3.1415926535671885;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			/*case 5:
			{
				int f[] = ;
				_expected = ;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int f[] = ;
				_expected = ;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int f[] = ;
				_expected = ;
				_received = _obj.expectedBus(vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
