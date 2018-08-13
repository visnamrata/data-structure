#include<stdlib.h>
#include<iostream>
#define size 10
using namespace std;
//This is stack class, all functions are defined inside this class
template <class t>
class Stack
{
	int top;
	public:
		int s[size];
		Stack()
		{
			top=-1;
		}
		void push(t element);
		t pop();
};
	template <class t>
	void Stack<t>::push(t element)
	{
		if(top>10)
		{
			cout<<("Stack is overflow");
			//return 0;
		}
		else
		{
			s[++top]=element;
			//return 1;
		}
	}

	template <class t>
	t Stack<t>::pop()
	{
	    if (top < 0)
	    {
	        cout<<("Stack is Underflow");
	        return 0;
	    }
	    else
	    {
	        int y = s[top--];
	        return y;
	    }
	}

int main()
{
	Stack<int> obj;
	obj.push(10);
	obj.push(20);
	obj.push(35);

	cout<<obj.pop()<<" popped from Stack\n";
	cout<<obj.pop()<<" popped from Stack\n";
	cout<<obj.pop()<<" popped from Stack\n";
return 0;
}
