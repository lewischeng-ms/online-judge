class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, vector<string> > m;
        vector<string>::iterator i = strs.begin();
        while (i != strs.end()) {
            string temp(*i);
            sort(i->begin(), i->end());
            m[*i].push_back(temp);
            ++i;
        }
        vector<string> result;
        map<string, vector<string> >::iterator j = m.begin();
        while (j != m.end()) {
            if (j->second.size() > 1) {
                for(vector<string>::iterator k = j->second.begin(); k < j->second.end(); ++k)
                    result.push_back(*k);
            }
            ++j;
        }
        return result;
    }
};