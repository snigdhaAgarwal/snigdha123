#include<iostream>
#include<exception>
#include<stdlib.h>
using namespace std;

class underflow:public exception
{
    public:
        const char* what()
        {
            return("underflow error..");
        }
};
class overflow:public exception
{
    public:
        const char* what()
        {
            return("overlow error..");
        }
};
typedef struct node

{

    int value;

    struct node* next;

} stack;



stack* create_stack()

{

    return NULL;

}



stack* push(stack* s, int data)

{

    stack* newnode = (stack*)malloc(sizeof(stack));

    newnode->value = data;

    newnode->next  = s;

    return newnode;

}



stack* pop(stack* s)throw()

{

    stack* newstart = s->next;

    free(s);

    return newstart;

}


int main()
{
    stack* s = create_stack();
    for(int i=3;i<10;i++)
    {
        try{
             s=push(s,i);        }
        catch(overflow &e)
        {
            cout<<e.what()<<endl;
        }
    }
    for(int i=3;i<11;i++)
    {
        try
        {
            s=pop(s);
        }
        catch(underflow &e1)
        {
            cout<<e1.what()<<endl;
        }
    }
}

