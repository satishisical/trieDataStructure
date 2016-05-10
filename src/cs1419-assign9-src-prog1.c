/*------------------------------------------------------------------
Name: Satish Chandra	
Roll Number: CS1419
Date of Submission:01/11/2014
Deadline date: 01/11/2014
Program description:Generate a trie structure T with all the words of a given file
Acknowledgements: 
--------------------------------------------------------------------*/
#include "cs1419-assign9-prog1.h"
//create the node
struct node* createNode()
{
	int i;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->end =0;	
	//set all next array field to null 
	for(i=0;i<69;i++)
	new->next[i] = NULL;
	return new;
}
//change all char to upper case
char* Upper(char* charr)
{
    	 int j;
    	for(j = 0; charr[j]; j++)
    	{
    	    charr[j] = toupper(charr[j]);
    	}
	return charr;
}
//takes a string and delete a char depending on parameter c(position) and return resulted string
char* deleteLetter(char* oWord,int c,char* nWord)
{
	int j,k=0;
	for(j = 0;j<strlen(oWord); j++)
    	{
		//if position find that have to delete
		if(c!=j)
		{
        		nWord[k] = oWord[j];
			k++;
		}
    	}
	return nWord;
}
//words obtained from input return word by adding one letter at any   position c of 'w';
char* addLetter(char *oWord,int c,int ch,char* nWord)
{	
	int i,k=0;
	//copy char into new array before given position 
	for(i=0;i<c;i++)
	{
		nWord[k]=oWord[i];
		k++;
	}
	//add char at given position
	nWord[k]=ch;
	k++;
	//copy char into new array after given position 
	for(i=c;i<strlen(oWord);i++)
	{
		nWord[k]=oWord[i];
		k++;
	}
	return nWord;
}
//return words obtained  by changing any single letter of 'w' at given position c
char* changeLetter(char* oWord,int c,int ch,char* nWord)
{
	int i,k=0;
	for(i=0;i<strlen(oWord);i++)
	{
		//find position and replace char with given char into new array
		if(i==c)
		nWord[k]=ch;
		else
		//otherwise copy all char into new array
		nWord[k]=oWord[i];
		k++;
	}
	return nWord;
}
//return words  by swapping any two letters of 'w' given two position.	
char* swapLetter(char* oWord,int c1,int c2,char* nWord)
{
	char s;
	int i;
	//copy all char into other array
	for(i=0;i<strlen(oWord);i++)
		nWord[i]=oWord[i];
	//swap two char position given by c1 and c2
	s =nWord[c1];
	nWord[c1]=nWord[c2];
	nWord[c2]=s;
	return nWord;
}
//insert a word into trie
struct node* insert(struct node *temp,char *arr,int start,int last)
{
		int index,i;
		struct node *newNode;
		//return if array ends
		if(start > last+1)
			return NULL;
		//calculate index value where we have to insert char of word
		index = (int)arr[start];
		if(index >=32 && index <= 96)
			index = index - 32;
		else if(index >=123 && index <= 126)
			index = index - 58;
		//if node with given char does not exist create node
		if(temp == NULL)
		{
			newNode = createNode();
			//if last char of word is reached set 1 at next node
			if(start > last)
				newNode->end =1;
			else
				newNode->next[index] = insert(newNode->next[index],arr,start+1,last);
			return newNode;
			
		}//if last char of word is reached set 1 at next node
		if(start > last)
		{
			temp->end =1;
			return temp;
		}
		temp->next[index] =insert(temp->next[index],arr,start+1,last);
		return temp;
}
//search a word into trie
bool search(struct node *temp,char *arr,int start,int last)
{
	int index,i;
	//if tree null return
	if(temp==NULL)
		return false;
	//if we reached at last char of word
	if(start > last)
	{
		//success if end bit is 1 otherwise failure
		if(temp->end == 1)
		return true;
		else
		return false;
	}
	//calculate index value
	index = (int)arr[start];
	if(index >=32 && index <= 96)
		index = index - 32;
	else if(index >=123 && index <= 126)
		index = index - 58;
	//if not reached at last char go to next level
	if(temp->next[index]!=NULL)
		return search(temp->next[index],arr,start+1,last);
	else
		return false;
}

//free trie 
void freeFunction(struct node* temp)
{
	int i;
	for(i=0;i<69;i++)
	{
		if(temp->next[i] != NULL){
			freeFunction(temp->next[i]);
			free(temp->next[i]);			
		}

	}
	
}






		
