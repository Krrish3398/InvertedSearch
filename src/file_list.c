#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i=1, empty;
    while ( argv[i] != NULL )
    {
       	empty = isFileEmpty(argv[i] );
	if ( empty == FILE_NOTAVAILABLE )
	{
	    printf("File : %s is not available\n", argv[i]);
	    printf("Hence we are not adding this file into file list\n");
	    i++;
	    continue;
	}
	else if ( empty == FILE_EMPTY )
	{

	    printf("File : %s is Empty\n", argv[i]);
	    printf("Hence we are not adding this file into file list\n");
	    i++;
	    continue;
	}
	else
	{
	   int ret_val=  to_create_list_of_files(f_head, argv[i] );
	   if ( ret_val == SUCCESS)
	   {
	       printf("Succesfully : Inserting the file name : %s into the file linkedlist \n",argv[i] );
	   }
	   else if ( ret_val == REPEATATION )
	   {
	       printf("This file name : %s is repeated . Do not add more than once\n", argv[i] );
	   }
	   else
	   {
	       printf("Failure......\n");
	   }
	   i++;
	}

    }
}
int isFileEmpty(char *filename)
{
    //Check if file exists or not
    FILE *fptr = fopen(filename, "r");
    if ( fptr == NULL )
    {
	if( errno == ENOENT )
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    //check file contains contents or not

    fseek(fptr, 0, SEEK_END );
    if (ftell(fptr) == 0 )
    {
	return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //Check files are repeated or not and if not repeated add the file name into the list
    
    Flist *new = malloc( sizeof(Flist));
    if ( new == NULL )
    {
	return FAILURE;
    }
    strcpy ( new->file_name, name );
    new ->link = NULL;

    Flist *temp = *f_head;
    Flist *prev = *f_head;

    if ( *f_head == NULL )
    {
	*f_head = new;
	return SUCCESS;
    }

    while ( temp != NULL  )
    {
	if ( strcmp (temp->file_name, name ) == 0 )
	{
	    return REPEATATION;
	}
	else
	{
	    prev = temp;
	    temp = temp->link;
	}
    }

    prev->link = new;
    
    return SUCCESS;
}

    
   





