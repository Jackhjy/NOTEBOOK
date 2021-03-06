//example\rime\example-abc.c线程解析


/**
#define PROCESS_EVENT_NONE            0x80
#define PROCESS_EVENT_INIT            0x81
#define PROCESS_EVENT_POLL            0x82
#define PROCESS_EVENT_EXIT            0x83
#define PROCESS_EVENT_SERVICE_REMOVED 0x84
#define PROCESS_EVENT_CONTINUE        0x85
#define PROCESS_EVENT_MSG             0x86
#define PROCESS_EVENT_EXITED          0x87
#define PROCESS_EVENT_TIMER           0x88
#define PROCESS_EVENT_COM             0x89
#define PROCESS_EVENT_MAX             0x8a

#define PROCESS_BROADCAST NULL
#define PROCESS_ZOMBIE ((struct process *)0x1)
*/


/**
1，timer
    该模块以clock的tick作为时间精度，设定定时器，等待时间到达以后触发，需要轮询调用；
2，stimer
    该模块以second作为时间精度，设定定时器，等待时间到达以后触发，需要轮询调用；
3，ctimer
    该模块调用etimer，触发以后调用回调函数；
4，etimer
    该模块调用timer，当定时器超时触发以后以事件的方式通知绑定定时器的线程；
5，rtimer
    该模块直接调用硬件平台，设定一个硬件实时定时器，触发以后调用一个定时器回调；
*/


/*
typedef unsigned char process_event_t;
typedef void *        process_data_t;
typedef unsigned char process_num_events_t;
*/

/**
*
#define LC_INIT(s) s = 0;

#define LC_RESUME(s) switch(s) { case 0:

#define LC_SET(s) s = __LINE__; case __LINE__:

#define LC_END(s) }
*/


/*
struct pt {
  lc_t lc;
};

#define PT_WAITING 0
#define PT_YIELDED 1
#define PT_EXITED  2
#define PT_ENDED   3

#define PT_INIT(pt)   LC_INIT((pt)->lc)

#define PT_THREAD(name_args) char name_args

#define PT_BEGIN(pt) { char PT_YIELD_FLAG = 1; if (PT_YIELD_FLAG) {;} LC_RESUME((pt)->lc)

#define PT_END(pt) LC_END((pt)->lc); PT_YIELD_FLAG = 0; \
                   PT_INIT(pt); return PT_ENDED; }

#define PT_WAIT_UNTIL(pt, condition)	        \
  do {						\
    LC_SET((pt)->lc);				\
    if(!(condition)) {				\
      return PT_WAITING;			\
    }						\
  } while(0)
  
#define PT_WAIT_WHILE(pt, cond)  PT_WAIT_UNTIL((pt), !(cond))

#define PT_WAIT_THREAD(pt, thread) PT_WAIT_WHILE((pt), PT_SCHEDULE(thread))

#define PT_SPAWN(pt, child, thread)		\
  do {						\
    PT_INIT((child));				\
    PT_WAIT_THREAD((pt), (thread));		\
  } while(0)

#define PT_RESTART(pt)				\
  do {						\
    PT_INIT(pt);				\
    return PT_WAITING;			\
  } while(0)  

#define PT_EXIT(pt)				\
  do {						\
    PT_INIT(pt);				\
    return PT_EXITED;			\
  } while(0)

#define PT_SCHEDULE(f) ((f) < PT_EXITED)  

#define PT_YIELD(pt)				\
  do {						\
    PT_YIELD_FLAG = 0;				\
    LC_SET((pt)->lc);				\
    if(PT_YIELD_FLAG == 0) {			\
      return PT_YIELDED;			\
    }						\
  } while(0)

#define PT_YIELD_UNTIL(pt, cond)		\
  do {						\
    PT_YIELD_FLAG = 0;				\
    LC_SET((pt)->lc);				\
    if((PT_YIELD_FLAG == 0) || !(cond)) {	\
      return PT_YIELDED;			\
    }						\
  } while(0)

*/

/**
PROCESS_CONTEXT_BEGIN 和PROCESS_CONTEXT_END 。这两个宏搭配使用，就是用来保存当前process_current指针的，用完后再将其恢复。
*/

/**
		1)  __VA_ARGS__ 是一个可变参数的宏，很少人知道这个宏，
		这个可变参数的宏是新的C99规范中新增的，目前似乎只有gcc支持
		（VC6.0的编译器不支持）。宏前面加上##的作用在于，
		当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,
		否则会编译出错, 你可以试试。__VA_ARGS__只能是一些不含任何变量的字符串常量
　　2) __FILE__ 宏在预编译时会替换成当前的源文件名
　　3) __LINE__宏在预编译时会替换成当前的行号
　　4) __FUNCTION__宏在预编译时会替换成当前的函数名称
*/
//PROCESS(example_abc_process, "ABC example");
char  process_thread_example_abc_process(struct pt *process_pt,ev,data);		
struct process example_abc_process = { NULL, "ABC example",process_thread_example_abc_process}

//AUTOSTART_PROCESSES(&example_abc_process);
struct process * const autostart_processes[] = {&example_abc_process, NULL}


//PROCESS_THREAD(example_abc_process, ev, data)
char  process_thread_example_abc_process(struct pt *process_pt,ev,data)
{
	static struct etimer et;
	if(ev ==  PROCESS_EVENT_EXIT)
		{
			abc_close(&abc);;
			}
	{//一定要注意这一对括号
		char PT_YIELD_FLAG=1;
		if(PT_YIELD_FLAG)
			{
				;
				}
		switch (process_pt->lc)//要注意这一对括号哦！LC_RESUME((pt->lc))	
		{
			case 0:

						abc_open(&abc,128,&abc_call);
						while(1)
						{
								etimer_set(&et,CLOCK_SECOND*2+random_rand()%(CLOCK_SECOND * 2));
								do
								{
									PT_YIELD_FLAG=0;
									process_pt->lc = __LINE__;//LC_SET((pt)->lc);
			case __LINE__ :
									if((PT_YIELD_FLAG == 0)||!(et->p==PROCESS_NONE))
										{
											return PT_YIELDED;
											}
									}while(0);
								packetbuf_copyfrom("Hello", 6);
    						abc_send(&abc);
    						printf("abc message sent\n");
							}	
		
		}//要注意这一对括号哦！LC_END((pt)->lc);
		PT_YIELD_FLAG=0;
		process_pt->lc=0;
		return PT_ENDED;
	}//一定要注意这一对括号
		
	}