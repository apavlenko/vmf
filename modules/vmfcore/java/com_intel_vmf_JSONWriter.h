/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_intel_vmf_JSONWriter */

#ifndef _Included_com_intel_vmf_JSONWriter
#define _Included_com_intel_vmf_JSONWriter
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_JSONWriter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_JSONWriter_n_1JSONWriter
  (JNIEnv *, jclass);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSchemas
 * Signature: (J[J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSchemas
  (JNIEnv *, jclass, jlong, jlongArray);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeMetadataSet
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeMetadataSet
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeAll
 * Signature: (JJLjava/lang/String;Ljava/lang/String;[J[JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeAll
  (JNIEnv *, jclass, jlong, jlong, jstring, jstring, jlongArray, jlongArray, jlong);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSegment
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSegment
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSegments
 * Signature: (J[J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSegments
  (JNIEnv *, jclass, jlong, jlongArray);

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_intel_vmf_JSONWriter_n_1delete
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
