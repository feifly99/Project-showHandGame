#pragma once
#ifndef __showHandDefs__
#define __showHandDefs__
#endif 
//�������ͷ�ļ������
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//�������ͷ�ļ������
//���Ͷ����
typedef int GAME_STATUS;
//���Ͷ����
//�ṹ�����
typedef struct _Card
{
	char* num;
	char* color;
}Card, * PCard;
typedef struct _Player
{
	PCard* playerCardStack;
	int** playerCardMatrix;
	ULONG chips;
	int round;
	int credits;
	int points;
}Player, * PPlayer;
//�ṹ�����
//�β����Ժ궨���
#ifndef _IN_
#define _IN_
#endif
#ifndef _OUT_
#define _OUT_
#endif
#ifndef _IN_OUT_
#define _IN_OUT_
#endif
//�β����Ժ궨���
//�������Ժ궨���
#define COUNT_OF_NUM 7
#define COUNT_OF_COLOR 4
#define COUNT_OF_EXTERNAL 4
#define COUNT_OF_ALL 5
#define BYTES_FOR_SINGLE_NUM 3
#define BYTES_FOR_SINGLE_COLOR 7
#define MAX_POSSIBLE_CARDS 25
#define MAX_PERSONNAL_CARDS 5
#define CARD_ATTRIBUTION_TYPES 2
//�������Ժ궨���
//�������궨���
#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS 0
#endif
#define MEMORY_FAILED_ALLOCATE 0x00000001
#define INVALID_STACK_LOCATION 0x00000002
#define NULL_MEMORY_INPUT 0x00000003
//�������궨���
//���ܺ궨���
#define merge(sta1, sta2) (sta1 ## sta2)
#define CHECK_RETURN_WITH_STATUS(status) \
do\
{\
	if((status) != 0x0)\
	{\
		printf("Operation: %s Failed. Error Code: %ld\n", #status, (status));\
	}\
	else\
	{\
		printf("Operation: %s Successfully. Returned code: %ld\n", #status, (status));\
	}\
}while(0);
#define TEST_MEMORY(address) \
do\
{\
	if((ULONG)(address) == 0) \
	{\
		printf("Address: %s is NULL\n", #address);\
	}\
	else\
	{\
		printf("Address: %s exists\n", #address);\
	}\
}while(0);
#define PRINT_SENTENCE(sentence) \
do\
{\
	printf("%s\n", #sentence);\
}while(0);
//���ܺ궨���

