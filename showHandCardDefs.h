#ifndef __showHandCardDefs__
#define __showHandCardDefs__
#include "showHandDefs.h"
GAME_STATUS initialCard(_OUT_ PCard* card, _IN_ char* num, _IN_ char* color);
GAME_STATUS generateSingleRandomCard(_OUT_ PCard* returnedCard, _IN_ char*** combinedInfo);
GAME_STATUS initialSentCardsStack(_OUT_ PCard** stack);
GAME_STATUS getCombinedInfo(_OUT_ char**** combinedInfo);
GAME_STATUS verifyCardAlreadySent(_IN_ PCard card, _IN_ PCard* stack, _OUT_ INT* flag, _OUT_ INT* loc);
GAME_STATUS pushCardIntoStack(_IN_ PCard card, _IN_OUT_ PCard* stack);
GAME_STATUS displaySentStackValid(_IN_ PCard* stack);
GAME_STATUS displayAllStack(_IN_ PCard* stack);
GAME_STATUS clearSentCardsStack(_IN_OUT_ PCard* stack);
GAME_STATUS killCardMemory(_OUT_ PCard* card);
GAME_STATUS killStackMemory(_OUT_ PCard** stack);
GAME_STATUS killCombinedInfoMemory(_OUT_ char**** combinedInfo);
#endif
/*
GAME_STATUS initialCard(_OUT_ PCard* card, _IN_ char* num, _IN_ char* color);
	initialCard功能：初始化一张卡牌 输入（（PCard类型卡牌）的指针）、牌面大小和花色对输入指针初始化；
GAME_STATUS initialSentCardsStack(_OUT_ PCard** stack);
	initialSentCardsStack功能：初始化一个25个元素的PCard数组，25的意思是游戏场面上最多只有25张牌。 输入（（PCard*类型的栈）的指针）对其初始化；
GAME_STATUS getCombinedInfo(_OUT_ char**** combinedInfo);
	getCombinedInfo功能：把场面的所有牌大小和牌花色放在一个三级指针中。这样牌的所有信息都可以由此指针导出。 输入&(char***)来对combinedInfo初始化；
GAME_STATUS verifyCardAlreadySent(_IN_ PCard card, _IN_ PCard* stack, _OUT_ INT* flag, _OUT_ INT* loc);
	verifyCardAlreadySent功能：验证一张牌是否已经在被发出的牌栈中。 输入：待检测的PCard类型卡牌和已发牌的栈。输出flag标志为1则没被发，为0则已发。 输出loc标志着这
	张牌在栈中的位置；
GAME_STATUS pushCardIntoStack(_IN_ PCard card, _IN_OUT_ PCard* stack);
	pushCardIntoStack功能：视initialSentCardsStack为一个从左到右指标依次增大的栈型数组，此函数将一张牌从右向左“入栈”。执行此函数的那张卡牌将会在栈的最右侧保存；
GAME_STATUS displaySentStackValid(_IN_ PCard* stack);
	displaySentStackValid功能：展示出当前牌栈中所有有效牌。 输入PCard*类型的栈即可。（注意initialSentCardsStack中输入的是（（PCard*类型的栈）的指针））；
GAME_STATUS displayAllStack(_IN_ PCard* stack);
	displayAllStack功能：展示出当前牌栈的所有元素。没有被正常的牌初始化的牌以“无花0”展现。 输入PCard*类型的栈即可；
GAME_STATUS clearSentCardsStack(_IN_OUT_ PCard* stack);
	clearSentCardsStack功能：将已发牌栈的所有牌都初始化为“无花0”，此函数在重新开始游戏时会用到。 输入PCard*类型的栈即可；
GAME_STATUS killCardMemory(_OUT_ PCard* card);
	killCardMemory功能：释放掉一张卡片的内存。输入“（PCard类型卡牌）的指针”；
GAME_STATUS killStackMemory(_OUT_ PCard** stack);
	killStackMemory功能：释放掉已发牌栈的内存。输入“（PCard*类型的栈）的指针”；
GAME_STATUS killCombinedInfoMemory(_OUT_ char**** combinedInfo);
	killCombinedInfoMemory功能：释放掉所有牌的指针。输入（（三级指针combinedInfo）的指针）。
*/