#include "showHandCardDefs.h"
#include "showHandPublicDefs.h"
#include "showHandPlayerDefs.h"
int g_mark_flag = -1;
int g_mark_loc = -1;
int main()
{
	srand((UINT)time(NULL));
	PPlayer players[4] = { 0 }; for (int j = 0; j < 4; j++) { initialPlayerInfo(&players[j]); }
	PCard* stack = NULL; initialSentCardsStack(&stack);
	char*** combinedInfo = NULL; getCombinedInfo(&combinedInfo);
	PCard cards[20] = { 0 };
	for (int j = 0; j < 20; j++)
	{
		if (j == 0)
		{
			generateSingleRandomCard(&cards[j], combinedInfo);
			sentSingleCardToPlayer(cards[j], players[0]);
			pushCardIntoStack(cards[j], stack);
		}
		else
		{
			generateSingleRandomCard(&cards[j], combinedInfo);
			verifyCardAlreadySent(cards[j], stack, &g_mark_flag, &g_mark_loc);
			while (g_mark_flag == 0)
			{
				generateSingleRandomCard(&cards[j], combinedInfo);
				verifyCardAlreadySent(cards[j], stack, &g_mark_flag, &g_mark_loc);
			}
			sentSingleCardToPlayer(cards[j], players[j % 4]);
			pushCardIntoStack(cards[j], stack);
		}
	}
	//for (int j = 0; j < 20; j++) //²âÊÔÅÆÊÇ·ñÖØ¸´
	//{
	//	if(strncmp(cards[j]->color, (char*)"Ã·»¨", 7) == 0)
	//		printf("%s%s\n", cards[j]->color, cards[j]->num);
	//	else if (strncmp(cards[j]->color, (char*)"ºÚÌÒ", 7) == 0)
	//		printf("      %s%s\n", cards[j]->color, cards[j]->num);
	//	else if (strncmp(cards[j]->color, (char*)"ºìÌÒ", 7) == 0)
	//		printf("             %s%s\n", cards[j]->color, cards[j]->num);
	//	else if (strncmp(cards[j]->color, (char*)"·½Æ¬", 7) == 0)
	//		printf("                    %s%s\n", cards[j]->color, cards[j]->num);
	//}
	//for(int o = 1; o < 50; o++) //Õ¹Ê¾Íæ¼ÒÅÆÕ»
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		displaySinglePlayerAllInfo(players[j]);
	//	}
	//	printf("\n"); printf("\n"); printf("\n"); printf("\n");
	//}
	for (int j = 0; j < 4; j++)
	{
		convertPlayerCardStackIntoMatrix(players[j], combinedInfo, &players[j]->playerCardMatrix);
	}
	for (int j = 0; j < 4; j++)
	{
		displaySinglePlayerAllInfo(players[j]);
		judgePlayerCardTypeByCardPlayerMatrix(players[j], combinedInfo);
		printf("\n\n");
	}
	return 0;
}