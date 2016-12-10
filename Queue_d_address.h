#ifndef QUEUE
#define QUEUE
#include<stdio.h>
#include"dentry.h"
#include<stdlib.h>
#define QUEUE_EMPTY 1
#define QUEUE_NULL -1


typedef struct _QUEUE_NODE{
	struct _QUEUE_NODE *next;
	d_address data;
}QueueNode_d_address;

typedef struct _QUEUE{
	QueueNode_d_address* head;
	QueueNode_d_address* tail;
	int count;
}Queue_d_address;

void InitQueue(Queue_d_address* queue);
void Enqueue(Queue_d_address* queue,d_address* pT);
void Dequeue(Queue_d_address* queue,d_address* pT);
int IsQueueEmpty(Queue_d_address* queue);
void DestroyQueue(Queue_d_address* queue);

//初始化队列
void InitQueue(Queue_d_address* queue){
        queue->head = (QueueNode_d_address *)malloc(sizeof(QueueNode_d_address));
	queue->tail = queue->head;
	queue->head->next = NULL;
	queue->count = 0;
}

//入队列
void Enqueue(Queue_d_address* queue,d_address* pT){
	if(IsQueueEmpty(queue) != QUEUE_NULL){
		QueueNode_d_address* pQueueNode_d_address =(QueueNode_d_address *) malloc(sizeof(QueueNode_d_address));
		pQueueNode_d_address->data = *pT;
		pQueueNode_d_address->next = NULL;
		queue->tail->next = pQueueNode_d_address;
		queue->tail = pQueueNode_d_address;
		queue->count++;
	}
}

//出队列
void Dequeue(Queue_d_address* queue,d_address* pT){
	if(!IsQueueEmpty(queue)){	
		QueueNode_d_address* pDel = queue->head->next;
		queue->head->next = pDel->next;
		*pT = pDel->data;
		free(pDel);
		queue->count--;
	}
}
//队列是否为空
int IsQueueEmpty(Queue_d_address* queue){
	if(queue == NULL){
		printf("Error, The queue doesn't exist!\n");
		return QUEUE_NULL;
	}
	if(queue->count == 0)
		return QUEUE_EMPTY;
	return 0;
}

//删除队列
void DestroyQueue(Queue_d_address* queue){
	if(queue !=NULL){
		QueueNode_d_address *pTraverse,*pDel;
		for(pDel=pTraverse=queue->head;pDel!=NULL;pDel = pTraverse){
			pTraverse = pTraverse->next;
			free(pDel);
		}
		free(pTraverse);
	}
}

#endif
