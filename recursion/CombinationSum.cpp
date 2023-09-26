// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []
 class Solution {
public:
void find(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    //pick up the element
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        find(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
    //not pick
    find(ind+1,target,arr,ans,ds);
}
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        //find the combination sum
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,cand,ans,ds);
        return ans;
    }
};