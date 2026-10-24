#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
ll INF = 2e18;
#define endl '\n'
#define rep(i,n) for (int i = 0; i < (n); ++i)
// 小数点10桁まで表示(C++) => cout << fixed << setprecision(10) << (double) num;
// 小数点10桁まで表示(C)   => printf("%.10f¥n",num);
// にぶたん系: binary_search(a.begin(), a.end(), key); lower_bound(ALL(a), key);

/*
======================
= 正規表現マッチング =
======================
  regex pattern1("[A-Z]+");
  if (regex_search(a, pattern1)) cout << "A" << endl;
*/

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

ll binary_search(vector<ll> a, ll key) {
  ll ng = -1;
  ll ok = a.size();
  
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (a[mid] >= key) ok = mid;
    else ng = mid;
  }
  
  return ok;
}

/* ユークリッドの互除法 */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/* 高速な素数判定 */
bool isPrime(ll n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  
  double sqrtNum = sqrt(n);
  for (int i=3; i<=sqrtNum; i+=2) {
    if (n % i == 0) return false;
  }
  return true;
}

/* 二次元行列(NxN行列)を回転させる */
void rotateMatrix(vector<vector<char>>& mat) {
  int n = mat.size();
  vector<vector<char>> res(n, vector<char>(n));
    
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
    // res[n-j-1][i] = mat[i][j]; // 左に90度回転
    res[j][n-i-1] = mat[i][j]; // 右に90度回転
    // res[n-i-1][n-j-1] = mat[i][j]; // 180度回転
    }
  }
  mat = res; // 元の行列を更新
}

/* 回文判定 */
bool isPali(string s) {
  for (int i=0;i<s.size()/2;i++) {
    if (s[i]!=s[s.size()-1-i]) return false;
  }
  return true;
}

vector<string> abst(int y, int x, ll m, vector<string>& mp) {
  vector<string> sl(m);
  for (int i=0;i<m;i++) {
    sl[i] = mp[i+y].substr(x,m);
  }
  return sl;
}

template <typename T>
void lsvec(const vector<T>& v) {
  for (const auto& element : v) {
    cout << element << " ";
  }
  cout << endl;
}

template <typename T>
void lsvec2(const vector<vector<T>>& v) {
  for (const auto& element : v) {
    for (const auto& e : element) {
      cout << e << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vector<ll> runLength(string s) {
  vector<ll> ret;
  ll cnt = 1;

  char prev = '0';
  for (int i=0;i<s.size();i++) {
    if (s[i] != prev) {
      ret.push_back(prev);
      ret.push_back(cnt);
      prev = s[i];
      cnt = 1;
    } else {
      cnt++;
    }
  }
  ret.push_back(prev);
  ret.push_back(cnt);

  ret = {ret.begin()+2, ret.end()};
  return ret;
}


/* 回文判定 */
bool isPrePali(string s) {
  ll cnt = 0;
  for (int i=0;i<s.size()/2;i++) {
    if (s[i]!=s[s.size()-1-i]) cnt++;
    if (cnt >= 2) return false;
  }
  return true;
}

ll n;
vector<vector<ll>> g;
vector<ll> path;
vector<bool> visited;

void dfs(ll v, ll p) {
  visited[v] = true;
  path.push_back(v);
  sort(g[v].begin(), g[v].end());
  
  for (auto n_v : g[v]) {
    if (visited[n_v]) continue;
    dfs(n_v, v);
  }

  if (v == 0) return;

  path.push_back(p);
  return;
}


int main() {

}
