#include <iostream>
#include <mysql/jdbc.h>

// 执行表库的增删改语句

int main()
{
    try
    {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        std::unique_ptr<sql::Connection> connect(driver->connect("tcp://localhost:3306/testdb", "root", "asdf"));
        std::unique_ptr<sql::Statement> state(connect->createStatement());

        // 返回删除的行数
        std::cout << "delete " << state->executeUpdate("DELETE FROM temp") << std::endl;
        // 返回插入的行数
        std::cout << "insert " << state->executeUpdate("INSERT INTO temp (string)" \
            " VALUE ('one'),('two'), ('three'), ('four'), ('five')") << std::endl;
        // 返回更改的行数
        std::cout << "update " << state->executeUpdate("UPDATE temp SET string = UPPER(string)") << std::endl;
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
