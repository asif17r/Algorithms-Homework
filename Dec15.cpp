/*
Links:
(a) https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
(b) https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
(c) https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discussion/
*/


#include<bits/stdc++.h>
using namespace std;
vector<int>arr;

int solveForOne(int from, int to){
    if(from > to) return 0;
    int mn = 1e9;
    int ans = 0;
    for(int i = from; i <= to; i++){
        ans = max(ans, arr[i] - mn);
        mn = min(mn, arr[i]);
    }
    return ans;
}
int solveForTwo(int from, int to){
    int ans = 0;
    for(int i = from; i <= to; i++){
        ans = max(ans, solveForOne(from, i) + solveForOne(i+1, to));
    }
    return ans;
}
int solveForAny(){
    int ans = 0;
    for(int i = 1; i < arr.size(); i++){
        ans += max(0, arr[i]-arr[i-1]);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    arr.resize(n);
    for(auto &a:arr) cin >> a;
    cout << "Solve for one transaction " << solveForOne(0,n-1) << endl;
    cout << "Solve for two transaction " << solveForTwo(0,n-1) << endl;
    cout << "Solve for multiple transaction " << solveForAny() << endl;
}
