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
        if (!head)
            head = nn;
        else {
            Node* t = head;
            while (t->next != nullptr)
                t = t->next;
            t->next = nn;
        }
    }

    void printlist() {
        if (!head)
            cout << "List is empty" << endl;
        else {
            Node* t = head;
            while (t) {
                cout << t->data << "->";
                t = t->next;
            }
            cout << "Null" << endl;
        }
    }

    Node* search(int value) {
        Node* t = head;
        Node* prev = nullptr;
        while (t) {
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
        if (!find) {
            find->data = value;
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);
        }
    }

    void insertNext(int existing, int value) {
        Node* find = search(existing);
        if (!find) {
            Node* nn = new Node(value);
            nn->next = find->next;
            find->next = nn;
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);
        }
    }

    void remove(int value) {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        while (head && head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node* current = head;
        while (current && current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next; // Only move to next if no deletion
            }
        }
    }

    void pop(){
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        head = head->next;
        delete t;
    }

    void reverse(){
        if(!head){
            cout << "List is empty." << endl;
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        Node* nn = nullptr;
        while (current) {
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