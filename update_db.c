#include "inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //prompt the user to enter the file name
    char file_name[FNAME_SIZE];

    printf("Enter the file name\n");
    scanf("%s" , file_name);

    //validate the file_name
    int empty = isFileEmpty(file_name);
    if ( empty == FILE_NOTAVAILABLE )
    {
	printf("File : %s is not available\n", file_name);
	printf("Hence we are not adding this file into file list\n");
    }
    else if ( empty == FILE_EMPTY )
    {
	printf("File : %s is Empty\n", file_name);
	printf("Hence we are not adding this file into file list\n");
    }
    else
    {
	int ret_val=  to_create_list_of_files(f_head, file_name );
	if ( ret_val == SUCCESS)
	{
	    read_datafile(head,file_name);
//	    printf("Succesfully : Inserting the file name : %s into the file linkedlist \n",file_name);
	}
	else if ( ret_val == REPEATATION )
	{
	    printf("This file name : %s is repeated . Do not add more than once\n", file_name );
	}
	else
	{
	    printf("Failure....\n");
	}
    }
    return;
}

