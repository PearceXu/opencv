//
// Created by moubiao on 2017/6/30.
//

#include "headers/FileManager.h"

//bool Java_com_xubaipei_utils_FileManager_readFile(JNIEnv* env,jobject obj)
//{
//    LOGE("log from jni %s","dd");
//    return true;
//}
//
//
//bool Java_com_xubaipei_utils_FileManager_copyFile(JNIEnv* env,jobject obj)
//{   std::string hello = "Hello from C++";
//    return true;
//}
//
//#endif
//#include "filemanager.h"
//


bool FileManager::copyFile(std::string srcFile, std::string destFile)
{
    char* srcData = readFile(srcFile);
    if(srcData == NULL)
    {
        return false;
    }
    return writeFile(srcData,destFile);
}

char* FileManager::readFile(std::string path)
{

    fstream file;
    file.open(path,ios::in);
    if(!file.is_open())
    {
        return NULL;
    }
    file.seekg(0,ios_base::end);// stream end
    long size = file.tellg();
    file.seekg(0,ios_base::beg);// stream begin
    char* data = (char*)malloc(size);
    if(data == NULL){
        return NULL;
    }
    file>>data;
    file.close();
    return data;
}

bool FileManager::writeFile(const char* data, string destPath)
{
    fstream file;
    file.open(destPath,ios::out);
    if(!file.is_open())
    {
        return false;
    }
    file<<data;
    file.close();
    return true;
}

bool FileManager::appendFile(const char *data, string destPath)
{
    fstream file;
    file.open(destPath,ios::out|ios::app);
    if(!file.is_open())
    {
        return false;
    }
    file<<data;
    file.close();
    return true;
}

bool FileManager::mkdir(string path)
{
//    int ret = _mkdir(path.c_str());
    int ret = std::remove(path.c_str());

    return ret == 0;
}

bool FileManager::remove(string path)
{
    int ret = std::remove(path.c_str());
    if(ret != 0)
    {
//        ret = rmdir(path.c_str());
    }
    return ret == 0;
}

void FileManager::getFiles(string path, vector<string>& files)
{
    //文件句柄
    //long hFile = 0;  //win7
    intptr_t hFile = 0;   //win10
                          //文件信息
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
        // "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib &  _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(path + "\\" + fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

