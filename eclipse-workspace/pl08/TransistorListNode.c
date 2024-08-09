#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TransistorListNode.h"

void CreateTransistorListNode(TransistorListNode* thisNode, char modelInit[], double maxVoltageInit, double maxCurrentInit, TransistorListNode* nextLoc)
{
strcpy(thisNode -> model, modelInit);
thisNode -> maxVoltage = maxVoltageInit;
thisNode -> maxCurrent = maxCurrentInit;
return;
}

void InsertTransistorListNodeAfter(TransistorListNode* thisNode, TransistorListNode* newNode) {
TransistorListNode* tmpNext = NULL;

tmpNext = thisNode -> nextNodePtr;
thisNode -> nextNodePtr = newNode;
newNode -> nextNodePtr = tmpNext;
return;
}

void SetNextTransistorListNode(TransistorListNode* thisNode, TransistorListNode* newNode) {
	thisNode -> nextNodePtr = newNode;
	return;
}

TransistorListNode* GetNextTransistorListNode(TransistorListNode* thisNode) {
	return thisNode -> nextNodePtr;
}

void PrintTransistorListNode(TransistorListNode* thisNode) {
	printf("model: %s\n", thisNode -> model);
	printf("maximum rated voltage (V): %.1f\n", thisNode -> maxVoltage);
	printf("maximum rated current (mA): %.1f\n", thisNode -> maxCurrent);
	return;
}
