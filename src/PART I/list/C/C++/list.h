#include <stdlib.h>
#include <stdio.h>
#include <stderror.h>

typedef struct data
{
	int d;
} data;

typedef struct sd_node
{
	data _data;
	sd *next;
}sd;

typedef struct dd_node
{
	data _data;
	dd *pre;
	dd *next;
}dd;

//operations

/** create **/
sd *create_sd(data d);
dd *create_dd(data d);

/** add **/
void add_sd(sd* pre, data d);
void add_dd(dd* pre, data d);

/** delete **/
int delete_sd(sd *pre);
int delete_dd(sd *pre);

/** search **/
sd* search_sd(data d);
dd* search_dd(data d);

/** change **/
int change_sd(data d);
int change_dd(data d);

/** reverse **/
void reverse_sd(sd *sd);
void reverse_dd(dd *dd);

/** compare **/
void compare_sd(sd *sd);
void compare_dd(dd *dd);

/** merge **/
sd *merge(sd *sd1, sd *sd2);
dd *merge(dd *dd1, dd *dd2);