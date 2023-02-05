/*
 *  this.FrankZhou
 *  单调栈模板
 *  四种类型：左边第一个比它小 左边第一个比它大 右边第一个比它大 右边第一个比它小
 */

#include <iostream>
#include <stack>
#include <vector>

// 左边第一个比它小
std::vector<int> prevSmallerElement(std::vector<int> &nums) {
    std::vector<int> res(nums.size());

    std::stack<int> stk;
    for (int i=0;i<nums.size();i++) {
        int target = nums[i];

        while (!stk.empty() && stk.top() >= target) {
            stk.pop();
        }

        res[i] = stk.empty() ? -1 : stk.top();
        stk.push(target);
    }

    return res;
}

// 左边第一个比它大
std::vector<int> prevGreaterElement(std::vector<int> &nums) {
    std::vector<int> res(nums.size());

    std::stack<int> stk;
    for (int i=0;i<nums.size();i++) {
        int target = nums[i];

        while (!stk.empty() && stk.top() <= target) {
            stk.pop();
        }

        res[i] = stk.empty() ? -1 : stk.top();
        stk.push(target);
    }

    return res;
}

// 模板三->右边第一个比它小
std::vector<int> nextSmallerElement(std::vector<int> &nums) {
    std::vector<int> res(nums.size());

    std::stack<int> stk;
    for (int i=nums.size()-1;i>=0;i--) {
        int target = nums[i];

        while (!stk.empty() && stk.top() >= target) stk.pop();

        if (!stk.empty()) res[i] = stk.top();
        else res[i] = -1;

        stk.push(target);
    }

    return res;
}

// 模板四->右边第一个比它大
std::vector<int> nextGreaterElement(std::vector<int> &nums) {
    std::vector<int> res(nums.size());

    std::stack<int> stk;
    for (int i=nums.size()-1;i>=0;i--) {
        int target = nums[i];

        while (!stk.empty() && stk.top() <= target) stk.pop();

        if (!stk.empty()) res[i] = stk.top();
        else res[i] = -1;

        stk.push(target);
    }

    return res;
}

/*
 *  input: 3 4 2 7 5
 *  output:
 *      模板一 -1 3 -1 2 2
 *      模板二 -1 -1 4 -1 7
 *
 *  input: 2 1 2 4 3
 *  output:
 *      模板三 1 -1 -1 -3 -1
 *      模板四 4 2 4 -1 -1
 */
int main() {
    std::vector<int> vec;
    int nums[] = {3,4,2,7,5};
    int size = 5;
    for (int i=0;i<size;i++) {
        vec.push_back(nums[i]);
    }

    std::vector<int> res = prevSmallerElement(vec);

    for (auto x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    res = prevGreaterElement(vec);

    for (auto x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    /*
    std::vector<int> vec;
    int nums[] = {2,1,2,4,3};
    int size = 5;
    for (int i=0;i<size;i++) {
        vec.push_back(nums[i]);
    }

    std::vector<int> res = nextGreaterElement(vec);

    for (int i=0;i<res.size();i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    res = nextSmallerElement(vec);

    for (int i=0;i<res.size();i++) {
        std::cout << res[i] << " ";
    }
    */

    return 0;
}