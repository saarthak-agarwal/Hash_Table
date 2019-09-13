#include<stdio.h>
#include<string.h>
#include"Hash_map_server.c"

void main()
{
	int choice, key, value, n, c;
	char usn[20];
	char pass[20];
	do {
		printf("\n Implementation of Hash Table in C \n\n");
		printf("MENU-:  \n1.Login" 
                               "\n2.Sign up"
			       "\n3.Exit"
		       "\n\nPlease enter your choice -:");
 
		scanf("%d", &choice);
 
		switch(choice) 
        {
 
			case 1:sign_in();
				break;
	 
			case 2:sign_up();
				break;
			
			case 3:break;
	 
			default:printf("\nInvalid choice\nPlease try again...\n");
					break;
				
 
		}
 
	}
	while(choice != 3);

}		
