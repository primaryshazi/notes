#include <iostream>
#include <mysql/jdbc.h>

int main()
{
    try
    {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        // 第一种连接方式
        std::unique_ptr<sql::Connection> connect(driver->connect("tcp://localhost:3306/testdb", "root", "asdf"));

        // 第二种连接方式
        // std::unique_ptr<sql::Connection> connect(driver->connect("tcp://localhost:3306", "root", "asdf"));
        // connect->setSchema("testdb");

        connect->close();
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
