const int NT_WORD = 0;
const int NT_SPACES = 1;
struct Node {
    Node(int type, const char *word)
    {
        this->type = type;
        this->word = word;
    }
        
    Node(int type, int nSpaces)
    {
        this->type = type;
        this->nSpaces = nSpaces;
    }
        
    int type;
    const char *word;
    int nSpaces;
};

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        
        int lineLen = -1;
        vector<Node> line;
        bool isEnd = false;
        int i = 0;
        while (!isEnd) {
            while (i < words.size() && lineLen + 1/*leading space*/ + words[i].size() <= L) {
                // Put the word in line.
                line.push_back(Node(NT_SPACES, 1));
                line.push_back(Node(NT_WORD, words[i].c_str()));
                lineLen += 1 + words[i].size();
                isEnd = (++i == words.size());
            }
            
            // Expand line.
            while (!isEnd) {
                bool expanded = false;
                for (int j = 1; j < line.size(); ++j) {
                    if (line[j].type == NT_SPACES && lineLen < L) {
                        line[j].nSpaces++;
                        lineLen++;
                        expanded = true;
                    }
                }
                if (!expanded)
                    break;
            }
            
            // Generate line string.
            string lineStr;
            for (int j = 1; j < line.size(); ++j) {
                if (line[j].type == NT_WORD) {
                    lineStr += line[j].word;
                } else {
                    for (int k = 0; k < line[j].nSpaces; ++k)
                        lineStr += " ";
                }
            }
            for (int k = 0; k < L - lineLen; ++k)
                lineStr += " ";
            r.push_back(lineStr);
            
            // Reset line.
            lineLen = -1;
            line.clear();
        }
            
        return r;
    }
};
