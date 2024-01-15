#include <iostream>
using namespace std;
#define MAX_SIZE 3

int NumArray[MAX_SIZE];
int FRONT= -1;
int REAR= -1;
int QUEUESIZE=0;

bool isEmpty() {
    if (QUEUESIZE==0)
        return true;
    else
        return false;
}

bool isFull() {
    if (REAR<MAX_SIZE-1)
        return false;
    else
        return true;
}

void enqueue(int data) {
    if (REAR<MAX_SIZE-1){
        REAR++;
        NumArray[REAR] = data;
        QUEUESIZE++;
        if (FRONT == -1){
            FRONT++;
        }
        cout<<"Data inserted";
    } else{
        cout<<"Queue Overflow";
    }
}

void dequeue() {
    int x;
    if (QUEUESIZE > 0){
        x = NumArray[FRONT];
        FRONT++;
        QUEUESIZE--;
        cout<<x <<"removed from the que";
    } else{
        cout<<"Queue Underflow";
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements: ";
    int i = FRONT;
    do {
        cout << NumArray[i] << " ";
        i = i+1;
    } while (i <= REAR);
    cout << endl;
}

void arrayMenu() {
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if the queue is empty\n";
        cout << "5. Check if the queue is full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Queue is " << (isEmpty() ? "" : "not ") << "empty.\n";
                break;

            case 5:
                cout << "Queue is " << (isFull() ? "" : "not ") << "full.\n";
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
}

void linkedListMenu() {
    cout<<"not implemented yet!";
}

void circularEnqueue(int data) {
    if (QUEUESIZE<MAX_SIZE){
        REAR++;
        if (REAR == MAX_SIZE){
            REAR = 0;
        }
        NumArray[REAR] = data;
        QUEUESIZE++;
        if (FRONT == -1){
            FRONT++;
        }
    } else{
        cout<<"Queue Overflow!";
    }
}
void circularDisplay(){
    if (QUEUESIZE == 0){
        cout<<"Queue is empty!\n";
    }

}

void circularDequeue() {
    int x;
    if (QUEUESIZE>0){
        x = NumArray[FRONT];
        FRONT++;
        if (FRONT==MAX_SIZE)
            FRONT=0;
        QUEUESIZE--;
        cout<<x<<" Removed from the queue";
    } else
        cout<<"Queue Underflow";
}

void circularArrayMenu() {
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if the queue is empty\n";
        cout << "5. Check if the queue is full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                circularEnqueue(data);
                break;

            case 2:
                circularDequeue();
                break;

            case 3:
                circularDisplay();
                break;

            case 4:
                cout << "Queue is " << (isEmpty() ? "" : "not ") << "empty.\n";
                break;

            case 5:
                cout << "Queue is " << (isFull() ? "" : "not ") << "full.\n";
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
}

void enqueFront(int data) {
    if (FRONT == -1){
        FRONT++;
        REAR++;
        NumArray[FRONT] = data;
    }
    if (FRONT == -1) {
        FRONT = REAR = 0;
        NumArray[FRONT] = data;
    } else if (FRONT > 0) {
        NumArray[--FRONT] = data;
    } else {
        cout << "Deque is full from the front. Cannot push.\n";
    }
}

void enqueRear(int data) {

}

void dequeFront() {

}

void dequeRear() {

}

void dequeMenu() {
    int choice;
    while (choice != 6) {
        cout << "\n----- Double-Ended Queue Implementation -----\n";
        cout << "1. Enque Element at Front\n";
        cout << "2. Enque Element at rear\n";
        cout << "3. Deque Element from Front\n";
        cout << "4. deque Element from rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int element;
                cout << "Enter element to enque at front: ";
                cin >> element;
                enqueFront(element);
                break;
            }
            case 2: {
                int element;
                cout << "Enter element to push at rear: ";
                cin >> element;
                enqueRear(element);
                break;
            }
            case 3:
                dequeFront();
                break;
            case 4:
                dequeRear();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void priorityQueueMenu() {

}

int main() {
    cout<<"\n1. Linear Array Implementation\n"
          "2. Circular Array Implementation\n"
          "3. Double Ended Queue Implementation\n"
          "4. Priority Queue Implementation\n"
          "0. Exit\n\n Enter your choice:";
    int choice;
    cin>>choice;
    switch(choice) {
        case 1: {
            arrayMenu();
            break;
        }
        case 2: {
            circularArrayMenu();
            break;
        }
        case 3:
            dequeMenu();
            break;
        case 4:
            priorityQueueMenu();
            break;
        case 0: {
            exit(0);
        }
        default: {
            cout<<"\nInvalid Choice\n";
            break;
        }
    }
}