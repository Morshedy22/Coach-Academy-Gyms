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
const int N = 1e5+5;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/

int check(int l, int mid)
{
    return 1;   
}

void testCase()
{
    int n;
    cin >> n;
    
    vi tea(n+2), tester(n+2);
    for(int i=1; i<=n; i++)
        cin >> tea[i];
    for(int i=1; i<=n; i++)
        cin >> tester[i];

    vi pref(n+2);
    pref[1] = tester[1];
    for(int i=2; i<=n; i++)
        pref[i] = pref[i-1] + tester[i];

    vi prefans(n+2), ans(n+2);
    for(int i=1; i<=n; i++)
    {
        int l=i, r=n, mid =0;
        int end = 0;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if( tea[i] - (pref[mid]-pref[i-1])  >= 0)
            {
                end = mid;
                l = mid+1;
            }else
                r = mid - 1;
        }     
        // cout << "i: " << i << " end: " << end << el; 

        if(end!=0)
        {
            prefans[i] += 1, prefans[end+1] -= 1;
            ans[end+1] += (tea[i]-(pref[end] - pref[i-1]));
        }
        else
            ans[i] += tea[i];
            
        // for(auto i : prefans) cout << i << " ";
        // cout << el;
        // for(auto i : ans)    cout << i << " ";
        // cout << el;        
    }

    // for(int i=1; i<=n; i++)
    //     cout << ans[i] << " ";
    // cout << el;

    for(int i=1; i<=n; i++)
    {
        prefans[i] += prefans[i-1];
        ans[i] += (prefans[i]*tester[i]);
    }

    // for(int i=1; i<=n; i++)
    //     cout << prefans[i] << " ";
    // cout << el;
    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << el;
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