#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int data;
        int count = 0;
        cout << "len :" << len << endl;
        for (std::vector<int>::iterator it = digits.begin(); it != digits.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << "====" << endl;

        while (len > 0)
        {
            data = digits[len - 1];
            if (data < 9)
            {
                cout << "<9 : digits[" << len - 1 << "] -- >" << digits[len - 1] << endl;
                digits[len - 1] += 1;
                break;
            }
            else
            {
                cout << ">=9 : digits[" << len - 1 << "] -- >" << digits[len - 1] << endl;
                digits[len - 1] = 0;
                len--;
            }
        }

        cout << "111 digits.size(): " << digits.size() << endl;

        if (len == 0)
        {
            // digits.clear();
            cout << "digits.size(): " << digits.size() << endl;
            int new_len = digits.size() + 1;
            cout << "new len: " << new_len << endl;
            digits.resize(new_len);
            for (int i = 1; i < new_len; i++)
            {
                digits[i] = 0;
            }
            digits[0] = 1;
        }

        return digits;
    }
};

int main()
{
  Solution s;
  // vector<int> nums = {1,1,2};
  vector<int> nums = {9};
  vector<int> nums1 = s.plusOne(nums);
  cout << nums1.size() << endl;

  for (std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
  {
    cout << *it << endl;
  }
  return 0;
}