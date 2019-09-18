#include<iostream>
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int this_sum,max_sum= LONG_MIN;
        int n = nums.size();
        int index = 0;
        for(int i=0;i<n;i++){
            if(nums[i]< 0)
                index++;
            if(max_sum <nums[i])
                max_sum = nums[i];
        }
        if(index == n)
            return max_sum;
        else 
            for(int i = 0;i<n;i++)
            {
                max_sum = 0;
                for(int j=i;j<n;j++)
                {
                    this_sum = 0;
                    for(int k=i; k<= j; k++)
                        this_sum += nums[k];
                    if(this_sum > max_sum)
                        max_sum = this_sum;
                }//j½áÊø
            }//i½áÊø
        return max_sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = max(pre, 0) + nums[i];
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }
};
