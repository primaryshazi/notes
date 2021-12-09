#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char const *argv[])
{
    MYSQL *connect = NULL;     // mysql连接对象
    MYSQL_RES *result = NULL;  // 查询返回结果集
    MYSQL_ROW row = NULL;      // 查询返回的一行结果
    MYSQL_FIELD *field = NULL; // 字段名
    int num_fields = 0;        // 查询返回字段数量
    int num_rows = 0;          // 查询返回行数

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
    if (mysql_query(connect, "SELECT * FROM temp"))
    {
        printf("Error %u: %s status: %s\n", mysql_errno(connect), mysql_error(connect), mysql_sqlstate(connect));
        mysql_close(connect);
        exit(1);
    }

    // 获取查询结果
    result = mysql_store_result(connect);
    // 按行获取查询结果
    num_rows = mysql_num_rows(result);
    // 获取字段数量
    num_fields = mysql_num_fields(result);

    printf("row[%d] column[%d]\n", num_rows, num_fields);

    // 获取字段名
    while ((field = mysql_fetch_field(result)) != NULL)
    {
        printf("%-10s", field->name);
    }
    printf("\n");

    // 获取查询结果
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%-10s", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);

    mysql_close(connect);
    mysql_library_end();

    return 0;
}
