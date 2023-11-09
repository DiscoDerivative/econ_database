#include <stdio.h>
#include <stdlib.h>
#include "exchange_rates.h"

int printExchangeRates(void)
{
    FILE *file;
    file = fopen("exchange_rates.txt", "r");

    // Checks if the file exists
    if (file == NULL)
    {
        printf("File does not exist.");
        fclose(file);
        return 1;
    }

    else
    {
        // Stores the content of the file with dynamic memory allocation
        char *content = calloc(100, sizeof(char));

        // Reads out the content of the file
        while(fgets(content, 100, file))
        {
            printf("%s", content);
        }

        // Freeing the memory stored in heap to avoid memory leak
        free(content);

        // Closing the file
        fclose(file);
        return 0;
    }
}