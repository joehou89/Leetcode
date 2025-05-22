/*
TODO: 该代码段只是实现一个功能，比如字符串操作，给一段字符串“  hello world  ”,，去掉字符串开始和结尾的空格，但是中间的空格保留
比如leetcode:151 反转字符串中的单词
*/

void remove_spaces(string& s)
{
  int size = s.size();
  int i = size - 1;
  for (; i > 0; i--)
  {
    if (s[i] == s[i - 1] && s[i] == ' ')
    {
        s.erase(s.begin() + i);
    }
  }
  if (s[0] == ' ')
  {
     s.erase(s.begin());
  }
  if (s[size - 1] == ' ')
  {
    s.erase(s.begin() + size - 1);
  }
}
