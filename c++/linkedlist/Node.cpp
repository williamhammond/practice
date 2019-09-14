#include<stdio.h>
#include<iostream>
#include<unordered_set>

struct Node { 
   int data; 
   struct Node *next; 
}; 

struct Node* head = NULL;   
struct Node* tail = NULL;   
int size = 0;

void insert(int data) { 
   struct Node* n = (struct Node*) malloc(sizeof(struct Node)); 
   n->data = data; 
   if (head == NULL) {
       head = n;
       tail = n;
   } else {
       tail->next = n;
       tail = n;
   }
   size++;
} 

bool detect_loop(Node* ptr) {
    unordered_set<Node *> seen; 
    while(ptr != NULL) {
        
    }
}

void remove(int data) {
    Node* curr = new Node;
    Node* prev = new Node;
    curr = head;
    while(curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if(curr != NULL) {
        prev->next = curr->next;
        delete curr;
    }
    size--;
}

Node* remove_by_index(Node* ptr, int i) {
    if (i==0) {
        return ptr;
    }
    return remove_by_index(ptr->next, i-1);
}

Node* get_kth_element(int k) {
    if (k > size) {
        throw std::string("Requesting index out of bounds");
    }
    int i = size-k;

    return remove_by_index(head, i);
}

void display() { 
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) { 
      std::cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } 
} 

int main() { 
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(2);
    insert(9);
    std::cout << get_kth_element(2)->data;
    std::cout<<"The linked list is: ";
    display(); 
    return 0; 
} 