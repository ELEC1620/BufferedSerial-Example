/*  BufferedSerial-Example
*   This example uses the .write method of the BufferedSerial class to output characters via serial.
*   
*   The code should be modified in accordance with the Serial Communication Activities. 
*
*   Board: NUCLEO L476RG
*   Author: James Chandler 2021
*/

#include "mbed.h"

BufferedSerial pc(USBTX, USBRX);        //establish serial communications between PC and NUCLEO

//create a char array called instruct and store the message within it
char INSTRUCT[] = "This example writes ASCII characters via the BufferedSerial.write method.\n" ; //Initial instruction to print via the BufferedSerial.write method

#define WAIT_TIME_MS 500 
DigitalOut led1(PC_0);

int main()
{
    char ASCII_char = 'A';                      //Define char using character representation
    char ASCII_num = 0x5A;                      //Define char using numeric representation (0x5A == 'Z')
    char VAL1[2] = {ASCII_char, ASCII_num};     //Add the charaters to the 2 element array
           
    pc.write(INSTRUCT, sizeof(INSTRUCT));       //print instructions to terminal
    thread_sleep_for(1000);                     //Delay before staring the loop

    while (true)
    {
        pc.write(VAL1, sizeof(VAL1));           //write the char values stored in VAL1
        led1 = !led1;                           //Toggle the LED on PC_0 to show loop is active
        
        thread_sleep_for(WAIT_TIME_MS);         //Wait between sending messages     
    }
}
