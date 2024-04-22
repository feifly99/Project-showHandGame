#include "showHandPlayerDefs.h"
#include "showHandPublicDefs.h"
GAME_STATUS initialPlayerInfo(_OUT_ PPlayer* player)
{
	(*player) = (PPlayer)malloc(sizeof(Player));
	if (*player)
	{
		(*player)->playerCardStack = (PCard*)malloc(MAX_PERSONNAL_CARDS * sizeof(PCard));
		if ((*player)->playerCardStack)
		{
			for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
			{
				((*player)->playerCardStack)[j] = (PCard)malloc(CARD_ATTRIBUTION_TYPES * sizeof(Card));
			}
		}
		if ((*player)->playerCardStack && ((*player)->playerCardStack)[0] && ((*player)->playerCardStack)[1] && ((*player)->playerCardStack)[2] && ((*player)->playerCardStack)[3] && ((*player)->playerCardStack)[4])
		{
			for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
			{
				(((*player)->playerCardStack)[j])->num = (char*)malloc(BYTES_FOR_SINGLE_NUM * sizeof(char));
				(((*player)->playerCardStack)[j])->color = (char*)malloc(BYTES_FOR_SINGLE_COLOR * sizeof(char));
			}
		}
		if ((*player)->playerCardStack && ((*player)->playerCardStack)[0] && ((*player)->playerCardStack)[1] && ((*player)->playerCardStack)[2] && ((*player)->playerCardStack)[3] && ((*player)->playerCardStack)[4])
		{
			if ((((*player)->playerCardStack)[0])->num && (((*player)->playerCardStack)[1])->num && (((*player)->playerCardStack)[2])->num && (((*player)->playerCardStack)[3])->num && (((*player)->playerCardStack)[4])->num && (((*player)->playerCardStack)[0])->color && (((*player)->playerCardStack)[1])->color && (((*player)->playerCardStack)[2])->color && (((*player)->playerCardStack)[3])->color && (((*player)->playerCardStack)[4])->color)
			{
				for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
				{
					memcpy((((*player)->playerCardStack)[j])->num, g_initialCardNum, BYTES_FOR_SINGLE_NUM);
					memcpy((((*player)->playerCardStack)[j])->color, g_initialCardColor, BYTES_FOR_SINGLE_COLOR);
				}
			}
		}
		(*player)->playerCardMatrix = (int**)malloc(COUNT_OF_NUM * sizeof(int*));
		if ((*player)->playerCardMatrix)
		{
			for (int t = 0; t < COUNT_OF_NUM; t++)
			{
				((*player)->playerCardMatrix)[t] = (int*)malloc(COUNT_OF_COLOR * sizeof(int));
			}
		}
		if (
			(*player)->playerCardMatrix
			&&
			(*player)->playerCardMatrix[1]
			&&
			(*player)->playerCardMatrix[2]
			&&
			(*player)->playerCardMatrix[3]
			)
		{
			for (int i = 0; i < COUNT_OF_NUM; i++)
			{
				for (int j = 0; j < COUNT_OF_COLOR; j++)
				{
					(*player)->playerCardMatrix[i][j] = 0;
				}
			}
		}
		(*player)->chips = 50000;
		(*player)->round = 0;
		(*player)->credits = 0;
		(*player)->points = 0;
	}
	return STATUS_SUCCESS;
}
GAME_STATUS sentSingleCardToPlayer(_IN_ PCard card, _IN_ PPlayer player)
{
	int top = 0;
	for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
	{
		if (*(((player->playerCardStack)[j])->num) == '0')
		{
			top = j;
			break;
		}
	}
	memcpy(((player->playerCardStack)[top])->num, card->num, BYTES_FOR_SINGLE_NUM);
	memcpy(((player->playerCardStack)[top])->color, card->color, BYTES_FOR_SINGLE_COLOR);
	return STATUS_SUCCESS;
}
GAME_STATUS convertPlayerCardStackIntoMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo, _OUT_ int*** cardMatrix)
{
	int loop_flag = 0;
	for (int cardIndex = 0; cardIndex < COUNT_OF_ALL; cardIndex++)
	{
		for (int numIndex = 0; numIndex < COUNT_OF_NUM && !loop_flag; numIndex++)
		{
			if (strncmp((player->playerCardStack[cardIndex])->num, combinedInfo[0][numIndex], BYTES_FOR_SINGLE_NUM) == 0)
			{
				for (int colorIndex = 0; colorIndex < COUNT_OF_COLOR; colorIndex++)
				{
					if (strncmp((player->playerCardStack[cardIndex])->color, combinedInfo[1][colorIndex], BYTES_FOR_SINGLE_COLOR) == 0)
					{
						(*cardMatrix)[numIndex][colorIndex] = 1;
						loop_flag = 1;
						break;
					}
				}
			}
		}
		loop_flag = 0;
	}
	return STATUS_SUCCESS;
}
GAME_STATUS judgePlayerCardTypeByCardPlayerMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo)
{
	int rankCount[7] = { 0 };
	int suitCount[4] = { 0 };
	int straightCount = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((player->playerCardMatrix)[i][j] == 1)
			{
				rankCount[i]++;
				suitCount[j]++;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (rankCount[i] == 1)
		{
			straightCount++;
			if (straightCount == 5)
			{
				if (suitCount[0] == 5)
				{
					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][0], combinedInfo[0][i]);
					return 9;
				}
				else if (suitCount[1] == 5)
				{
					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][1], combinedInfo[0][i]);
					return 9;
				}
				else if (suitCount[2] == 5)
				{
					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][2], combinedInfo[0][i]);
					return 9;
				}
				else if (suitCount[3] == 5)
				{
					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][3], combinedInfo[0][i]);
					return 9;
				}
				int tempNum = 0, tempColor = 0;
				for (int i = 6; i >= 0; i--)
				{
					if (rankCount[i] == 1)
					{
						tempNum = i;
						break;
					}
				}
				for (int j = 0; j < 4; j++)
				{
					if ((player->playerCardMatrix)[tempNum][j] == 1)
					{
						tempColor = j;
						break;
					}
				}
				printf("牌型为：顺子(%s%s)\n", combinedInfo[1][tempColor], combinedInfo[0][tempNum]);
				return 5;
			}
		}
		else
		{
			straightCount = 0;
		}
	}
	int pairCount = 0, pairIndex = 0;
	int threeCount = 0, threeIndex = 0;
	for (int i = 0; i < 7; i++)
	{
		if (rankCount[i] == 4)
		{
			printf("牌型为：四条(%s%s)\n", combinedInfo[1][0], combinedInfo[0][i]);
			return 8;
		}
		else if (rankCount[i] == 3)
		{
			threeCount++;
			threeIndex = i;
		}
		else if (rankCount[i] == 2)
		{
			pairCount++;
			pairIndex = i;
		}
	}
	if (threeCount == 1 && pairCount == 1)
	{
		int colorIndex = 0;
		for (int j = 0; j < 4; j++)
		{
			if ((player->playerCardMatrix)[threeIndex][j] == 1)
			{
				colorIndex = j;
				break;
			}
		}
		printf("牌型为：葫芦(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][threeIndex]);
		return 7;
	}
	else if (threeCount == 1)
	{
		int colorIndex = 0;
		for (int j = 0; j < 4; j++)
		{
			if ((player->playerCardMatrix)[threeIndex][j] == 1)
			{
				colorIndex = j;
				break;
			}
		}
		printf("牌型为：三条(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][threeIndex]);
		return 4;
	}
	else if (pairCount == 2)
	{
		int colorIndex = 0;
		for (int j = 0; j < 4; j++)
		{
			if ((player->playerCardMatrix)[pairIndex][j] == 1)
			{
				colorIndex = j;
				break;
			}
		}
		printf("牌型为：两对(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][pairIndex]);
		return 3;
	}
	else if (pairCount == 1)
	{
		int colorIndex = 0;
		for (int j = 0; j < 4; j++)
		{
			if ((player->playerCardMatrix)[pairIndex][j] == 1)
			{
				colorIndex = j;
				break;
			}
		}
		printf("牌型为：一对(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][pairIndex]);
		return 2;
	}
	int tempNum = 0, tempColor = 0;
	for (int i = 6; i >= 0; i--)
	{
		if (rankCount[i] == 1)
		{
			tempNum = i;
			break;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		if ((player->playerCardMatrix)[tempNum][j] == 1)
		{
			tempColor = j;
			break;
		}
	}
	if (suitCount[0] == 5)
	{
		printf("牌型为：同花(%s%s)\n", combinedInfo[1][0], combinedInfo[0][tempNum]);
		return 6;
	}
	else if (suitCount[1] == 5)
	{
		printf("牌型为：同花(%s%s)\n", combinedInfo[1][1], combinedInfo[0][tempNum]);
		return 6;
	}
	else if (suitCount[2] == 5)
	{
		printf("牌型为：同花(%s%s)\n", combinedInfo[1][2], combinedInfo[0][tempNum]);
		return 6;
	}
	else if (suitCount[3] == 5)
	{
		printf("牌型为：同花(%s%s)\n", combinedInfo[1][3], combinedInfo[0][tempNum]);
		return 6;
	}
	printf("牌型为：散牌(%s%s)\n", combinedInfo[1][tempColor], combinedInfo[0][tempNum]);
	return STATUS_SUCCESS;
}
GAME_STATUS calculatePlayerPointsByPlayerCardType(_IN_OUT_ PPlayer player)
{
	return STATUS_SUCCESS;
}
GAME_STATUS resetPersonalChips(_IN_ PPlayer player, _IN_ ULONG newChip)
{
	player->chips = newChip;
	return STATUS_SUCCESS;
}
GAME_STATUS incGameRounds(_IN_ PPlayer player)
{
	player->round++;
	return STATUS_SUCCESS;
}
GAME_STATUS showPlayerCardStackValid(_IN_ PPlayer player)
{
	for (int j = 0; j < MAX_PERSONNAL_CARDS && *(((player->playerCardStack)[j])->num) != '0'; j++)
	{
		printf("Target Player's %ldth Card is %s%s\n", j + 1, ((player->playerCardStack)[j])->color, ((player->playerCardStack)[j])->num);
	}
	return STATUS_SUCCESS;
}
GAME_STATUS showPlayerCardStackMatrix(_IN_ PPlayer player)
{
	for (int i = 0; i < COUNT_OF_NUM; i++)
	{
		for (int j = 0; j < COUNT_OF_COLOR; j++)
		{
			printf("%ld ", (player->playerCardMatrix)[i][j]);
		}
		printf("\n");
	}
	return STATUS_SUCCESS;
}
GAME_STATUS displaySinglePlayerAllInfo(_IN_ PPlayer player)
{
	showPlayerCardStackValid(player);
	printf("Chips now: %ld\n", player->chips);
	printf("Round now: %ld\n", player->round);
	for (int i = 0; i < COUNT_OF_NUM; i++)
	{
		for (int j = 0; j < COUNT_OF_COLOR; j++)
		{
			printf("%ld ", (player->playerCardMatrix)[i][j]);
		}
		printf("\n");
	}
	return STATUS_SUCCESS;
}
GAME_STATUS killPlayerMemory(_OUT_ PPlayer* player)
{
	for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((((*player)->playerCardStack)[j])->num)));
	}
	for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&((((*player)->playerCardStack)[j])->color)));
	}
	for (int j = 0; j < MAX_PERSONNAL_CARDS; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&(((*player)->playerCardStack)[j])));
	}
	ExFreeMemoryToNULL((PVOID)(&((*player)->playerCardStack)));
	for (int j = 0; j < COUNT_OF_NUM; j++)
	{
		ExFreeMemoryToNULL((PVOID)(&(((*player)->playerCardMatrix)[j])));
	}
	ExFreeMemoryToNULL((PVOID)(&((*player)->playerCardMatrix)));
	ExFreeMemoryToNULL((PVOID)(&(*player)));
	return STATUS_SUCCESS;
}
//GAME_STATUS __$Debug$__judgePlayerCardTypeByPlayerCardMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo)
//{
//	int rankCount[7] = { 0 };
//	int suitCount[4] = { 0 };
//	int straightCount = 0;
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if ((player->playerCardMatrix)[i][j] == 1)
//			{
//				rankCount[i]++;
//				suitCount[j]++;
//			}
//		}
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		if (rankCount[i] == 1)
//		{
//			straightCount++;
//			if (straightCount == 5)
//			{
//				if (suitCount[0] == 5)
//				{
//					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][0], combinedInfo[0][i]);
//					return 9;
//				}
//				else if (suitCount[1] == 5)
//				{
//					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][1], combinedInfo[0][i]);
//					return 9;
//				}
//				else if (suitCount[2] == 5)
//				{
//					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][2], combinedInfo[0][i]);
//					return 9;
//				}
//				else if (suitCount[3] == 5)
//				{
//					printf("牌型为：同花顺(%s%s)\n", combinedInfo[1][3], combinedInfo[0][i]);
//					return 9;
//				}
//				int tempNum = 0, tempColor = 0;
//				for (int i = 6; i >= 0; i--)
//				{
//					if (rankCount[i] == 1)
//					{
//						tempNum = i;
//						break;
//					}
//				}
//				for (int j = 0; j < 4; j++)
//				{
//					if ((player->playerCardMatrix)[tempNum][j] == 1)
//					{
//						tempColor = j;
//						break;
//					}
//				}
//				printf("牌型为：顺子(%s%s)\n", combinedInfo[1][tempColor], combinedInfo[0][tempNum]);
//				return 5;
//			}
//		}
//		else
//		{
//			straightCount = 0;
//		}
//	}
//	int pairCount = 0, pairIndex = 0;
//	int threeCount = 0, threeIndex = 0;
//	for (int i = 0; i < 7; i++)
//	{
//		if (rankCount[i] == 4)
//		{
//			printf("牌型为：四条(%s%s)\n", combinedInfo[1][0], combinedInfo[0][i]);
//			return 8;
//		}
//		else if (rankCount[i] == 3)
//		{
//			threeCount++;
//			threeIndex = i;
//		}
//		else if (rankCount[i] == 2)
//		{
//			pairCount++;
//			pairIndex = i;
//		}
//	}
//	if (threeCount == 1 && pairCount == 1)
//	{
//		int colorIndex = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			if ((player->playerCardMatrix)[threeIndex][j] == 1)
//			{
//				colorIndex = j;
//				break;
//			}
//		}
//		printf("牌型为：葫芦(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][threeIndex]);
//		return 7;
//	}
//	else if (threeCount == 1)
//	{
//		int colorIndex = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			if ((player->playerCardMatrix)[threeIndex][j] == 1)
//			{
//				colorIndex = j;
//				break;
//			}
//		}
//		printf("牌型为：三条(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][threeIndex]);
//		return 4;
//	}
//	else if (pairCount == 2)
//	{
//		int colorIndex = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			if ((player->playerCardMatrix)[pairIndex][j] == 1)
//			{
//				colorIndex = j;
//				break;
//			}
//		}
//		printf("牌型为：两对(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][pairIndex]);
//		return 3;
//	}
//	else if (pairCount == 1)
//	{
//		int colorIndex = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			if ((player->playerCardMatrix)[pairIndex][j] == 1)
//			{
//				colorIndex = j;
//				break;
//			}
//		}
//		printf("牌型为：一对(%s%s)\n", combinedInfo[1][colorIndex], combinedInfo[0][pairIndex]);
//		return 2;
//	}
//	int tempNum = 0, tempColor = 0;
//	for (int i = 6; i >= 0; i--)
//	{
//		if (rankCount[i] == 1)
//		{
//			tempNum = i;
//			break;
//		}
//	}
//	for (int j = 0; j < 4; j++)
//	{
//		if ((player->playerCardMatrix)[tempNum][j] == 1)
//		{
//			tempColor = j;
//			break;
//		}
//	}
//	if (suitCount[0] == 5)
//	{
//		printf("牌型为：同花(%s%s)\n", combinedInfo[1][0], combinedInfo[0][tempNum]);
//		return 6;
//	}
//	else if (suitCount[1] == 5)
//	{
//		printf("牌型为：同花(%s%s)\n", combinedInfo[1][1], combinedInfo[0][tempNum]);
//		return 6;
//	}
//	else if (suitCount[2] == 5)
//	{
//		printf("牌型为：同花(%s%s)\n", combinedInfo[1][2], combinedInfo[0][tempNum]);
//		return 6;
//	}
//	else if (suitCount[3] == 5)
//	{
//		printf("牌型为：同花(%s%s)\n", combinedInfo[1][3], combinedInfo[0][tempNum]);
//		return 6;
//	}
//	printf("牌型为：散牌(%s%s)\n", combinedInfo[1][tempColor], combinedInfo[0][tempNum]);
//	return STATUS_SUCCESS;
//}