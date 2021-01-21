#include "list.h"


// operations
/** create **/
sd *create_sd(data d) {
	sd *p = (sd *)malloc(sizeof(sd) * 1);
	if(p){
		p->_data = d;
		p->next = NULL;
	}
	else{
		printf("%s, %d", __func__, errno);
	}

	return p;
}

dd *create_dd(data d){
	dd *p = (dd *)malloc(sizeof(dd) * 1);
	if(p){
		p->_data = d;
		p->pre = NULL;
		p->next = NULL;
	}
	else{
		printf("%s, %d", __func__, errno);
	}

	return p;
}

/** add **/
void add_sd(sd* pre, data d){
	sd *p = create_sd(d);
	if(p){
		sd *tmp = pre->next;
		pre->next = p;
		p->next = tmp;
	}

	return;
}

void add_dd(dd* pre, data d){
	dd *p = create_dd(d);
	if(p){
		dd *tmp = pre->next;
		pre->next = p;
		p->next = tmp;
	}

	return;
}

/** delete **/
int delete_sd(sd *pre){
	sd *p = pre->next ? pre->next->next : NULL;
	if(p){
		free(pre->next);
		pre->next = p;
	}

	return 0;
}

int delete_dd(dd *p){
	if(p){
		p->pre->next = p->next;
		free(p);
	}

	return 0;
}

/** search **/
sd* search_sd(sd* r, data d){
	sd *s = r;
	if(!s) return NULL;
	if(s->_data == d) return s;
	return search_sd(s->next, d);
}

dd* search_dd(dd* r, data d){
	dd *s = r;
	if(!s) return NULL;
	if(s->_data == d) return s;
	return search_rd(s->next, d);
}

/** change **/
int change_sd(sd* r, data d){
	sd *p = search_sd(r, d);
	if(p){
		p->_data = d;
	}
	else{
		return -1;
	}

	return 0;
}

int change_dd(dd* r, data d){
	dd *p = search_dd(r, d);
	if(p){
		p->_data = d;
	}
	else{
		return -1;
	}

	return 0;
}

/** reverse **/
sd* reverse_sd(sd *p, sd *n){
	sd *tmp = NULL;
	while(n != NULL) {
		tmp = n->next;
		n->next = p;
		p = n;
		n = tmp;
	}

	return p;
}

/* void reverse_dd(dd *dd); */

/** compare **/
void compare_sd(sd *sd);
void compare_dd(dd *dd);

/** merge **/
sd *merge(sd *sd1, sd *sd2);
dd *merge(dd *dd1, dd *dd2);