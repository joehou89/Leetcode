## 给定数组或需求求满足条件的子序列或区间算法问题总结    
这一类算法题目往往是说给定一个数组或区间，然后求比如说连续字数组的和最大，输出这个和的值。这一类问题基本上都可以用双for循环进行遍历，然后求得。  
时间复杂度: O(n2)  
空间复杂度: O(1)  
  
## 题目举例  
力扣 53:最大字序和  
```sh
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```
  
这道题可以使用双for循环进行暴力解法，代码如下:  
```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int result = INT32_MIN;
        for (int i = 0; i < size; i++)
        {
            sum = 0;
            for (int j = i; j < size; j++) //时间复杂度大头全在这一遍循环里，完全可以用判断语句进行判断
            {
                sum += nums[j];
                result = sum > result ? sum : result;
            }
        }
        return result;
    }
};
```
但是比较遗憾的是上述算法并没有通过力扣，超时。    
代码优化为如下:  
```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int result = INT32_MIN;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            if (result < sum)
            {
                result = sum;
            }
            if (sum <= 0)
            {
                sum = 0;
                // result = 0;
            }
        }
        return result;
    }
};

```  
该算法：  
时间复杂度: O(n)  
空间复杂度: O(1)  
  
 




