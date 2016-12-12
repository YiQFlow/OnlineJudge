/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/
/*class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //this pattern should be nums[j] > nums[i] && nums[j] > nums[k]
        if(nums.size()<3) return false;
        vector<int> leftMax(nums),rightMax(nums);
        for(int i=1;i<nums.size();i++){
            leftMax[i] = max(leftMax[i-1],nums[i]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],nums[i]);
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>leftMax[i-1] && nums[i]>rightMax[i+1]){
                return true;
            }
        }
        return false;
    }
};*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        /*O(nlogn)*/
        if(nums.size()<3) return false;
        vector<int> leftMin(nums);
        for(int i=1;i<nums.size();i++){
            leftMin[i] = min(leftMin[i-1],nums[i]);
        }
        
        set<int> rightNums;
        rightNums.insert(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>0;i--){
            auto it = rightNums.upper_bound(leftMin[i-1]);
            if(it!=rightNums.end() && *it < nums[i]){
                return true;
            }
            rightNums.insert(nums[i]);
        }
        return false;
    }
};
