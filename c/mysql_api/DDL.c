#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char const *argv[])
{
    MYSQL *connect = NULL; // mysql连接对象

    // 初始化客户端开发库
    if (mysql_library_init(0, NULL, NULL))
    {
        printf("Error %u: %s status: %s\n", mysql_errno(connect), mysql_error(connect), mysql_sqlstate(connect));
        exit(1);
    }

    // 初始化连接
    connect = mysql_init(NULL);
    if (connect == NULL)
    {
        printf("Error %u: %s status: %s\n", mysql_errno(connect), mysql_error(connect), mysql_sqlstate(connect));
        exit(1);
    }

    // 连接服务器
    if (mysql_real_connect(connect, "localhost", "root", "asdf", "testdb", 3306, NULL, 0) == NULL)
    {
        printf("Error %u: %s status: %s\n", mysql_errno(connect), mysql_error(connect), mysql_sqlstate(connect));
        mysql_close(connect);
        exit(1);
    }
    if (mysql_query(connect, "DELETE FROM temp"))
    {
        printf("Error %u: %s status: %s\n", mysql_errno(connect), mysql_error(connect), mysql_sqlstate(connect));
        mysql_close(connect);
        exit(1);
    }

    // 返回delete的个数
    printf("delete %ld\n", mysql_affected_rows(connect));

    mysql_close(connect);
    mysql_library_end();

    return 0;
}
