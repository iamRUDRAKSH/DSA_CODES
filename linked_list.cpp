#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* nn = new Node(value);
        if (head == nullptr)
            head = nn;
        else {
            Node* t = head;
            while (t->next != nullptr)
                t = t->next;
            t->next = nn;
        }
    }

    void printlist() {
        if (head == nullptr)
            cout << "List is empty" << endl;
        else {
            Node* t = head;
            while (t != nullptr) {
                cout << t->data << "->";
                t = t->next;
            }
            cout << "Null" << endl;
        }
    }

    Node* search(int value) {
        Node* t = head;
        Node* prev = nullptr;

        while (t != nullptr) {
            if (t->data == value) {
                cout << "Element " << value << " found" << endl;
                return t;
            }
            prev = t;
            t = t->next;
        }
        cout << "Element " << value << " not found. Returning last element." << endl;
        return prev;  // Return the last element in the list
    }

    void replace(int existing, int value) {
        Node* find = search(existing);
        if (find != nullptr) {
            find->data = value;
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);
        }
    }

    void insertNext(int existing, int value) {
        Node* find = search(existing);
        if (find != nullptr) {
            Node* nn = new Node(value);
            nn->next = find->next;
            find->next = nn;
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);
        }
    }

    void remove(int value) {
        Node* prev = nullptr;
        Node* t = head;
        bool found = false;

        while (t != nullptr) {
            if (t->data == value) {
                Node* temp = t; // Store the current node to delete it later
                if (prev != nullptr) {
                    prev->next = t->next;
                } 
                else {
                    head = t->next;
                }
                t = t->next; // Move to the next node before deleting the current one
                delete temp; // Delete the current node
                found = true;
                cout << "Element " << value << " removed" << endl;
            } 
            else {
                prev = t;
                t = t->next;
            }
        }

        if (!found)
            cout << "Element " << value << " not found." << endl;
    }

    void pop(){
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        head = head->next;
        delete t;
    }

    ~LinkedList() {
        Node* current = head;
        Node* nn = nullptr;
        while (current != nullptr) {
            nn = current->next;
            delete current;
            current = nn;
        }
    }
};

int main() {
    LinkedList list;
    list.append(21);
    list.append(41);
    list.printlist();
    list.append(51);
    list.insertNext(21, 31);
    list.replace(41, 61);
    list.printlist();
    list.replace(71, 81);  // Element 71 does not exist, so 81 is added to the end
    list.insertNext(71, 91); // Insert 91 after the last element (81)
    list.printlist();
    list.remove(41);
    list.remove(81);
    list.printlist();
    list.pop();
    list.printlist();
    return 0;
}