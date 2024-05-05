#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
void enqueue()
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = NULL;
    cout << "Enter your data:";
    cin >> ptr->data;
    if (front == NULL && rear == NULL)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void print()
{
    if (front == NULL && rear == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "The peek value is " << front->data << endl;
    }
}

void dequeue()
{

    if (front == NULL && rear == NULL)
    {
        cout << "List is empty" << endl;

    }else{
        struct node *temp = front;
        cout<<"Dequeued --> "<<front->data<<endl;
        front = front->next;
        free(temp);
    }
}

int main()
{
    int choice;
    cout << "Press 1 to enqueue" << endl;
    cout << "Press 2 to dequeue" << endl;
    cout << "Press 3 to display" << endl;
    cout << "Press 4 to peek" << endl;
    cout << "Press 0 to Exit" << endl;
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        case 4:
            peek();
            break;
        default:
            cout << "invalid choice" << endl;
            break;
        }
        cout << "\nEnter your choice again: ";
        cin >> choice;

    }

    while (choice != 0);
}