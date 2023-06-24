#include <iostream>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <map>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;
std::map<std::string, std::string> keyMaps;
std::string fileName;
void AnalysisCommand(int argc, char* argv[]){
    // std::cout<<"进入"<<argc<<std::endl;
    int option;
    // std::string fileName;
    while((option = getopt(argc, argv, "f:")) != -1){
        switch (option){
            case 'f':
                fileName = optarg;
                break;
            
            default:
                std::cerr<<"命令行输入错误"<<std::endl;
                break;
        }
    }
    if(!fileName.empty()){
        std::ifstream file;
        // std::cout<<fileName<<std::endl;
        file.open(fileName.c_str());
        if(!file.is_open()){
            std::cerr<<"文件打开失败"<<fileName<<std::endl;
            exit(1);
        }
        // std::cout<<"进入"<<std::endl;
        std::string line;
        while (std::getline(file, line)){
            std::size_t delimiterPosition = line.find('=');
            if(delimiterPosition != std::string::npos){
                std::string key = line.substr(0, delimiterPosition);
                std::string value = line.substr(delimiterPosition + 1);
                keyMaps[key] = value;
            }
        }
        // 展示键值对
        // std::map<std::string, std::string>::iterator it;
        // for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
        //     std::cout<<it->first<<"="<<it->second<<std::endl;
        // }
    }
}
void ShowMenu(){
    std::cout<<"-------------MENU------------------"<<std::endl;
    std::cout<<"--1.SearchFromKey"<<std::endl;
    std::cout<<"--2.InsertByKeyAndValue"<<std::endl;
    std::cout<<"--3.ModifyByKey"<<std::endl;
    std::cout<<"--4.DeleteByKey"<<std::endl;
    std::cout<<"--5.ShowKeyAndValue"<<std::endl;
    std::cout<<"--6.exit"<<std::endl;
    std::cout<<"-------------END------------------"<<std::endl;
}

void ShowKeys(){
    std::cout<<"-------------KEYS------------------"<<std::endl;
    std::map<std::string, std::string>::iterator it;
    for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
        std::cout<<it->first<<std::endl;
    }
    std::cout<<"-------------END------------------"<<std::endl;
}

void ShowAll(){
    std::cout<<"-------------KEYS------------------"<<std::endl;
    std::map<std::string, std::string>::iterator it;
    for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
        std::cout<<it->first<<"="<<it->second<<std::endl;
    }
    std::cout<<"-------------END------------------"<<std::endl;
}
int Write(){
    fstream myFile;
    myFile.open(fileName, ios::out);
    if(myFile.is_open()){
        std::map<std::string, std::string>::iterator it;
        for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
            myFile << it->first;
            myFile << "=";
            myFile << it->second;
            myFile << "\n";
        }
        myFile.close();
        return 0;
    }else{
        return -1;
    }    
}

