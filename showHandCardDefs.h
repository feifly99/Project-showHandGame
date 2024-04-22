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
	initialCard���ܣ���ʼ��һ�ſ��� ���루��PCard���Ϳ��ƣ���ָ�룩�������С�ͻ�ɫ������ָ���ʼ����
GAME_STATUS initialSentCardsStack(_OUT_ PCard** stack);
	initialSentCardsStack���ܣ���ʼ��һ��25��Ԫ�ص�PCard���飬25����˼����Ϸ���������ֻ��25���ơ� ���루��PCard*���͵�ջ����ָ�룩�����ʼ����
GAME_STATUS getCombinedInfo(_OUT_ char**** combinedInfo);
	getCombinedInfo���ܣ��ѳ���������ƴ�С���ƻ�ɫ����һ������ָ���С������Ƶ�������Ϣ�������ɴ�ָ�뵼���� ����&(char***)����combinedInfo��ʼ����
GAME_STATUS verifyCardAlreadySent(_IN_ PCard card, _IN_ PCard* stack, _OUT_ INT* flag, _OUT_ INT* loc);
	verifyCardAlreadySent���ܣ���֤һ�����Ƿ��Ѿ��ڱ���������ջ�С� ���룺������PCard���Ϳ��ƺ��ѷ��Ƶ�ջ�����flag��־Ϊ1��û������Ϊ0���ѷ��� ���loc��־����
	������ջ�е�λ�ã�
GAME_STATUS pushCardIntoStack(_IN_ PCard card, _IN_OUT_ PCard* stack);
	pushCardIntoStack���ܣ���initialSentCardsStackΪһ��������ָ�����������ջ�����飬�˺�����һ���ƴ���������ջ����ִ�д˺��������ſ��ƽ�����ջ�����Ҳౣ�棻
GAME_STATUS displaySentStackValid(_IN_ PCard* stack);
	displaySentStackValid���ܣ�չʾ����ǰ��ջ��������Ч�ơ� ����PCard*���͵�ջ���ɡ���ע��initialSentCardsStack��������ǣ���PCard*���͵�ջ����ָ�룩����
GAME_STATUS displayAllStack(_IN_ PCard* stack);
	displayAllStack���ܣ�չʾ����ǰ��ջ������Ԫ�ء�û�б��������Ƴ�ʼ�������ԡ��޻�0��չ�֡� ����PCard*���͵�ջ���ɣ�
GAME_STATUS clearSentCardsStack(_IN_OUT_ PCard* stack);
	clearSentCardsStack���ܣ����ѷ���ջ�������ƶ���ʼ��Ϊ���޻�0�����˺��������¿�ʼ��Ϸʱ���õ��� ����PCard*���͵�ջ���ɣ�
GAME_STATUS killCardMemory(_OUT_ PCard* card);
	killCardMemory���ܣ��ͷŵ�һ�ſ�Ƭ���ڴ档���롰��PCard���Ϳ��ƣ���ָ�롱��
GAME_STATUS killStackMemory(_OUT_ PCard** stack);
	killStackMemory���ܣ��ͷŵ��ѷ���ջ���ڴ档���롰��PCard*���͵�ջ����ָ�롱��
GAME_STATUS killCombinedInfoMemory(_OUT_ char**** combinedInfo);
	killCombinedInfoMemory���ܣ��ͷŵ������Ƶ�ָ�롣���루������ָ��combinedInfo����ָ�룩��
*/