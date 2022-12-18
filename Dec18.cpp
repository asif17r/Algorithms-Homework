// Problem Link: https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>
using namespace std;
 
int comp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}
 
int main(){
    int n; cin >> n;
    vector<pair<int,int>>arr(n);
    for(auto &a: arr){
        cin >> a.first >> a.second;
    }
    sort(arr.begin(), arr.end(), comp);
    int lstMovie = -1e9;
    int cnt = 0;
    for(auto a: arr){
        if(a.first >= lstMovie){
            lstMovie = a.second;
            cnt++;
        }
    }
    cout << cnt << endl;
}