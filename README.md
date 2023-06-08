# C_Challenges

# Challenge 1: Data Packet Corruption Detection

In a Wireless communciation device, multiple data packets are transferred over the air.
It is possible that data might get corrupted or lost before it reaches the destination.
Create a method to identify if a data packet is corrupted
Assume below format for the data packet
#define MAX_PACKET_DATA_LENGTH (50)

`````
typedef struct data_packet_t{
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;
}data_packet_t;

```````
# Challenge 2: Date String to Structure conversion

* In a application, the date is stored as a string and for computations, converting the string to number is required.
* Write a function to convert the string formated date to a structure as per the below code
* Return appropriate error values if the conversion is not successful

## Inptu string format
```
    DD/MM/YYYY
```

## Output Structure format
```
typedef struct my_date_t
{
    uint8_t date;       /*<<< date */
    uint8_t month;      /*<<< month */
    uint16_t year;      /*<<< year   */
}my_date_t;
```

### Conversion status 
```
typedef enum status_t
{
    SUCCESS,                    /**< Function has successfully converted the string to structure */
    NULL_PTR,                   /**< Function is given NULL pointers to work with */
    INCORRECT                   /**< Incorrect values for date or month or year */
}status_t;

```

### Function prototype
```
/**
 * @brief Function to convert string of the format DD/MM/YYYY to my_date_t structure
 * 
 * @param input_string String which needs to be converted
 * @param result_time Resultant structure to hold the converted string
 * @return status_t SUCCESS if conversion is done, status_t code otherwise.
 */
status_t string_to_date_converter(char* input_string, my_date_t* result_date);
```
