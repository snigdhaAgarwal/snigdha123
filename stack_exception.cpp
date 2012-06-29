#include<iostream>
#include<exception>
#include<cstdlib>
#include<string>

class stack_exception : public std::exception
{
    public:
        stack_exception(const std::string& message = "stack error")
            : m_msg(message.c_str())
        { }
        const char* what() throw()
        {
            return m_msg;
        }
    private:
        const char* m_msg;
};

class underflow : public stack_exception
{
public:
    underflow(const std::string& message = "underflow error")
        : stack_exception(message) { }
};

class overflow : public stack_exception
{
public:
    overflow(const std::string& message = "overflow error")
        : stack_exception(message) { }
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
    if(newnode==NULL)
        throw overflow("Insufficient Memory");
    newnode->value = data;
    newnode->next  = s;
    return newnode;
}
int empty(stack* s)
{
    return (s == NULL);
}

stack* pop(stack* s)
{
    if(empty(s))
        throw underflow();
    stack* newstart = s->next;
    free(s);
    return newstart;
}

using namespace std;

int main()
{
    stack* s = create_stack();
    for(int i=3;i<10;i++)
    {
        try
        {
             s=push(s,i);        
        }
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

