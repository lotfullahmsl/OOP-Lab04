#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void reverse() {

        Node* prev = nullptr;
        Node* current = head;

        Node* next = nullptr;
        while (current != nullptr) {

            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        head = prev;
    }

    void printList() {

        Node* temp = head;
        while (temp) {

            cout << temp->data << " ";
            temp = temp->next;

        }
        cout << endl;
    }
};


void customSort(list<int>& lst) {
    lst.sort();
}


list<int> mergeLists(const list<int>& lst1, const list<int>& lst2) {
    list<int> mergedList = lst1;
    return mergedList;
}

class Spreadsheet {
public:
    vector<list<int>> data;

    void addRow(const list<int>& row) {
        data.push_back(row);
    }

    void deleteRow(int index) {
        if (index >= 0 && index < data.size()) {
            data.erase(data.begin() + index);
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    void display() {
        cout << "\n\tSpreadsheet:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            cout << "\tRow " << i + 1 << ": ";
            for (int val : data[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "\n\t\tSimple Spreadsheet Application!\n";

    LinkedList myList;
    myList.append(4);
    myList.append(9);
    myList.append(3);
    myList.append(0);
    myList.append(7);

    cout << "\n\tOriginal list: ";
    myList.printList();

    int key;
    cout << "\tEnter a Number to search in the list: ";
    cin >> key;

    if (myList.search(key)) {
        cout << endl;
        cout << "\t(" << key << ") Is Available in the list." << endl;
    }
    else {
        cout << endl;
        cout << "\t(" << key << ") Is Not Available in the list." << endl;
    }

    cout << "\tReversed list: ";
    myList.reverse();
    myList.printList();

    list<int> myCustomList = { 8, 6, 1, 7, 4 };
    cout << "\n\tBefore sorting: ";

    for (int n : myCustomList) cout << n << " ";
    cout << endl;

    customSort(myCustomList);
    cout << "\tAfter sorting: ";

    for (int n : myCustomList) cout << n << " ";
    cout << endl;

    list<int> list1 = { 9, 0, 3, 0, 12 };
    list<int> list2 = { 2, 4, 6, 2, 11 };

    list<int> merged = mergeLists(list1, list2);
    cout << "\tMerged list: ";

    for (int n : merged) cout << n << " ";
    cout << endl;

    Spreadsheet spreadsheet;

    // Adding rows
    list<int> row1 = { 4, 2, 9 };
    list<int> row2 = { 6, 0, 2 };
    list<int> row3 = { 1, 3, 5 };

    spreadsheet.addRow(row1);
    spreadsheet.addRow(row2);
    spreadsheet.addRow(row3);

    // Display the initial spreadsheet
    spreadsheet.display();

    int choice;
    cout << "\n\tWhat would you like to do?\n";
    cout << "\t1. Add a row\n";
    cout << "\t2. Delete a row\n";
    cout << "\tEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        list<int> newRow;
        string rowInput;
        cout << "\tEnter the elements of the new row separated by spaces (press Enter to finish): ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, rowInput);

        stringstream ss(rowInput);
        int value;
        while (ss >> value) {
            newRow.push_back(value);
        }
        spreadsheet.addRow(newRow);
        cout << "\n\tRow added successfully!" << endl;
        cout << "\tUpdated spreadsheet:" << endl;
        spreadsheet.display();
    }
    else if (choice == 2) {
        int index;
        cout << "\tEnter the index of the row you want to delete (1-" << spreadsheet.data.size() << "): ";
        cin >> index;
        spreadsheet.deleteRow(index - 1);
        cout << "\n\tRow deleted successfully!" << endl;
        cout << "\tUpdated spreadsheet:" << endl;
        spreadsheet.display();
    }
    else {
        cout << "\tInvalid choice! Exiting program." << endl;
    }

    return 0;
}
