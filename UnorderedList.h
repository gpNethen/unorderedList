#ifndef UNORDEREDLIST_H
#define UNORDEREDLIST_H

#include <cstdlib>                 // Provides size_t
#include <iostream>                // Provides ostream
#include <cstring>

class UnorderedList
{
	public: 
    	typedef char Item;
    	UnorderedList( ) { first = last = NULL; }
    	~UnorderedList( );
    	void append ( const Item& entry );
    	void removeLast ( );
    	bool isEmpty( ) const { return first == NULL; }
    	friend std::ostream& operator << ( std::ostream& outStr, const UnorderedList& u );
	private:
    	struct Node
    	{
    		Item data;
        	Node *next;
        	Node *back;
    	};
    	Node *first;
    	Node *last;
    	Node* getNode( const Item& entry, Node* forward, Node* backward );
};
#endif
