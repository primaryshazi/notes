#include <iostream>
#include <memory>

class Expression
{
public:
    virtual ~Expression() {}

    virtual bool isReal() = 0;
};

class FlagExpression : public Expression
{
public:
    FlagExpression(bool flag) : flag_(flag) {}

    virtual ~FlagExpression() {}

    virtual bool isReal() override { return flag_; }

private:
    bool flag_;
};

class AndExpression : public Expression
{
public:
    AndExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : wpExprFirst_(c_spExprFirst), wpExprSecond_(c_spExprSecond) {}

    virtual ~AndExpression() {}

    virtual bool isReal() override { return wpExprFirst_.lock()->isReal() && wpExprSecond_.lock()->isReal(); }

private:
    std::weak_ptr<Expression> wpExprFirst_;
    std::weak_ptr<Expression> wpExprSecond_;
};

class OrExpression : public Expression
{
public:
    OrExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : wpExprFirst_(c_spExprFirst), wpExprSecond_(c_spExprSecond) {}

    virtual ~OrExpression() {}

    virtual bool isReal() override { return wpExprFirst_.lock()->isReal() || wpExprSecond_.lock()->isReal(); }

private:
    std::weak_ptr<Expression> wpExprFirst_;
    std::weak_ptr<Expression> wpExprSecond_;
};

class XorExpression : public Expression
{
public:
    XorExpression(const std::shared_ptr<Expression> &c_spExprFirst, const std::shared_ptr<Expression> &c_spExprSecond)
        : wpExprFirst_(c_spExprFirst), wpExprSecond_(c_spExprSecond) {}

    virtual ~XorExpression() {}

    virtual bool isReal() override { return !(wpExprFirst_.lock()->isReal() == wpExprSecond_.lock()->isReal()); }

private:
    std::weak_ptr<Expression> wpExprFirst_;
    std::weak_ptr<Expression> wpExprSecond_;
};

int main()
{
    std::shared_ptr<Expression> spTrue = std::make_shared<FlagExpression>(true);
    std::shared_ptr<Expression> spFalse = std::make_shared<FlagExpression>(false);

    std::shared_ptr<Expression> spAnd = std::make_shared<AndExpression>(spTrue, spFalse);
    std::shared_ptr<Expression> spOr = std::make_shared<OrExpression>(spTrue, spFalse);
    std::shared_ptr<Expression> spXor = std::make_shared<XorExpression>(spTrue, spFalse);

    /**
     * => 0
     * => 1
     * => 1
     */
    std::cout << spAnd->isReal() << std::endl;
    std::cout << spOr->isReal() << std::endl;
    std::cout << spXor->isReal() << std::endl;

    return 0;
}
