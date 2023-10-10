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
const int N = 2e5+5;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/

int n, h;
vi v(N);

int dp[N][3][2];

int solve(int idx,int h, int green,int blue)
{
    if(idx == n)
        return 0;

    int ret = dp[idx][green][blue];
    if(~ret)
        return ret;
        
    if(h>v[idx])
        ret = solve(idx+1, h+v[idx]/2, green, blue)+1;
    else
    {
        if(green)
            ret = max(ret, solve(idx, h*2, green-1, blue));
        if(blue)
            ret = max(ret, solve(idx, h*3, green, blue-1));

        if(not green && not blue)
            return 0;
    }
    return ret;
}


void testCase()
{
    cin >> n >> h;

    for(int i=0; i<=n; i++)
        for(int g=0; g<3; g++)
            for(int b=0; b<2; b++)
                dp[i][g][b] = -1;

    for(int i=0; i<n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.begin()+n);

    cout << solve(0,h,2,1) << el;
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