void DealConsumerCommand(){
    while (true){
        ShowMenu();
        char* input = readline("(input the number)>>");
        if(strcmp(input, "6") == 0){
            int res = Write();
            if(res == 0){
                std::cout<<"写入成功"<<std::endl;
                std::cout<<"退出"<<std::endl;
            }else{
                std::cout<<"写入失败"<<std::endl;
                std::cout<<"退出"<<std::endl;
            }
            break;
        }
         while (true){
            if(strcmp(input, "1") == 0){
                // 选择1通过key查找value
                ShowKeys();
                char* select = readline("(eg: search key)>>>");
                std::string strs = select;
                int pos = strs.find(" ");
                std::string key = strs.substr(pos + 1);
                // 在keyMaps中通过key查找
                int flag = 0;
                std::map<std::string, std::string>::iterator it;
                for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
                    if (strcmp((it->first).c_str(), key.c_str()) == 0){
                        flag = 1;
                        std::cout<<it->first<<"="<<it->second<<std::endl;
                        break;
                    }
                }
                if (flag == 0)
                {
                    std::cout<<key<<"键不存在于已有的文档之中"<<std::endl;
                }
                break;
            }else if (strcmp(input, "2") == 0)
            {
                // 选择2 插入键值对
                ShowKeys();
                char* select = readline("(eg: insert key=value)>>>");
                std::string strs = select;
                int pos = strs.find(" ");
                std::string key_value = strs.substr(pos + 1);
                // std::cout<<"key_value="<<key_value<<std::endl;
                pos = key_value.find("=");
                // std::cout<<"pos2="<<pos1<<std::endl;
                std::string key = key_value.substr(0, pos);
                std::string value = key_value.substr(pos + 1);
                // std::cout<<"key="<<key<<std::endl;
                // std::cout<<"value="<<value<<std::endl;
                // 在keyMaps中通过key查找
                int flag = 0;
                std::map<std::string, std::string>::iterator it;
                for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
                    if (strcmp((it->first).c_str(), key.c_str()) == 0){
                        flag = 1;
                        std::cout<<it->first<<"="<<it->second<<std::endl;
                        std::cout<<"该键值对的键与已有文档中的重复不能插入"<<std::endl;
                        break;
                    }
                }
                if (flag == 0)
                {
                    keyMaps[key] = value;
                    std::cout<<key<<"="<<value<<"键值对插入成功"<<std::endl;
                }
                break;
            }else if (strcmp(input, "3") == 0)
            {
                // 选择3
                ShowKeys();
                char* select = readline("(eg: modify key=value)>>>");
                std::string strs = select;
                int pos = strs.find(" ");
                std::string key_value = strs.substr(pos + 1);
                pos = key_value.find("=");
                std::string key = key_value.substr(0, pos);
                std::string value = key_value.substr(pos + 1);
                // 在keyMaps中通过key查找
                int flag = 0;
                std::map<std::string, std::string>::iterator it;
                for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
                    if (strcmp((it->first).c_str(), key.c_str()) == 0){
                        flag = 1;
                        keyMaps[key] = value;
                        // std::cout<<it->first<<"="<<it->second<<std::endl;
                        std::cout<<"修改成功"<<std::endl;
                        break;
                    }
                }
                if (flag == 0)
                {
                    // keyMaps[key] = value;
                    std::cout<<key<<"该键值不存在于已有的文件，故不能修改"<<std::endl;
                }
                break;
            }else if (strcmp(input, "4") == 0)
            {
                // 选择4
                ShowKeys();
                char* select = readline("(eg: delete key)>>>");
                std::string strs = select;
                int pos = strs.find(" ");
                std::string key = strs.substr(pos + 1);
                // 在keyMaps中通过key查找
                int flag = 0;
                std::map<std::string, std::string>::iterator it;
                for(it=keyMaps.begin(); it!=keyMaps.end(); it++){
                    if (strcmp((it->first).c_str(), key.c_str()) == 0){
                        flag = 1;
                        select = readline("(Are you sure? Y/N)>>>");
                        if (strcmp(select, "Y") == 0)
                        {
                            std::cout<<it->first<<"="<<it->second<<std::endl;
                            keyMaps.erase(key);
                            std::cout<<"该键值对已经删除"<<std::endl;
                        }else{
                            std::cout<<"该键值对删除撤销"<<std::endl;
                        }
                        break;
                    }
                }
                if (flag == 0)
                {
                    std::cout<<key<<"该键值对不存在于文件中，故删除无效"<<std::endl;
                }
                break;
            }else if(strcmp(input, "5") == 0){
                ShowAll();
                break;
            }else{
                input = readline("(wrong number)>>");
            }
        }
        std::string command(input);
        free(input);
        if(!command.empty()){
            add_history(command.c_str());
        }
    }
}

int main(int argc, char* argv[]){
    // std::cout<<"进入"<<argc<<std::endl;
    AnalysisCommand(argc, argv);
    DealConsumerCommand();
    return 0;
}