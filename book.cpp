#include"book.h"
#include"array.h"

book::book()
{
	id=0;
	price=0;
}
book::book(int id,char*name,char*author,double pr,double rat)
{
	this->id=id;
	strcpy(this->name,name);
	strcpy(this->author,author);
	this->price=pr;
	this->rating=rat;
}

//setters
void book::setId(int id)
{
	this->id=id;
}
void book::setName(char* n)
{
	strcpy(this->name,n);
}
void book::setPrize(double d)
{
	price=d;
}


void book::setRating(double r)
{
	this->rating=r;
}
void book::setAuthor(char* n)
{
	strcpy(this->author,n);
}
//getters

int book::getId()
{
	return this->id;
}
char* book::getName()
{
	return this->name;
}
double book::getPrize()
{
	return this->price;
}
double book::getRating()
{
	return this->rating;
}
char* book::getAuthor()
{
	return this->author;
}



void book::display()
{
	cout<<id<<"\t\t";
	cout<<name<<"\t\t";
	cout<<author<<"\t\t\t";
	cout<<price<<"\t\t\t";
	cout<<rating<<"\t\t";
}









