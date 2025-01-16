#include <stdio.h>
#include"general_productivity.h"
#include"gaming.h"
#include"programming.h"
#include"video_editing.h"






int main() {
	while(1)
	{

    printf("\n\n\n\n\n					==========================================\n");
    printf("						    Welcome to SpecSculpter          \n");
    printf("					==========================================\n\n");
    printf("					Build a PC according to your needs stress-free.\n\n\n");


    printf("-----Available user preferences-----\n");
    printf("1. General Productivity\n");
    printf("2. Programming\n");
    printf("3. Gaming\n");
    printf("4. Video Editing\n");
    printf("5. Exit\n");
	
	    int usage = 1;
	  printf("\nChoose your usage preference or exit the program: ");
    scanf("%d", &usage);
	    
	  while(1)
	{
		if(usage < 1 || usage > 5)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&usage);
		}
		
		else
		{
			break;
		}
	}  
	
	
	    switch (usage) 
		{
	        case 1:
	            general_productivity();
	            break;
	
	        case 2:
	            programming();
	            break;
	
	        case 3:
	            gaming();
	            break;
	
	        case 4:
	            video_editing();
	            break;
	        
	        case 5:
	        	return 0;
	            break;
	        
	    }
	    
	    
	}
}

