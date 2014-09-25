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

//external method
jstring s2Jstring(JNIEnv *env, const char *pat);
char* substring(char*dst, char*src, int start, int n);
char* jstring2string(JNIEnv *env, jstring jstr);
jobjectArray get_words(JNIEnv *env, jobject obj, scws_top_t top_t, int resultCount);

//java model info
jclass objClass;

jclass segmentationClass;
jfieldID offsetID;
jfieldID seg_wordID;
jfieldID idfID;
jfieldID seg_attrID;

jclass topwordClass;
jfieldID top_wordID;
jfieldID timesID;
jfieldID weightID;
jfieldID top_attrID;

scws_t interface;

JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_create_1new
(JNIEnv *env, jobject obj) {
    objClass = (*env)->FindClass(env, "java/lang/Object");
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

JNIEXPORT jobjectArray JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1result
(JNIEnv *env, jobject obj) {
    
    if(segmentationClass == NULL) {  
        segmentationClass = (*env)->FindClass(env,"com/intexh/segmentation/model/SegmentationModel");        
        offsetID = (*env)->GetFieldID(env, segmentationClass, "offset", "I");
        seg_wordID = (*env)->GetFieldID(env, segmentationClass, "word", "Ljava/lang/String;");
        idfID = (*env)->GetFieldID(env, segmentationClass, "idf", "F");
        seg_attrID = (*env)->GetFieldID(env, segmentationClass, "attr", "Ljava/lang/String;");
    }
    
    int count = 0;
    
    scws_res_t res = scws_get_result(interface,&count);

    //申明一个object数组 
    jobjectArray args = 0;
    args = (*env)->NewObjectArray(env, count, objClass, 0);
    
    int i = 0;
    scws_res_t cur = res;
    do {
        char* word;
        substring(word,interface->txt,cur->off,cur->len);
        (*env)->SetIntField(env, obj, offsetID, cur->off);
        (*env)->SetObjectField(env, obj, seg_wordID, s2Jstring(env,word));
        (*env)->SetFloatField(env, obj, idfID, cur->idf);
        (*env)->SetObjectField(env, obj, seg_attrID, s2Jstring(env, cur->attr));
        res = cur->next;
        free(cur);
        //添加到objcet数组中
        (*env)->SetObjectArrayElement(env, args, i++, obj);
    } while ((cur = res) != NULL);

    return args;
}

JNIEXPORT jobjectArray JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1tops
(JNIEnv *env, jobject obj, jint ji, jstring jstr) {
    int nums = ji,count=0;
    char* xattr = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    return get_words(env, obj, scws_get_tops(interface, nums, xattr,&count),count);
}

JNIEXPORT jobjectArray JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1words
  (JNIEnv *env, jobject obj, jstring jstr){
    char* xattr = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    int count=0;
    return get_words(env, obj, scws_get_words(interface, xattr, &count),count);
}

JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_has_1word
  (JNIEnv *env, jobject obj, jstring jstr){    
    char* word = (char*) (*env)->GetStringUTFChars(env, jstr, 0);
    return scws_has_word(interface,word)==1;
}

jobjectArray get_words(JNIEnv *env, jobject obj, scws_top_t top_t, int resultCount) {
    
    if(topwordClass == NULL){
        topwordClass = (*env)->FindClass(env, "com/intexh/segmentation/impl/scws/TopWordModel");
        top_wordID = (*env)->GetFieldID(env, topwordClass, "word", "Ljava/lang/String;");
        timesID = (*env)->GetFieldID(env, topwordClass, "times", "S");
        weightID = (*env)->GetFieldID(env, topwordClass, "weight", "F");
        top_attrID = (*env)->GetFieldID(env, topwordClass, "attr", "Ljava/lang/String;");
    }

    if (top_t == NULL) return NULL;

    //申明一个object数组 
    jobjectArray args = 0;
    args = (*env)->NewObjectArray(env, resultCount, objClass, 0);
    
    int i = 0;
    
    do {
        (*env)->SetObjectField(env, obj, top_wordID, s2Jstring(env,top_t->word));
        (*env)->SetCharField(env, obj, timesID, top_t->times);
        (*env)->SetFloatField(env, obj, weightID, top_t->weight);
        (*env)->SetObjectField(env, obj, top_attrID, s2Jstring(env, top_t->attr));
        //添加到objcet数组中
        (*env)->SetObjectArrayElement(env, args, i, obj);
        i++;
    } while ((top_t = top_t->next) != NULL);

    return args;
}

char* substring(char*dst, char*src, int start, int n) {
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

//jstring to char*

char* jstring2string(JNIEnv *env, jstring jstr) {
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

jstring s2Jstring(JNIEnv *env, const char *pat) {
    jclass strClass = (*env)->FindClass(env, "Ljava/lang/String;");
    jmethodID ctorID = (*env)->GetMethodID(env, strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (*env)->NewByteArray(env, strlen(pat));
    (*env)->SetByteArrayRegion(env, bytes, 0, strlen(pat), (jbyte*) pat);
    jstring encoding = (*env)->NewStringUTF(env, "utf-8");
    return (jstring) (*env)->NewObject(env, strClass, ctorID, bytes, encoding);
}