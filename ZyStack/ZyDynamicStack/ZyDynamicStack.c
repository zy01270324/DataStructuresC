#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> 

#include "ZyDynamicStack.h" 

//����һ����̬ջ������Ҫָ����С 
pStack create_stack(){
	pStack pAddrStack = (pStack)malloc(sizeof(Stack));
	if(NULL == pAddrStack){
		printf("�ڴ治��!\n");
		exit(-1);
	}
	pAddrStack->pTop = (pNode)malloc(sizeof(Node));
	if(NULL == pAddrStack->pTop){
		printf("�ڴ治��!\n");
		//�ͷſռ� 
		free(pAddrStack);
		exit(-1);
	}
	pAddrStack->pBottom = pAddrStack->pTop;
	//��һ����ʼ��һ��Ҫд���ܿ��ܳ�������Ȼ������Ӧ��д���������������ġ� 
	pAddrStack->ElemNum = 0;
	return pAddrStack;
}

//�ݻٶ�̬ջ
bool destory_stack(pStack *ppAddrStack){
	
	assert(NULL != ppAddrStack);
	assert(NULL != *ppAddrStack);
	
	pNode pTmp = NULL;
	while((*ppAddrStack)->pTop != (*ppAddrStack)->pBottom){
		pTmp = (*ppAddrStack)->pTop;
		(*ppAddrStack)->pTop = (*ppAddrStack)->pTop->pNext;
		free(pTmp);
	}
	//�ͷ�ͷ���
	free((*ppAddrStack)->pTop); 
	//�ͷŶ�̬ջָ���Ӧ�Ŀռ� 
	free(*ppAddrStack);
	*ppAddrStack = NULL; 
	return true;
} 

//ѹջ
bool push_stack(pStack pAddrStack, ElemType DataPush){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew){
		printf("�ڴ治��!\n");
		exit(-1);
	}
	pNew->Data = DataPush;
	pNew->pNext = pAddrStack->pTop;
	pAddrStack->pTop = pNew;
	
	(pAddrStack->ElemNum)++;
	
	return true;
}

//��ջ
bool pop_stack(pStack pAddrStack, ElemType *DataPop){
	if(is_empty_stack(pAddrStack)){
		return false;
	}
	
	*DataPop = pAddrStack->pTop->Data;
	pNode pTmp = pAddrStack->pTop;
	pAddrStack->pTop = pAddrStack->pTop->pNext;
	(pAddrStack->ElemNum)--;
	
	return true;
}

//�ж��Ƿ�Ϊ��ջ
bool is_empty_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	return (0 == pAddrStack->ElemNum);
}

//���ص�ǰջ��Ԫ�ظ��� 
int len_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	return pAddrStack->ElemNum;
}

//������ǰջ
void traverse_stack(pStack pAddrStack){
	//�ж�ջ���Ѿ����˶��� 
	if(is_empty_stack(pAddrStack)){
		printf("���ǿ�ջ��\n");
		return;
	}
	
	pNode pTmp = NULL;
	printf("ջ��Ԫ��Ϊ��");
	for(pTmp = pAddrStack->pTop; pTmp != pAddrStack->pBottom; pTmp = pTmp->pNext){
		printf("%d  ", pTmp->Data);
	}
	printf("\n");
	
} 

