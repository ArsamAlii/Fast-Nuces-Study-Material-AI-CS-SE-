#include <stdio.h>
#include <string.h>

int budget = 0;

int general_productivity() {
    FILE *fptr = NULL;
    char ch;

    fptr = fopen("General_productivity.txt", "r");

    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }

    fclose(fptr);

    // Choosing a PC
    int option1;
    printf("\nChoose an option: ");
    scanf("%d",&option1);

while(1)
	{
		if(option1 < 1 || option1 > 5)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option1);
		}
		
		else
		{
			break;
		}
	}


    // if PC = 1
    if (option1 == 1) {
        budget += 98700;
        char model_string[100] = "HP Slim Desktop S01-pF1046b";
        char pro_string[100] = "AMD Athlon Silver 3050U";
        char ram_string[100] = "4GB DDR4";
        char storage_string[100] = "256GB SSD";
        char gpu_string[100] = "Integrated AMD Radeon Graphics";

        // Processor upgrade or downgrade
        int option2;

        printf("\nDo you want to upgrade or degrade your processor: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option2);



while(1)
	{
		if(option2 < 1 || option2 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option2);
		}
		
		else
		{
			break;
		}
	}



        if (option2 == 1) {
            int option3;

            printf("\n==========Upgrade==========");
            printf("\n1. AMD Athlon 4500U (+Rs. 3300)");
            printf("\n2. AMD Athlon 4700 (+Rs. 5600)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. AMD Athlon 2500U (-Rs. 2200)");
            printf("\n4. AMD Athlon 2000 (-Rs. 4400)");

            printf("\nChoose your option: ");
            scanf("%d", &option3);

            
			while(1)
	{
		if(option3 < 1 || option3 > 4)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option3);
		}
		
		else
		{
			break;
		}
	}
			
			

            if (option3 == 1) {
                strcpy(pro_string, "AMD Athlon 4500U");
                budget += 3300;
            } else if (option3 == 2) {
                strcpy(pro_string, "AMD Athlon 4700");
                budget += 5600;
            } else if (option3 == 3) {
                strcpy(pro_string, "AMD Athlon 2500U");
                budget -= 2200;
            } else {
                strcpy(pro_string, "AMD Athlon 2000");
                budget -= 4400;
            }
        }

        // RAM upgrade or downgrade
        int option4;

        printf("\nDo you want to upgrade or degrade your RAM: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option4);

       while(1)
	{
		if(option4 < 1 || option4 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option4);
		}
		
		else
		{
			break;
		}
	}
	   
	   

        if (option4 == 1) {
            int option5;

            printf("\n==========Upgrade==========");
            printf("\n1. 8GB DDR4 (+Rs. 2200)");
            printf("\n2. 16GB DDR4 (+Rs. 4400)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 8GB DDR3 (-Rs. 4400)");
            printf("\n4. 4GB DDR3 (-Rs. 6400)");

            printf("\nChoose your option: ");
            scanf("%d", &option5);

            while (option5 < 1 || option5 > 4) {
                printf("\nInvalid option.Choose again: ");
                scanf("%d", &option5);
            }

            if (option5 == 1) {
                strcpy(ram_string, "8GB DDR4");
                budget += 2200;
            } else if (option5 == 2) {
                strcpy(ram_string, "16GB DDR4");
                budget += 4400;
            } else if (option5 == 3) {
                strcpy(ram_string, "8GB DDR3");
                budget -= 4400;
            } else {
                strcpy(ram_string, "4GB DDR3");
                budget -= 6400;
            }
        }

        // Storage Upgrade or downgrade
        
        int option6;

        printf("\nDo you want to upgrade or downgrade your storage: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option6);

        while(1)
	{
		if(option6 < 1 || option6 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option6);
		}
		
		else
		{
			break;
		}
	}
	
        if (option6 == 1) {
            int option7;

            printf("\n==========Upgrade==========");
            printf("\n1. 512GB SSD (+Rs. 3400)");
            printf("\n2. 1TB SSD (+Rs. 6600)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 128GB SSD (-Rs. 2000)");
            printf("\n4. 512GB HDD (-Rs. 3400)");

            printf("\nChoose your option: ");
            scanf("%d", &option7);

            while(1)
	{
		if(option7 < 1 || option7 > 4)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option7);
		}
		
		else
		{
			break;
		}
	}
			
            if (option7 == 1) {
                strcpy(storage_string, "512GB SSD");
                budget += 3400;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB SSD");
                budget += 6600;
            } else if (option7 == 3) {
                strcpy(storage_string, "128GB SSD");
                budget -= 2000;
            } else {
                strcpy(storage_string, "512GB HDD");
                budget -= 3400;
            }
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card (downgrade not possible as no GPU present currently): ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option8);

     
	 while(1)
	{
		if(option8 < 1 || option8 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option8);
		}
		
		else
		{
			break;
		}
	}

        if (option8 == 1) {
            int option9;

            printf("\n==========Upgrade==========");
            printf("\n1. GTX 760 (+Rs. 11000)");
            printf("\n2. RX Vega 8 (+Rs. 8900)");

            printf("\nChoose your option: ");
            scanf("%d", &option9);

          
	while(1)
	{
		if(option9 < 1 || option9 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option9);
		}
		
		else
		{
			break;
		}
	}	  


            if (option9 == 1) {
                strcpy(gpu_string, "GTX 760");
                budget += 11000;
            } else {
                strcpy(gpu_string, "RX Vega 8");
                budget += 8900;
            }
        }

        printf("\n\nFinal Budget: Rs. %d\n", budget);
        printf("PC Specifications:\n");
        printf("Model: %s\n", model_string);
        printf("Processor: %s\n", pro_string);
        printf("RAM: %s\n", ram_string);
        printf("Storage: %s\n", storage_string);
        printf("GPU: %s\n", gpu_string);
        
        return 0;
    }

    



