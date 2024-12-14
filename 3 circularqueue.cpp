#include <iostream>
using namespace std;

#define MAX 5  // Size of the queue

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}  // Constructor

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
        } else {
            if (front == -1) front = 0;  // First element
            rear = (rear + 1) % MAX;
            arr[rear] = value;
            cout << value << " inserted." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << arr[front] << " removed." << endl;
            if (front == rear) {  // Only one element left
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // Queue is Full!

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.display();

    return 0;
}