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

void swap(int *a, int x, int y) {
  int t = a[x];
  a[x] = a[y]; a[y] = t;
}

int partition(int *a, int i, int j) {
  int pivot = a[i], pivot_index = i;

  while (i < j) {
    do {
      i++;
    } while(a[i] <= pivot);

    do {
      j--;
    } while(a[j] > pivot);

    if(i<j) swap(a, i, j);

    
  }

  swap(a, pivot_index, j);

  return j;
}

void quick_sort(int *a, int l, int r) {
  if(l<r) {
    int pivot = partition(a, l, r);

    quick_sort(a, 0, pivot);
    quick_sort(a, pivot+1, r);
  }


}

void sort() {
  int n; cin >> n;
  int a[n]; for(int i=0; i<n; i++) cin >> a[i];

  quick_sort(a, 0, n);

  for(int i=0; i<n; i++) cout << a[i] << " ";
  cout << endl;
}

int main()
{
  _ios;
  test(sort);
  

  return 0;
}