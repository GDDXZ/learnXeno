#include <stdio.h>
#include <rtdm/rtdm.h>
#include <native/task.h>
#include <rtdk.h>
#include <pthread.h>

#define PERIOD_NS 2000000 // 2ms

RT_TASK myTask;

void myTask_proc(void * arg)
{
	int count = 0, num = 0;
    char c;
	rt_task_set_periodic(NULL, TM_NOW, PERIOD_NS); // ns
	while(1)
    {
        rt_task_wait_period(NULL);

        if (count == 0){
        	rt_printf("%d\n", num);
        	count = 499;
        	num++;}
        else{
        	count --;
        }
        if (num >= 5)
        	break;
    }
    //rt_printf("\n");
    c = getchar();
    printf("delete rt_task...\n");
    rt_task_delete(NULL);
}

int main()
{
	int ret;
    /* Perform auto-init of rt_print buffers if the task doesn't do so */
    rt_print_auto_init(1);
	ret = rt_task_create(&myTask, "myTask", 0, 90, T_FPU);

	ret = rt_task_start(&myTask, &myTask_proc, NULL);

	sleep(10);

    printf("End of Program\n");
	return 0;
}