// if PC = 2
    if (option1 == 2) {
        budget += 141000;
        char model_string[100] = "Lenovo IdeaCentre 3";
        char pro_string[100] = "AMD Ryzen 3 3250U";
        char ram_string[100] = "8GB DDR4";
        char storage_string[100] = "1TB HDD";
        char gpu_string[100] = "Integrated AMD Radeon Graphics";

        // Processor upgrade or downgrade
        int option2;

        printf("\nDo you want to upgrade or degrade your processor: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option2);



while(1)
	{
		if(option2 < 1 || option2 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option2);
		}
		
		else
		{
			break;
		}
	}



        if (option2 == 1) {
            int option3;

            printf("\n==========Upgrade==========");
            printf("\n1. AMD Ryzen 5 2200U (+Rs. 3700)");
            printf("\n2. Intel Core i5 8700K (+Rs. 5800)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. AMD Ryzen 3 2200X (-Rs. 1200)");
            printf("\n4. Intel Core i3 6700K (-Rs. 1000)");

            printf("\nChoose your option: ");
            scanf("%d", &option3);

            
			while(1)
	{
		if(option3 < 1 || option3 > 4)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option3);
		}
		
		else
		{
			break;
		}
	}
			
			

            if (option3 == 1) {
                strcpy(pro_string, "AMD Ryzen 5 2200U");
                budget += 3700;
            } else if (option3 == 2) {
                strcpy(pro_string, "Intel Core i5 8700K");
                budget += 5800;
            } else if (option3 == 3) {
                strcpy(pro_string, "AMD Ryzen 3 2200X");
                budget -= 1200;
            } else {
                strcpy(pro_string, "Intel Core i3 6700K");
                budget -= 1000;
            }
        }

        // RAM upgrade or downgrade
        int option4;

        printf("\nDo you want to upgrade or degrade your RAM: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option4);

       while(1)
	{
		if(option4 < 1 || option4 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option4);
		}
		
		else
		{
			break;
		}
	}
	   
	   

        if (option4 == 1) {
            int option5;

            printf("\n==========Upgrade==========");
            printf("\n1. 32GB DDR4 (+Rs. 5800)");
            printf("\n2. 16GB DDR4 (+Rs. 1800)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 8GB DDR4 (-Rs. 4100)");
            printf("\n4. 4GB DDR4 (-Rs. 5400)");

            printf("\nChoose your option: ");
            scanf("%d", &option5);

            while (option5 < 1 || option5 > 4) {
                printf("\nInvalid option.Choose again: ");
                scanf("%d", &option5);
            }

            if (option5 == 1) {
                strcpy(ram_string, "32GB DDR4");
                budget += 5800;
            } else if (option5 == 2) {
                strcpy(ram_string, "16GB DDR4");
                budget += 1800;
            } else if (option5 == 3) {
                strcpy(ram_string, "8GB DDR4");
                budget -= 4100;
            } else {
                strcpy(ram_string, "4GB DDR4");
                budget -= 5400;
            }
        }

        // Storage Upgrade or downgrade
        
        int option6;

        printf("\nDo you want to upgrade or downgrade your storage: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option6);

        while(1)
	{
		if(option6 < 1 || option6 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option6);
		}
		
		else
		{
			break;
		}
	}
	
        if (option6 == 1) {
            int option7;

            printf("\n==========Upgrade==========");
            printf("\n1. 1TB SSD (+Rs. 5500)");
            printf("\n2. 1TB NVME SSD (+Rs. 10000)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 128GB SSD (-Rs. 3000)");
            printf("\n4. 256GB SSD (-Rs. 2200)");

            printf("\nChoose your option: ");
            scanf("%d", &option7);

            while(1)
	{
		if(option7 < 1 || option7 > 4)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option7);
		}
		
		else
		{
			break;
		}
	}
			
            if (option7 == 1) {
                strcpy(storage_string, "1TB SSD");
                budget += 5500;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB NVME SSD ");
                budget += 10000;
            } else if (option7 == 3) {
                strcpy(storage_string, "128GB SSD ");
                budget -= 3000;
            } else {
                strcpy(storage_string, "256GB SSD ");
                budget -= 2200;
            }
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card (downgrade not possible as no GPU present currently): ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option8);

     
	 while(1)
	{
		if(option8 < 1 || option8 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option8);
		}
		
		else
		{
			break;
		}
	}

        if (option8 == 1) {
            int option9;

            printf("\n==========Upgrade==========");
            printf("\n1. GTX 1070ti (+Rs. 34000)");
            printf("\n2. RX 560 4GB (+Rs. 27000)");

            printf("\nChoose your option: ");
            scanf("%d", &option9);

          
	while(1)
	{
		if(option9 < 1 || option9 > 2)
		{
			printf("Invalid option.Choose again: ");
			scanf("%d",&option9);
		}
		
		else
		{
			break;
		}
	}	  


            if (option9 == 1) {
                strcpy(gpu_string, "GTX 1070ti");
                budget += 34000;
            } else {
                strcpy(gpu_string, "RX 560 4GB");
                budget += 27000;
            }
        }

            printf("\n=============================");
    printf("\nFinal Budget: Rs. %d\n", budget);
    printf("=============================\n");
    printf("PC Specifications:\n");
    printf("=============================\n");
    printf("Model:      %s\n", model_string);
    printf("Processor:  %s\n", pro_string);
    printf("RAM:        %s\n", ram_string);
    printf("Storage:    %s\n", storage_string);
    printf("GPU:        %s\n", gpu_string);
    printf("=============================\n");
    }

    return 0;
}



