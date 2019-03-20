#include <cstdlib>
#include <iostream>
#include <cstring>
#include "UnorderedList.h"
#include "UnorderedList.cpp"
using namespace std;

main()
{
	UnorderedList u1;
	char ch;
	
	cout << "Please enter a line of characters (Letters only); " << endl;
	cout << "('#' will delete last character in the line)";
	cout << endl << " ----> ";
	cin.get(ch); // Gets first input character
	
	// while ( uppercase letter or lowercase letter or delete indicator )
	while ( ( ch>64 && ch<91 ) || ( ch>96 && ch<123 ) || ch == 35 )
	{
		// if ( uppercase letter or lowercase letter )
		if( ( ch>64 && ch<91) || ( ch>96 && ch<123) )
			u1.append(ch); // Appends valid char to end of UnorderedList
			
		// else if ( delete indicator )
		else if( ch == 35 )
			u1.removeLast(); // Removes last char in UnorderedList
		cin.get(ch); // Gets next input character
	}
	cout << u1; // Outputs contents of UnorderedList
	return 0; // Ceases computation
}
