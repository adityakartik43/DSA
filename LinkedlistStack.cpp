#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct stack
{
    int top;
    int size;
    node *list;
};

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        node *newNode = new node; //create a new node for push
        newNode->data = value; //assigning new node data
        newNode->next = ptr->list; //newnode next assign as ptr->list which is nullptr
        ptr->list = newNode; //ptr->next connect with newnode
        ptr->top++; //increment of top
    }
}

int peek(stack *ptr, int index){
    node *temp = ptr->list;
    for(int i=0; i<=(ptr->size-2-index); i++){
        ptr->list = ptr->list->next;
    }
    return ptr->list->data;
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        ptr->top--; //minus top value by 1
        int value; //initalize the pop value
        node *temp = ptr->list; //creating a node that point last node of list 
        value = temp->data; //getting last value of list
        ptr->list = ptr->list->next; //decrement the node by 1
        delete temp; //deleting temp node for memory managemet
        return value; //returning value
    }
}
void traversal(stack *ptr)
{
    while (ptr->list != NULL)
    {
        cout << ptr->list->data << endl;
        ptr->list = ptr->list->next;
    }
}

int main()
{
    stack *sp = new stack;
    sp->size = 10;
    sp->top = -1;
    sp->list = new node;
    sp->list = NULL;

    // cout<<isFull(sp)<<endl;
    // cout<<isEmpty(sp)<<endl;

    for (int i = 0; i < 10; i++)
    {
        push(sp, 100 + i + 1);
    }

    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout << "Popped value : " << pop(sp) << endl;
    // cout<<isFull(sp)<<endl;
    // cout<<isEmpty(sp)<<endl;

    cout<<"Peek 2 index "<<peek(sp, 2);

    // traversal(sp);

    return 0;
}