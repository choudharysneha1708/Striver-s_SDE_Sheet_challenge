class Solution {
public:
    vector<int> getRow(int r) {
        vector<vector<int>>ro;
        vector<int>ans;
        for(int i=0;i<=r;++i)
        {
            vector<int>temp(i+1);
            temp[0]=1;temp[i]=1;
            int j=1;
            for(int k=0;k<i-1;++k)
            {
                temp[j]=ro[i-1][k]+ro[i-1][k+1];
                j++;
            }
            
            ro.push_back(temp);
        }
        return ro[r];
    }
};