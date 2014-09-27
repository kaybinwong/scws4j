#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include "config_win32.h"
#endif

#include "com_intexh_segmentation_impl_scws_SCWSLibrary.h"
#include "scws.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

//external method
scws_t interface;

static char *substring(char*dst, char*src, int start, int n);
static jstring s2Jstring(JNIEnv *env, const char *pat);
static char* jstring2string(JNIEnv *env, jstring jstr);

#define GET_WORDS(env,obj,top_t)\
do{\
    cJSON *root;\
    cJSON *fld;\
    scws_top_t cur = top_t;\
    root=cJSON_CreateArray();\
    while (cur != NULL) {\
        cJSON_AddItemToArray(root,fld=cJSON_CreateObject());\
        cJSON_AddStringToObject(fld, "word", cur->word);\
        cJSON_AddNumberToObject(fld,"weight", cur->weight);  \ 
        cJSON_AddNumberToObject(fld,"times", cur->times);  \          
        cJSON_AddStringToObject(fld,"attr", cur->attr);\
        cur = cur->next;\
    }\
    scws_free_tops(cur);\
    char *json = cJSON_Print(root);\
    cJSON_Delete(root);\
    return s2Jstring(env,json);\
}while(0)

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_create_1new
(JNIEnv *env, jobject obj) {
    interface = scws_new();
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_free
(JNIEnv *env, jobject obj) {
    scws_free(interface);
}

JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_add_1dict
(JNIEnv *env, jobject obj, jstring jstr, jint ji) {
    char* fpath = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    int mode = ji;
    return scws_add_dict(interface, fpath, mode) == SCWS_YEA;
}

JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1dict
(JNIEnv *env, jobject obj, jstring jstr, jint ji) {
    char* fpath = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    int mode = ji;
    return scws_add_dict(interface, fpath, mode) == SCWS_YEA;
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1charset
(JNIEnv *env, jobject obj, jstring jstr) {
    char* charset = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    scws_set_charset(interface, charset);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1rule
(JNIEnv *env, jobject obj, jstring jstr) {
    char* fpath = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    scws_set_rule(interface, fpath);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1ignore
(JNIEnv *env, jobject obj, jboolean jbool) {
    int yes;
    if (jbool) {
        yes = 1;
    } else {
        yes = 0;
    }
    scws_set_ignore(interface, yes);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1multi
(JNIEnv *env, jobject obj, jint ji) {
    int mode = ji;
    scws_set_multi(interface, mode);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1debug
(JNIEnv *env, jobject obj, jboolean jbool) {
    int yes;
    if (jbool) {
        yes = 1;
    } else {
        yes = 0;
    }
    scws_set_debug(interface, yes);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1duality
(JNIEnv *env, jobject obj, jboolean jbool) {
    int yes;
    if (jbool) {
        yes = 1;
    } else {
        yes = 0;
    }
    scws_set_duality(interface, yes);
}

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_reset_1text
(JNIEnv *env, jobject obj, jstring jstr) {
    char* text = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    int len = strlen(text);
    scws_send_text(interface, text, len);
}

JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1result
(JNIEnv *env, jobject obj) {
    cJSON *root,*fld;
    scws_res_t res, cur;
    
    root=cJSON_CreateArray();
    
    while (res = cur = scws_get_result(interface)) {
        while (cur != NULL) {
            //handle seg
            //printf("WORD: %.*s/%s (IDF = %4.2f)\n", cur->len, interface->txt + cur->off, cur->attr, cur->idf);
            cJSON_AddItemToArray(root,fld=cJSON_CreateObject());            
            char word[256];
            substring(word,interface->txt,cur->off,cur->len);
            cJSON_AddNumberToObject(fld,"offset",cur->off);
            cJSON_AddStringToObject(fld, "word", word);
            cJSON_AddNumberToObject(fld,"idf", cur->idf);            
            cJSON_AddStringToObject(fld,"attr", cur->attr);
            //repoint the next
            cur = cur->next;
        }
        scws_free_result(res);
    }
    char *json = cJSON_Print(root);
    cJSON_Delete(root);
    return s2Jstring(env,json);
}

JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1tops
(JNIEnv *env, jobject obj, jint ji, jstring jstr) {
    int nums = ji;
    char* xattr = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    GET_WORDS(env, obj, scws_get_tops(interface, nums, xattr));
}

JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1words
  (JNIEnv *env, jobject obj, jstring jstr){
    char* xattr = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    GET_WORDS(env, obj, scws_get_words(interface, xattr));
}

JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_has_1word
  (JNIEnv *env, jobject obj, jstring jstr){    
    char* word = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    return scws_has_word(interface,word)==1;
}

//jstring to char*

static char* jstring2string(JNIEnv *env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "Ljava/lang/String;");
    jstring strencode = (*env)->NewStringUTF(env, "utf-8");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid, strencode);
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}

//char* to jstring

static jstring s2Jstring(JNIEnv *env, const char *pat) {
    jclass strClass = (*env)->FindClass(env, "Ljava/lang/String;");
    jmethodID ctorID = (*env)->GetMethodID(env, strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (*env)->NewByteArray(env, strlen(pat));
    (*env)->SetByteArrayRegion(env, bytes, 0, strlen(pat), (jbyte*) pat);
    jstring encoding = (*env)->NewStringUTF(env, "utf-8");
    return (jstring) (*env)->NewObject(env, strClass, ctorID, bytes, encoding);
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