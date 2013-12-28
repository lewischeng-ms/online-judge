class Solution {
private:
    int count1[256];
    int count2[256];
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.size() == 0 || S.size() == 0)
            return "";
            
        memset(count1, 0, sizeof(count1));
        memset(count2, 0, sizeof(count2));
        
        for(int i = 0; i < T.size(); i++)
        {
            count1[T[i]]++;
            count2[T[i]]++;
        }
        
        int count = T.size();
        
        int start = 0;
        int minSize = INT_MAX;
        int minStart;
        for(int end = 0; end < S.size(); end++)
        {
            if (count2[S[end]] > 0) // T里确实有S[end]这个字符
            {
                count1[S[end]]--;
                if (count1[S[end]] >= 0) // s[end]出现次数太多了，多出来的直接无视
                    count--;
            }
            
            // T里面所有的字符都匹配掉了
            if (count == 0)
            {
            	// 前进start到start之后下一个在T中的字符
            	// 如S=bacb,T=bc,在匹配了bac和T之后
            	// 下一步该匹配的是cb和T，而不是b和T！
            	// 因为每次从window中踢掉start，
            	// 但是又补充了一个新的start，所以count不变。
                while(true)
                {
                    if (count2[S[start]] > 0)
                    {
                    	// 原来start指向的字符
                        if (count1[S[start]] < 0)
                            count1[S[start]]++;
                        else
                            break;
                    }
                    start++;
                }
            
            	// 更新最小窗口
                if (minSize > end - start + 1)
                {
                    minSize = end - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minSize == INT_MAX)
            return "";
        
        string ret(S, minStart, minSize);
        
        return ret;        
    }
};