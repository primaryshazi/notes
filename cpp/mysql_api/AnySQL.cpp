#include <iostream>
#include <iomanip>
#include <mysql/jdbc.h>

// 执行表库的增删改语句

int main()
{
    try
    {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        std::unique_ptr<sql::Connection> connect(driver->connect("tcp://localhost:3306/testdb", "root", "asdf"));
        std::unique_ptr<sql::Statement> state(connect->createStatement());

        // 返回true，执行的是查询语句，返回false执行的是非查询语句
        state->execute("CREATE TABLE IF NOT EXISTS temp_bak SELECT * FROM temp");

        state->execute("UPDATE temp_bak SET string = UPPER(string)");

        // 查询表
        if (state->execute("SELECT * FROM temp_bak"))
        {
            std::unique_ptr<sql::ResultSet> result(state->getResultSet());

            while (result->next())
            {
                std::cout << "[ " << result->getRow() << "] "
                          << std::left << std::setw(5) << result->getString(1).c_str()
                          << std::left << std::setw(10) << result->getString(2).c_str()
                          << std::left << std::setw(20) << result->getString(3).c_str() << std::endl;
            }
        }
        // 删除表
        state->execute("DROP TABLE IF EXISTS temp_bak");
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
