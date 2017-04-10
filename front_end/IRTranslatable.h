#ifndef IRTRANSLATABLE
#define IRTRANSLATABLE

class CFG;

class IRTranslatable
{
public:
    IRTranslatable() = default;
    virtual ~IRTranslatable() = default;
    virtual void buildIR(CFG * cfg) const = 0;
};


#endif // IRTRANSLATABLE

