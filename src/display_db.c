#include "inverted_search.h"

void display_database( Wlist *head[] )
{
    printf("[index]  [word]   file_count   file/s File: File_name  word_count\n");
    
    for(int i = 0 ; i < 27; i++)
    {
	//Traversing through the list, to check for pointers which are not null
	if(head[i] != NULL )
	{
	    //call print_word_count function
	    print_word_count(head[i]);
	}
    }
}

int print_word_count(Wlist *head)
{
    int index=0;
    while( head != NULL)
    {
	//Check for index value
	index = tolower(head->word[0])%97;
	if (index > 25 )
	{
	    //if other than alphabets are present, update index value to 26
	    index = 26;
	}
	//Print the index, word and file count
	printf("[%d]   [%s]  %d  file\\s " , index , head->word , head->file_count);

	Ltable *Thead = head->Tlink;
	//traverse
	while(Thead)
	{
	    //Print the values filename, wordcount present in the link table
	    printf(": File : %s  %d " , Thead->file_name , Thead->word_count);
	    Thead = Thead->table_link;
	}
	printf("\n");
	head = head->link;
    }
}

