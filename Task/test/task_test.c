/*Name: AhmadWattad
  Project: Work Sheet 12 - Data Structures - SL
  Reviewer: Idan
  Date: 23/08/2023
  Version: 1.0
*/


/******************************************************************************/
#include <stdio.h>/*printf*/
#include <stdlib.h>/*malloc*/

#include "task.h"
#include "uid.h"

#define ErrorMsg(expected, result, name) \
	{\
		if (expected == result)\
		{\
			printf("%s has succeeded\n",  name);\
		}\
		else\
		{\
			printf("%s has failed\n",  name);\
		}\
}

#define REPORT(expected	, result, str) \
	{\
	    if (expected != result)\
	    {\
	    	printf("%s has failed\n", str);\
	    }\
	}

static int Compare(const void *data1, const void *data2);
static int Match(const void* data, void* param);
static void CleanUp(void* param);
static int UnschedOp(void* param);
static int ReschedOp(void* param);
static time_t GiveAbsFutureTime(double sec_from_now);

/************************** Forwarded declarations ****************************/

static void UnitTesting();

static void TestTaskCreate(void);
static void TestTaskDestroy(void);
static void TestTaskExecute(void);
static void TestTaskGetTimeToExecute(void);
static void TestTaskGetUID(void);
static void TestTaskUpdateTime(void);
static void TestTaskIsMatch(void);
static void TestTaskCompare(void);
/*********************************** main *************************************/

int main()
{
	UnitTesting();

	return 0;
}




/******************************************************************************/

static void UnitTesting()
{
	TestTaskCreate();
	TestTaskDestroy();
	TestTaskExecute();
	TestTaskGetTimeToExecute();
	TestTaskGetUID();
	TestTaskUpdateTime();
	TestTaskIsMatch();
	TestTaskCompare();
}
/******************************************************************************/	



static void TestTaskCreate(void)
{
	int data = 100;
	time_t t1 = GiveAbsFutureTime(100);
	time_t t2 = GiveAbsFutureTime(200);

	int* alloc_var = (int*)malloc(sizeof(int));

	task_t *task = TaskCreate(t1, ReschedOp, NULL, NULL, NULL);
	task_t *task2 = TaskCreate(t2, UnschedOp, &data, CleanUp, (void*)alloc_var);
	REPORT(FALSE, TaskIsMatch(task, TaskGetUID(task2)), "TestTaskCreate()");

	printf("TestTaskCreate() tested\n");
	TaskDestroy(task);
	TaskDestroy(task2);
}

static void TestTaskDestroy(void)
{
	int data = 100;
	time_t t1 = GiveAbsFutureTime(100);
	task_t *task = TaskCreate(t1, UnschedOp, &data, CleanUp, NULL);

/*	TaskExecute(task);
*/	printf("TestTaskDestroy() tested\n");
	TaskDestroy(task);

}

static void TestTaskExecute(void)
{
	  int res = 100;
		int data = 100;
		int* add_date = &data;
		time_t t1 = GiveAbsFutureTime(100);
	  int res_struct = {0};

		task_t *task = TaskCreate(t1, UnschedOp, add_date, NULL, NULL);
		res = TaskExecute(task);
		REPORT(FALSE, res, "TestTaskExecute()");
/*		REPORT(FALSE, res_struct.sched, "TestTaskCreate()");
*/	printf("TestTaskExecute() tested\n");
		TaskDestroy(task);
}

static void TestTaskGetTimeToExecute(void)
{
	time_t t1 = GiveAbsFutureTime(100);
	task_t *task = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	REPORT(TaskGetTimeToExecute(task), t1, "TestTaskGetTimeToExecute()");

	printf("TestTaskGetTimeToExecute() tested\n");
	TaskDestroy(task);
}

static void TestTaskGetUID(void)
{
	time_t t1 = GiveAbsFutureTime(100);
	task_t *task = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	task_t *task2 = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	
	REPORT(TRUE, TaskIsMatch(task, TaskGetUID(task)),
	 "TestTaskGetUID()");
	REPORT(FALSE, TaskIsMatch(task, TaskGetUID(task2)), "TestTaskGetUID()");

	printf("TestTaskGetUID() tested\n");
	TaskDestroy(task);
}

static void TestTaskUpdateTime(void)
{
	time_t t1 = GiveAbsFutureTime(100);
	time_t res_t = time(NULL);

	task_t *task = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	res_t = (time_t)TaskUpdateTime(task);

	REPORT(TaskGetTimeToExecute(task), t1+100, "TestTaskUpdateTime()");

	printf("TestTaskUpdateTime() tested\n");
	TaskDestroy(task);
}

static void TestTaskIsMatch(void)
{
	time_t t1 = GiveAbsFutureTime(100);
	task_t *task = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	task_t *task2 = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	
	REPORT(TRUE, TaskIsMatch(task, TaskGetUID(task)), "TestTaskIsMatch()");
	REPORT(FALSE, TaskIsMatch(task, TaskGetUID(task2)), "TestTaskIsMatch()");

	printf("TestTaskIsMatch() tested\n");
	TaskDestroy(task);
}

static void TestTaskCompare(void)
{
	time_t t1 = GiveAbsFutureTime(100);
	task_t *task = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	task_t *task2 = TaskCreate(t1, UnschedOp, NULL, CleanUp, NULL);
	
	REPORT(FALSE, TaskIsMatch(task, TaskGetUID(task2)), "TestTaskCompare()");

	printf("TestTaskCompare() tested\n");
	TaskDestroy(task);
}

/*****************************************************************************/
/******************************* Tester Helper Functions  ********************/
/*****************************************************************************/

/* Function to match data & param */
static int Match(const void* data, void* param)
{
    return *((int*)data) == *((int*)param);
}

/* Function to compare data & param */
static int Compare(const void *data1, const void *data2)
{
	return (*((int*)data1) - *((int*)data2));
}

static void CleanUp(void* param)
{
		free(param);
		param = NULL;
}

static int UnschedOp(void* param)
{
	  printf("\tUnschedOp Func Does Nothing\n");
		return DONT_RESCHEDULE;
}

static int ReschedOp(void* param)
{
	  printf("\tReschedOp Func Does Nothing\n");
		return RESCHEDULE;
}

/* Function to calculate a future time */
static time_t GiveAbsFutureTime(double sec_from_now)
{
    time_t currentTime = time(NULL);
    return currentTime + sec_from_now;
}




