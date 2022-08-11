#include "inverted_search.h"

void search_database( Wlist *head, char *word)
{
    //check if the list is empty of not
    if (head == NULL )
    {
	printf("The search word is not availble, because the list is empty\n");
	return;
    }

    //traverse through the Wlist

    while( head )
    {
	//Compare the search word with the available words in the list
	if ( strcmp( head->word, word ) == 0)
	{
	    //If comparison is successful, print word and filecount
	    printf("word %s is present in %d file \n",word, head->file_count);

	    //Traverse through the link table
	    Ltable *Thead = head->Tlink;

	    while (Thead )
	    {
		//Printf filename and wordcounts present in linktable
		printf("In file : %s %d times\n",Thead->file_name, Thead->word_count );
		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return;
	}
	head = head->link;
    }
    printf("Search word is not found in the list\n");
}
