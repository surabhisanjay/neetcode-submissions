class Node{
    public: 
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v),prev(nullptr),next(nullptr)
        {}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;  
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    void insert(Node* node){
            Node* Prev = right->prev;
            node->prev = Prev;
            Prev->next = node;
            node->next = right;
            right->prev = node;

        }
        void remove(Node* node){
            Node* Next = node->next;
            Node* Prev = node->prev;
            Next->prev = Prev;
            Prev->next = Next;
        }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node * newnode = new Node(key,value);
        cache[key ] = newnode;
        insert(newnode);

        if(cache.size() > capacity){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }  
    }
};
