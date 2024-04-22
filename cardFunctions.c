#include "showHandCardDefs.h"
#include "showHandPublicDefs.h"
char* g_initialCardNum = (char*)"0\0";
char* g_initialCardColor = (char*)"ÎÞ»¨";
GAME_STATUS initialCard(_OUT_ PCard* card, _IN_ char* num, _IN_ char* color)
{
	*card = (PCard)malloc(sizeof(Card));
	if (*card)
	{
		(*card)->num = (char*)malloc(BYTES_FOR_SINGLE_NUM * sizeof(char));
		if ((*card)->num)
		{
			memcpy((*card)->num, num, BYTES_FOR_SINGLE_NUM);
		}
		(*card)->color = (char*)malloc(BYTES_FOR_SINGLE_COLOR * sizeof(char));
		if ((*card)->color)
		{
			memcpy((*card)->color, color, BYTES_FOR_SINGLE_COLOR);
		}
	}
	return STATUS_SUCCESS;
}
GAME_STATUS generateSingleRandomCard(_OUT_ PCard* returnedCard, _IN_ char*** combinedInfo)
{
	initialCard(returnedCard, g_initialCardNum, g_initialCardColor);

	int row = rand() % 7;
	int col = rand() % 4;
	memcpy((*returnedCard)->num, combinedInfo[0][row], BYTES_FOR_SINGLE_NUM);
	memcpy((*returnedCard)->color, combinedInfo[1][col], BYTES_FOR_SINGLE_COLOR);
	return STATUS_SUCCESS;
}
GAME_STATUS initialSentCardsStack(_OUT_ PCard** stack)
{
	*stack = (PCard*)malloc(MAX_POSSIBLE_CARDS * sizeof(PCard));
	if (*stack)
	{
		for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
		{
			(*stack)[j] = (PCard)malloc(sizeof(Card));
		}
		for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
		{
			if (((*stack)[j]) != NULL)
			{
				((*stack)[j])->num = (char*)malloc(BYTES_FOR_SINGLE_NUM * sizeof(char));
				((*stack)[j])->color = (char*)malloc(BYTES_FOR_SINGLE_COLOR * sizeof(char));
			}
		}
		for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
		{
			if (((*stack)[j]) != NULL)
			{
				if ((*stack)[j]->num && (*stack)[j]->color && g_initialCardNum && g_initialCardColor)
				{
					memcpy(((*stack)[j])->num, g_initialCardNum, BYTES_FOR_SINGLE_NUM);
					memcpy(((*stack)[j])->color, g_initialCardColor, BYTES_FOR_SINGLE_COLOR);
				}
			}
		}
	}
	return STATUS_SUCCESS;
}
GAME_STATUS getCombinedInfo(_OUT_ char**** combinedInfo)
{
	*combinedInfo = (char***)malloc(2 * sizeof(char**));
	if (*combinedInfo)
	{
		(*combinedInfo)[0] = (char**)malloc(COUNT_OF_NUM * sizeof(char*));
		(*combinedInfo)[1] = (char**)malloc(COUNT_OF_COLOR * sizeof(char*));
	}
	if (*combinedInfo && (*combinedInfo)[0])
	{
		for (int j = 0; j < COUNT_OF_NUM; j++)
		{
			(*combinedInfo)[0][j] = (char*)malloc(BYTES_FOR_SINGLE_NUM * sizeof(char));
		}
	}
	if (*combinedInfo && (*combinedInfo)[1])
	{
		for (int j = 0; j < COUNT_OF_COLOR; j++)
		{
			(*combinedInfo)[1][j] = (char*)malloc(BYTES_FOR_SINGLE_COLOR * sizeof(char));
		}
	}
	char* Card_NUM_8 = (char*)"8\0";
	char* Card_NUM_9 = (char*)"9\0";
	char* Card_NUM_10 = (char*)"10";
	char* Card_NUM_J = (char*)"J\0";
	char* Card_NUM_Q = (char*)"Q\0";
	char* Card_NUM_K = (char*)"K\0";
	char* Card_NUM_A = (char*)"A\0";
	char* Card_COLOR_Ã·»¨ = (char*)"Ã·»¨";
	char* Card_COLOR_ºÚÌÒ = (char*)"ºÚÌÒ";
	char* Card_COLOR_ºìÌÒ = (char*)"ºìÌÒ";
	char* Card_COLOR_·½Æ¬ = (char*)"·½Æ¬";
	if (*combinedInfo && (*combinedInfo)[0] && (*combinedInfo)[0][0] && (*combinedInfo)[0][1] && (*combinedInfo)[0][2] && (*combinedInfo)[0][3] && (*combinedInfo)[0][4] && (*combinedInfo)[0][5] && (*combinedInfo)[0][6])
	{
		memcpy((*combinedInfo)[0][0], Card_NUM_8, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][1], Card_NUM_9, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][2], Card_NUM_10, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][3], Card_NUM_J, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][4], Card_NUM_Q, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][5], Card_NUM_K, BYTES_FOR_SINGLE_NUM);
		memcpy((*combinedInfo)[0][6], Card_NUM_A, BYTES_FOR_SINGLE_NUM);
	}
	if (*combinedInfo && (*combinedInfo)[1] && (*combinedInfo)[1][0] && (*combinedInfo)[1][1] && (*combinedInfo)[1][2] && (*combinedInfo)[1][3])
	{
		memcpy((*combinedInfo)[1][0], Card_COLOR_Ã·»¨, BYTES_FOR_SINGLE_COLOR);
		memcpy((*combinedInfo)[1][1], Card_COLOR_ºÚÌÒ, BYTES_FOR_SINGLE_COLOR);
		memcpy((*combinedInfo)[1][2], Card_COLOR_ºìÌÒ, BYTES_FOR_SINGLE_COLOR);
		memcpy((*combinedInfo)[1][3], Card_COLOR_·½Æ¬, BYTES_FOR_SINGLE_COLOR);
	}
	return STATUS_SUCCESS;
}
GAME_STATUS verifyCardAlreadySent(_IN_ PCard card, _IN_ PCard* stack, _OUT_ INT* flag, _OUT_ INT* loc)
{
	*flag = -1;
	*loc = -1;
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		if (strncmp(stack[j]->num, card->num, BYTES_FOR_SINGLE_NUM) == 0)
		{
			if (strncmp(stack[j]->color, card->color, BYTES_FOR_SINGLE_COLOR) == 0)
			{
				*flag = 0;
				*loc = j;
			}
		}
	}
	return STATUS_SUCCESS;
}
GAME_STATUS pushCardIntoStack(_IN_ PCard card, _IN_OUT_ PCard* stack)
{
	int top = 0;
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		if (*(stack[j]->num) == '0')
		{
			top = j;
			break;
		}
	}
	memcpy(stack[top]->num, card->num, BYTES_FOR_SINGLE_NUM);
	memcpy(stack[top]->color, card->color, BYTES_FOR_SINGLE_COLOR);
	return STATUS_SUCCESS;
}
GAME_STATUS displaySentStackValid(_IN_ PCard* stack)
{
	for (int j = 0; j < MAX_POSSIBLE_CARDS && *(stack[j]->num) != '0'; j++)
	{
		printf("%ld -> %s%s\n", j + 1, stack[j]->color, stack[j]->num);
	}
	return STATUS_SUCCESS;
}
GAME_STATUS displayAllStack(_IN_ PCard* stack)
{
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		printf("%ld -> %s%s\n", j + 1, stack[j]->color, stack[j]->num);
	}
	return STATUS_SUCCESS;
}
GAME_STATUS clearSentCardsStack(_IN_OUT_ PCard* stack)
{
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		memcpy(stack[j]->num, g_initialCardNum, BYTES_FOR_SINGLE_NUM);
		memcpy(stack[j]->color, g_initialCardColor, BYTES_FOR_SINGLE_COLOR);
	}
	return STATUS_SUCCESS;
}
GAME_STATUS killCardMemory(_OUT_ PCard* card)
{
	ExFreeMemoryToNULL((PVOID)(&((*card)->num)));
	ExFreeMemoryToNULL((PVOID)(&((*card)->color)));
	*card = NULL;
	return STATUS_SUCCESS;
}
GAME_STATUS killStackMemory(_OUT_ PCard** stack)
{
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&(((*stack)[j])->num)));
	}
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&(((*stack)[j])->color)));
	}
	for (int j = 0; j < MAX_POSSIBLE_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((*stack)[j])));
	}
	ExFreeMemoryToNULL((PVOID)(&(*stack)));
	return STATUS_SUCCESS;
}
GAME_STATUS killCombinedInfoMemory(_OUT_ char**** combinedInfo)
{
	for (int j = 0; j < COUNT_OF_NUM; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((*combinedInfo)[0][j])));
	}
	for (int j = 0; j < COUNT_OF_COLOR; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((*combinedInfo)[1][j])));
	}
	for (int j = 0; j < 2; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((*combinedInfo)[j])));
	}
	ExFreeMemoryToNULL((PVOID)(&(*combinedInfo)));
	return STATUS_SUCCESS;
}