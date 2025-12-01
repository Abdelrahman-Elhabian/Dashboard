#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class Queue {
    public:
    Node* front;
    Node* rear;
    Queue() {
        front = rear = NULL;
    }
    bool isEmpty() {
        if(front == NULL && rear == NULL)
        {
            return true;
        }
        else {
            return false;
        }
    }
    void Enqueue(int item) {
        Node*newnode = new Node();
        newnode->data = item;
        if (isEmpty())
        {
            front = rear = newnode;
        }
        else 
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void Display() {
        if (isEmpty())
        {
            cout << "No items to Display\n";
        }
        else {
        Node*temp = front;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        }
        cout << endl;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Error!\n";
        }
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else {
            Node*delptr = front;
            front = front->next;
            int value = delptr->data;
            delete delptr;
        }
    }
    int Getfront() {
        return front->data;
    }
    int Getrear() {
        return rear->data;
    }
    int count() {
        Node*temp = front;
        int counter;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isFound(int item) {
        bool found = false;
        Node*temp = front;
        while (front != NULL)
        {
            if (temp->data == item)
            {
                found = true;
                temp = temp->next;
                break;
            }
        }
        return found;
    }
    void clear() {
        while (!isEmpty())
        {
            Dequeue();
        }
    }
};


int main () {
    Queue q;
    for (int i = 1; i <= 3; i++)
    {
        int item;
        cout << "Enter Item to Enqueue: \n";
        cin >> item;
        q.Enqueue(item);
    }
    q.Display();
    cout << "Clear all items \n";
    q.clear();
    cout << "Display after clear\n";
    q.Display();
}