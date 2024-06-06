#include <iostream>
using namespace std;

// Array Implementation
struct stack
{
    int size;
    int top;
    int *arr;
};

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

void push(stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
void traversal(stack *ptr)
{
    int index = ptr->top;
    for (int i = 0; i <= index; i++)
    {
        cout << ptr->arr[i] << endl;
    }
}

int peek(stack *sp, int index)
{
    int totalIndex = sp->top;
    if (totalIndex < index)
    {
        return -1;
    }
    else
    {
        return sp->arr[index];
    }
}
int main()
{
    struct stack *sp = new stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int[sp->size];

    // cout<<isFull(sp)<<endl;
    // cout<<isEmpty(sp)<<endl;

    for (int i = 0; i < 10; i++)
    {
        int value = 50 + i;
        push(sp, value);
    }
    int index = 12;

    cout<<"Value at Index "<<index<<" is "<<peek(sp, index);

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "Popped element = " << pop(sp) << endl;
    // }

    // traversal(sp);

    // cout<<isFull(sp)<<endl;
    // cout<<isEmpty(sp)<<endl;

    return 0;
}