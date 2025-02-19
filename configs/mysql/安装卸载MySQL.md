# 安装卸载Mysql

## windows下安装mysql

1. mysqld --install

2. mysqld --initialize-insecure --user=mysql

3. net start mysql

4. mysql -u root -p

5. alter user 'root'@'localhost' identified by 'Password';

## windows卸载

1. net stop mysql

2. mysqld --remove mysql
