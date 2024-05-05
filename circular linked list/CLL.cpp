#include <iostream>
using namespace std;

struct node
{
    int rollNum;
    float GPA;
    struct node *next;
};

void insert(struct node **head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    cout << "Enter Roll Number: ";
    cin >> ptr->rollNum;
    cout << "Enter GPA : ";
    cin >> ptr->GPA;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        ptr->next = *head;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = *head;
    }
}

// My own logic code
// void print(struct node **head)
// {
//     if (*head == NULL)
//     {
//         cout << "List is empty" << endl;
//     }
//     else
//     {
//         struct node *temp = *head;
//         struct node *curr = NULL;
//         while (curr != *head)
//         {
//             cout << "rollnumber: " << temp->rollNum << "\tGPA: " << temp->GPA << endl;
//             temp = temp->next;
//             curr = temp;
//         }
//     }
// }

// Optimized code because only one pointer is used here
void print(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp = *head;
        while (temp != NULL)
        {
            cout << "rollnumber: " << temp->rollNum << "\tGPA: " << temp->GPA << endl;
            temp = temp->next;
            if (temp == *head)
            {
                temp = NULL;
            }
        }
    }
}

void search(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp = *head;
        int searchRollnum;
        cout << "Enter your rollNumber to search your id: ";
        cin >> searchRollnum;
        bool flag = false;
        while (temp != NULL)
        {
            if (temp->rollNum == searchRollnum)
            {
                cout << "Your id is found and your academics are here" << endl;
                cout << "RollNumber: " << temp->rollNum << "\tGPA: " << temp->GPA << endl;
                flag = true;
                break;
            }
            else
            {
                temp = temp->next;
                if (temp == *head)
                {
                    temp = NULL;
                }
            }
        }
        if (flag == false)
        {
            cout << "Your id is not present" << endl;
        }
    }
}

//? code is working fine but not fullfilled all rule of circular linked list
// void del(struct node** head) {
//     if (*head == NULL) {
//         cout << "List is empty" << endl;
//     } else {
//         struct node *temp = *head, *prevnode = NULL; // Initialize prevnode to NULL
//         int rollSearch;
//         cout << "Enter your rollnumber to delete: " << endl;
//         cin >> rollSearch;

//         // if node 1 to be deleted
//         if (rollSearch == temp->rollNum) {
//             *head = temp->next;
//             free(temp);
//         }

//         while (temp != NULL && temp->rollNum != rollSearch) {
//             prevnode = temp;
//             temp = temp->next;
//             if(temp == *head){
//                 temp = NULL;
//             }
//         }

//         // if there is no found in the list
//         if (temp == NULL) {
//             cout << "Roll number not found" << endl;
//         }

//         prevnode->next = temp->next;
//         free(temp);
//     }
// }

//? correct code
void del(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp = (*head)->next;
        struct node *prev = (*head);
        int toDel;
        bool isFound = false;
        cout << "Enter Roll number to delete: ";
        cin >> toDel;
        // To delete first node
        if (toDel == (*head)->rollNum)
        {
            while (temp->next != *head)
            {
                temp = temp->next;
            }
            *head = (*head)->next;
            temp->next = *head;
            isFound = true;

            free(prev);
        }
        else
        { // To delete any node(last node is also incuded) except first node
            while (temp != *head)
            {
                if (toDel == temp->rollNum)
                {
                    prev->next = temp->next;
                    isFound = true;
                    free(temp);
                }
                else
                {
                    temp = temp->next;
                    prev = prev->next;
                }
            }
        }
        if(isFound == false){
            cout<<"Roll number is not found"<<endl;
        }
    }
}

int main()
{
    struct node *head = NULL;
    cout << "List is curently empty" << endl;
    insert(&head);
    int choice;
    cout << "Press 1 to Insert" << endl;
    cout << "Press 2 to Print" << endl;
    cout << "Press 3 to Search" << endl;
    cout << "Press 4 to Delete" << endl;
    cout << "Press 0 to Exit" << endl;
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
        {
            insert(&head);
        }
        else if (choice == 2)
        {
            print(&head);
        }
        else if (choice == 3)
        {
            search(&head);
        }
        else if (choice == 4)
        {
            del(&head);
        }
        cout << "Enter you choice Again: ";
        cin >> choice;
    }
}
