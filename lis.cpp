#include<bits/stdc++.h>
using namespace std;


int lis(int ind,int prevind,vector<int> &nums,vector<vector<int>> &dp)
{
    if(ind==nums.size())
    {
        return 0;
    }
     
    if(dp[ind][prevind+1]!=-1)
      return dp[ind][prevind+1];


    //on each index we have 2 possibilities.
    //1. Pick the index
    //2. Not pick
    // if the element is not picked then the length of lis will not increase
    // if element is picked then increment lis and update the prevind in recursive call.
    int notpick = lis(ind+1,prevind,nums,dp); 
    int pick = 0;
    if(prevind==-1 or nums[ind]>nums[prevind])
    {
       pick = 1+lis(ind+1,ind,nums,dp);
    }

    return dp[ind][prevind+1] = max(pick,notpick);
}


int main()
{
    vector<int> nums  = {10,9,2,5,3,7,101,18};
    vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));

    //lis(index,previndex,nums,dp)
    // previndex => indicates the last element that we picked in lis.
    // if nums[currindex]> nums[previndex] then only include that element in lis.
    cout<<lis(0,-1,nums,dp);
}