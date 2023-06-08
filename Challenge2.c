#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct my_date_t {
    uint8_t date;   /**< date */
    uint8_t month;  /**< month */
    uint16_t year;  /**< year */
} my_date_t;

typedef enum status_t {
    SUCCESS,    /**< Function has successfully converted the string to structure */
    NULL_PTR,   /**< Function is given NULL pointers to work with */
    INCORRECT   /**< Incorrect values for date or month or year */
} status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date) {
    if (input_string == NULL || result_date == NULL) {
        return NULL_PTR;
    }
    
    // Extracting date, month, and year from input string
    char* token;
    token = strtok(input_string, "/");
    
    if (token == NULL) {
        return INCORRECT;
    }
    result_date->date = atoi(token);
    
    token = strtok(NULL, "/");
    
    if (token == NULL) {
        return INCORRECT;
    }
    result_date->month = atoi(token);
    
    token = strtok(NULL, "/");
    
    if (token == NULL) {
        return INCORRECT;
    }
    result_date->year = atoi(token);
    
    // Performing additional validation on the values
    if (result_date->date < 1 || result_date->date > 31 ||
        result_date->month < 1 || result_date->month > 12 ||
        result_date->year < 0) {
        return INCORRECT;
    }
    
    return SUCCESS;
}

int main() {
    // Example usage of string_to_date_converter function
    
    char input_string[] = "20/06/2023";
    my_date_t result_date;
    
    status_t conversion_status = string_to_date_converter(input_string, &result_date);
    
    if (conversion_status == SUCCESS) {
        printf("Date converted successfully: %02d/%02d/%04d\n", result_date.date, result_date.month, result_date.year);
    } else if (conversion_status == NULL_PTR) {
        printf("NULL pointers provided.\n");
    } else if (conversion_status == INCORRECT) {
        printf("Incorrect date format or values.\n");
    }
    
    return 0;
}
