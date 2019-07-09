#ifndef LITINT_H
#define LITINT_H

#include <baseast.h>

class LitInt : public BaseAst
{
private:
    int value;
public:
    LitInt(int x): value(x) {}
    Value *codegen() override;
};

#endif // LITINT_H
