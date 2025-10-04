// COMSC 210 | Lab 18 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
using namespace std;

const int ignoreCount = 100; 

struct Node {
    string comments; 
    float rating; 
    Node *next;
};

Node* addToHead(Node*, float, string);
Node* addToTail(Node*, float, string);
void output(Node* hd); 

int main() {
    Node *head = nullptr;
    int choiceSelected; 
    float rating; 
    string comment;
    string enterNewReview = "y";

    while (enterNewReview == "y" || enterNewReview == "Y") {
        cout << "Which linked list method should we use?" << endl 
            << "    [1] New nodes are added at the head of the linked list" << endl 
            << "    [2] New nodes are added at the tail of the linked list" << endl
            << "    Choice: "; 
        cin >> choiceSelected; 
        
        while (choiceSelected != 1 && choiceSelected != 2) { 
            cin.clear(); 
            cin.ignore(ignoreCount, '\n');
            cout << "Error, please select 1 or 2: "; 
            cin >> choiceSelected; 
        }
        cout << "Enter review rating: ";
        cin >> rating; 
        cout << "Enter review rating: "; 
        cin >> comment; 
        
        if(choiceSelected == 1) { 
            addToHead(head, rating, comment); 
        }
        else if(choiceSelected == 2) { 
            addToTail(head, rating, comment); 
        }

        cout << "Enter another review? Y/N: "; 
        cin >> enterNewReview; 
    }

    return 0;
}

// addToHead(Node* hd, float rating, string comments) adds movie review to start of list
// hd is the head ptr for the linked list, rating is the movie rating and comments are the movie review comments
// returns: pointer to the new head of the linked list
Node* addToHead(Node* hd, float rating, string comments) { 
    Node* newNode = new Node; 
    newNode->comments = comments; 
    newNode->rating = rating; 
    newNode->next = hd; 
    return newNode;
}

// addToTail(Node* hd, int val) adds a value to the back of a linked list
// hd is the head ptr for the linked list, rating is the movie rating and comments are the movie review comments
// returns: pointer to the head of the linked list
Node* addToTail(Node* hd, float rating, string comments) { 
    Node* newNode = new Node; 
    newNode->comments = comments; 
    newNode->rating = rating; 
    newNode->next = nullptr; 
    Node* current = hd; 

    if (!hd) { 
        hd = newNode; 
        return hd;
    }

    while(current->next) { 
        current = current->next; 
    }
    current->next = newNode; 
    return hd; 
}

void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    Node* current = hd;
    int reviewNum = 1; 
    while (current) {
        cout << "    > Review #" << reviewNum; 
        current = current->next;
    }
    cout << endl;
}