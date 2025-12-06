#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "error.h" 

int keywordcheck( char word [] ) // this function checks all the 32 keywords
{
  if ( strcmp(word,"int") == 0) return 1;
  if ( strcmp(word,"float") == 0) return 1;
  if ( strcmp(word,"char") == 0) return 1;
  if ( strcmp(word,"for") == 0) return 1;
  if ( strcmp(word,"while") == 0) return 1;
  if ( strcmp(word,"do") == 0) return 1;
  if ( strcmp(word,"break") == 0) return 1;
  if ( strcmp(word,"return") == 0) return 1;
  if ( strcmp(word,"continue") == 0) return 1;
  if ( strcmp(word,"auto") == 0) return 1;
  if ( strcmp(word,"const") == 0) return 1;
  if ( strcmp(word,"double") == 0) return 1;
  if ( strcmp(word,"else") == 0) return 1;
  if ( strcmp(word,"enum") == 0) return 1;
  if ( strcmp(word,"extern") == 0) return 1;
  if ( strcmp(word,"goto") == 0) return 1;
  if ( strcmp(word,"if") == 0) return 1;
  if ( strcmp(word,"long") == 0) return 1;
  if ( strcmp(word,"register") == 0) return 1;
  if ( strcmp(word,"short") == 0) return 1;
  if ( strcmp(word,"signed") == 0) return 1;
  if ( strcmp(word,"sizeof") == 0) return 1;
  if ( strcmp(word,"static") == 0) return 1;
  if ( strcmp(word,"struct") == 0) return 1;
  if ( strcmp(word,"switch") == 0) return 1;
  if ( strcmp(word,"typedef") == 0) return 1;
  if ( strcmp(word,"union") == 0) return 1;
  if ( strcmp(word,"unsigned") == 0) return 1;
  if ( strcmp(word,"void") == 0) return 1;
  if ( strcmp(word,"volatile") == 0) return 1;
  if ( strcmp(word,"case") == 0) return 1;
  if ( strcmp(word,"default") == 0) return 1;

  return 0; // if none is present
}

