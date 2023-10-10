#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define Morshedy_22 ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define FILL(a, b) memset(a, b, sizeof(a))
#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) (int)(x).size()
#define el '\n'
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

const int inf = 0x3f3f3f3f;
const ll infLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 2e2+5;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/

int n, m;
int a[N][N];
int calc(int x, int y)
{
    int ret = 0;
    ret = a[x][y];
    for(int i = x-1, j=y-1; i>=0 && j>=0; i--, j--)
        ret+= a[i][j];
    for(int i = x+1, j=y+1; i<n && j<m; i++, j++)
        ret+= a[i][j];
    for(int i = x-1, j=y+1; i>=0 && j<m; i--, j++)
        ret+= a[i][j];
    for(int i = x+1, j=y-1; i<n && j>=0; i++, j--)
        ret+= a[i][j];
    return ret;
}   
void init()
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            a[i][j] = 0;
    
}
void testCase()
{
    cin >> n >> m;
    
    init();

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    int mx = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            mx = max(mx, calc(i,j));            

    cout << mx << el;
}


int32_t main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}