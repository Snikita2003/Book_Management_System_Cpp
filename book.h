#ifndef EMP_H
#define EMP_H
#include<iostream>
using namespace std;

class book
{
	int id;
	char name[20];
	char author[20];
	double price;
	double rating;
	
	public:
	
	book();
	book(int,char*,char*,double,double);
	//setters
	void setId(int );
	void setName(char*);
	void setPrize(double);
	void setRating(double );
	void setAuthor(char*);
	
	//getters
	
	int getId();
	char* getName();
	double getPrize();
	double getRating();
	char* getAuthor();	
	void display();
	
};
#endif;
