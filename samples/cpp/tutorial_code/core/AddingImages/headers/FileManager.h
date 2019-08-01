//
// Created by moubiao on 2017/6/30.
//
#include <stdlib.h>
#ifndef OPGL_FILEMANAGER_H
#define OPGL_FILEMANAGER_H
//
//#endif //OPGL_FILEMANAGER_H
//
//#include <jni.h>
//#include <string>
//#include <iostream>
//#include <android/log.h>
//#define  LOG_TAG "xubaipei"
//#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
//#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
//extern "C"
//{
//bool Java_com_xubaipei_utils_FileManager_readFile(JNIEnv* env,jobject obj);
//bool Java_com_xubaipei_utils_FileManager_copyFile(JNIEnv* env,jobject obj);
//};
//
//#ifndef FILEMANAGER_H
//#define FILEMANAGER_H
//#endif // FILEMANAGER_H
//#ifndef FILEMANAGER_H

//#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <stdio.h>
#include <io.h>
#include <string>
#include <vector>
//#include <dirent.h>

using namespace std;

class FileManager
{
public:
    FileManager();
    static bool copyFile(std::string srcFile,std::string destFile);
    static char* readFile(std::string path);
    static bool writeFile(const char* data,std::string destPath);
    static bool appendFile(const char* data,std::string destPath);
    static bool mkdir(std::string path);
    static bool remove(std::string path);
    static void getFiles(string path, vector<string>& files);
};

#endif // FILEMANAGER_H
