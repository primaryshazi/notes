#include <iostream>
#include <iomanip>
#include <mysql/jdbc.h>

// 执行查询的语句

int main()
{
    try
    {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        std::unique_ptr<sql::Connection> connect(driver->connect("tcp://localhost:3306/testdb", "root", "asdf"));
        std::unique_ptr<sql::Statement> state(connect->createStatement());
        std::unique_ptr<sql::ResultSet> result(state->executeQuery("SELECT * FROM temp"));

        // 获取查询结构信息
        sql::ResultSetMetaData *meta = result->getMetaData();

        // 获取结果行数
        std::cout << "row    " << result->rowsCount() << std::endl;
        // 获取结果列数
        std::cout << "column " << meta->getColumnCount() << std::endl;

        // 字段名
        std::cout << std::left << std::setw(10) << "empty"
                  << std::left << std::setw(10) << meta->getColumnName(1).c_str()
                  << std::left << std::setw(10) << meta->getColumnName(2).c_str()
                  << std::left << std::setw(30) << meta->getColumnName(3).c_str() << std::endl;

        // 字段类型
        std::cout << std::left << std::setw(10) << "empty"
                  << std::left << std::setw(10) << meta->getColumnTypeName(1).c_str()
                  << std::left << std::setw(10) << meta->getColumnTypeName(2).c_str()
                  << std::left << std::setw(30) << meta->getColumnTypeName(3).c_str() << std::endl;

        while (result->next())
        {
            // 结果行数
            std::cout << std::left << std::setw(10) << result->getRow()
                      << std::left << std::setw(10) << result->getString(1).c_str()
                      << std::left << std::setw(10) << result->getString(2).c_str()
                      << std::left << std::setw(30) << result->getString(3).c_str() << std::endl;
        }
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
