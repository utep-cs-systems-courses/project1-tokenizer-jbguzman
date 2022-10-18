#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h> //needed for use of malloc
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 1;
      }
  return 0;
    }
      
 /* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if ((c != ' ' || c != '\t' && c != '\0')){
      return 1;
	}
    return 0;
    }
  
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
  char *word_start(char *str){
    //
    while(space_char(*str)){
      str++;
    }
    return str; //return address of str pointer
  }
    

/* Returns a pointer terminator char following *word */
  char *word_terminator(char *word){
    //
    while(non_space_char(*word)){ 
      word++;
    }
    return word; //return address of word pointer at the end of the word
  }

/* Counts the number of words in the string argument. */
  int count_words(char *str){
    int nw; //variable created to count workds in string
    for (nw = 0; str != word_terminator(str); nw++){ //for loop to iterate through string pointer
      str = word_terminator(str); //keep passing string to word_teminator to check end
    }
    return nw; //return number of words
  }

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  int n; //int variable n used to iterate
  
  //char pointer named copy declared and initialized
  //malloc used to get exact size of string, cast of type char pointer
  //memory allocated will be 1 byte multipled by short length plus 1
  //total of 16 X 8 + 1 = 129 bits allocated
  char *copy = (char *)malloc(len * sizeof(char) +1); 

  for(n=0; n<len; n++) { //for loop to duplicate items from inStr to copy
    copy[n] = inStr[n];
  }
  copy[n] = '\0'; //add zero terminator at end of string
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str){
  int n;

  //variable of type int to count tokens passed to the count_words method
  int tokens = count_words(str);
  //char pointer of a pointer named array with memory allocated using malloc
  char **array = malloc(sizeof(char *) * (tokens));
  //char pointer start using method word_strart passing str to get begging of string
  char *start = word_start(str);
  //char pointer end using method word_terminator passing str to get end of string
  char *end = word_terminator(str);

  //for loop to iterate, copy contents of str to array using copy_str method passing
  //address for start and end minus start for remaining length
  for (n = 0; n < tokens; n++) {
    array[n] = copy_str(start, end-start);
    start = word_start(end); // new beginning of next word is the end address
    end = word_terminator(start); // new end word is the start of next word address
  }
  //declare 0 at end of tokens
  array[n] = 0;
  return array;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int n = 0;

  //while loop used to iterate through and print tokens
  while(tokens[n]){
    printf("Tokens %d: = %s\n", n, tokens[n]);
    n++;
  }

  return;
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
