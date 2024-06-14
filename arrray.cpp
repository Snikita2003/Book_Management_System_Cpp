#include"array.h"
#include"book.h"



void book::print(book *b,int i)
{
		printf("-------------------------------------------------------------------------------------");
		printf("\nBOOK ID\t\tBOOK NAME\t\tAUTHOR NAME\tBOOK PRIZE\tBOOK RATING \n");
		printf("%-5d   | ",b[i].id);
		printf("%-19s   | ",b[i].name);
		printf("%-19s   | ",b[i].author);
		printf("%-10.2lf | ",b[i].price);
		printf("%-10.2lf | ",b[i].rating);
		printf("\n");
		printf("-------------------------------------------------------------------------------------");
		printf("\n");
}



// add new book in database
void book::add(book &b,int *s)
{
	if(*s == 8)
	{
		printf("\nArray is Full, Cannot store data.. \n");
		return;
	}
		int i=*s;
		printf("Enter book id :");
		scanf("%d",&b[i].id);
		printf("Enter BookName :");
		fflush(stdin);
		//scanf("%s",&b[i].name);
		gets(b[i].name);
		printf("Enter book Author :");
		fflush(stdin);
		gets(b[i].author);
		printf("Enter bookPrize :");
		scanf("%lf",&b[i].price);
		printf("Enter book rating :");
		scanf("%lf",&b[i].rating);	
		printf("\n..Data Stored..\n");
}



// display all book details
void book::Display(book &b,int *s)
{
	int i=0;
	printf("--------------------------------------------------------------------------------------\n");
	printf("\nBOOK ID\t\t BOOK NAME\t\tAUTHOR NAME\tBOOK PRIZE\tBOOK RATING\n");
	for(i=0;i<(*s);i++)
	{
		printf("%-5d   | ",b[i].id);
		printf("%-19s   | ",b[i].name);
		printf("%-19s   | ",b[i].author);
		printf("%-11.2lf | ",b[i].price);
		printf("%-10.2lf | ",b[i].rating);
		printf("\n");
	}
	printf("\n--------------------------------------------------------------------------------------\n");
}




// delete record by id
void book::remove1(book &b,int *s)
{
	int id1,isTrue=0;
	printf("\nEnter id to remove record :");
	scanf("%d",&id1);
	if(*s == 0)
	{
		printf("\n..Array is Empty Please add Data..\n");
		return;
	}
	for(int i=0; i< *s;i++)
	{
		if(b[i].id==id1)
		{
			isTrue=1;
			for(int j=i;j< *s;j++)
			{
				b[j]=b[j+1];
			}
		}
		if(isTrue==1) 
		{
			(*s)--;
			printf("\n..Data Deleted ..\n"); 
			break;
		}
	}
	if(isTrue==0) printf("\nRecond Not Found..\n");
}


// search detaild by id
int book::searchId(book &b,int *s,int id)
{
	for(int i=0;i<(*s);i++)
	{
		if(b[i].id==id) return i;
	}
	return -1;
}



// search detaild by bname
int book::searchName(book *b,char *name1,int s)
{
	for(int i=0;i<(s);i++)
	{
		if(stricmp(b[i].name,name1)==0) return i;
	}
	return -1;
}


// search by id and bname
void book::search(book &b,nt *s)
{
	int choice;
	printf("which u want select \n1-Id\n2-BookName\n");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		int id;				// id
		printf("Enter id to search :");
		scanf("%d",&id);
		
		int index=searchId(b,s,id);  //found
		if(index >=0 && index < (*s))
		{
			printf("\n--Found--\n");
			print(b,index);
		}
		else printf("..record Not Found..\n");		
	}
	
	else if(choice == 2) // by bookname
	{
		char n[30];
		printf("Enter bookName :");
		fflush(stdin);
		//scanf("%s",&n);
		gets(n);
		int index=searchName(b,n,*s);
		
		if(index >=0 && index < (*s))
		{
			printf("\n--Found--\n");
			print(b,index);
		}
		else printf("..record Not Found..\n");	
		
	}	
	else printf("\nInvalid Choice\n");
}


// update values 
void book::update(book &b,int *s)
{
	int id1;
	printf("Enter id to update :"); scanf("%d",&id1);
	int flag=0,f=0;
	for(int i=0;i< *s;i++)
	{
		if(b[i].id==id1)
		{
			flag=1;
			printf("\n What u want update \n1-BookPrize\n2-BookRating\n");
			int n;printf("Enter choice 1/2 - "); scanf("%d",&n);
			double p1;
			
			if(n==1)
			{  
				f=1;
				printf("Enter BookPrize:"); scanf("%lf",&p1);
				b[i].price=p1;
			}
			else if(n==2)
			{
				f=1;
				printf("Enter New BookRating:"); scanf("%lf",&p1);
				b[i].rating=p1;
			}
			else printf("\n..Invalid choice..\n");
		}
		if(f==1) 
		{
			printf("\n...Data Updated...\n");
			f=0;
		}
	}
	if(flag==0) printf("\n..Record Not Found...\n");
}


// display top3 by price
void book::Top3(book &b1 ,int *s)
{	
	int i=0;
	for(i=0;i<(*s);i++)
	{
		int s1=*s;
		book ex;
		for(int j=0;j< (s1-i-1);j++)
		{
			if(b1[j].price < b1[j+1].price && b1[j].rating<b1[j+1].rating)
			{
				ex=b1[j];
				b1[j]=b1[j+1];
				b1[j+1]=ex;
			}			
		}
	}
	
	// if record less than 3
	int n=3;
	printf("\n-- Top 3 players --\n");
	if(*s < n)
	{
		printf("\n..only %d records are available in Database..\n",*s);
		Display(b1,s);
	}
	else Display(b1,&n);
}



// details all book name specified authorname
void book::listAuthor(book &b,int *s)
{
	char author1[20];
	printf("Enter AuthorName : ");
	scanf("%s",&author1);
	int f=0;
	for(int i=0;i<(*s);i++)
	{
		if(stricmp(b[i].author,author1)==0)
		{
			f=1;
			print(b,i);
		}
	}
	if(f==0)
	{
		printf("\nNo Record Found\n");
	}
}







