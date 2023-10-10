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


void testCase()
{
    int n, c;
    cin >> n >> c;

    vi v(n);
    vii pref(n), suff(n);
    
    for(auto& i : v)
        cin >> i;


    set<int> st;
    for(int i=0; i<n; i++)
    {
        pref[i].first =  v[i] + i + 1;
        pref[i].second = i+1;
        st.insert(i+1);
    }
    
   
    int cnt = 2;
    for(int i=n-1; i>=0; i--)
    {
        suff[i].first =  v[i] + cnt++;
        suff[i].second = i+1;
    }

    sort(all(pref));
    sort(all(suff));

    int ans = 0;
    if(c-pref[0].first >= 0)
    {
        cout << pref[0].second << " ";
        cout << pref[0].first << el;
        c-=pref[0].first;
        ans++;
        st.erase(pref[0].second);
    }else
        return cout << 0 << el, void();


    int pp=1, ps=0;

    while(pp<n && ps<n)
    {
        if(pref[pp].first < suff[ps].first)
        {
            if(c-pref[pp].first >= 0 && st.find(pref[pp].second)!=st.end())
            {   
                cout << pref[pp].second << " ";
                cout << pref[pp].first << el;
                
                st.erase(pref[pp].second);
                c-=pref[pp].first;
                ans++;
            }else
                pp++;
        }
        else
        {
            if(c-suff[ps].first >= 0 && st.find(suff[ps].second)!=st.end())
            {   
                cout << suff[ps].second << " ";
                cout << suff[ps].first << el;

                st.erase(suff[ps].second);
                c-=suff[ps].first;
                ans++;
            }else
                ps++;
        }

    }

    cout << ans << el;
}


int main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}