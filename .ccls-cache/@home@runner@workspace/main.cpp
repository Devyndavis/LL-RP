#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
protected:
    Node* head;
    Node* tail;
    int count;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void display() {
        Node* temp = head;
        std::cout << "(" << count << "): ";
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    int size() const { return count; }

    Node* getHead() { return head; }
    void setHead(Node* newHead) { head = newHead; }
    Node* getTail() { return tail; }
    void setTail(Node* newTail) { tail = newTail; }
    void setCount(int newCount) { count = newCount; }
};

class SplitLinkedList : public SinglyLinkedList {
public:
    void splitEvensAndOdds(SinglyLinkedList& evensList, SinglyLinkedList& oddsList) {
        Node* current = head;
        head = tail = nullptr; // Reset original list
        count = 0;

        while (current) {
            Node* nextNode = current->next; // Store next node
            current->next = nullptr; // Isolate current node

            if (current->data % 2 == 0) {
                if (!evensList.getHead()) {
                    evensList.setHead(current);
                    evensList.setTail(current);
                } else {
                    evensList.getTail()->next = current;
                    evensList.setTail(current);
                }
                evensList.setCount(evensList.size() + 1);
            } else {
                if (!oddsList.getHead()) {
                    oddsList.setHead(current);
                    oddsList.setTail(current);
                } else {
                    oddsList.getTail()->next = current;
                    oddsList.setTail(current);
                }
                oddsList.setCount(oddsList.size() + 1);
            }
            current = nextNode; // Move to next node
        }
    }
};

int main() {
    SplitLinkedList list;
    SinglyLinkedList evensList, oddsList;

    std::cout << "Enter integers ending with -999: ";
    int value;
    while (std::cin >> value && value != -999) {
        list.insertAtEnd(value);
    }

    std::cout << "list: ";
    list.display();

    list.splitEvensAndOdds(evensList, oddsList);

    std::cout << "evensList ";
    evensList.display();
    std::cout << "oddsList: ";
    oddsList.display();
    std::cout << "list: ";
    list.display();

    return 0;
}

