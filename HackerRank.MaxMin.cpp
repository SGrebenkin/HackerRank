#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<int> diff;
    for (int i = 0; i < arr.size() - 1; ++i)
        diff.push_back(arr[i + 1] - arr[i]);

    int sum = 0;
    for (int i = 0; i < k - 1; ++i)
        sum += diff[i];
    
    int minSum = sum;
    for (int i = k - 1; i < arr.size() - 1; ++i) {
        sum += diff[i];
        sum -= diff[i - k + 1];
        if (sum < minSum)
            minSum = sum;
    }
    
    return minSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
