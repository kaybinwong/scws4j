/*
 * File:   scws4jTest.c
 * Author: intexh
 *
 * Created on Sep 24, 2014, 9:25:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "scws.h"

void test_scws();
void test_cjson();
void test_scws_get_tops();

void test_scws_with_cjson();
void test_scws_get_tops_with_cjson();

int main() {
    //test scws
    //test_scws();    
    //test_scws_get_tops();


    //test_cjson();
    //test_scws_with_cjson();
    test_scws_get_tops_with_cjson();
}

/* Parse text to JSON, then render back to text, and print! */
void doit(char *text) {
    char *out;
    cJSON *json;

    json = cJSON_Parse(text);
    if (!json) {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    } else {
        out = cJSON_Print(json);
        cJSON_Delete(json);
        printf("%s\n", out);
        free(out);
    }
}

/* Read a file, parse, render back, etc. */
void dofile(char *filename) {
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *data = (char*) malloc(len + 1);
    fread(data, 1, len, f);
    fclose(f);
    doit(data);
    free(data);
}

/* Used by some code below as an example datatype. */
struct record {
    const char *precision;
    double lat, lon;
    const char *address, *city, *state, *zip, *country;
};

/* Create a bunch of objects as demonstration. */
void create_objects() {
    cJSON *root, *fmt, *img, *thm, *fld;
    char *out;
    int i; /* declare a few. */

    /* Here we construct some JSON standards, from the JSON site. */

    /* Our "Video" datatype: */
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
    cJSON_AddItemToObject(root, "format", fmt = cJSON_CreateObject());
    cJSON_AddStringToObject(fmt, "type", "rect");
    cJSON_AddNumberToObject(fmt, "width", 1920);
    cJSON_AddNumberToObject(fmt, "height", 1080);
    cJSON_AddFalseToObject(fmt, "interlace");
    cJSON_AddNumberToObject(fmt, "frame rate", 24);

    out = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n", out);
    free(out); /* Print to text, Delete the cJSON, print it, release the string. */

    /* Our "days of the week" array: */
    const char *strings[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    root = cJSON_CreateStringArray(strings, 7);

    out = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n", out);
    free(out);

    /* Our matrix: */
    int numbers[3][3] = {
        {0, -1, 0},
        {1, 0, 0},
        {0, 0, 1}
    };
    root = cJSON_CreateArray();
    for (i = 0; i < 3; i++) cJSON_AddItemToArray(root, cJSON_CreateIntArray(numbers[i], 3));

    /*	cJSON_ReplaceItemInArray(root,1,cJSON_CreateString("Replacement")); */

    out = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n", out);
    free(out);


    /* Our "gallery" item: */
    int ids[4] = {116, 943, 234, 38793};
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "Image", img = cJSON_CreateObject());
    cJSON_AddNumberToObject(img, "Width", 800);
    cJSON_AddNumberToObject(img, "Height", 600);
    cJSON_AddStringToObject(img, "Title", "View from 15th Floor");
    cJSON_AddItemToObject(img, "Thumbnail", thm = cJSON_CreateObject());
    cJSON_AddStringToObject(thm, "Url", "http:/*www.example.com/image/481989943");
    cJSON_AddNumberToObject(thm, "Height", 125);
    cJSON_AddStringToObject(thm, "Width", "100");
    cJSON_AddItemToObject(img, "IDs", cJSON_CreateIntArray(ids, 4));

    out = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n", out);
    free(out);

    /* Our array of "records": */
    struct record fields[2] = {
        {"zip", 37.7668, -1.223959e+2, "", "SAN FRANCISCO", "CA", "94107", "US"},
        {"zip", 37.371991, -1.22026e+2, "", "SUNNYVALE", "CA", "94085", "US"}
    };

    root = cJSON_CreateArray();
    for (i = 0; i < 2; i++) {
        cJSON_AddItemToArray(root, fld = cJSON_CreateObject());
        cJSON_AddStringToObject(fld, "precision", fields[i].precision);
        cJSON_AddNumberToObject(fld, "Latitude", fields[i].lat);
        cJSON_AddNumberToObject(fld, "Longitude", fields[i].lon);
        cJSON_AddStringToObject(fld, "Address", fields[i].address);
        cJSON_AddStringToObject(fld, "City", fields[i].city);
        cJSON_AddStringToObject(fld, "State", fields[i].state);
        cJSON_AddStringToObject(fld, "Zip", fields[i].zip);
        cJSON_AddStringToObject(fld, "Country", fields[i].country);
    }

    /*	cJSON_ReplaceItemInObject(cJSON_GetArrayItem(root,1),"City",cJSON_CreateIntArray(ids,4)); */

    out = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n", out);
    free(out);

}

