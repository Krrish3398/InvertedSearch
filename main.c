/************************************************************************************************************************
 Author :Krishna Chaitanya V.

Date : 05-07-2022

Description : To implement ivnerted search project to search a word based on inverted indexing concept which is 
              actually mapping of words to documents present.

Sample Input : Pass the database files as commandline arguments as :
               ./out.exe file1.txt file2.txt
	      
Sample Output : It will display a menu containing various actions that can be performed such as Create database, Display
                database, Update database, Search database, Save database into a file.
		User can perform actions according to the need by giving desired options.

**************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");

    // Validate the CLA

    if(argc <= 1)
    {
	printf("Enter valid no. of arg\n");
	printf("./Slist.exe file1.txt , file2.txt.....\n");
	return 0;
    }
    //create list of filenames
    //declare head pointer
    Flist *f_head = NULL;

    //validate the files
    file_validation_n_file_list(&f_head , argv);
    if(f_head == NULL)
    {
	printf("No files are available in the file linked list\n");
	printf("Hence process terminated\n");
	return 1;
    }
    Wlist *head[27]={NULL};

    //prompt the menu
    int ch, index =0;
    char opt = 'y', word[WORD_SIZE];
    while ( opt != 'n' && opt != 'N' )
    {
    	printf("Select your choices amont following options :\n1. Create database\n2. Display databse\n3. Update database\n4. Search database\n5. Save database\nEnter your option :\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
	    case 1: 
		//create database
		create_database(f_head, head );
	    	break;
	    case 2:
		//display database
	   	display_database(head);
	    	break;
	    case 3:
		//update database
	    	update_database(head , &f_head);
	    	break;
	    case 4:
		//search a word in database
	    	printf("Enter the word to be searched : \n");
	    	scanf("%s",word);
	    	index = tolower(word[0])%97;
	    	if (index > 25)
	    	{
		    index = 26;
	    	}
	    	search_database(head[index], word);
	    	break;
	    case 5:
		//save database into file
	    	save_database(head);
	    	break;
    	}
    	printf("Do you wish to continue?\n");
    	printf("Enter y/Y to continue and n/N to discontinue\n");
    	scanf(" %c",&opt);
    }
}
