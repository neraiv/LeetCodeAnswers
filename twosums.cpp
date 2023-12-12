#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> output = {0,0};
        
        int i = 0;
        int j = 1;
        for(i = 0; i<len; i++){
            for(j = i+1; j<len; j++){
                //printf("%d ve  %d \n",i,j);
                if ((nums[i]+nums[j] )== target){
                    output[0] = i;
                    output[1] = j;
                    break;
                }
            }
        }

        //printf("[%d , %d]",output[0],output[1]);
        return output;
    }
};


int main(){

    Solution sol =  Solution();

    vector<int> numbers = {3,2,4};
    int target = 6;

    sol.twoSum(numbers,target);

    return 0;
}