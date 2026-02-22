/*************************************************************************
 * Caesar Encryptor.
 * code by Destr0yd.
 *
 *************************************************************************
 * size of pe: 41,2K
 * gcc -v: 6.3.0 (mingw)
 * gcc cipher.c -o cipher.exe
 *************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXMESSAGESIZE 256
#define ENGLISHALPHABETLENGTH 26

#define DEBUG 1

typedef char* String;
typedef unsigned int UINT;

String EncryptMessage(char Message[], UINT Key);
String EncryptMessage(char Message[], UINT Key)
{
	for(UINT i = 0; i < strlen(Message); i++)
	{
		#ifdef DEBUG
		printf("symbol %c is going to be encrypted.\n", Message[i]);
		#endif
		
		if(isalpha(Message[i]) == 0)
		{
			#ifdef DEBUG
			printf("warning: symbol %c isn't a letter.\n\n", Message[i]);
			#endif
			continue;
		}

		else if(isalpha(Message[i] + Key) == 0)
			Message[i] = (Message[i] - ENGLISHALPHABETLENGTH) + Key;	// x = (l - 26) + k
											//
		else Message[i] += Key;							// x = k + l
	}

	return Message;
}

int main()
{
	long int UserKey;
	char UserMessage[MAXMESSAGESIZE];

	printf("\nCaesar Cipher.\n\nkey - ");
	scanf("%d", &UserKey);

	if((UserKey <= 0) || (UserKey > 26))
	{
		#ifdef DEBUG
		printf("\nerror: %d is a wrong key value.", UserKey);
		#endif

		goto ExitProgram;
	}

	printf("message - ");
	scanf("%s", &UserMessage);

	printf("\n"); puts(EncryptMessage(UserMessage, UserKey));

ExitProgram:
	return 0
;}








































