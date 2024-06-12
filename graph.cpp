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

const int _n = 1e5+2;

vector<bool> visited(_n, false);
vector<int> adz[_n];

void bfs(int node);
void dfs(int node);

int main()
{
  _ios;

  int n, m; cin >> n >> m;

  int x, y;

  for(int i=0; i<m; i++) {
    cin >> x >> y;

    adz[x].pb(y); adz[y].pb(x);
  }

  dfs(1);

  return 0;
}

void bfs(int node) {
  queue<int> q;

  visited[node] = true;
  q.push(node);

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    cout << node << " ";

    /* vector<int>::iterator it;

    for(it = adz[node].begin(); it != adz[node].end(); it++) {
      if(!visited[*it]) {
        visited[*it] = true;
        q.push(*it);

      }


    } */

    for(auto it : adz[node]) {
      if(!visited[it]) {
        visited[it] = true;
        q.push(it);
    
      }


    }


  }




}

void dfs(int node) {
  visited[node] = true;
  cout << node << " ";

  vector<int>::iterator it;

  for(it=adz[node].begin(); it != adz[node].end(); it++) {
    if(!visited[*it]) {
      dfs(*it);
    }


  }


  /* POST-ORDER_
  cout << node << " "; */
}