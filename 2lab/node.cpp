#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node{
    int value;
    Node* next;
};

void printList(Node*head);
void insert(Node** head, int newValue);
void task(Node*head);


int main(){
    srand(time(0));
    Node* head = NULL;
    int option;
    cout << "1 - Insert\n" << "2 - Show\n" << "3 - Do task\n" << "else - exit" << endl;
    
    while(true){
        cin >> option;
        switch (option)
        {
        case 1:
            insert(&head, rand()%20);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            task(head);
            break;
        default:
            exit(1);
        }
    }
    
    printList(head);
    return 0;
}

void printList(Node*head){
    cout << "\nElements:" << endl;
    while (head != NULL){
       cout << head->value << endl;
       head = head->next;
    }
}

void task(Node*head){
    int a, b;
    Node* head_copy;
    head_copy = head;
    cout << "Enter [a, b] <= 20:" << endl;
    cin >> a >> b;
    if(a > 20 || a < 0 || b > 20 || b < 0){
        cout << "Invalid data" << endl;
        return;
    }
    
    cout << "\nSmaller than a: " << endl;
    while (head != NULL){
        if (head->value < a){
            cout << head->value << " ";
        }
        head = head->next;
    }
    cout << endl;
    head = head_copy;

    cout << "\nGreater than b: " << endl;
    while (head != NULL){
        if (head->value > b){
            cout << head->value << " ";
        }
        head = head->next;
    }
    cout << endl;
    head = head_copy;

    cout << "\nIn [a,b]: " << endl;
    while (head != NULL){
        if (head->value <= b && head->value >= a){
            cout << head->value << " ";
        }
        head = head->next;
    }
    cout << endl;
    head = head_copy;
}

void insert(Node** head, int newValue){
    Node* newElem = new Node();
    newElem->value = newValue;

    if(*head == NULL){
        *head = newElem;
        cout << "Added item" << endl;
        return;
    }

    Node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newElem;
    cout << "Added item" << endl;
}