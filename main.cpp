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
void addNodeHead(Review*& head, double rating, const string& comments);
void addNodeTail(Review*& head, Review*& tail, double rating, const string& comments);
void traverseList(Review* head);
void deleteList(Review*& head);

int main() {
    Review* head = nullptr;
    Review* tail = nullptr; 
    int choice;
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(); 

    return 0;
}

void addNodeHead(Review*& head, double rating, const string& comments) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
}

void addNodeTail(Review*& head, Review*& tail, double rating, const string& comments) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = nullptr;
    if (head == nullptr) {
        // List is empty
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void traverseList(Review* head) {
    Review* current = head;
    int count = 0;
    double sum = 0.0;
    cout << fixed << setprecision(1);
    while (current != nullptr) {
        count++;
        cout << "        > Review #" << count << ": " << current->rating << ": " << current->comments << endl;
        sum += current->rating;
        current = current->next;
    }
    if (count > 0) {
        double average = sum / count;
        cout << fixed << setprecision(5);
        cout << "        > Average: " << average << endl;
    } else {
        cout << "No reviews to display.\n";
    }
}

void deleteList(Review*& head) {
    Review* current = head;
    while (current != nullptr) {
        Review* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}