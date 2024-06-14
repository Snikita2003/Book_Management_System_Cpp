#include"book.h"

class Array
{
	book *b;
	int index,size;
	
	public:
	
	Array(int);//size
	// prototype
	bool isFull();
	bool isEmpty();
	bool add(book&);
	void search();
	void remove1(int); //id.
	void store();
	int searchId(int);//id
	int searchName(char*);
	void updateR();
	void Top3();
	void Display();
	
};