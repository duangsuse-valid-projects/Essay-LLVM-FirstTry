#include <litint.h>
#include <main.h>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

Value *LitInt::codegen() {
    return llvm::Constant::getIntegerValue(Type::getInt32Ty(vLCtx), APInt(32, static_cast<unsigned long>(this->value), true));
}
