#include<bits/stdc++.h>
using namespace std;


void printlis(vector<int> &nums)
{
    vector<int> dp(nums.size(),1);
    int mx =1;
    vector<int> lis(nums.size());
    int lastindex = 0;
    for(int i = 0;i<nums.size();i++)
    {   
        lis[i] = i;
        for(int j = 0;j<i;j++)
        {
            if(nums[j]<nums[i] and dp[i]<1+dp[j] )
            {
                dp[i] = 1+dp[j];
                lis[i] = j;
            }
        }
        // mx = max(mx,dp[i]);
        if(dp[i]>mx)
        {
            mx = dp[i];
            lastindex = i;
        }

    }

    vector<int> temp;
    temp.push_back(nums[lastindex]);
    while(lis[lastindex]!=lastindex)
    {
          lastindex = lis[lastindex];
          temp.push_back(nums[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it:temp)
    {
        cout<<it<<" ";
    }
}

int main()
{
     vector<int> nums  = {10,9,2,5,3,7,101,18};
     printlis(nums);
}