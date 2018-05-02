#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the totalForecastInaccuracy function below.
int totalForecastInaccuracy(vector<int> t, vector<int> f) {
    // Return the sum of the weather forecast inaccuracies across all 7 days.
    int n = t.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += abs(t[i] - f[i]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp_temp;
    getline(cin, t_temp_temp);

    vector<string> t_temp = split_string(t_temp_temp);

    vector<int> t(7);

    for (int t_itr = 0; t_itr < 7; t_itr++) {
        int t_item = stoi(t_temp[t_itr]);

        t[t_itr] = t_item;
    }

    string f_temp_temp;
    getline(cin, f_temp_temp);

    vector<string> f_temp = split_string(f_temp_temp);

    vector<int> f(7);

    for (int f_itr = 0; f_itr < 7; f_itr++) {
        int f_item = stoi(f_temp[f_itr]);

        f[f_itr] = f_item;
    }

    int result = totalForecastInaccuracy(t, f);

    fout << result << "\n";

    fout.close();

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
