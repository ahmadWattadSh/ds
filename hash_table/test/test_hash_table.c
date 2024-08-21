/*
  Name: Ahmad Wattad
  Project: 
  Reviewer: Aya
  Date: 27/09/23
*/


/******************************************************************************/
#include <stdio.h>/*printf*/
#include <stdlib.h> /*	malloc	*/
#include <stdio.h> 
#include <string.h>

#include "hash_table.h"
#include "dll.h"

#define ErrorMsgEqual(expected, result, name) \
	{\
		if (expected == result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}
#define ErrorMsgNotEqual(expected, result, name) \
	{\
		if (expected != result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}


#define CAPACITY 1000


/*global vars*/
size_t g_word_count = 0;
/************************** Forwarded declarations ****************************/

static void UnitTesting();
static int MatchFunc(const void *list_data, void *params);
static size_t HashFunc(const void* str_ , void *params);
static void CreateTest();
static void InsertTest();
static void SizeTest();
static void IsEmptyTest();
static void RemoveTest();
static void FindTest();
static void ForeachTest();
static hash_ty* LoadDictionary();
static char** GeneratePointersToWords(char *buffer);
static char* GenerateBufferIMP();
static char *StrdupIMP( char *str);
static void SpellChecker(hash_ty *hash);
/*********************************** main *************************************/

int main()
{
	UnitTesting();
	return 0;
}

/******************************************************************************/

static void UnitTesting()
{
	hash_ty *hash = NULL;
	
	CreateTest();
	InsertTest();
	SizeTest();
	IsEmptyTest();
	RemoveTest();
	FindTest();
	ForeachTest();

	hash = LoadDictionary();
	SpellChecker(hash);
	
}
/******************************************************************************/	

static int MatchFunc(const void *list_data, void *params)
{
	char *table_data =  (char*)list_data;
	char *data_to_cmp =  (char*)params;
	
	if(!strcmp(data_to_cmp, table_data))
	{
		return TRUE;
	}	
	
	return FALSE;
}

static size_t HashFunc(const void* str_ , void *params)
{
	char *str =  (char*)str_;
	size_t i = 0;
	size_t j = 0 ; 
	
	for (j = 0; str[j]; ++j)
	{
        	i += str[j];
	}
	
	return i % CAPACITY;
}

/******************************************************************************/

static void CreateTest()
{
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	ErrorMsgEqual(HTableIsEmpty(hash), TRUE, "CreateTest1");
	ErrorMsgEqual(HTableSize(hash), 0, "CreateTest2");
	HTableDestroy(hash);
}


static void InsertTest()
{
	char *x = "abc";
	char *y = "def";
	char *z = "mmm";
	
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	HTableInsert(hash,x);
	HTableInsert( hash, y);

	ErrorMsgEqual(HTableIsEmpty(hash), FALSE, "InsertTest1");
	
	HTableDestroy(hash);
}


static void SizeTest()
{
	char *x = "abc";
	char *y = "def";
	char *z = "mmm";
	
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	HTableInsert(hash,x);
	HTableInsert( hash, y);
	HTableInsert( hash, z);
	ErrorMsgEqual(HTableSize(hash), 3, "SizeTest");
	
	HTableDestroy(hash);
}

static void IsEmptyTest()
{

	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	ErrorMsgEqual(HTableIsEmpty(hash), TRUE, "IsEmptyTest");
	
	HTableDestroy(hash);
}

static void RemoveTest()
{
	char *x = "abc";
	char *y = "def";
	char *z = "mmm";
	
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	HTableInsert(hash,x);
	HTableInsert( hash, y);
	HTableInsert( hash, z);
	HTableRemove(hash, x);
	ErrorMsgEqual(HTableSize(hash), 2, "RemoveTest");
	
	HTableDestroy(hash);
}



static void FindTest()
{

	char *x = "abc";
	char *y = "def";
	char *z = "mmm";
	
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	HTableInsert(hash,x);
	HTableInsert( hash, y);
	HTableInsert( hash, z);

	ErrorMsgEqual(*(char*)HTableFind(hash,x), *x, "FindTest1");

	HTableRemove(hash, x);
	
	ErrorMsgEqual(HTableFind(hash,x), NULL, "FindTest2");	
		
	HTableDestroy(hash);

}


static void ForeachTest()
{

	char *x = "abc";
	char *y = "def";
	char *z = "mmm";
	char *f = "sss";
		
	hash_ty *hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);
	
	HTableInsert(hash,x);
	HTableInsert( hash, y);
	HTableInsert( hash, z);
	HTableInsert(hash,f);
	
	ErrorMsgEqual(HTableSize(hash), 4, "ForeachTest1");
		
	HTableDestroy(hash);

}


static hash_ty* LoadDictionary()
{
	char *buffer = NULL;
	size_t file_size = 0;
	char **word_array = NULL;
	size_t i = 0;
	hash_ty *hash = NULL;
	
	buffer = GenerateBufferIMP();
	file_size = strlen(buffer);	
	word_array = GeneratePointersToWords(buffer);
	hash = HTableCreate(HashFunc, NULL, CAPACITY, MatchFunc);	
	
	for (i = 0; i < g_word_count; ++i)
	{
		HTableInsert(hash, word_array[i]);
	}

	ErrorMsgEqual(HTableSize(hash), g_word_count, "LoadDictionary");	
	
	return hash;
	
}

static char** GeneratePointersToWords(char *buffer) 
{
	char *token = buffer;
	int word_count = 0;
	char **word_array = NULL;
	size_t len = 0;
	size_t i = 0;

	/*calculate how many words in the buffer*/
	while (token != NULL) 
	{
		++token;
		token = strchr(token, '\n');
		word_count++;
	}
	
	--word_count;
	/*now it is possible to allocate it*/
	word_array = (char **)malloc(word_count * sizeof(char *) );
	/*handle err*/
	if (word_array == NULL)
	{
		perror("Error allocating memory");
		free(buffer);
	}
	
	g_word_count = word_count - 1;
	
	/*Reset the position of strtok*/
	token = strtok(buffer, "\n");

    	/*Copy each word into the array*/
	for (i = 0; i < word_count; i++) 
	{
        	word_array[i] = StrdupIMP(token);
		token = strtok(NULL, "\n");
	}
		
	return word_array;
}


static char* GenerateBufferIMP() 
{
	FILE *file_ptr = NULL;
	size_t file_size = 0;
	unsigned char *buffer = NULL;
 	size_t read_size = 0;

	file_ptr = fopen("/usr/share/dict/words", "r");
	if (NULL == file_ptr) 
	{
		perror("Error opening file");
		exit(FAILURE);
	}

	/* Get the file size */
	fseek(file_ptr, 0, SEEK_END);
	file_size = ftell(file_ptr);
	rewind(file_ptr);

	/* Allocate memory for the buffer */
	buffer = (char *)malloc(sizeof(char) * (file_size + 1));
	if (NULL == buffer) 
	{
		fclose(file_ptr);
		perror("Memory allocation error");
		exit(FAILURE);
	}

	/* Read the file content into the buffer */
	read_size = fread(buffer, 1, file_size, file_ptr);
	buffer[read_size] = '\0';
	/*  if (read_size != file_size) 
	{
		fclose(file_ptr);
		free(buffer);
		perror("Error reading file");
		exit(FAILURE);
	}*/

	fclose(file_ptr);
	return buffer;
}


static char *StrdupIMP( char *str) 
{
	size_t len = strlen(str);
	char *new_str = (char *)malloc(len + 1);

		
	if (NULL != new_str) 
	{
		strcpy(new_str, str);
	}
	
	return new_str;
}



static void SpellChecker(hash_ty *hash)
{

	char cmd[10] = {0}; 
	size_t length = 0;
	
	while(1)
	{
		printf("enter a string\n");
		fgets(cmd, sizeof(cmd), stdin);
		length = strcspn(cmd, "\n");
		
		if (cmd[length] == '\n') 
		{
			cmd[length] = '\0';
		}

		if(!strcmp("exit", cmd))
		{
			printf("exitting\n");
			HTableDestroy(hash);
			exit(0);
		}		
		
		if(HTableFind(hash, cmd))
		{
			printf("The string was found\n");	
		}
		else
		{
			printf("The string wasn't found\n");	
		}		
	}


}