int main( int argc , char* argv[] )
{
  // argc reads how many argv user has written on command line
  // argv[0] = ./a.out and argv[1] = file_name.c
  if ( argc != 2 )
  {
    printf("Usage: %s <filename>\n", argv[0]);
    printf("Example: %s test.c\n", argv[0]);
    return 1;
  }

  char* filename = argv[1];
  int len = strlen(filename);

  // checks if minimum single character is named like a.c which is for len 3
  // filename+len-2 => gives the address where dot is present
  // this is for checking is .c extension is present
  if (len < 3 || strcmp(filename + len - 2, ".c") != 0)
  {
    printf("Error: Input file must have .c extension\n");
    printf("Provided: %s\n", filename);

    return 1;
  }

  FILE* fptr = fopen(argv[1],"r"); // were opening the file in read mode
  if ( fptr == NULL ) // checking if it is an NULL
  {
    printf("Failed to open file \n");
    return 1;
  }
  char word[200]; // declaring word to store values which are fetched from code
  int pos; // for putting characters into word each by each
  int ch = getc(fptr); // now ch stores the first element in program

  int doublecount = 0;
  int singlecount = 0;
  int paracount = 0;
  int curlycount = 0;
  int bracketcount = 0;         // to count [ and ]
  int line_number = 1;          // to track current line
  int para_line = 0;            // stores line where ( opened
  int bracket_line = 0;         //  stores line where [ opened
  while ( ch != EOF ) // checks if ch is not equal to EOF
  {

    if ( ch == '\n' )            // track line numbers
    {
      line_number++;
      ch = getc(fptr);
      continue;
    }

    if ( ch == '(')
    {
      paracount+=1;
      para_line = line_number;   // remember line number
    }
    if ( ch == ')')
    {
      paracount-=1;
      //  check if parenthesis on same line
      if (para_line != line_number && para_line != 0)
      {
        printf("Error : Parenthesis () not on same line (opened at line %d)\n", para_line);
      }
    }
    if ( ch == '[')              // square bracket opening
    {
      bracketcount+=1;
      bracket_line = line_number;
    }
    if (ch == ']')               //  square bracket closing
    {
      bracketcount-=1;
      // check if brackets on same line
      if (bracket_line != line_number && bracket_line != 0)
      {
        printf("Error : Square brackets [] not on same line (opened at line %d)\n", bracket_line);
      }
    }
    if ( ch == '{')
    {
      curlycount+=1;
    }
    if (ch == '}')
    {
      curlycount-=1;
    }

    if ( isspace(ch) ) // checks if there space present if present then ignore them
    {

      ch = getc(fptr);
      continue;

    }

    else if ( ch == '#' ) // for ignoring preprocessor directives
    {

      while ( ch != '\n' && ch != EOF ) // if its an preprocessor directive skip that line
      {

        ch = getc(fptr);

      }
      if (ch != EOF) ch = getc(fptr); // here it means it reached \n now go to next element

    }

    else if ( ch == '/' ) // for checking if this is an comment or division Operator
    {

      char first_check = ch; // storing that / for comparison
      ch = getc(fptr);

      if ( first_check == '/' && ch == '/' ) // checking if its an comment
      {

        while ( ch != '\n' && ch != EOF)
        { 

          ch = getc(fptr);

        }
        if (ch != EOF) ch = getc(fptr); // if its an comment we ignore till \n and now its at \n now move to next element

      }

      else if ( first_check == '/' && ch == '*' ) // checking if its an multi line comment
      {

        char prev = 0; // prev for storing that end * / comparison
        ch = getc(fptr);

        while ( ch != EOF )
        {

          if ( prev == '*' && ch == '/' )
          {

            ch = getc(fptr);
            break; // if we found that */ then break from loop now ch contain /

          }

          prev = ch;
          ch = getc(fptr);

        }

      }

      else
      {

        printf("Operator : %c\n",first_check); // if its just an single / only print it as an division Operator

      }

    }

    else if ( isalpha(ch) || ch == '_' ) // check if current ch is alphabet or _
    {

      pos = 0; // setting position to 0
      word[pos] = ch; // storing that ch to word[0]
      ch = getc(fptr); // incrementing ch to next element

      while ( ch != EOF &&( isalpha(ch) || isdigit(ch) || ch == '_' )) // checking if it contain alphabet and digit or _
      {

        pos+=1;
        word[pos] = ch;
        ch = getc(fptr);

      }

      pos+=1;
      word[pos] = '\0'; // ending the word with \0

      if ( keywordcheck(word) == 1 ) // checking if that word is an keyword
      {

        printf("Keyword : %s\n",word);

      }

      else 
      {

        if (!interr(word)) // if its not an keyword then checking if its an identifier error like 1num like number before digit
        {

          printf("Identifier : %s\n",word);

        }

      }

    }

    else if ( isdigit(ch) ) // checking if that character first is an digit
    {

      pos = 0;
      word[pos] = ch;
      ch = getc(fptr);
      int itsanfloat = 0; // for checking if it belongs to float

      while ( ch != EOF && (isdigit(ch) || ch == '.' || ch == 'x' || ch == 'X' || 
        isalpha(ch) || ch == '_' || ch == 'b') ) // for checking if it belongs to bin hex
      {

        if ( ch == '.')
        {

          itsanfloat = 1; // we found that its an float

        }

        pos+=1;
        word[pos] = ch;
        ch = getc(fptr);

      }

      pos+=1;
      word[pos] = '\0';

      // Check if it's a hexadecimal number
      if (word[0] == '0' && (word[1] == 'x' || word[1] == 'X'))
      {

        if (!hexcheck(word)) 
        {

          printf("Numeric Literals : %s\n", word); // prints that hex digit as Numeric Literals if no error is found

        }

      }

      else if (itsanfloat) // if its an float
      {

        if (!floatcheck(word)) // were putting that float digit to check if theres an error
        {

          printf("Numeric Literals : %s\n",word); // if no error is seen then its printed as Numeric

        }

      }

      else if ( word[0] == '0' && word[1] == 'b') // for cheking if it has binary starting
      {

        if (!bincheck(word))
        {

          printf("Numeric Literals : %s\n",word); // if it passes by not showing error then its printed as numeric Literals
          
        }

      }

      else if ( word[0] == '0' && word[1] != '\0' && isdigit(word[1]) )
      {

        if(!octcheck(word))
        {

          printf("Numeric Literals : %s\n",word);

        }

      }
      // Check if it starts with digit but has letters (invalid identifier)
      else 
      {
        int has_letters = 0; // for cheking if it has letters present in it
        int i = 0;

        while (word[i] != '\0') 
        {

          if (isalpha(word[i]) || word[i] == '_')  // checking letter is present or not
          {

            has_letters = 1;
            break;

          }

          i++;

        }

        if (has_letters) 
        {
          interr(word); // we check on function also if theres an error
        }

        else 
        {

          printf("Numeric Literals : %s\n", word); // if it passes then only it is printed as numeric Literals

        }

      }

    }

else if ( ch == '"')
{

  doublecount+=1;
  int string_line = line_number;  //  remember line where string started
  pos = 0;
  word[pos] = ch;
  ch = getc(fptr);

  while ( (ch != EOF ) && (ch != '"' && ch != '\n' ))
  {

    pos+=1;
    word[pos] = ch;
    ch = getc(fptr);

  }

  if ( ch == '"' )
  {

    doublecount+=1;
    pos+=1;
    word[pos] = ch;
    ch = getc(fptr);
    pos+=1;
    word[pos] = '\0';
    
    // check if string quotes on same line
    if (string_line != line_number )
    {
      printf("Error : String quotes \"\" not on same line (opened at line %d)\n", string_line);
    }
    
    printf("String Literals : %s \n",word);

  }

  else if ( ch == '\n' )  //  handle newline case
  {

    pos+=1;
    word[pos] = '\0';
    printf("Error : Theres No Closing for the string : %s \n",word);
    line_number++;
    ch = getc(fptr);

  }

  else  // EOF case
  {

    pos+=1;
    word[pos] = '\0';
    printf("Error : Theres No Closing for the string : %s \n",word);

  }

 }

    else if ( ch == '\'')
    {

      singlecount+=1;
      pos = 0;
      word[pos] = ch;
      ch = getc(fptr);

      if (ch == '\\')  // checking if it an escape sequence
      {

        pos+=1;
        word[pos] = ch;
        ch = getc(fptr);

        if (ch != EOF && ch != '\n') // storing that escape sequence
        {

          pos+=1;
          word[pos] = ch;
          ch = getc(fptr);

        }

      }

      else if (ch != EOF && ch != '\n' && ch != '\'') //for storing character
      {

        pos+=1;
        word[pos] = ch;
        ch = getc(fptr);

      }

      if (ch == '\'') // end of that single quote character
      {

        singlecount+=1;
        pos+=1;
        word[pos] = ch;
        ch = getc(fptr);
        pos+=1;
        word[pos] = '\0';

        if (pos == 2)  // Only has opening and closing quotes
        {

          printf("Error : Empty character literal %s\n", word);

        }

        else
        {

          printf("Character Literal : %s\n", word);

        }

      }

      else 
      {

        pos+=1;
        word[pos] = '\0';

        printf("Error : Theres No Closing for character %s\n", word);

      }

    }

    else if ( ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '!' ||
    ch == '&' || ch == '|' || ch == '<' || ch == '>' || ch == '=' || ch == '/' )
    {

      char first_ch = ch;
      ch = getc(fptr);

      if (( first_ch == '+' && ch == '+') ||
          (first_ch == '-' && ch == '-' ) ||
          (first_ch == '&' && ch == '&' ) ||
          (first_ch == '|' && ch == '|' ) ||
          (first_ch == '<' && ch == '=' ) ||
          (first_ch == '>' && ch == '=' ) ||
          (first_ch == '=' && ch == '=')  ||
          (first_ch == '!' && ch == '=')  ||
          (first_ch == '<' && ch == '<')  ||
          (first_ch == '>' && ch == '>')  ||
          (first_ch == '&' && ch == '=')  ||
          (first_ch == '|' && ch == '=')  ||
          (first_ch == '+' && ch == '=')  ||
          (first_ch == '-' && ch == '=')  ||
          (first_ch == '*' && ch == '=')  ||
          (first_ch == '/' && ch == '=')
      )
      {

        printf("Operator : %c%c\n",first_ch,ch);

        ch = getc(fptr);

      }

      else 
      {

        printf("Operator : %c\n",first_ch);

      }

    }

    else 
    {

      printf("Symbols : %c\n",ch);

      ch = getc(fptr);

    }
  }

  if ( doublecount % 2 != 0 )
  {

    printf("Error :  Missing \" in program \n");

  }

  if ( singlecount %2 != 0 )
  {

    printf("Error : Missing ' in program \n");

  }

  if ( paracount > 0 )
  {

    printf("Error : Missing %d closing paranthesis ')' \n",paracount );

  }

  else if ( paracount < 0 )
  {

    printf("Error : Missing %d extra paranthesis ')' \n",-paracount );

  }

  if (curlycount > 0 )
  {

    printf("Error : Missing %d closing curlybracket '}' \n",curlycount);

  }
  else if ( curlycount < 0)
  {

    printf("Error : Missing %d extra curlybracket '}' \n",-curlycount);

  }

  if (bracketcount > 0 )
  {

    printf("Error : Missing %d closing square bracket ']' \n", bracketcount);

  }

  else if (bracketcount < 0)
  {

    printf("Error : Missing %d extra square bracket ']' \n", -bracketcount);

  }

  fclose(fptr);

  return 0;
}
