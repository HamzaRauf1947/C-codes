#include <iostream>
using namespace std;

struct node
{
    int rollNum;
    float GPA;
    struct node *next;
    struct node *prev;
};

void insert(struct node **head)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    cout << "Enter RollNum: ";
    cin >> ptr->rollNum;
    cout << "Enter GPA: ";
    cin >> ptr->GPA;
    ptr->prev = ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

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
        }
    }
}

void count(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty,how this funtion is supposed to count" << endl;
    }
    else
    {
        struct node *temp = *head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "The total element in a list are: " << count << endl;
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
            }
        }
        if (flag == false)
        {
            cout << "Your id is not present" << endl;
        }
    }
}

void delAll(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        bool flag = false;
        struct node *temp = *head;
        while (temp != NULL)
        {
            *head = temp->next;
            (*head)->prev = NULL;
            free(temp);
            temp = *head;
            flag = true;
        }
        if (flag)
        {
            cout << "All List is deleted successfully" << endl;
        }
    }
}

void delBeg(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp = *head;
        if (temp->next == NULL)
        {
            *head = temp->next;
        }
        else
        {
            *head = temp->next; // or *head = (*head)->next;
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

void delEnd(struct node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *temp, *prevNode;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp == *head)
        {
            *head = NULL; // or   *head = temp->next     or     *head = (*head)->next
        }
        else
        {
            prevNode = temp->prev;
            prevNode->next = NULL;
        }
        free(temp);
    }
}

void delAtPos(struct node * *head){
    if(*head == NULL){
        cout<<"List is empty"<<endl;
    }
    else{
    struct node *temp,*nextNode;
    int pos;
    cout<<"Enter position which u want to delete: ";
    cin >> pos;
    temp = *head;
    if(pos < 1){
        cout<<"invalid position"<<endl;
    }
    if(pos==1){
        *head = temp->next;
        free(temp);
    }else{
    for (int i = 1;  temp!=NULL && i < pos-1; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        cout<<"position is out of range"<<endl;
    }else{
    nextNode = temp->next;
    temp->next = nextNode->next;
    if(nextNode->next == NULL){
        free(nextNode);
    }else{
    nextNode->next->prev = temp;
    free(nextNode);

}
}
}
}
}

// void delRoll(struct node** head) {
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
//             (*head)->prev = NULL;
//             free(temp);
//         }else{

//         while (temp != NULL && temp->rollNum != rollSearch) {
//             prevnode = temp;
//             temp = temp->next;
//         }

//         // if there is no found in the list
//         if (temp == NULL) {
//             cout << "Roll number is not found" << endl;
//         }
//         if(temp->next == NULL){
//             prevnode->next = temp->next;   // or prenode->next = NULL;
//             free(temp);
//         }else{
//             prevnode->next = temp->next;
//             temp->next->prev = prevnode;
//             free(temp); 
//         }

        
//     }
// }
// }


void delRoll(struct node **head){
    if(*head == NULL){
        cout << "list is empty";
    }else{
        struct node *temp = *head;
        int toDel;
        cout<<"Enter roll number to be deleted: ";
        cin >> toDel;
        bool isFound = false;
        while(temp!=NULL){
            if(temp->rollNum == toDel){
               //deleting first node 
               if(temp == *head){
                *head = temp->next;
                temp->prev = NULL;
               }if(temp->prev!=NULL){
                temp->prev->next = temp->next;
               }if(temp->next!=NULL){
                temp->next->prev = temp->prev;
               }
               isFound = true;
               free(temp);
            }else{
            temp=temp->next;
            }
                
        }
        if(isFound == false){
            cout<<"Roll number not found"<<endl;
        }
        
        

    }
}







int main()
{
    struct node *head = NULL;
    cout << "List is currently empty" << endl;
    insert(&head);
    int choice;
    cout << "Press 1 to Insert" << endl;
    cout << "Press 2 to Print" << endl;
    cout << "Press 3 to Delete All" << endl;
    cout << "Press 4 to Delete from begining" << endl;
    cout << "Press 5 to Delete from end" << endl;
    cout << "Press 6 from specific position Enter position :" << endl;
    cout << "Press 7 to Search" << endl;
    cout << "Press 8 to display number of nodes" << endl;
    cout << "Press 9 from rollnumber:" << endl;
    cout << "Press 0 to Exit" << endl;
    cout << "Enter Your choie: ";
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
            delAll(&head);
        }
        else if (choice == 4)
        {
            delBeg(&head);
        }
        else if (choice == 5)
        {
            delEnd(&head);
        }
        else if (choice == 6)
        {
            delAtPos(&head);
        }
        else if (choice == 7)
        {
            search(&head);
        }
        else if (choice == 8)
        {
            count(&head);
        }
        else if (choice == 9)
        {
            delRoll(&head);
        }

        cout << "Enter your choice: ";
        cin >> choice;
    }
}
