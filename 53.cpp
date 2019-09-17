class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int this_sum,max_sum=0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
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