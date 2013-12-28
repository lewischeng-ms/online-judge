
struct Task {
    Task * parent;
    int index;
    Task(int i, Task *p)
        : index(i), parent(p) { }
};

vector<Task *> freeList;
vector<Task *> allocList;

Task *get(int i, Task *p) {
    Task *result = NULL;
    if (!freeList.empty()) {
        result = freeList.back();
        freeList.pop_back();
        new (result)Task(i, p);
    } else {
        result = new Task(i, p);
    }
    allocList.push_back(result);
    return result;
}

void clear() {
    for (int i = 0; i < allocList.size(); ++i)
        freeList.push_back(allocList[i]);
    allocList.clear();
}

class Solution {
public:
    bool findTrace(const string &s, Task * task) {
        while (task) {
            if (vdict[task->index] == s)
                return true;
            task = task->parent;
        }
        return false;
    }
    
    void putResult(const string &s, Task *task) {
        vector<string> v;
        while (task) {
            v.insert(v.begin(), vdict[task->index]);
            task = task->parent;
        }
        v.push_back(s);
        result.push_back(v);
    }

    void bfs(const string &start, const string &end, unordered_set<string> &dict) {
        queue<Task *> q;
        q.push(get(0, NULL));
        
        bool isEnd = false;
        while (!isEnd && !q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Task *task = q.front();
                q.pop();
                const string &word = vdict[task->index];
                int l = word.size();
                list<int> &ll = one[task->index];
                for (list<int>::iterator i = ll.begin();
                     i != ll.end();
                     ++i) {
                         const string &s = vdict[*i];
                    if (findTrace(s, task))
                           continue;
                        if (s == end) {
                            isEnd = true;
                            putResult(s, task);
                        }
                        if (!isEnd)
                            q.push(get(*i, task));
                }
/*
                for (int i = 0; i < l; ++i) {
                    string s = task->word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;

                        unordered_set<string>::iterator it;
                        if ((it = dict.find(s)) == dict.end())
                            continue;

                        if (findTrace(*it, task))
                           continue;
                        
                        if (*it == end) {
                            isEnd = true;
                            putResult(*it, task);
                        }
                        if (!isEnd)
                            q.push(get(*it, task));
                    }
                }*/
            }
        }
    }

    bool diffOne(const string &x, const string &y) {
        int count = 0;
        for (int i = 0;i < x.size(); ++i) {
            if (x[i] != y[i])
                count++;
            if (count > 1)
                return false;
        }
        return count == 1;
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        one.clear();
        result.clear();

        vdict.clear();
        vdict.push_back(start);
        for (unordered_set<string>::iterator it = dict.begin();
             it != dict.end();
             ++it) {
                 vdict.push_back(*it);
        }
        for (int i = 0; i < vdict.size(); ++i) {
            for (int j = i; j < vdict.size(); ++j) {
                if (diffOne(vdict[i], vdict[j])) {
                    one[i].push_back(j);
                    one[j].push_back(i);
                }
            }
        }
        bfs(start, end, dict);
        clear();
        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> vdict;
    unordered_map<int, list<int>> one;
};
