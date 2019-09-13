#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct user_details
{
	char name[100];
	char pass[100];
    	int age;
    	char gender;
	char location[100];
	struct user_details* next;
} ud;

int hash_func(char* a)
{
	int sum=0;
	for(int i=0;a[i]!='\0';i++)
	{
		sum=sum+a[i];			
	}
	int c = sum % 15;
	return c;
}


ud* heads[15]={NULL};

void read(ud* A)
{
	printf("Enter user name:");
	fflush(stdin);
    scanf("%[^\n]s",A->name);
	printf("Enter password:");
	fflush(stdin);
    scanf("%s",A->pass);
	printf("Enter age:");
    scanf("%d",&A->age);
	fflush(stdin);
	printf("Enter gender:");
	scanf("%c",&A->gender);
	printf("Enter location:");
	fflush(stdin);
	scanf("%s",A->location);
	
	A->next=NULL;
}	

int traverse_linked_list(ud* head, char* usn,char* pass)
{
	ud* node=head;
	while(node!=NULL)
	{
		if(strcmp(node->name,usn)==0 && strcmp(node->pass,pass)==0)
		return 1;
		else
		node=node->next;
	}
	return 0;
}
 	
ud* add_ele()
{
	ud* node=(ud*)malloc(sizeof(ud));
	read(node);
	node->next=NULL;	
	return node;
}

	
void disp(ud* head)
{
	ud* node=head;
	if(head==NULL)
	printf("\nList empty !\n");
	else
	{
		while(node!=NULL)
		{
			printf("\nUsername: %s\n",node->name);
			printf("Password: %s\n",node->pass);
			printf("Age: %d\n",node->age);
			printf("Gender: %c\n",node->gender);
			printf("Location: %s\n\n",node->location);	
			node=node->next;
		}
	
    }
	printf("\n");
}		
void linked_list(int ch, ud* head, int n)
{
	ud* node=head;
	ud* temp;
	switch(ch)
	{
		case 1:
			if(head==NULL)
			{
				heads[n]=add_ele();
				node=heads[n];
			}	
			else
			{
				temp=add_ele();
				node->next=temp;
				node=node->next;
			}				
			break;			
		case 2:	disp(head);
			break;
	
	}
}

void new_user(int n)
{
	linked_list(1,heads[n],n);
}

int password_validation(char *s)
{
	int sl=0,cl=0,n=0,i;
	for(i=0;s[i]!='\0';i++)
	{

		if(s[i]>='A' && s[i]<='Z')
			cl++;
		if(s[i]>='a' && s[i]<='z') 
			sl++;
		if(s[i]>='0' && s[i]<='9')	
		n++;
	}
	return (sl>0 && cl>0 && n>0 && i>=8)?1:0;				
}
	
void sign_up()
{
  char usn[100];
  char pass[100];
  printf("Enter a username:");
  fflush(stdin);
  scanf("%[^\n]s", usn);
  while(strlen(usn)>15)
  {
	printf("Username is invalid !\n");
	printf("Please try again\n");
	printf("Enter your Username-:");
	fflush(stdin);
    scanf("%[^\n]s", usn);
  }
  printf("Enter a password :");
  fflush(stdin);
  scanf("%[^\n]s",pass);
  int valid = password_validation(pass);
  while(valid!=1)
   {
       printf("Password invalid !\n");
       printf("Please try again\n");
       printf("Enter your Password\n");
       fflush(stdin);
       scanf("%[^\n]s", pass);	
       valid = password_validation(pass);
   }
  printf("Account created !\n");

  int n= hash_func(usn);
  new_user(n);
}

int pass_verification(char* usn, char* pass)
{
 int n= hash_func(usn);
 int found=traverse_linked_list(heads[n],usn,pass);
 return found;
}

void disp_complete_linked_list()
{
	ud* node;
	for(int i=0;i<15;i++)
	{
		if(heads[i]==NULL)
		printf("No user details at index %d\n",i);
		else{
		printf("Details stored at index: %d\n",i);
		disp(heads[i]);}
	}
}
			
int admin(char* usn,char* pass)
{
	if(strcmp("admin",usn)==0 && strcmp("admin",pass)==0)
	{
		disp_complete_linked_list();
		return 1;
	}
	return 0;
}

void sign_in()
{
  char usn[100];
  char pass[100];
  printf("Enter your Username-:");
  fflush(stdin);
  scanf("%[^\n]s", usn);
  printf("Enter a password :");
  fflush(stdin);
  scanf("%[^\n]s",pass); 
  
  if(!admin(usn,pass))
  {
  	int valid=pass_verification(usn,pass);
  	if(valid)
  	{
	  printf("Logged in!\n");
	  int n= hash_func(usn);
	  linked_list(2,heads[n],n);
    }
  else
  printf("Invalid password !");
 }

}




  	