#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>
#define BUFFER 4096*4096		//缓冲区大小
#define FLAG 9999999			//返回值常量
using namespace std;
/*******************************符号类*****************************/
typedef class SYM {
private:
    string name;
    string type;
    int level;
    string value;
    char* location;
    long int line;
public:
    SYM() {}
    SYM(string name, string type = "void", int level = 0, string value = "") {
        this->name = name;
        this->type = type;
        this->level = level;
        this->value = value;
        location = NULL;
    }
    string getName() {
        return this->name;
    }
    string getType() {
        return this->type;
    }
    int get_Level() {
        return this->level;
    }
    string get_value() {
        return this->value;
    }
    void modifyValue(string value) {
        this->value = value;
    }
    void modifyType(string type) {
        this->type = type;
    }
    void modifyLevel(int level) {
        this->level = level;
    }
    void modifyLocation(char* loc) {
        this->location = loc;
    }
    char* getLocation() {
        return this->location;
    }
    void modifyLine(long int line) {
        this->line = line;
    }
    long int get_Line() {
        return this->line;
    }
}Symbol;

/*******************************用到的辅助函数*****************************/
void inicializeFunction();					//初始化系统函数
string trim(string s);						//去掉字符串一头一尾函数
bool Compare(Symbol s1, Symbol s2);			//比较两个符号是否相等
bool is_contain(Symbol s1);					//判断符号表中是否包含了查找的符号
void syntaxError(int k, long int l = 0, string s = "");//根据错误类型抛出异常
int Find(string name, int level);			//在当前的运行等级下查找变量名name
string tokenType(int Type);					//将整形的type转为对应的字符串
bool is_alpha(char c);						//判断字符c是否只包含字母和下划线
bool is_alpha(string s);					//判断字符串s是否只包含字母和下划线(重载)
bool is_num(string s);						//判断字符串s是否只包含数字
bool is_num(char c);						//判断字符c是否只包含数字(重载)
/*******************************关键算法函数*****************************/
void nextToken();							//修改current_token的值
void checkMatch(string s);					//检查字符是否匹配并获取下一个token
double expression();						//计算表达式的值
double factor();							//计算因子的值
double term();
double Fun(vector<string>pre);			//计算函数的值
int expression_bool();						//计算bool类型的值
int AND();
int OR();
char* Skip();								//跳过无需执行的语句块
double statement();							//解析语句块
int Excute(string s);                      //执行

#endif // FUNCTION_H
