XENO_PATH := /usr/xenomai/include
XENO_LIBS := /usr/xenomai/lib
CC := gcc
CFLAGS := -Wall -lrtdm -lpthread_rt -lnative -lxenomai -lrt -I$(XENO_PATH) -L$(XENO_LIBS)

SOURCES1 := xddp_test.c
SOURCES2 := task_test.c

xddp_test: $(SOURCES1)
	$(CC) -o xddp_test $(SOURCES1) $(CFLAGS)

task_test: $(SOURCES2)
	$(CC) -o task_test $(SOURCES2) $(CFLAGS)
