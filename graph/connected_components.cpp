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
template<typename... T>
void readln(T&... args) { ((cin >> args), ...); }
template<typename... T>
void println(T&&... args) { ((cout << args << " "), ...); }
template<class T>
void writeln(const T &t) { cout << t << '\n'; }
template<class T, class...args>
void writeln(const T &t, const args &...rest) {
  cout << t << ' ';
  writeln(rest...);
}
template<class T>
void writeln(const vector<T> &v) {
  for (auto c : v) cout << c << ' ';
  cout << '\n';
}
template<class T, class T_>
void writeln(const vector<T> &v, T_ n) {
  for (T_ i = 1; i <= n; i++) cout << v[i] << ' ';
  cout << '\n';
}
template<class T, class T_>
void writeln(const pair<T, T_>p) { cout << p.first << ' ' << p.second << '\n'; }

const int n = 1e3+10;

vector<int> grap_[n];
vector<bool> visited(n, false);

vector<vector<int>> connComponents;
vector<int> cConnComponent;

void dfs(int node) {
  visited[node] = true;
  cConnComponent.push_back(node);

  for(int child : grap_[node]) if(!visited[child]) dfs(child);
}

int main() {
  _ios;

  int n, e; readln(n, e);

  for(int i = 0; i < e; i++) {
    int a, b; readln(a, b);

    grap_[a].push_back(b); grap_[b].push_back(a);
  }

  int cnt = 0;

  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      cConnComponent.clear();
      dfs(i);
      cnt++;
      connComponents.push_back(cConnComponent);
    }
  }

  writeln(cnt);

  for(auto v : connComponents) {
    for(auto c : v) cout << c << " ";
    cout << endl;
  }

  return 0;
}