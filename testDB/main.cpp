#include "MyStack.h"
#include <stack>

using namespace std;

int main()
{
	MyStack< char* > *ms = new MyStack< char* >();
	cout<<ms<<endl;

	ms->push("abcde");
	ms->push("fghijk");
	ms->push("lmnop");
	
	delete ms;
	cout<<ms<<endl;
	ms=NULL;

	cout<<ms<<endl;
	return 0;
}