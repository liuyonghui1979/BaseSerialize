# BaseSerialize
基于c++模板和接口的简单序列化解析库，用 运算符>> 和 << 序列化和解析，支持基本数据类型，结构体，二进制数据块，string，vector，list，指针的序列化解析；复杂数据类型通过集成CSerialInterface接口实现；

windows平台下编译：
1.进入src文件夹下，打开BaseSerialize.sln，编译；
2.进入test文件夹下，打开SerializeTest.sln，编译；生成文件在bin_win32下；

linux平台下编译：
1.进入src文件夹下，makefile编译；
2.进入test文件夹下，make -f Makefile.gui生成QT h和cpp；make生成SerializeTest测试文件；生成文件在bin_linux下；
