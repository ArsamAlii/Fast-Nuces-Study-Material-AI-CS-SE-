#include <stdio.h>
#include <string.h>



int programming() {
    FILE *fptr = NULL;
    char ch;

    fptr = fopen("Programming.txt", "r");

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
    scanf("%d", &option1);

    while (1) {
        if (option1 < 1 || option1 > 5) {
            printf("Invalid option. Choose again: ");
            scanf("%d", &option1);
        } else {
            break;
        }
    }
	int budget = 0;
    // if PC = 1
    if (option1 == 1) {
        budget += 112000;
        char model_string[100] = "Acer Aspire TC-895-UA92";
        char pro_string[100] = "Intel Core i3-10100";
        char ram_string[100] = "8GB DDR4";
        char storage_string[100] = "256GB SSD";
        char gpu_string[100] = "Integrated Intel UHD Graphics 630";

        // Processor upgrade or downgrade
        int option2;

        printf("\nDo you want to upgrade or degrade your processor: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option2);

        while (1) {
            if (option2 < 1 || option2 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option2);
            } else {
                break;
            }
        }

        if (option2 == 1) {
            int option3;

            printf("\n==========Upgrade==========");
            printf("\n1. Intel Core i5 (+Rs. 4500)");
            printf("\n2. Intel Core i7 (+Rs. 8800)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. Intel Core i3-4300K (-Rs. 4500)");
            printf("\n4. Intel Core i3-5400K (-Rs. 4200)");

            printf("\nChoose your option: ");
            scanf("%d", &option3);

            while (1) {
                if (option3 < 1 || option3 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option3);
                } else {
                    break;
                }
            }

            if (option3 == 1) {
                strcpy(pro_string, "Intel Core i5");
                budget += 4500;
            } else if (option3 == 2) {
                strcpy(pro_string, "Intel Core i7");
                budget += 8800;
            } else if (option3 == 3) {
                strcpy(pro_string, "Intel Core i3-4300K");
                budget -= 4500;
            } else {
                strcpy(pro_string, "Intel Core i3-5400K ");
                budget -= 4200;
            }
        }

        // RAM upgrade or downgrade
        int option4;

        printf("\nDo you want to upgrade or degrade your RAM: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option4);

        while (1) {
            if (option4 < 1 || option4 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option4);
            } else {
                break;
            }
        }

        if (option4 == 1) {
            int option5;

            printf("\n==========Upgrade==========");
            printf("\n1. 32GB DDR4 (+Rs. 8200)");
            printf("\n2. 16GB DDR4 (+Rs. 5400)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 16GB DDR3 (-Rs. 4400)");
            printf("\n4. 8GB DDR3 (-Rs. 6400)");

            printf("\nChoose your option: ");
            scanf("%d", &option5);

            while (1) {
                if (option5 < 1 || option5 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option5);
                } else {
                    break;
                }
            }

            if (option5 == 1) {
                strcpy(ram_string, "32GB DDR4");
                budget += 8200;
            } else if (option5 == 2) {
                strcpy(ram_string, "16GB DDR4");
                budget += 5400;
            } else if (option5 == 3) {
                strcpy(ram_string, "16GB DDR3");
                budget -= 4400;
            } else {
                strcpy(ram_string, "8GB DDR3");
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

        while (1) {
            if (option6 < 1 || option6 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option6);
            } else {
                break;
            }
        }

        if (option6 == 1) {
            int option7;

            printf("\n==========Upgrade==========");
            printf("\n1. 512GB SSD (+Rs. 5000)");
            printf("\n2. 1TB SSD (+Rs. 6600)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 128GB SSD (-Rs. 2000)");
            printf("\n4. 512GB HDD (-Rs. 5000)");
            

            printf("\nChoose your option: ");
            scanf("%d", &option7);

            while (1) {
                if (option7 < 1 || option7 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option7);
                } else {
                    break;
                }
            }

            if (option7 == 1) {
                strcpy(storage_string, "512GB SSD ");
                budget += 5000;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB SSD");
                budget += 6600;
            } else if(option7 == 3) {
                strcpy(storage_string, "128GB SSD");
                budget -= 2000;
            } else{
            	strcpy(storage_string, "512GB HDD");
                budget -= 5000;
			}
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card (downgrade is not recommended if your use is related to programming): ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option8);

        while (1) {
            if (option8 < 1 || option8 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option8);
            } else {
                break;
            }
        }

        if (option8 == 1) {
            int option9;

            printf("\n==========Upgrade==========");
            printf("\n1. GTX 760Ti (+Rs. 7500)");
            printf("\n2. AMD RX 560 8GB (+Rs. 5500)");
            printf("\n==========DOWNGRADE==========");
            

            while (1) {
                if (option9 < 1 || option9 > 2) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option9);
                } else {
                    break;
                }
            }

            if (option9 == 1) {
                strcpy(gpu_string, "GTX 760Ti");
                budget += 7500;
            } else if (option9 == 2) {
                strcpy(gpu_string, "AMD RX 560 8GB ");
                budget += 5500;
        }

        printf("\n\nFinal Budget: Rs. %d\n", budget);
        printf("PC Specifications:\n");
        printf("Model: %s\n", model_string);
        printf("Processor: %s\n", pro_string);
        printf("RAM: %s\n", ram_string);
        printf("Storage: %s\n", storage_string);
        printf("GPU: %s\n", gpu_string);
    }
    
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    // if PC = 2
    if (option1 == 1) {
        budget += 190000;
        char model_string[100] = "Lenovo IdeaCentre 3";
        char pro_string[100] = "AMD Ryzen 5 3400G";
        char ram_string[100] = "12GB DDR4";
        char storage_string[100] = "512GB SSD";
        char gpu_string[100] = "Integrated AMD Radeon RX Vega 11";

        // Processor upgrade or downgrade
        int option2;

        printf("\nDo you want to upgrade or degrade your processor: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option2);

        while (1) {
            if (option2 < 1 || option2 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option2);
            } else {
                break;
            }
        }

        if (option2 == 1) {
            int option3;

            printf("\n==========Upgrade==========");
            printf("\n1. Intel Core i5-10700K (+Rs. 6700)");
            printf("\n2. Ryzen 5-5500U (+Rs. 6000)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. Intel Core i5-5400K (-Rs. 4500)");
            printf("\n4. Intel Core i5-6700K (-Rs. 4200)");

            printf("\nChoose your option: ");
            scanf("%d", &option3);

            while (1) {
                if (option3 < 1 || option3 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option3);
                } else {
                    break;
                }
            }

            if (option3 == 1) {
                strcpy(pro_string, "Intel Core i5-10700K");
                budget += 6700;
            } else if (option3 == 2) {
                strcpy(pro_string, "Ryzen 5-5500U");
                budget += 6000;
            } else if (option3 == 3) {
                strcpy(pro_string, "Intel Core i5-5400K");
                budget -= 4500;
            } else {
                strcpy(pro_string, "Intel Core i5-6700K");
                budget -= 4200;
            }
        }

        // RAM upgrade or downgrade
        int option4;

        printf("\nDo you want to upgrade or degrade your RAM: ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option4);

        while (1) {
            if (option4 < 1 || option4 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option4);
            } else {
                break;
            }
        }

        if (option4 == 1) {
            int option5;

            printf("\n==========Upgrade==========");
            printf("\n1. 32GB DDR4 (+Rs. 8200)");
            printf("\n2. 64GB DDR4 (+Rs. 11000)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 16GB DDR3 (-Rs. 4400)");
            printf("\n4. 8GB DDR3 (-Rs. 6400)");

            printf("\nChoose your option: ");
            scanf("%d", &option5);

            while (1) {
                if (option5 < 1 || option5 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option5);
                } else {
                    break;
                }
            }

            if (option5 == 1) {
                strcpy(ram_string, "32GB DDR4");
                budget += 8200;
            } else if (option5 == 2) {
                strcpy(ram_string, "64GB DDR4");
                budget += 11000;
            } else if (option5 == 3) {
                strcpy(ram_string, "16GB DDR3");
                budget -= 4400;
            } else {
                strcpy(ram_string, "8GB DDR3");
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

        while (1) {
            if (option6 < 1 || option6 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option6);
            } else {
                break;
            }
        }

        if (option6 == 1) {
            int option7;

            printf("\n==========Upgrade==========");
            printf("\n1. 2TB SSD (+Rs. 8000)");
            printf("\n2. 1TB SSD (+Rs. 6600)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 128GB SSD (-Rs. 2000)");
            printf("\n4. 256GB SSD (-Rs. 3500)");

            printf("\nChoose your option: ");
            scanf("%d", &option7);

            while (1) {
                if (option7 < 1 || option7 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option7);
                } else {
                    break;
                }
            }

            if (option7 == 1) {
                strcpy(storage_string, "2TB SSD  ");
                budget += 8000;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB SSD");
                budget += 6600;
            } else if(option7 == 3) {
                strcpy(storage_string, "128GB SSD");
                budget -= 2000;
            }  else {
                strcpy(storage_string, "256 SSD");
                budget -= 3500;
            } 
            
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card (downgrade is not recommended if your use is related to programming): ");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoose your option: ");
        scanf("%d", &option8);

        while (1) {
            if (option8 < 1 || option8 > 2) {
                printf("Invalid option. Choose again: ");
                scanf("%d", &option8);
            } else {
                break;
            }
        }

        if (option8 == 1) {
            int option9;

            printf("\n==========Upgrade==========");
            printf("\n1. GTX 1060Ti (+Rs. 8000)");
            printf("\n2. AMD RX 560 8GB (+Rs. 5500)");
            printf("\n Downgrade Not possible as does not comes with graphic card");
            

            while (1) {
                if (option9 < 1 || option9 > 2) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option9);
                } else {
                    break;
                }
            }

            if (option9 == 1) {
                strcpy(gpu_string, "GTX 1060Ti");
                budget += 8000;
            } else if (option9 == 2) {
                strcpy(gpu_string, "AMD RX 560 8GB ");
                budget += 5500;
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
    
}
    
    
    

    return 0;
}
}



