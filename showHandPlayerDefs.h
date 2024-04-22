#ifndef __showHandPlayerDefs__
#define __showHandPlayerDefs__
extern char* g_initialCardNum; // From cardFunctions.c extern g_initialCardNum
extern char* g_initialCardColor; // From cardFunctions.c extern g_initialCardColor
#include "showHandDefs.h"
GAME_STATUS initialPlayerInfo(_OUT_ PPlayer* player);
GAME_STATUS sentSingleCardToPlayer(_IN_ PCard card, _IN_ PPlayer player);
GAME_STATUS convertPlayerCardStackIntoMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo, _OUT_ int*** cardMatrix);
GAME_STATUS judgePlayerCardTypeByCardPlayerMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo);
GAME_STATUS calculatePlayerPointsByPlayerCardType(_IN_OUT_ PPlayer player);
GAME_STATUS resetPersonalChips(_IN_ PPlayer player, _IN_ ULONG newChip);
GAME_STATUS incGameRounds(_IN_ PPlayer player);
GAME_STATUS showPlayerCardStackValid(_IN_ PPlayer player);
GAME_STATUS showPlayerCardStackMatrix(_IN_ PPlayer player);
GAME_STATUS displaySinglePlayerAllInfo(_IN_ PPlayer player);
GAME_STATUS killPlayerMemory(_OUT_ PPlayer* player);
//GAME_STATUS __$Debug$__judgePlayerCardTypeByPlayerCardMatrix(_IN_ PPlayer player, _IN_ char*** combinedInfo);
#endif