# SummerTrain
暑假实训的远程仓库
## 一、使用g++
把keymap.txt、main.cpp文件放在linux系统中的同一个目录下，直接在linux系统下使用g++生成可执行文件，在同一目录下运行如下命令：
···
g++ -lreadline -g main.cpp -o main # 通过g++把源文件main.cpp编译成可执行文件main(名字随意)
./main -f keymap.txt # 运行可执行文件
···
## 二、使用cmake
把build目录放到linux系统上任意位置，在build目录下执行如下命令：
···
cmake . # 点之前有一个空格，该命令会生成Makefile等
make # 该命令会生成main可执行文件
./main -f keymap.txt # 运行可执行文件
···
