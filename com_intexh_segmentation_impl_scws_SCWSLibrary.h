/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_intexh_segmentation_impl_scws_SCWSLibrary */

#ifndef _Included_com_intexh_segmentation_impl_scws_SCWSLibrary
#define _Included_com_intexh_segmentation_impl_scws_SCWSLibrary
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    create_new
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_create_1new
  (JNIEnv *, jobject);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    free
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_free
  (JNIEnv *, jobject);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    add_dict
 * Signature: (Ljava/lang/String;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_add_1dict
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_dict
 * Signature: (Ljava/lang/String;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1dict
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_charset
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1charset
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_rule
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1rule
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_ignore
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1ignore
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_multi
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1multi
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_debug
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1debug
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    set_duality
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_set_1duality
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    reset_text
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_reset_1text
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    get_result
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1result
  (JNIEnv *, jobject);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    get_tops
 * Signature: (ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1tops
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    get_words
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_get_1words
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_intexh_segmentation_impl_scws_SCWSLibrary
 * Method:    has_word
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_intexh_segmentation_impl_scws_SCWSLibrary_has_1word
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
