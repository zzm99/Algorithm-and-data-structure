#include <bits/stdc++.h> 
using namespace std; 

class Node  
{  
public: 
    int data;  
    Node *next;  
};  

int getCount(Node* head)  
{  
    int count = 0; 
    Node* current = head; 
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  

bool search(Node* head, int x)  
{  
    Node* current = head; 
    while (current != NULL)  
    {  
        if (current->key == x)  
            return true;  
        current = current->next;  
    }  
    return false;  
} 

int GetNth(Node* head, int index)  
{  
    Node* current = head;  
    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
    return -1;       
}  

void printNthFromLast(Node *head, int n) 
{ 
  Node *main_ptr = head; 
  Node *ref_ptr = head; 
  int count = 0; 
  if(head != NULL) 
  { 
     while( count < n ) 
     { 
        if(ref_ptr == NULL) 
        { 
           printf("%d is greater than the no. of "
                    "nodes in list", n); 
           return; 
        } 
        ref_ptr = ref_ptr->next; 
        count++; 
     } 
     while(ref_ptr != NULL) 
     { 
        main_ptr = main_ptr->next; 
        ref_ptr  = ref_ptr->next; 
     } 
     printf("Node no. %d from last is %d ",  
              n, main_ptr->data); 
  } 
} 

void printMiddle(Node *head)  
{  
    Node *slow_ptr = head;  
    Node *fast_ptr = head;  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        } 
        printf("The middle element is [%d]\n\n", slow_ptr->data);  
    }  
}  

bool isPalin(Node* head){ 
        Node* slow= head; 
        stack <int> s; 
        while(slow != NULL){ 
                s.push(slow->data); 
                slow = slow->ptr; 
        } 
        while(head != NULL ){ 
            int i=s.top(); 
            s.pop(); 
            if(head -> data != i){ 
                return false; 
            } 
        head=head->ptr; 
        } 
    return true; 
} 

void removeDuplicates1(Node* head)  // Remove duplicates from a sorted linked list
{  
    Node* current = head;  
    Node* next_next;  
    if (current == NULL)  
        return;  
    while (current->next != NULL)  
    {  
        if (current->data == current->next->data)  
        {      
            next_next = current->next->next;  
            free(current->next);  
            current->next = next_next;  
        }  
        else 
        {  
            current = current->next;  
        }  
    }  
}  

void removeDuplicates2(Node *head) // Remove duplicates from an unsorted linked list
{ 
    Node *ptr1, *ptr2, *dup; 
    ptr1 = head; 
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (ptr1->data == ptr2->next->data) 
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else 
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
} 

void moveLastToFront(Node **head_ref)  
{  
    if (*head_ref == NULL || (*head_ref)->next == NULL)  
        return;  
    Node *secLast = NULL;  
    Node *last = *head_ref;  
    while (last->next != NULL)  
    {  
        secLast = last;  
        last = last->next;  
    }  
    secLast->next = NULL;  
    last->next = *head_ref;  
    *head_ref = last;  
}  

/* Function to swap nodes x and y in linked list by 
changing links */
void swapNodes(struct Node **head_ref, int x, int y) 
{ 
    struct Node *prev_x = NULL, *curr_x = (*head_ref);
    struct Node *prev_y = NULL, *curr_y = (*head_ref);
    //findind x and y in single transversal using flags
    int x_found=0,y_found=0;
    while((curr_x!=NULL && !x_found) || (curr_y!=NULL && !y_found)){
        if(!x_found && curr_x->data==x) x_found=1;
        if(!y_found && curr_y->data==y) y_found=1;
        if(!x_found) {prev_x=curr_x; curr_x=curr_x->next;}
        if(!y_found) {prev_y=curr_y; curr_y=curr_y->next;}
    }
    if(!x_found || !y_found) return; //ensuring both curr is not a nullptr
    struct Node *next_x=curr_x->next, *next_y=curr_y->next;
    //prev can be nullptr so better check before accessing its next component
    if(prev_x) prev_x->next=curr_y;
    else (*head_ref)=curr_y;
    if(prev_y) prev_y->next=curr_x;
    else (*head_ref)=curr_y;
    //since curr is already ensured to be not a nullptr, there is no need of if condition.Notice it works even if any of next is nullptr
    curr_x->next=next_y;
    curr_y->next=next_x;
    //if x and y are adjacent at this stage link between x and y is broken, but everthing else is linked properly
    if(next_x==curr_y) curr_y->next=curr_x;
    if(next_y==curr_x) curr_x->next=curr_y;
} 

void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
}  
  
void insertAfter(Node* prev_node, int new_data)  
{  
    if (prev_node == NULL)  
    {  
        cout<<"the given previous node cannot be NULL";  
        return;  
    }  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = prev_node->next;  
    prev_node->next = new_node;  
}  
  
void append(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    Node *last = *head_ref; 
    new_node->data = new_data;  
    new_node->next = NULL;  
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
    while (last->next != NULL)  
        last = last->next;  
    last->next = new_node;  
    return;  
}  

void deleteNodeByKey(Node **head_ref, int key) 
{ 
    Node* temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    } 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);  
} 

void deleteNodeByPos(Node **head_ref, int position) 
{ 
    if (*head_ref == NULL) 
        return; 
    Node* temp = *head_ref; 
    if (position == 0) 
    { 
        *head_ref = temp->next;  
        free(temp);              
        return; 
    } 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
    if (temp == NULL || temp->next == NULL) 
         return; 
    Node *next = temp->next->next; 
    free(temp->next); 
    temp->next = next;   
} 

void deleteList(Node** head_ref)  
{  
    Node* current = *head_ref;  
    Node* next;  
    while (current != NULL)  
    {  
        next = current->next;  
        free(current);  
        current = next;  
    }  
    *head_ref = NULL;  
} 

Node* sortedIntersect(Node* a, Node* b) 
{ //let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, 
  // then your function should create and return a third list as 2->4->6.
  Node dummy; 
  Node* tail = &dummy; 
  dummy.next = NULL; 
  while (a != NULL && b != NULL) 
  { 
    if (a->data == b->data) 
    { 
       push((&tail->next), a->data); 
       tail = tail->next; 
       a = a->next; 
       b = b->next; 
    } 
    else if (a->data < b->data)  
       a = a->next; 
    else
       b = b->next; 
  } 
  return(dummy.next); 
} 

void pairWiseSwap(Node* head) 
{ 
    Node* temp = head; 
    while (temp != NULL && temp->next != NULL) { 
        swap(temp->data, temp->next->data); 
        temp = temp->next->next; 
    } 
} 

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  
  
int main()  
{  
    Node* head = NULL;  
    append(&head, 6);  
    push(&head, 7);  
    push(&head, 1);  
    append(&head, 4);
    cout <<"Linked list is: ";  
    printList(head);  
    cout << endl;
    deleteNodeByKey(&head, 7); 
    cout <<"Linked list is: ";  
    printList(head);  
    cout << endl;
    deleteNodeByPos(&head, 1); 
    cout <<"Linked list is: ";  
    printList(head);  
    cout << endl;
    insertAfter(head->next, 8);  
    cout <<"Linked list is: ";  
    printList(head);  
    cout << endl;
    deleteList(&head);
    cout <<"Linked list is: ";  
    printList(head);  
    cout << endl;
    return 0; 
}  