void test_cjson() {
    /* a bunch of json: */
    char text1[] = "{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";
    char text2[] = "[\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"]";
    char text3[] = "[\n    [0, -1, 0],\n    [1, 0, 0],\n    [0, 0, 1]\n	]\n";
    char text4[] = "{\n		\"Image\": {\n			\"Width\":  800,\n			\"Height\": 600,\n			\"Title\":  \"View from 15th Floor\",\n			\"Thumbnail\": {\n				\"Url\":    \"http:/*www.example.com/image/481989943\",\n				\"Height\": 125,\n				\"Width\":  \"100\"\n			},\n			\"IDs\": [116, 943, 234, 38793]\n		}\n	}";
    char text5[] = "[\n	 {\n	 \"precision\": \"zip\",\n	 \"Latitude\":  37.7668,\n	 \"Longitude\": -122.3959,\n	 \"Address\":   \"\",\n	 \"City\":      \"SAN FRANCISCO\",\n	 \"State\":     \"CA\",\n	 \"Zip\":       \"94107\",\n	 \"Country\":   \"US\"\n	 },\n	 {\n	 \"precision\": \"zip\",\n	 \"Latitude\":  37.371991,\n	 \"Longitude\": -122.026020,\n	 \"Address\":   \"\",\n	 \"City\":      \"SUNNYVALE\",\n	 \"State\":     \"CA\",\n	 \"Zip\":       \"94085\",\n	 \"Country\":   \"US\"\n	 }\n	 ]";

    /* Process each json textblock by parsing, then rebuilding: */
    doit(text1);
    doit(text2);
    doit(text3);
    doit(text4);
    doit(text5);

    /* Parse standard testfiles: */
    /*	dofile("../../tests/test1"); */
    /*	dofile("../../tests/test2"); */
    /*	dofile("../../tests/test3"); */
    /*	dofile("../../tests/test4"); */
    /*	dofile("../../tests/test5"); */

    /* Now some samplecode for building objects concisely: */
    create_objects();
}

void test_scws() {
    char *dic_path = "/home/intexh/NetBeansProjects/scws4jTest/dict.utf8.xdb";
    char *rules = "/home/intexh/NetBeansProjects/scws4jTest/rules";

    scws_t t = scws_new();
    scws_set_dict(t, dic_path, 1);
    scws_set_charset(t, "utf-8");
    scws_set_rule(t, rules);
    scws_set_ignore(t, 0);
    scws_set_multi(t, 1);
    scws_set_debug(t, 0);
    scws_set_duality(t, 0);
    scws_res_t res, cur;
    char *text = "Hello, 我名字叫李那曲是一个中国人, 我有时买Q币来玩, 我还听说过C#语言";
    scws_send_text(t, text, strlen(text));
    while (res = cur = scws_get_result(t)) {
        while (cur != NULL) {
            printf("WORD: %.*s/%s (IDF = %4.2f) Offset:%d Attr: %s\n", cur->len, t->txt + cur->off, cur->attr, cur->idf, cur->off, cur->attr);
            cur = cur->next;
        }
        scws_free_result(res);
    }
    scws_free(t);
}

static char* substring(char*dst, char*src, int start, int n) {
    char *p = src;
    char *q = dst;
    int len = strlen(p);
    if (n > len) n = len - start;
    if (start < 0) start = 0;
    if (start > len) return NULL;
    p += start;
    while (n--) *(q++) = *(p++);
    *(q++) = '\0';
    return dst;
}

