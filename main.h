#ifndef MAIN_H
#define MAIN_H

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>

#include <llvm/IR/Type.h>

#include <llvm/Pass.h>
#include <llvm/PassRegistry.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>

using namespace std;
using namespace llvm;

// application scoped
static LLVMContext vLCtx;
static PassManager<Function> *vOpts;
static IRBuilder<> vIrb(vLCtx);


#endif // MAIN_H
