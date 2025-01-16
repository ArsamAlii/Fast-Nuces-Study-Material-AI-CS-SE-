#include <stdio.h>
#include <string.h>



int video_editing() {
    FILE *fptr = NULL;
    char ch;

    fptr = fopen("videoedit.txt", "r");

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
int budget;
    // if PC = 1
    if (option1 == 1) {
    	budget = 0;
        budget += 197000;
        char model_string[100] = "Acer Aspire TC-895-UA92";
        char pro_string[100] = "Intel Core i5-10400";
        char ram_string[100] = "16GB DDR4";
        char storage_string[100] = "512GB SSD";
        char gpu_string[100] = "GTX 1660Ti";

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
            printf("\n1. Ryzen 5 7600X (+Rs. 7800)");
            printf("\n2. Core i7-10900K (+Rs. 6700)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. Core i5-8200 (-Rs. 6600)");
            printf("\n4. Ryzen 5 2200U (-Rs. 5300)");

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
                strcpy(pro_string, "Ryzen 5 7600X");
                budget += 7800;
            } else if (option3 == 2) {
                strcpy(pro_string, "Core i7-10900K");
                budget += 6700;
            } else if (option3 == 3) {
                strcpy(pro_string, "i5-8200");
                budget -= 6600;
            } else {
                strcpy(pro_string, "Ryzen 5 2200U ");
                budget -= 5300;
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
            printf("\n1. 32GB DDR4 (+Rs. 6900)");
            printf("\n2. 16GB DDR5 (+Rs. 8500)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 4GB DDR4 (-Rs. 7600)");
            printf("\n4. 8GB DDR4 (-Rs. 5400)");

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
                budget += 6900;
            } else if (option5 == 2) {
                strcpy(ram_string, "16GB DDR5");
                budget += 8500;
            } else if (option5 == 3) {
                strcpy(ram_string, "4GB DDR3");
                budget -= 7600;
            } else {
                strcpy(ram_string, "8GB DDR4");
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
            printf("\n1. 512GB NVME SSD (+Rs. 9300)");
            printf("\n2. 1TB SSD (+Rs. 7600)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 128GB SSD (-Rs. 4000)");
            printf("\n4. 256GB SDD (-Rs. 3300)");

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
                strcpy(storage_string, "512GB NVME SSD");
                budget += 9300;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB SSD");
                budget += 7600;
            } else if (option7 == 3) {
                strcpy(storage_string, "128GB SSD");
                budget -= 4000;
            } else {
                strcpy(storage_string, "256GB SDD");
                budget -= 3300;
            }
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card: ");
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
            printf("\n1. GTX 2060 (+Rs. 11000)");
            printf("\n2. GTX 1080Ti (+Rs. 12000)");
            printf("\n==========DOWNGRADE==========");
            printf("\n3. GTX 1650 (-Rs. 5000)");
            printf("\n4. GTX 1070Ti (-Rs. 8800)");

            printf("\nChoose your option: ");
            scanf("%d", &option9);

            while (1) {
                if (option9 < 1 || option9 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option9);
                } else {
                    break;
                }
            }

            if (option9 == 1) {
                strcpy(gpu_string, "GTX 2060");
                budget += 11000;
            } else if (option9 == 2) {
                strcpy(gpu_string, "GTX 1080Ti");
                budget += 12000;
            } else if (option9 == 3) {
                strcpy(gpu_string, "GTX 1650");
                budget -= 5000;
            } else {
                strcpy(gpu_string, "GTX 1070Ti");
                budget -= 8800;
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


        budget += 253000;
        char model_string[100] = "Dell Inspiron 3880";
        char pro_string[100] = "Intel Core i5-11400";
        char ram_string[100] = "16GB DDR4";
        char storage_string[100] = "512GB NVMe SSD";
        char gpu_string[100] = "RX 5700XT";

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
            printf("\n1. Intel Core i5-12700K (+Rs. 8900)");
            printf("\n2. AMD Ryzen 7 5500U (+Rs. 11000)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. Ryzen 5 4700X (-Rs. 4900)");
            printf("\n4. Core i3-10700K (-Rs. 8300)");

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
                strcpy(pro_string, "Intel Core i5-12700K ");
                budget += 8900;
            } else if (option3 == 2) {
                strcpy(pro_string, "AMD Ryzen 7 5500U");
                budget += 11000;
            } else if (option3 == 3) {
                strcpy(pro_string, " Ryzen 5 4700X");
                budget -= 4900;
            } else {
                strcpy(pro_string, "Core i3-10700K");
                budget -= 8300;
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
            printf("\n1. 32GB DDR4 (+Rs. 8900)");
            printf("\n2. 16GB DDR5 (+Rs. 9400)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 8GB DDR4 (-Rs. 4400)");
            printf("\n4. 4GB DDR4 (-Rs. 6400)");

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
                budget += 8900;
            } else if (option5 == 2) {
                strcpy(ram_string, "16GB DDR5");
                budget += 9400;
            } else if (option5 == 3) {
                strcpy(ram_string, "8GB DDR4");
                budget -= 4400;
            } else {
                strcpy(ram_string, "4GB DDR4");
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
            printf("\n1. 2TB NVME SSD (+Rs. 12000)");
            printf("\n2. 1TB NVME SSD (+Rs. 8000)");

            printf("\n\n==========Downgrade==========");
            printf("\n3. 256GB NVME SSD (-Rs. 4400)");
            printf("\n4. 128GB NVME SSD (-Rs. 5800)");

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
                strcpy(storage_string, "2TB NVME SSD");
                budget += 12000;
            } else if (option7 == 2) {
                strcpy(storage_string, "1TB NVMESSD");
                budget += 8000;
            } else if (option7 == 3) {
                strcpy(storage_string, "128GB SSD");
                budget -= 4400;
            } else {
                strcpy(storage_string, "512GB HDD");
                budget -= 5800;
            }
        }

        // GPU Upgrade or downgrade
        int option8;

        printf("\nDo you want to upgrade your Graphics Card: ");
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
            printf("\n1. GTX 3060Ti (+Rs. 23000)");
            printf("\n2. AMD RX 6700XT (+Rs. 44000)");
            printf("\n==========DOWNGRADE==========");
            printf("\n3. AMD RX 5600XT (-Rs. 9800)");
            printf("\n4. GTX 2060 (-Rs. 12000)");

            printf("\nChoose your option: ");
            scanf("%d", &option9);

            while (1) {
                if (option9 < 1 || option9 > 4) {
                    printf("Invalid option. Choose again: ");
                    scanf("%d", &option9);
                } else {
                    break;
                }
            }

            if (option9 == 1) {
                strcpy(gpu_string, "GTX 3060Ti");
                budget += 23000;
            } else if (option9 == 2) {
                strcpy(gpu_string, "AMD RX 6700XT");
                budget += 44000;
            } else if (option9 == 3) {
                strcpy(gpu_string, "AMD RX 5600XT");
                budget -= 9800;
            } else {
                strcpy(gpu_string, "GTX 2060");
                budget -= 12000;
            }
        }

        printf("\n\nFinal Budget: Rs. %d\n", budget);
        printf("PC Specifications:\n");
        printf("Model: %s\n", model_string);
        printf("Processor: %s\n", pro_string);
        printf("RAM: %s\n", ram_string);
        printf("Storage: %s\n", storage_string);
        printf("GPU: %s\n", gpu_string);
    }

    return 0;
}



