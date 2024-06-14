#include <iostream>
#include"array.h"
#include"book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	
	Array a1(10);
	a1.store();
	int ch;
	do
	{
		cout<<"1 - Add Elements \n";
		cout<<"2 - Search Elements\n";
		cout<<"3 - Delete Elements\n";
		cout<<"4 - Update records\n";
		cout<<"5 - Top3 Records\n";
		cout<<"6 - Display\n";
		cout<<"Enter choice - "; cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					int id;
					char name[20];
					double sal;
					double rating;
					char author[20];
					cout<<"Enter id,name,salary,rating,author \n";
					cin>>id>>name>>sal>>rating>>author;
					
					book e1(id,name,author,sal,rating);
					
					if( a1.add(e1) ) //if true
						cout<<"\n----element inserted------\n";
					
					else
						cout<<"\n-------Array is Full------\n";
						
					break;
				}
			case 2:
				{
					a1.search();
						break;
				}
			case 3:
				{
					int id;
					cout<<"Enter id to remove record : "<<endl;
					cin>>id;
					a1.remove1(id);
					break;
				}
			case 4:
				{
					a1.updateR();
					break;
				}
			case 5:
					{
						a1.Top3();
						break;
					}
			case 6:
					{
						a1.Display();
						break;
					}
		}
		
		
	}while(ch != 0);
	return 0;
}