#include "inverted_search.h"

char *f_name;

void create_database(Flist *f_head, Wlist *head[])
{
    while (f_head != NULL )
    {
       	read_datafile(head,f_head->file_name );
	f_head = f_head->link;
    }
}

Wlist * read_datafile( Wlist *head[], char *filename)
{
    f_name = filename;
    FILE *fptr = fopen( filename, "r" );
    char word[15];
    int flag , index=0;

    while ( fscanf(fptr, "%s", word ) != EOF )
    {
	flag = 1;

	//Tolower function to convert the first char to lowercase
	index = tolower(word[0]) % 97;

	if ( index > 25 )
	{
	    index = 26;
	}

	if ( head[index] != NULL )
	{
	    Wlist *temp = head[index];
	    while (temp )
	    {
		//Compare words to check whether a repeated word is encountered
		if ( strcmp ( temp->word, word) == 0 )
		{
		    //If word is repeated, call updateword function to check for filenames
		    update_word_count( &head[index], filename);
		    flag = 0;
		}
		temp=temp->link;
	    }
    	}

	if (flag == 1)
	{
	    insert_at_last( &head[index], word);
	}
    }

    printf("Successful : creation of database for %s\n", filename);

}

int insert_at_last(Wlist **head, data_t *data)
{
    //create a node
    Wlist *new = malloc(sizeof(Wlist));
    if ( new == NULL )
    {
	return FAILURE;
    }
    //update the word and link

    new->file_count =1;
    strcpy(new->word, data);
    new->link = NULL;
    
    //Update link_table
    update_link_table(&new);

    if( *head == NULL )
    {
	*head = new;
	return SUCCESS;
    }

    Wlist *temp = *head;
    
    //If not Null, traverse through the list to add at last
    while (temp->link != NULL )
    {
	temp = temp->link;
    }
    temp->link = new;

    return SUCCESS;

}

int  update_link_table(Wlist **head)
{
    Ltable *Tnew = malloc(sizeof(Ltable));
    if (Tnew == NULL )
    {
	return FAILURE;
    }

    //update the word count
    Tnew->word_count = 1;
    strcpy ( Tnew->file_name, f_name );
    Tnew->table_link = NULL;

    (*head) ->Tlink = Tnew;
    return SUCCESS;
}

int update_word_count(Wlist ** head, char * file_name)
{
    //create a local reference for Tlink

    Ltable *Ttemp =  (*head)->Tlink;
    Ltable *prev = (*head)->Tlink; 

    //Compare the filenames, if filename matches increment the word count
    
    while ( Ttemp != NULL )
    {
	if (strcmp ( Ttemp->file_name, file_name ) == 0 )
	{
	    Ttemp->word_count += 1;
	    return SUCCESS;
	}
	prev = Ttemp;
	Ttemp = Ttemp->table_link;
    }

    //If Filename not matches, create a link table and update word count and file name

    Ltable *Tnew = malloc(sizeof(Ltable));
    if (Tnew == NULL )
    {
	return FAILURE;
    }
    Tnew->word_count = 1;
    strcpy (Tnew->file_name, file_name );
    Tnew->table_link = NULL;

    prev->table_link = Tnew;

    //Also increment filecount in wlist
    (*head)->file_count +=1;

    return SUCCESS;


}


