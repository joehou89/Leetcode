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
        
## 134. 加油站    
```sh  
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
示例 1:
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
```    
这道题目很明显也是可以用暴力解法，代码如下:  
双for循环要在内循环有一个判断条件，用于结束，这是一个关键；  
```c  
int fun(vector<int>& gas, vector<int>& cost)
{
  for (int i = 0; i < gas.size(); i++) //依次从头开始遍历
  {
    int rest = gas[i] - cost[i];
    int index = (i + 1) % gas.size(); //模拟从某一个i点开始遍历，当然这里是从i=0开始  
    while (index != i && rest > 0)
    {
      rest += gas[index] - cost[index];
      index = (index + 1) % gas.size();
    }
    if (index == i && rest >= 0) return i;
  }
  return -1;
}
```    
暴力解法比较遗憾的是，未能通过力扣测试例，接下来就要用贪心算法进行解题，书里给到的贪心算法其实是分了情况的：  
(1).如果gas总和<cost总和，说明是到达不了一圈的，直接烦-1即可；  
(2).rest = gas[i] - cost[i]；rest表示从第i个节点开始的剩余油量，当然要有一个值min表示每一段的最小值，如果这个最小值>=0，说明从0开始是可以一圈的；  
(3).如果min这个最小值可能为0，也不能说明就到达不了一圈，所以就从尾巴上开始遍历，让这个min能够成为>=0的下标，返回即可；    
  
代码如下：  
```c
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int min = INT_MAX;
       for (int i = 0; i < gas.size(); i++)
       {
            cursum += gas[i] - cost[i];
            if (cursum < min)
            {   
                min = cursum;
            }
       }
       if (cursum < 0) return -1;
       if (min >= 0) return 0;

       for (int i = gas.size() - 1; i >= 0; i--)
       {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0)
            {
                return i;
            }
       }
       return -1;
    }
};
```  
    
## 力扣题目.42. 接雨水  
```sh  
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
```  
![]()  



















