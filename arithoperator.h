#ifndef ARITHOPERATOR_H
#define ARITHOPERATOR_H

#include <baseast.h>

enum BinOperator { ADD, SUB, MUL, DIV };

class ArithOperator : public BaseAst
{
private:
    BinOperator binop;
    BaseAst &lhs, &rhs;
public:
    ArithOperator(BinOperator op, BaseAst &lhs, BaseAst &rhs): binop(op), lhs(lhs), rhs(rhs) {}
    Value *codegen() override;
};

#endif // ARITHOPERATOR_H
