/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
<<<<<<< HEAD
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        stack<char> mystack;

        for (auto key : s)
        {
            if (key == '(' || key == '{' || key == '[')
            {
                mystack.push(key);
            }
            else
            {
                if (mystack.empty() == true)
                {
                    return false;
                    //case3  ())
                }

                char left = mystack.top();
                mystack.pop();
                char right = key;
                if ((left == '(' && right == ')') ||
                    (left == '{' && right == '}') ||
                    (left == '[' && right == '['))
                {
                    continue;
                    //case1 ()
                }
                else
                {
                    return false; //case4  (]
                }
            }
        }
        //case2 (()
        if (mystack.empty() ==false)
        {
            return false;
        }
        return true;
    }

}
;
// @lc code=end
=======
class Solution {
public:
    int longestValidParentheses(string s) {

    }
};
// @lc code=end

>>>>>>> 7905712e42b8bf7118adadbf8f2d0729f9b54df0
