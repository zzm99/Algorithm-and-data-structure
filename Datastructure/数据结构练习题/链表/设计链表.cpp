class MyLinkedList {
public:
    struct Node{
        int val;
        Node* prev, *next;
        Node(int val): val(val), prev(NULL), next(NULL){}
    };
    Node* head;
    Node* tail;
    int size;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(getNode(index)) return getNode(index)->val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new Node(val);
        ++size;
        if(!head){
            head = node;
            tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = new Node(val);
        ++size;
        if(!tail){
            head = node;
            tail = node;
        }
        else{
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == size){
            addAtTail(val);
            return;
        }
        if(index <= 0){
            addAtHead(val);
            return;
        }
        auto node = new Node(val);
        auto nextNode = getNode(index);
        nextNode->prev->next = node;
        node->prev = nextNode->prev;
        node->next = nextNode;
        nextNode->prev = node;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(auto node = getNode(index)){
            if(node == head){
                head = head->next;
                if(head != NULL) head->prev = NULL;
                node->next = NULL;
            }
            if(node == tail){
                tail = tail->prev;
                if(tail != NULL) tail->next = NULL;
                node->prev = NULL;
            }
            if(node->next != NULL) node->next->prev = node->prev;
            if(node->prev != NULL) node->prev->next = node->next;
            delete node;
            --size;
        }
    }
    Node* getNode(int index){
        if(index >= size || index < 0) return NULL;
        Node* node;
        int i;
        if(size / 2 >= index){
            i = index;
            node = head;
            while(i--) node = node->next;
        }
        else{
            i = size-index-1;
            node = tail;
            while(i--) node = node->prev;
        }
        return node;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */