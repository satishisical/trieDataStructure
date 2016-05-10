/*------------------------------------------------------------------
Name: Satish Chandra	
Roll Number: CS1419
Date of Submission:01/11/2014
Deadline date: 01/11/2014
Program description:Generate a trie structure T with all the words of a given file
Acknowledgements: 
--------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
//structure of a node
struct node
{
	//end field denote if 1 ,end of string
	int end;
	struct node *next[69];
};
//create the node
struct node* createNode();

//insert the string into trie
struct node* insert(struct node *,char *,int ,int );

//search string into trie
bool search(struct node *,char *,int ,int);

//change all string into upper case
char* Upper(char* );

//takes string ang give another string by deleting a char
char* deleteLetter(char* ,int ,char*);

//takes string ang give another string by adding a char
char* addLetter(char *,int ,int ,char*);

//takes string ang give another string by changing a char
char* changeLetter(char* ,int ,int ,char* );

//free memory
void freeFunction(struct node* );

//takes string ang give another string by swaping any two char
char * swapLetter(char* ,int ,int ,char* );
