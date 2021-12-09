#ifndef INlINE_VARIABLE_H_
#define INlINE_VARIABLE_H_

#include <string>

// 这个定义被多个编译单元使用，它们都指向同一个惟一的对象
inline std::string g_str = "Hello World!"

#endif  // INlINE_VARIABLE_H_
