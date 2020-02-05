#include <iostream>
#include "StackOVERFLOW.cpp"
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    Stack <char> A;
    string res;
    while(s.size())
    {
        char g = s[0];
        if(g>='0'&&g<='9')res += g;
        else if(g=='(')A.Push(g);
        else if(g==')')
        {
            while(A.Getvalue()!='(')res += A.Popvalue();
            A.Pop();
        }
        else if(g=='*'||g=='/')
            {
                while(A.GetL()!=0&&(A.Getvalue()=='*'||A.Getvalue()=='/'))res+=A.Popvalue();
                A.Push(g);
            }
        else
            {
                while(A.GetL()!=0&&A.Getvalue()!='(')res+=A.Popvalue();
                A.Push(g);
            }
        s.erase(0, 1);
    }
    while(A.GetL())res+=A.Popvalue();
    cout<<res<<endl;
    Stack <float> B;
    while (res.size())
    {
        char f = s[0];
        if(f>='0'&&f<='9')B.Push(f-'0');
        else if(f=='+'||f=='-'||f=='*'||f=='/')
        {
            float a = B.Popvalue();
            float b = B.Popvalue();
            if(f=='+')B.Push(a+b);
            if(f=='-')B.Push(b-a);
            if(f=='*')B.Push(a*b);
            if(f=='/')B.Push(b/a);
        }
        res.erase(0, 1);
    }
    cout<<"here"<<endl;
    cout<<B.Popvalue();
    return 0;
}
