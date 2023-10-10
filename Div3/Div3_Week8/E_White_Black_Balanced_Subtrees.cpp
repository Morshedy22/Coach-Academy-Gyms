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
const int N = 4005;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/
string color;
vvi g(N);

vii v(N);
int ans = 0;

void dfs(int node)
{

    for(auto child : g[node])
    {
        // cout << node << " " << child << el;
        dfs(child);
        v[node].first += (v[child].first);
        v[node].second += (v[child].second);
    }
    
    ans += (v[node].F==v[node].S);
}

int n;
void init()
{
    for(int i=0; i<=n; i++)
        g[i].clear(), v[i] = {0,0};

    ans = 0;
}

void testCase()
{
    cin >> n;
    
    init();

    int x;
    for(int i=2; i<=n; i++)
        cin >> x, g[x].pb(i);

    cin >> color;

    for(int i=0; i<n; i++)
    {
        v[i+1].F = (color[i]=='W'); 
        v[i+1].S = (color[i]=='B');
    }   
    
    dfs(1);

    cout << ans << el;
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