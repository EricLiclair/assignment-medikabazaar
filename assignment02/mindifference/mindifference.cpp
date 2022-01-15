#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void find_min_difference(vector<int> arr, int n)
{
  int mindiff = INT_MAX;
  int lowerval = 0;
  int upperval = 0;
  sort(arr.begin(), arr.end());
  for (int i = 1; i < n; i++)
  {
    if ((arr[i] - arr[i - 1]) < mindiff)
    {
      mindiff = arr[i] - arr[i - 1];
      lowerval = arr[i - 1];
      upperval = arr[i];
    }
  }
  cout << "(" << lowerval << ", " << upperval << ", " << mindiff << ")" << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t > 0)
  {
    t--;
    int n;
    vector<int> speeds;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      speeds.push_back(a);
    }
    find_min_difference(speeds, n);
    speeds.clear();
  }

  return 0;
}