void test_scws_get_tops() {
    char *dic_path = "/home/intexh/NetBeansProjects/scws4jTest/dict.utf8.xdb";
    char *rules = "/home/intexh/NetBeansProjects/scws4jTest/rules";

    scws_t t = scws_new();
    scws_set_dict(t, dic_path, 1);
    scws_set_charset(t, "utf-8");
    scws_set_rule(t, rules);
    scws_set_ignore(t, 0);
    scws_set_multi(t, 1);
    scws_set_debug(t, 0);
    scws_set_duality(t, 0);
    scws_top_t res, cur;
    char *text = "Hello, 我名字叫李那曲是一个中国人, 我有时买Q币来玩, 我还听说过C#语言";
    scws_send_text(t, text, strlen(text));
    res = cur = scws_get_tops(t, 10, "n");
    while (cur != NULL) {
        printf("WORD: %s/%s (Weight = %4.2f) Times:%d\n", cur->word, cur->attr, cur->weight, cur->times);
        cur = cur->next;
    }
    scws_free_tops(res);
    scws_free(t);
}

void test_scws_get_tops_with_cjson(){
    cJSON *root,*fld;
    char *dic_path = "/home/intexh/NetBeansProjects/scws4jTest/dict.utf8.xdb";
    char *rules = "/home/intexh/NetBeansProjects/scws4jTest/rules";

    scws_t t = scws_new();
    scws_set_dict(t, dic_path, 1);
    scws_set_charset(t, "utf-8");
    scws_set_rule(t, rules);
    scws_set_ignore(t, 0);
    scws_set_multi(t, 1);
    scws_set_debug(t, 0);
    scws_set_duality(t, 0);
    scws_top_t res, cur;
    char *text = "Hello, 我名字叫李那曲是一个中国人, 我有时买Q币来玩, 我还听说过C#语言";
    scws_send_text(t, text, strlen(text));
    res = cur = scws_get_tops(t, 10, "n");
    root=cJSON_CreateArray();
    while (cur != NULL) {
        //printf("WORD: %s/%s (Weight = %4.2f) Times:%d\n", cur->word, cur->attr, cur->weight, cur->times);
        cJSON_AddItemToArray(root,fld=cJSON_CreateObject());
        cJSON_AddStringToObject(fld, "word", cur->word);
        cJSON_AddNumberToObject(fld,"weight", cur->weight);   
        cJSON_AddNumberToObject(fld,"times", cur->times);            
        cJSON_AddStringToObject(fld,"attr", cur->attr);
        cur = cur->next;
    }
    scws_free_tops(cur);
    scws_free_tops(res);
    scws_free(t);    
    char *json = cJSON_Print(root);
    cJSON_Delete(root);
    printf("%s\n",json);
}

void test_scws_with_cjson() {
    char *dic_path = "/home/intexh/NetBeansProjects/scws4jTest/dict.utf8.xdb";
    char *rules = "/home/intexh/NetBeansProjects/scws4jTest/rules";

    scws_t t = scws_new();
    scws_set_dict(t, dic_path, 1);
    scws_set_charset(t, "utf-8");
    scws_set_rule(t, rules);
    scws_set_ignore(t, 0);
    scws_set_multi(t, 1);
    scws_set_debug(t, 0);
    scws_set_duality(t, 0);

    scws_res_t res, cur;
    char *text = "Hello, 我名字叫李那曲是一个中国人, 我有时买Q币来玩, 我还听说过C#语言";
    scws_send_text(t, text, strlen(text));
    cJSON *root, *fld;
    root = cJSON_CreateArray();

    while (res = cur = scws_get_result(t)) {
        while (cur != NULL) {
            //handle seg
            printf("WORD: %.*s/%s (IDF = %4.2f)\n", cur->len, text + cur->off, cur->attr, cur->idf);
            cJSON_AddItemToArray(root, fld = cJSON_CreateObject());
            char word[256];
            substring(word, t->txt, cur->off, cur->len);
            cJSON_AddNumberToObject(fld, "offset", cur->off);
            cJSON_AddStringToObject(fld, "word", word);
            cJSON_AddNumberToObject(fld, "idf", cur->idf);
            cJSON_AddStringToObject(fld, "attr", cur->attr);
            //repoint the next
            cur = cur->next;
        }
        scws_free_result(res);
    }
    scws_free(t);
    char *json = cJSON_Print(root);
    printf("%s\n", json);
    cJSON_Delete(root);
}

