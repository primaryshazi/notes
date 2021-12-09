#include <iostream>
#include <memory>
#include <string>

class Expression
{
public:
    virtual ~Expression() {}

    virtual bool IsReal() = 0;
};

class FlagExpression : public Expression
{
private:
    bool _flag;

public:
    FlagExpression(bool flag) : _flag(flag) {}

    virtual ~FlagExpression() {}

    virtual bool IsReal() override { return _flag; }
};

class AndExpression : public Expression
{
private:
    std::weak_ptr<Expression> _wpExprFirst;
    std::weak_ptr<Expression> _wpExprSecond;

public:
    AndExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : _wpExprFirst(c_spExprFirst), _wpExprSecond(c_spExprSecond) {}

    virtual ~AndExpression() {}

    virtual bool IsReal() override { return _wpExprFirst.lock()->IsReal() && _wpExprSecond.lock()->IsReal(); }
};

class OrExpression : public Expression
{
private:
    std::weak_ptr<Expression> _wpExprFirst;
    std::weak_ptr<Expression> _wpExprSecond;

public:
    OrExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : _wpExprFirst(c_spExprFirst), _wpExprSecond(c_spExprSecond) {}

    virtual ~OrExpression() {}

    virtual bool IsReal() override { return _wpExprFirst.lock()->IsReal() || _wpExprSecond.lock()->IsReal(); }
};

class XorExpression : public Expression
{
private:
    std::weak_ptr<Expression> _wpExprFirst;
    std::weak_ptr<Expression> _wpExprSecond;

public:
    XorExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : _wpExprFirst(c_spExprFirst), _wpExprSecond(c_spExprSecond) {}

    virtual ~XorExpression() {}

    virtual bool IsReal() override { return !(_wpExprFirst.lock()->IsReal() == _wpExprSecond.lock()->IsReal()); }
};

int main()
{
    std::shared_ptr<Expression> spTrue{ new FlagExpression{true} };
    std::shared_ptr<Expression> spFalse{ new FlagExpression{false} };

    std::shared_ptr<Expression> spAnd{ new AndExpression{spTrue, spFalse} };
    std::shared_ptr<Expression> spOr{ new OrExpression{spTrue, spFalse} };
    std::shared_ptr<Expression> spXor{ new XorExpression{spTrue, spFalse} };

    /**
     * => 0
     * => 1
     * => 1
     */
    std::cout << spAnd->IsReal() << std::endl;
    std::cout << spOr->IsReal() << std::endl;
    std::cout << spXor->IsReal() << std::endl;

    return 0;
}
