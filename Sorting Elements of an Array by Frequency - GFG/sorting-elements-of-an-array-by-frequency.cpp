#include <bits/stdc++.h>
using namespace std;
void SortD(vector<int>& a){
    vector<int>h(61,0);
    for(auto e: a){
        h[e]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=0;i<=60;i++){
        if(h[i]!=0){
            pq.push({-h[i],i});
        }
    }
    int i=0;
    while(i<a.size()){
        int l=abs(pq.top().first);
        int n=pq.top().second;
        pq.pop();
        while(l--){
            a[i++]=n;
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;++i){
	        cin>>a[i];
	    }
	    SortD(a);
	    for(int i=0;i<n;++i){
	        cout<<a[i]<<" ";
	    }cout<<endl;
	}
	
	return 0;
}