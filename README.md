# Android-JNI
A sample for Android JNI
### 第一步
功能介绍：新建文本框和按钮，同时调用so库JNITest，调用so库里面的函数是helloJNI，同时为按钮建立一个点击监听器，点击按钮，则调用helloJNI()函数，并显示返回的字符串。
<br/>至此，前期准备工作都已完成。
### 第二步
需要先生成MainActivity.java的class文件。
<br/>点击菜单栏build->Make Project编译整个工程。编译完成后，在路径app/build/intermediates/classes/debug/com/android/jni/下应该会出现MainActivity。
### 第三步
生成jni目录。
<br/>进入main目录并新建文件夹jni
<br/>cd app/src/main/
<br/>mkdir jni
### 第四步
生成.h文件
<br/>运行以下命令：
<br/>javah -d jni -classpath /opt/android-sdk-linux/platforms/android-24/android.jar:../app/build/intermediates/classes/debug/com.android.jni.MainActivity
<br/>就会在jni目录下生成com_android_jni_MainActivity.h文件。
<br/>里面有函数声明Java_com_android_jni_MainActivity_helloJNI
### 第五步
实现函数
<br/>生成.h文件后我们就可以编写相应的C/C++实现代码
<br/>在jni目录下新建main.cpp，并在里面实现Java_com_android_jni_MainActivity_helloJNI函数。
### 第六步
生成.so库
<br/>1、在目录jni中新建Android.mk。
<br/>2、新建Application.mk。
<br/>3、进入jni目录，运行命令ndk-build，运行成功，同时生成so库libJNITest.so，位于目录libs/armeabi-v7a中。
### 第七步
使用.so库
<br/>打开app/build.gradle文件，在android{}内加入：
```
sourceSets {
    main() {
        jniLibs.srcDirs = ['src/main/libs']
        jni.srcDirs = []
    }
}
```
<br/>就会生成jniLibs目录。
<br>同时，在gradle.properties文件中加入语句：
android.useDeprecatedNdk=true
把第六步生成的.so库复制进jniLibs即可使用。
### 第八步
编译运行。


