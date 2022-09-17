#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名栈数据元素类型
typedef int ElemType;

//定义结构体类型(队列节点)
typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
} QueueNode;

//定义结构体类型(队列)
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	size_t size;
} Queue;

//初始化队列
void Init_Queue(Queue* ptr);

//向队列尾部插入元素
void Push_Queue(Queue* ptr, ElemType data);

//从首端弹出元素
void Pop_Queue(Queue* ptr);

//获取队列的首端元素数据
ElemType Front_Queue(Queue* ptr);

//获取队列的尾部元素数据
ElemType Back_Queue(Queue* ptr);

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr);

//获取队列中的元素个数
size_t Size_Queue(Queue* ptr);

//销毁队列
void Destroy_Queue(Queue* ptr);