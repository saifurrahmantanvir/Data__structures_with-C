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
#define print(x) for (auto i : x) cout << i << " ";
#define all(x)   x.begin(), x.end()
#define loop(a)  for(int i=0; i<a; i++)
#define test(fn) int t; cin >> t; while(t--) fn();
#define loop2d(n, m) for(int i=0; i<n; i++) for(int j=0; j<m; j++)

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

const int S = 1e3+10;
const int inf = 1e9+10;

int val[S][S], visited[S][S], level[S][S];
int n, m;

vector<pair<int, int>> movements = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool isValid(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

void reset() {
  loop2d(n, m) {
    level[i][j] = inf;
    visited[i][j] = 0;

  }


}

int bfs() {
  int _max = 0;

  loop2d(n, m) _max = max(_max, val[i][j]);

  queue<pair<int, int>> q;

  loop2d(n, m) {
    if(_max == val[i][j]) {
      q.push({i, j});
      level[i][j] = 0;
      visited[i][j] = 1;
    }

  }

  int ans = 0;

  while(!q.empty()) {
    auto v = q.front();
    int vx = v.first, vy = v.second;
    q.pop();

    for(auto m : movements) {
      int cx = m.first + vx, cy = m.second + vy;

      if(!isValid(cx, cy) || visited[cx][cy]) continue;

      q.push({cx, cy});

      level[cx][cy] = level[vx][vy] + 1;
      visited[cx][cy] = 1;

      ans = max(ans, level[cx][cy]);
    }


  }

  return ans;
}

void solve() {
  readln(n, m);
  reset();

  loop2d(n, m) readln(val[i][j]);

  cout << bfs() << endl;
}

int main() {
  _ios;

  test(solve);




  return 0;
}