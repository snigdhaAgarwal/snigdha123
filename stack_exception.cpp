#include<iostream>
#include<exception>
#include<cstdlib>
#include<string>

class underflow : public std::exception
{
    public:
        underflow(const std::string& message = "underflow error")
            : m_msg(message.c_str())
        { }
        const char* what() throw()
        {
            return m_msg;
        }
    private:
        const char* m_msg;
};

class overflow : public std::exception
{
    public:
        overflow(const std::string& message = "overflow error")
            : m_msg(message.c_str())
        { }
        const char* what() throw()
        {
            return m_msg;
        }
    private:
        const char* m_msg;
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
        throw overflow();
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
        throw underflow("Poping from empty stack");
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

