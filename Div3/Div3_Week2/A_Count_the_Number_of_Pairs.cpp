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
    int n, k;
    cin >> n >> k;    

    string s;
    cin >> s;
    int freqL[26]{}, freqU[26]{};
    for(int i=0; i<n; i++)
    {
        if(islower(s[i]))
            freqL[s[i]-'a']++;
        else
            freqU[s[i]-'A']++;
    }

    int burls = 0;
    int rem = 0;
    for(int i=0; i<26; i++)
    {
        burls += min(freqL[i], freqU[i]);
        rem  = abs(freqL[i]- freqU[i]);

        if(k-(rem/2)>=0)
        {
            burls+= rem/2;
            k-=(rem/2);
        }
        else
        {
            burls+=k;
            k=0;
        }
    }

    cout << burls << el;

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