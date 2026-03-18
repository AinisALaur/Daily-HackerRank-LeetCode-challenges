#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

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

SinglyLinkedListNode* deleteDuplicates(SinglyLinkedListNode* head) {
    if(head == nullptr){
        return head;
    }
    
    SinglyLinkedListNode* pointer1 = head;
    SinglyLinkedListNode* pointer2 = head;

    while(pointer2->next != nullptr){
        pointer2 = pointer2->next;

        if(pointer1->data == pointer2->data){
            if(pointer2->next != nullptr)
                pointer1->next = pointer2->next;
            else
                pointer1->next = nullptr;
        }else{
            pointer1 = pointer1->next;
        }
    }

    return head;
}

int main(){
    SinglyLinkedList list;
    list.insert_node(1);
    list.insert_node(2);
    list.insert_node(2);
    list.insert_node(2);
    list.insert_node(3);
    list.insert_node(4);
    list.insert_node(4);
    list.insert_node(5);

    print_singly_linked_list(deleteDuplicates(list.head), " -> ");
    
    
    
    return 0;
}