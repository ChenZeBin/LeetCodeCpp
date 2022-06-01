//
//  ThreeSum.cpp
//  LeetCodeCpp
//
//  Created by ChenZeBin on 2022/6/1.
//

#include "ThreeSum.hpp"
#include <iostream>

/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

 输入：nums = [-1,0,1,2,-1,-4]
 输出：[[-1,-1,2],[-1,0,1]]
 */

vector<vector<int>> ThreeSum::threeSum(vector<int> nums) {
    vector<vector<int>> result;
    // 从小到大排序
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        // 当第一个元素值都大于0，说明不会出现三数之和==0的case
        if (nums[i] > 0) {
            return result;
        }
        
        // i去重
        // 为什么不可以，nums[i] == nums[i+1],case:{-1,-1,0,1,2}就会出现只有{-1,0,1}的结果，漏了{-1,-1,2}
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = (int)nums.size() - 1;
        
        while (right > left) {
            
            /*
             去重放这里，会导致right <= left, case:{0,0,0,0,0}没法得到{0,0,0}的结果
             while (right > left && nums[right] == nums[right - 1]) {
                 right--;
             }
             
             while (right > left && nums[left] == nums[left + 1]) {
                 left++;
             }
             */
            
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                result.push_back({nums[i],nums[left],nums[right]});
                
                while (right > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                while (right > left && nums[left] == nums[left + 1]) {
                    left++;
                }
                
                // 找到答案后，双指针同时收缩
                right--;
                left++;
            }
        }
    }
    
    return result;
}

void ThreeSum::test() {
    vector<int> params = {-1,-1,0,1,2};
    vector<vector<int>> result = threeSum(params);
    
    
}

