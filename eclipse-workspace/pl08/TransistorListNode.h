#ifndef TRANSISTORNODE_H_
#define TRANSISTORNODE_H_

typedef struct TransistorListNode_struct {
	char model[50];
	double maxVoltage;
	double maxCurrent;
	struct TransistorListNode_struct* nextNodePtr;
}TransistorListNode;

void CreateTransitorListNode(TransistorListNode* thisNode, char modelInit[], double maxVoltageInit, double maxCurrentInit, TransistorListNode* nextLoc);
void InsertTransistorListNodeAfter(TransistorListNode* thisNode, TransistorListNode* newNode);
void SetNextTransistorListNode(TransistorListNode* thisNode, TransistorListNode* newNode);
TransistorListNode* GetNextTransistorListNode();
void PrintTransistorListNode();

#endif
