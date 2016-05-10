/*------------------------------------------------------------------
Name: Satish Chandra	
Roll Number: CS1419
Date of Submission:01/11/2014
Deadline date: 01/11/2014
Program description:Generate a trie structure T with all the words of a given file
Acknowledgements: 
--------------------------------------------------------------------*/
#include "cs1419-assign9-prog1.h"
#include<string.h>
int main()
{
	//head of the trie
	struct node* head = (struct node*)malloc(sizeof(struct node));
	//word array is used to read the word from file and insert into trie 
	char *word =(char*)calloc(20,sizeof(char));
	//word2 array used to take input from user to search hthe string
	char *word2 =(char*)calloc(20,sizeof(char));
	//sugword array to store suggestion for a word
	char* sugword =(char*)calloc(20,sizeof(char));
	int i,j,choice;
	//varible to calculate the time to make dictionary
	clock_t start, end;
        double totalTime;
	FILE *fp;
	//open the file
	fp =fopen("/usr/share/dict/words","r");
	//if file not found
	if(fp == NULL)
	{
		printf("\n**********file does not exist***********\n");
		exit(0);
	}
	start = clock();
	//read words from file into array line by line
	char c = fscanf(fp,"%s",word);
	while (c != EOF)
        {
		word = Upper(word);
		//insert into trie
		head =insert(head,word,0,strlen(word)-1);
		for(i = 0 ; i < 20 ; i++)
			word[i] = '\0';  
		c = fscanf(fp,"%s",word); 
      		       
        }
	//close file
        fclose(fp);
	end = clock();
	totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n\n--Total time to make trie is %f-->\n\n",totalTime);
	do
	{
		printf("what do you want to search->");
		scanf("%s",word2);
		word2 = Upper(word2);
		//search word into trie
		bool b =search(head,word2,0,strlen(word2)-1);
		if(b)
			printf("\n*******word is present in the dictonary*******\n");
		else
		{
		
			printf("\n*******word is NOT  present in the dictonary*******\n");
			//Group 1: words obtained from T by delete any one letter from 'w'
			printf("\n----------------------------\nsuggested word for you \n------------------------------\n");
			for(i=0;i<strlen(word2);i++)
			{
				sugword = deleteLetter(word2,i,sugword);
				if(search(head,sugword,0,strlen(sugword)-1))
					printf("%s\n",sugword);
			}
			//Group 2: words obtained from T by adding one letter at any position of 'w';
			for(i=0;i<=strlen(word2);i++)
			{
				for(j=32;j<97;j++)
				{
					sugword=addLetter(word2,i,j,sugword);
					if(search(head,sugword,0,strlen(sugword)-1))
						printf("%s\n",sugword);
				}
			}
			//Group 3: words obtained from T by changing any single letter of 'w';
			for(i = 0 ; i < 20 ; i++)
				sugword[i] = '\0';  
			for(i=0;i<strlen(word2);i++)
			{
				for(j=32;j<97;j++)
				{
					
					sugword=changeLetter(word2,i,j,sugword);
					if(search(head,sugword,0,strlen(sugword)-1))
						printf("%s\n",sugword);
				}
			}
			//Group 4: words obtained from T by swapping any two letters of 'w'.
			for(i=0;i<strlen(word2);i++)
			{
				for(j=i+1;j<strlen(word2);j++)
				{
					sugword=swapLetter(word2,i,j,sugword);
					if(search(head,sugword,0,strlen(sugword)-1))
						printf("%s\n",sugword);
				}
			}
				
		}
		printf("\n  you want more searches press 1 otherwise 0-->\t");
		scanf("%d",&choice);
	}while(choice==1);
	
	free(sugword);
	freeFunction(head);
	
	return 0;
}
