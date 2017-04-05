#include "Java.h"

const int Java::OFFSET_VALUE = 8;

Java::Java(const std::string _filename, std::map<std::string, CFG*> _listCFG)
    : Writer(_filename), listCFG(_listCFG)
{
    open();

    // Begin of the assembler part
    write(".class public " + filename);
    write(".super java/lang/Object");
    write();
    write(".method public <init>()V");
    write("\taload_0");
    write("\tinvokenonvirtual java/lang/Object/<init>()V");
    write("\treturn");
    write(".end method");
    write("");
    // For the time being, only one method is handled
    write(".method public static main([Ljava/lang/String;)V");
}

void Java::parse()
{
    std::string label;
    std::vector<IRInstruction*> instructions;

    for (std::map<std::string, CFG*>::iterator itCFG = listCFG.begin(); itCFG != listCFG.end(); ++itCFG)
    {
        const BasicBlock* block = itCFG->second->getRootBasicBlock();

        bool prolog = true;
        while (block != nullptr)
        {
            if (prolog) // Prolog
            {
                int offset = itCFG->second->getOffsetFromCurrentBasicBlock();
                write("\t.limit stack " + std::to_string(offset));

                prolog = false;
            }
            else // Other
            {
                instructions = block->getInstructions();
                for (const IRInstruction* iri : instructions)
                {
                    IRInstruction::Type instruction = iri->getOperation();

                    switch (instruction)
                    {
                        case IRInstruction::Type::BINARY_OP :
                            binaryOp((IRBinaryOp*) iri);
                            break;
                        case IRInstruction::Type::LOAD_CONSTANT :
                            loadConstant((IRLoadConstant*) iri);
                            break;
                        case IRInstruction::Type::RWMEMORY :
                            rwmemory((IRRWMemory*) iri);
                            break;
                        case IRInstruction::Type::CALL :
                            call((IRCall*) iri);
                            break;
                        case IRInstruction::Type::JUMP :
                            jump((IRJump*) iri);
                            break;
                        case IRInstruction::Type::SELECTION :
                            selection((IRSelection*) iri);
                            break;
                        default:
                            break;
                    }
                }
            }

            if (block->getExitTrue() != nullptr)
            {
                block = block->getExitTrue();
            }
            else if (block->getExitFalse() != nullptr)
            {
                block = block->getExitFalse();
            }
            else
            {
                block = nullptr;
            }
        }
    }
    write("\treturn");
    write(".end method");
    write();
}

int Java::compile()
{
    if (!system(nullptr))
    {
        std::cout << "Erreur : impossible de lancer une commande système [back_end:Java:compile()]." << std::endl;
        return -1;
    }
    close();

    int result = 0;
    result = system(("java -jar back_end/jasmin/jasmin.jar " + filename + ".s").c_str());

    if (isOpen())
    {
        open(std::ios::app);
    }

    if (result != 0)
    {
        std::cout << "Erreur lors de la compilation de l'assembleur [back_end:Java:compile()]." << std::endl;
        return -1;
    }    

    return 0;
}

void Java::binaryOp(const IRBinaryOp* instruction)
{
    write(";binaryOp");

    const Symbol* destination = instruction->getDestination();
    const Symbol* operand1 = instruction->getOperand_1();
    const Symbol* operand2 = instruction->getOperand_2();

    switch (instruction->getType())
    {
        case IRBinaryOp::Type::ADD :
            break;
        case IRBinaryOp::Type::SUB :
            break;
        case IRBinaryOp::Type::MUL :
            break;
        case IRBinaryOp::Type::DIV :
            break;
        default:
            std::cout << "Erreur : type d'instruction IRBinaryOp invalide [back_end:Java:binaryOp()]." << std::endl;
            break;
    }
}

void Java::loadConstant(const IRLoadConstant* instruction)
{
    write(";loadConstant");

    const Symbol* destination = instruction->getDestination();
    const int value = instruction->getValue();
}

void Java::rwmemory(const IRRWMemory* instruction)
{
    write(";rwmemory");

    const Symbol* destination = instruction->getDestination();
    const Symbol* source = instruction->getSource();

    switch (instruction->getType())
    {
        case IRRWMemory::Type::READ_MEMORY :
            break;
        case IRRWMemory::Type::WRITE_MEMORY :
            //write("\tgetstatic java/lang/System/out Ljava/io/PrintStream;");
            //write("\tldc \"Hello World!\"");
            break;
        default:
            std::cout << "Erreur : type d'instruction IRRWMemory invalide [back_end:Java:rwmemory()]." << std::endl;
            break;
    }
}

void Java::call(const IRCall* instruction)
{
    write(";call");

    std::vector<Symbol*> params = instruction->getParams();

    // Just System.out.println() for the time being

    write("\tgetstatic java/lang/System/out Ljava/io/PrintStream;");
    write("\tldc \"Hello World!\"");
    write("\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
}

void Java::jump(const IRJump* instruction)
{
    write(";jump");
}

void Java::selection(const IRSelection* instruction)
{
    write(";selection");
}

Java::~Java()
{
    close();
}