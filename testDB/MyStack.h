#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

template< class T > class MyStack
{
private:
	struct StackNode
	{
		T value;
		StackNode *prev;	
		StackNode()
		{
			std::cout<<"StackNode Constructor"<<std::endl;
		}
		~StackNode()
		{
			std::cout<<"StackNode Destructor : Delete "<<value<<std::endl;
		}
	};
	StackNode *head;

public:
	MyStack()
	{
		head=NULL;
		std::cout<<"MyStack Constructor"<<std::endl;
	}

	~MyStack()
	{
		StackNode *prevNode;

		
		while( NULL != head )
		{
			
			prevNode = head->prev;
			delete head;
			head = prevNode;
		}
		std::cout<<"MyStack Desturctor"<<std::endl;
		
	}
	void push(T value)
	{
		StackNode *newNode;
		newNode = new StackNode;
		newNode->value = value;
		if( true == isEmpty() )
		{
			head = newNode;
			newNode->prev = NULL;
		}
		else
		{
			newNode->prev = head;
			head = newNode;
		}
	}

	T pop()
	{
		StackNode *temp;
		T temp_value;
		if( true == isEmpty() )
		{
			//TODO error message
			return 0;
		}
		else
		{
			temp_value = head->value;
			temp=head->prev;
			delete head;
			head = temp;
			return temp_value;
		}

	}
	bool isEmpty()
	{
		return (NULL==head)?true:false;
	}

};
#endif