#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const double eps = 1e-9;

// Complete the minimumTimeToEnd function below.
void minimumTimeToEnd(vector<long> x, long w, long v, int q) {
    // Take the descriptions of the people from standard input and print the answers to standard output
    int n = x.size();
    while (q--) {
        int p, t, u;
        cin >> p >> t >> u;
        double ans = t + (double)(x[n-1] - p) / u;
        // cerr << ans << " ";
        int nx = lower_bound(x.begin(), x.end(), p) - x.begin();
        {
            double time = t + (double)(x[nx] - p) / u;
            double awal = (double)(x[nx]) / v;
            if (awal <= time) {
                int need = max(int((double)(time-awal)/w), 0);
                awal += need * w;
                while (awal + eps < time) awal += w;
            }
            awal += (double)(x[n-1] - x[nx])/v;
            ans = min(ans, awal);
        }
        // cerr << ans << " ";
        --nx;
        if (nx >= 0)
        {
            double time = t + (double)(p - x[nx]) / u;
            double awal = (double)(x[nx]) / v;
            // cerr << awal << " " << time << endl;
            if (awal <= time) {
                int need = max(int((double)(time-awal)/w), 0);
                awal += need * w;
                while (awal + eps < time) awal += w;
            }
            // cerr << awal << " ";
            awal += (double)(x[n-1] - x[nx])/v;
            ans = min(ans, awal);
        }
        printf("%.10lf\n", ans);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<long> x(n);

    for (int x_itr = 0; x_itr < n; x_itr++) {
        long x_item = stol(x_temp[x_itr]);

        x[x_itr] = x_item;
    }

    string wv_temp;
    getline(cin, wv_temp);

    vector<string> wv = split_string(wv_temp);

    long w = stol(wv[0]);

    long v = stol(wv[1]);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    minimumTimeToEnd(x, w, v, q);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}