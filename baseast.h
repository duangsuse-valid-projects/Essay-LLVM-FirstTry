#ifndef BASEAST_H
#define BASEAST_H

#include <llvm/IR/Value.h>

using namespace llvm;

class BaseAst
{
public:
    explicit BaseAst();
    virtual ~BaseAst() = default;
    virtual llvm::Value *codegen();
};

#endif // BASEAST_H
