#include <iostream>  
#include <jni.h>  
#include <android/log.h>  
#include "com_android_jni_MainActivity.h"
using namespace std;  
  
#define LOG_TAG "jniLog"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)  
  
extern "C"  
{  
  
/* 
 * Class:     com_android_jni_MainActivity
 * Method:    helloJNI 
 * Signature: ()Ljava/lang/String; 
 */  
JNIEXPORT jstring JNICALL Java_com_android_jni_MainActivity_helloJNI
  (JNIEnv *env, jobject obj)  
  {  
    LOGI("now in jni world");
    return env->NewStringUTF("Hello JNI");  
  }
}  