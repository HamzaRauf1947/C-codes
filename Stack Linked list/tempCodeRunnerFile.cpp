#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void push(struct node **top){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    cout<<"Enter your data:";
    cin >> ptr->data;
    if(*top == NULL){
        *top = ptr;
    }else{
        ptr->next = *top;
        *top = ptr;
    }
}




void print(struct node **top){
    if(*top == NULL){
        cout<<"List is empty"<<endl;
    }else{
        struct node *temp = *top;
        while (temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        
    }
}

void peek(struct node**top){
     if(*top == NULL){
        cout<<"List is empty"<<endl;
    }else{
    cout<<"The top element is "+(*top)->data;
    
}
}


int main(){
        struct node *top = NULL;
       int choice;
        cout<<"Press 1 to Push"<<endl;
        cout<<"Press 2 to pop"<<endl;
        cout<<"Press 3 to display"<<endl;
        cout<<"Press 4 to peek"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        cin >> choice;
    do
    {
        switch (choice)
        {
        case 1: push(&top);
            break;

        case 3: print(&top);
            break;
         case 4: peek(&top);
            break;  
        default: cout<<"invalid choice"<<endl;
            break;
        }
        cout<<"\nEnter your choice again: ";
        cin>>choice;
     
    }

    
     while (choice!=0);
    

}