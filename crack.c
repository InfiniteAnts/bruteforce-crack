#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define STRTRMNTR 0
#define ENDLOOP 123
#define SKP1 1
#define TOSMLA 97
#define SKP2 91
#define TOA 65


// error if more or less than 1 command line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error.\n");
        return 1;
    }
    
    // command line argument string validity check
    if (argv[1] != NULL)
    {
        char salt[3];
        
        // Acquiring salt. salt is the first 2 characters of the hashed password.(salt = '50' for pset2)
        for (int i = 0; i < 2 ; i++)
        {
            salt[i] = argv[1][i];
        }
        
        // initialising plaintext
        char plaintext[5] = {STRTRMNTR, STRTRMNTR, STRTRMNTR, STRTRMNTR, STRTRMNTR};
        
        // Four identical nested loops for each element in the string which will cycle through each and every permutation of A-Z,a-z,\0.
        // Have to improve this section of the code. Find a replacement for the nested loops.
        for (plaintext[0] = 65; plaintext[0] < ENDLOOP; plaintext[0]++)
        {

            // To make the loop skip ahead to 'a' after 'A'
            if (plaintext[0] == SKP2)
            {
                plaintext[0] = TOSMLA;
            }
            
            for (plaintext[1] = STRTRMNTR; plaintext[1] < ENDLOOP; plaintext[1]++)
            {
                
                if (plaintext[1] == SKP1)
                {
                    plaintext[1] = TOA;
                }
                
                
                if (plaintext[1] == SKP2)
                {
                    plaintext[1] = TOSMLA;
                }
                    
                for (plaintext[2] = STRTRMNTR; plaintext[2] < ENDLOOP; plaintext[2]++)
                {
                    if (plaintext[2] == SKP1)
                    {
                        plaintext[2] = TOA;
                    }
                    
                    if (plaintext[2] == SKP2)
                    {
                        plaintext[2] = TOSMLA;
                    }
                    
                    for (plaintext[3] = STRTRMNTR; plaintext[3] < ENDLOOP; plaintext[3]++)
                    {
                        if (plaintext[3] == SKP1)
                        {
                            plaintext[3] = TOA;
                        }
                        
                        if (plaintext[3] == SKP2)
                        {
                            plaintext[3] = TOSMLA;
                        }
                        
                        // Using crypt function to encrypt the plaintext every iteration
                        string encrypted = crypt(plaintext, salt);
                        
                        // comparing the encrypted string with the hashed password every iteration by using the strcmp function
                        
                        // if the encrypted string is the same as the hashed password, success!
                        if (strcmp(encrypted, argv[1]) == 0)
                        {
                            printf("%s\n", plaintext);
                            return 0;
                            
                        }
                    }
                }
            }
        }
    }    
}
