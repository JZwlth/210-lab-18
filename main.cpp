// COMSC-210 | Lab 18 | Zhaoyi Zheng
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Review {
    double rating;
    string comments;
    Review* next;
};

//Function Prototypes


int main() {
    // Initialize the linked list with a dummy head node
    Review* head = new Review{0.0, "", nullptr};
    Review* tail = head; // Start tail at head since list has one node now

    int choice;
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "    Choice: ";
    cin >> choice;
    cin.ignore();

    return 0;
}
