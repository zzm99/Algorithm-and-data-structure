// 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

// 在链表类中实现这些功能：

// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

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
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(getNode(index)) return getNode(index)->val;
        return -1;
    }
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