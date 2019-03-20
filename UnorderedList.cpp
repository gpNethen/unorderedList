#include <cstdlib>
#include <iostream>
#include <cstring>
#include "UnorderedList.h"
using namespace std;

// Default constructor is inline.

UnorderedList::~UnorderedList( )
{
	Node* temp;

    while ( first != NULL )
    {
    	temp = first;
    	first = first -> next;
    	delete temp;
    }
}

void UnorderedList::append ( const Item& entry )
{
	if ( isEmpty() )
    	last = first = getNode(entry, NULL, NULL);
    else
    {
    	last->next = getNode(entry, NULL, last);
    	last = last->next;
    }
}

void UnorderedList::removeLast()
{
	Node* temp;
	if (first != NULL && first->next == NULL)
	{
		temp = first;
		first = NULL;
		last = NULL;
		delete temp;
	}
	else if (last != NULL)
	{
		temp = last;
		last = temp->back;
		temp->back->next = temp->next;
		delete temp;
	}
}

ostream& operator << ( ostream& outStr, const UnorderedList& u )
{
    UnorderedList::Node *cursor;

    for ( cursor=u.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
    	outStr << cursor->data;
    if ( cursor != NULL )
    	outStr << cursor->data;

    return outStr;
}

UnorderedList::Node* UnorderedList::getNode ( const Item& entry, Node* forward, Node* backward )
{
    Node *temp;

    temp = new Node;
    temp->data = entry;
    temp->next = forward;
    temp->back = backward;
    return temp;
}

