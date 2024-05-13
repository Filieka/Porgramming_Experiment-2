#include<iostream>
using namespace std;

class LinkedList {
protected:
    Node* head;

public:
    class Node{
    public:
        int data;
        Node* next;
        Node():next(nullptr),data(0){}
        Node(int d):next(nullptr), data(d){}
        Node(Node* n):next(n),data(0){}
        Node(Node* n,int d):next(n),data(d){}
    };

    LinkedList():head(nullptr) {}
    ~LinkedList(){}

    bool addFromHead(int d){
        Node* newNode=new Node(d);
        if(!newNode){return false;}
        newNode->next=head;
        head=newNode;
        return true;
    }

    bool addFromTail(int d){
        Node* newNode=new Node(d);
        if(!newNode){return false;}
        if(!head){head=newNode;}
        else{
            Node* current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
            current->next=newNode;
        }
        return true;
    }

    bool removeFromHead(){
        if(!head){return false;}
        Node* temp=head;
        head=head->next;
        delete temp;
        return true;
    }

    bool removeFromTail(){
        if(!head){return false;}
        if(!head->next){
            delete head;
            head=nullptr;
            return true;
        }

        Node* current=head;
        while(current->next->next!=nullptr){current=current->next;}
        delete current->next;
        current->next=nullptr;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& o,LinkedList* l){
        o<<"{";
        Node* current=l->head;
        while(current!=nullptr){
            o<<current->data;
            if(current->next!=nullptr){o<<", ";}
            current=current->next;
        }
        o<<"}\n";
        return o;
    }

    size_t getSize()const{
        size_t size=0;
        Node* current=head;
        while(current!=nullptr){
            size++;
            current=current->next;
        }
        return size;
    }
};