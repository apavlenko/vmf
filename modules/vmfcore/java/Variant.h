/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class Variant */

#ifndef _Included_Variant
#define _Included_Variant
#ifdef __cplusplus
extern "C" {
#endif
#undef Variant_type_unknown
#define Variant_type_unknown 0L
#undef Variant_type_char
#define Variant_type_char 1L
#undef Variant_type_integer
#define Variant_type_integer 2L
#undef Variant_type_real
#define Variant_type_real 3L
#undef Variant_type_string
#define Variant_type_string 4L
#undef Variant_type_vec2d
#define Variant_type_vec2d 5L
#undef Variant_type_vec3d
#define Variant_type_vec3d 6L
#undef Variant_type_vec4d
#define Variant_type_vec4d 7L
#undef Variant_type_rawbuffer
#define Variant_type_rawbuffer 8L
#undef Variant_type_char_vector
#define Variant_type_char_vector 9L
#undef Variant_type_integer_vector
#define Variant_type_integer_vector 10L
#undef Variant_type_real_vector
#define Variant_type_real_vector 11L
#undef Variant_type_string_vector
#define Variant_type_string_vector 12L
#undef Variant_type_vec2d_vector
#define Variant_type_vec2d_vector 13L
#undef Variant_type_vec3d_vector
#define Variant_type_vec3d_vector 14L
#undef Variant_type_vec4d_vector
#define Variant_type_vec4d_vector 15L
/*
 * Class:     Variant
 * Method:    n_Variant
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1Variant
  (JNIEnv *, jobject);

/*
 * Class:     Variant
 * Method:    n_copy
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_Variant_n_1copy
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__JI
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (JF)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__JF
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (J[I)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__J_3I
  (JNIEnv *, jclass, jlong, jintArray);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (J[F)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__J_3F
  (JNIEnv *, jclass, jlong, jfloatArray);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__JLjava_lang_String_2
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     Variant
 * Method:    n_setTo
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_Variant_n_1setTo__JJ
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     Variant
 * Method:    n_equals
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_Variant_n_1equals
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     Variant
 * Method:    n_unequals
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_Variant_n_1unequals
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     Variant
 * Method:    n_toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Variant_n_1toString
  (JNIEnv *, jclass, jlong);

/*
 * Class:     Variant
 * Method:    n_fromString
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_Variant_n_1fromString
  (JNIEnv *, jclass, jlong, jint, jstring);

/*
 * Class:     Variant
 * Method:    n_getType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_Variant_n_1getType
  (JNIEnv *, jclass, jlong);

/*
 * Class:     Variant
 * Method:    n_isEmpty
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_Variant_n_1isEmpty
  (JNIEnv *, jclass, jlong);

/*
 * Class:     Variant
 * Method:    n_getTypeName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Variant_n_1getTypeName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     Variant
 * Method:    n_convertTo
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_Variant_n_1convertTo
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     Variant
 * Method:    n_typeToString
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Variant_n_1typeToString
  (JNIEnv *, jclass, jint);

/*
 * Class:     Variant
 * Method:    n_typeFromString
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_Variant_n_1typeFromString
  (JNIEnv *, jclass, jstring);

/*
 * Class:     Variant
 * Method:    n_isConvertible
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_Variant_n_1isConvertible
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     Variant
 * Method:    n_base64Encode
 * Signature: (Ljava/nio/ByteBuffer;J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Variant_n_1base64Encode
  (JNIEnv *, jclass, jobject, jlong);

/*
 * Class:     Variant
 * Method:    n_base64Decode
 * Signature: (Ljava/lang/String;[I)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_Variant_n_1base64Decode
  (JNIEnv *, jclass, jstring, jintArray);

/*
 * Class:     Variant
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_Variant_n_1delete
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
