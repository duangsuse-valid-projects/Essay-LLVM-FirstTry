#include <arithoperator.h>
#include <main.h>

Value *ArithOperator::codegen() {
    Value *lc = this->lhs.codegen(), *rc = this->rhs.codegen();
    if (lc ==nullptr || rc ==nullptr) return nullptr;

    switch (this->binop) {
    case BinOperator::ADD:
        return vIrb.CreateAdd(lc, rc, "sum");
    case BinOperator::SUB:
        return vIrb.CreateSub(lc, rc, "substr");
    case BinOperator::MUL:
        return vIrb.CreateMul(lc, rc, "multipli");
    case BinOperator::DIV:
        return vIrb.CreateSDiv(lc, rc, "division");
    default: return nullptr;
    }
}
