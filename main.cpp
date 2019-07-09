#include <iostream>
#include <memory>

#include <ctype.h>

#include <main.h>
#include <litint.h>
#include <arithoperator.h>

const string vFStdin = ":stdin:";

void repl(string file) {
    auto mod = std::make_unique<Module>(StringRef(file), vLCtx);

    vOpts = new PassManager<Function>();
    ExecutionEngine *jitter = EngineBuilder(std::move(mod)).create();

    LitInt a1(10), a2(2);
    BaseAst *ast0 = new ArithOperator(BinOperator::DIV, a1, a2);

    auto fn = Function::Create(FunctionType::get(Type::getInt32Ty(vLCtx), ArrayRef<Type *>(), false), Function::InternalLinkage, "__eval", mod.get());
    auto bb = BasicBlock::Create(vLCtx, "entry", fn);
    vIrb.SetInsertPoint(bb);

    auto retv = ast0->codegen();
    vIrb.CreateRet(retv);

    fn->print(llvm::outs());
    //verifyFunction(*fn);

    auto fun = (jitter->getPointerToFunction(fn));
    int32_t (*func)() = reinterpret_cast<int32_t (*)()>(fun);

    cout << "10 / 2 = @" << fun << ": " << flush;
    cout << func() << endl;
}

int main(int argc, char **argv)
{
    cout << "Jit calculator: (*) (/) > (+)  (-)" << endl;
    if (argc >1)
    { repl(string(argv[1])); }
    else { repl(vFStdin); }
    return 0;
}
