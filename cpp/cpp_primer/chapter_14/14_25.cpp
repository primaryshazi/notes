/*

还应该定义赋值运算符，参数为string，将date作为一个字符串赋值给Date类

Date & Sales_data::operator=(const string &date)
{
    istringstream in(date);
    char ch1, cha2;
    in >> year >> ch1 >> month >> ch2 >> day;
    if (!in || ch1 != '-' || ch2 != '-')
        throw std::invalid_argument("Bad date");
    if (month < 1 || month >12 || day < 1 || day > 31)
        throw std::invalid_argument("Bad date");
    return *this;
}

*/