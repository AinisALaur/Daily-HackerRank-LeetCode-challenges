#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    if(head == nullptr || k < 0){
        return head;
    }
    
    SinglyLinkedListNode* pointer1 = head;
    SinglyLinkedListNode* pointer2 = head;

    for(int i = 0; i < k; ++i){
        if(pointer2->next == nullptr && i == k){
            return head->next; 
        }else if(pointer2->next == nullptr && i != k){
            return head;
        }
        pointer2 = pointer2->next;
    }

    if(pointer2->next == nullptr){
        return head->next;
    }

    while(pointer2->next != nullptr && pointer2->next->next != nullptr){
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }

    pointer1->next = pointer1->next->next;

    return head;
}

int main(){
    SinglyLinkedList list;
    list.insert_node(1);

    print_singly_linked_list(removeKthNodeFromEnd(list.head, 0), " -> ");


    return 0;
}