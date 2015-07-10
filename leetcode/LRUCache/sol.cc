struct LinkedListNode {
    int key;
    int value;
    LinkedListNode *next;
    LinkedListNode *prev;
    
    LinkedListNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() : head(0, 0), tail(0, 0) {
        head.next = &tail;
        tail.prev = &head;
        _size = 0;
    }
    
    LinkedListNode *push_front(int key, int value) {
        auto node = new LinkedListNode(key, value);
        insert_front(node);
        ++_size;
        return node;
    }
    
    int pop_back() {
        auto pop_node = tail.prev;
        pop_node->prev->next = &tail;
        tail.prev = pop_node->prev;
        --_size;
        int key = pop_node->key;
        delete pop_node;
        return key;
    }
    
    void move_front(LinkedListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insert_front(node);
    }
    
    int size() {
        return _size;
    }
    
private:
    void insert_front(LinkedListNode *node) {
        node->next = head.next;
        node->prev = &head;
        head.next = node;
        node->next->prev = node;
    }
       
private:
    LinkedListNode head;
    LinkedListNode tail;
    int _size;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = dict.find(key);
        if (it == dict.end()) {
            return -1;
        }
        
        keys.move_front(it->second);
        return it->second->value;
    }
    
    void set(int key, int value) {
        int old_value = get(key);
        if (old_value > 0) {
            dict[key]->value = value;
            return;
        }
        
        if (keys.size() >= capacity) {
            dict.erase(keys.pop_back());
        }
        
        dict[key] = keys.push_front(key, value);
    }
    
private:
    LinkedList keys;
    std::unordered_map<int, LinkedListNode *> dict;
    int capacity;
};