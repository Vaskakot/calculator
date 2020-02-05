#include <iostream>

using namespace std;
template <class Nebelwerfer>
class Stack
{
private:
    struct elem
    {
        Nebelwerfer num;
        elem*next=NULL;
    };
    typedef elem* pelmen;
    pelmen Top;
    int Length;
    void Del (pelmen &Top, pelmen x)
    {
        pelmen q = Top;
        if(Top==x)Top=x->next;
        else
        {
            while (q&&q->next!=x)q=q->next;
            if(q==NULL)return;
            q->next=x->next;
        }
        delete x;
    }
public:
    Stack()
    {
        Top = NULL;
        Length = 0;
    }
    ~Stack()
    {
        if(Top!=NULL)
        {
            pelmen k=Top->next;
            while(k)
            {
                Del(Top,k);
                k=k->next;
            }
            Del(Top, Top);
        }
    }
    void Push (Nebelwerfer n)
    {
        pelmen q=Top;
        Top = new elem;
        Top->num = n;
        Top->next = q;
        Length++;
    }
    void Pop()
    {
        Del(Top, Top);
        Length--;
    }
    Nebelwerfer Popvalue()
    {
        Nebelwerfer n = Top->num;
        Pop();
        return n;
    }
    Nebelwerfer Getvalue()
    {
        Nebelwerfer n = Top->num;
        return n;
    }
    void PrL()
    {
        cout<<Length<<endl;
    }
    int GetL()
    {
        return Length;
    }
};

