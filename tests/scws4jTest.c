/*
 * File:   scws4jTest.c
 * Author: intexh
 *
 * Created on Sep 24, 2014, 9:25:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "scws.h"

int main() {
    char *dic_path = "../dict.utf8.xdb";
    char *rules = "../rules";
    
    scws_t t = scws_new();
    scws_set_dict(t,dic_path,1);
    scws_set_charset(t,"utf-8");
    scws_set_rule(t,rules);
    scws_set_ignore(t,1);
    scws_set_multi(t,1);
    scws_set_debug(t,1);
    scws_set_duality(t,1);
    char *txt = "我是中国人！！！";
    scws_send_text(t,txt,strlen(txt));
    int count=0;
    scws_res_t res_t = scws_get_result(t,&count);
    scws_res_t cur;

    while ((cur = res_t) != NULL){
        printf("Start=%d Length=%d Idf=%d Attr=%s\n",
        res_t->off,res_t->len,res_t->idf,&(res_t->attr));
        res_t = cur->next;
	free(cur);
    }
}
