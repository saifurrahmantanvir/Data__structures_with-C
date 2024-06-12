#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define _ios     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fill(a,b) memset(a, b, sizeof(a))
#define pr       pair<int, int>
#define ft       first
#define sn       second
#define vi       vector<int>
#define vll      vector<ll>
#define pb       push_back
#define endl     "\n"
#define printl(x) for (auto i : x) cout << i << " ";
#define all(x)   x.begin(), x.end()
#define loop(a)  for(int i=0; i<a; i++)
#define test(fn) int t; cin>>t; while(t--) fn();

const int mod =  1e9+7;
void print(int x) { cout << x << endl; }

void merge(int *a, int left, int mid, int right) {
  int l = mid - left + 1;
  int r = right - mid;

  int L[l], R[r];

  for(int i=0; i<l; i++) {
    L[i] = a[left + i];

  }
  for(int j=0; j<r; j++) {
    R[j] = a[mid + 1 + j];

  }

  int i = 0, j = 0, k = left;

  while(i < l && j < r) {
    if(L[i] < R[j]) {
      a[k++] = L[i++];
      
    }
    else {
      a[k++] = R[j++];

    }


  }

  while(i < l) a[k++] = L[i++];

  while(j < r) a[k++] = R[j++];
}

void merge_sort(int *a, int l, int r) {
  if(l<r) {
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);

    merge(a, l, m, r);
  }


}

void sort() {
  int n; cin >> n;
  int a[n]; for(int i=0; i<n; i++) cin >> a[i];

  merge_sort(a, 0, n-1);

  for(int i=0; i<n; i++) cout << a[i] << " ";
  cout << endl;
}

int main()
{
  _ios;
  test(sort);


  return 0;
}