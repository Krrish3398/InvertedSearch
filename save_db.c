#include "inverted_search.h"

void save_database( Wlist *head[])
{
    //prompt the user to enter the file name
    char file_name[FNAME_SIZE];
    printf("Enter the file name :\n");
    scanf("%s",file_name);

    //openfile
    FILE *fptr = fopen(file_name, "w" );

    int i=0;
    for(i = 0 ; i < 27 ; i++ )
    {
	if (head[i] != NULL )
	{
	    //Calling write_databasefile function only for nodes which contain data
	    write_databasefile(head[i], fptr);
	}
    }
    printf("Database is saved!!!!!\n");
}


void write_databasefile(Wlist *head, FILE* databasefile)
{
    //#[1] word is [bye]: file count is 1: file/s: file is file2.txt: word count is 1

    //Declaring of str1, str2, index
    char str1[100];
    int index=0;

    //Traverse through the headpointer
    while (head != NULL )
    {
	//Evaluate index
	index = tolower(head->word[0])%97;
	if(index >25 )
	{
	    index = 26;
	}
	//Store head node values in str
	sprintf(str1,"#[%d]\n word is %s : file count is %d ",index, head->word, head->file_count);

	//Write str1 into the database file
    	fwrite(str1, strlen(str1), 1, databasefile);

	Ltable *Thead = head->Tlink;

	//Traverse through the link table
	while(Thead)
	{
	    //Store link table values into str
	    sprintf(str1,"file/s: file is %s : word count is %d ",Thead->file_name, Thead->word_count);

	    //Write str into database file
	    fwrite(str1, strlen(str1), 1, databasefile);	    
	    Thead = Thead->table_link;
	}
	fwrite("\n", strlen("\n"),1,databasefile);
	head = head->link;
    }

}
