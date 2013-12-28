class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<string> nodes;
        string::iterator i = path.begin();
        while (true) {
            // Ignore path-separating slashes.
            while (i != path.end() && *i == '/')
                ++i;
            
            if (i == path.end())
                break;
            
            string name;
            while (i != path.end() && *i != '/')
                name += *i++;
            
            if (name == ".") {
                continue;
            } else if (name == "..") {
                if (!nodes.empty())
                    nodes.pop_back();
            } else {
                nodes.push_back(name);
            }
        }
        string result;
        deque<string>::iterator j = nodes.begin();
        while (j != nodes.end())
            result += "/" + *j++;
        if (result.empty())
            return "/";
        else
            return result;
    }
};