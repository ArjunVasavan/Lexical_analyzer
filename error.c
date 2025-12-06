#include<stdio.h>
#include <ctype.h>
#include<string.h>

int interr(char word[] )
{

  if( isdigit( word[0] ) )
  {

    printf("Error : Number %c cant be added infront of identifier\n",word[0]);

    return 1;

  }

  return 0;

}

int hexcheck( char word[] )
{

  // Check if it's a hexadecimal number (starts with 0x or 0X)
  if (word[0] == '0' && (word[1] == 'x' || word[1] == 'X'))
  {

    if ( word[2] == '\0' )
    {

      printf("Error: Hexadecimal number has no digits after 0x\n");

      return 1;

    }

    int i = 2; // Start checking from index 2 (after "0x" or "0X")

    while (word[i] != '\0') // Check until end of string
    {

      if (!((word[i] >= 'A' && word[i] <= 'F') || 
            (word[i] >= 'a' && word[i] <= 'f') || 
            (word[i] >= '0' && word[i] <= '9')))
      {

        printf("Error: %c is not a valid hexadecimal number %s \n", word[i],word);

        return 1;

      }

      i++;

    }

  }

  return 0;

}

int bincheck ( char word[] ) // for checking binary
{

  if ( word[0] == '0' && word[1] == 'b')
  {

    if (word[2] == '\0')
    {

      printf("Error: Binary number %s has no digits after 0b\n",word);

      return 1; 

    }

    int i = 2;

    while (word[i] != '\0')
    {

      if( !(word[i] == '0' || word[i] == '1' ))
      {

        printf("Error : %c is not valid for binary digit %s \n",word[i],word);

        return 1;

      }

      i+=1;

    }

  }

  return 0;

}

int floatcheck(char* word) 
{
  int i = 0;
  int dotcount = 0;
  int digitcount = 0;
  int len = strlen(word);
  
  // Check if last character is 'f' or 'F' 
  int has_suffix = 0;

  if (len > 0 && (word[len-1] == 'f' || word[len-1] == 'F'))
  {
    has_suffix = 1;
    len--; // Don't check the suffix character in the loop
  }
  
  while (i < len)
  {
    if (word[i] == '.')
    {
      dotcount++;
    }
    else if (word[i] >= '0' && word[i] <= '9')
    {
      digitcount++;
    }
    else
    {
      printf("Error: %c is invalid in float %s\n", word[i], word);
      return 1;
    }
    i++;
  }
  
  // Check after the loop
  if (dotcount > 1)
  {
    printf("Error: Multiple dots are present in float %s\n", word);
    return 1;
  }
  
  if (digitcount == 0)
  {
    printf("Error: Float %s has no digits\n", word);
    return 1;
  }
  
  return 0;
}

int octcheck ( char* word )
{

  int i = 1;

  while ( word[i] )
  {

    if ( !(word[i] >= '0' && word[i] <= '7' )) // checks if number greater than 7 is present
    {

      printf("Error : %c doesnt belong to Octal %s\n",word[i],word);

      return 1;

    }

    i+=1;

  }

  return 0;

}
