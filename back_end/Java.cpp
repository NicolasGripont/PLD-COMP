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
                write("\t.limit locals " + std::to_string(offset));
                write("\t.limit stack " + std::to_string(offset));

                write("\tgetstatic java/lang/System/out Ljava/io/PrintStream;");
                write("\tastore_0");

                prolog = false;
            }
            else // Other
            {
                instructions = block->getInstructions();
                for (const IRInstruction* iri : instructions)
                {
                    IRInstruction::Operation instruction = iri->getOperation();

                    switch (instruction)
                    {
                        case IRInstruction::Operation::BINARY_OP :
                            binaryOp((IRBinaryOp*) iri);
                            break;
                        case IRInstruction::Operation::LOAD_CONSTANT :
                            loadConstant((IRLoadConstant*) iri);
                            break;
                        case IRInstruction::Operation::RWMEMORY :
                            rwmemory((IRRWMemory*) iri);
                            break;
                        case IRInstruction::Operation::CALL :
                            call((IRCall*) iri);
                            break;
                        case IRInstruction::Operation::CONDITIONNAL :
                            selection((IRConditionnal*) iri);
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
        case IRBinaryOp::Type::MOD :
            break;
        case IRBinaryOp::Type::EQUAL_EQUAL :
            break;
        case IRBinaryOp::Type::DIFF :
            break;
        case IRBinaryOp::Type::LESS_THAN :
            break;
        case IRBinaryOp::Type::LESS_THAN_OR_EQUAL :
            break;
        case IRBinaryOp::Type::MORE_THAN :
            break;
        case IRBinaryOp::Type::MORE_THAN_OR_EQUAL :
            break;
        case IRBinaryOp::Type::AND_AND :
            break;
        case IRBinaryOp::Type::OR_OR :
            break;
        case IRBinaryOp::Type::OR :
            break;
        case IRBinaryOp::Type::AND :
            break;
        case IRBinaryOp::Type::LEFT_DEC :
            break;
        case IRBinaryOp::Type::RIGHT_DEC :
            break;
        case IRBinaryOp::Type::POW :
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

    write("\tbipush " + std::to_string(value));
    //write("\ti2c"); // ToDo
    write("\tinvokestatic java/lang/String/valueOf(I)Ljava/lang/String;");
    write("\tastore " + std::to_string(destination->getOffset()));
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
            write("\taload " + std::to_string(source->getOffset()));
            write("\tastore " + std::to_string(destination->getOffset()));
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

    if (params.size() > 0)
    {
        int offset = params.at(0)->getOffset();

        // Only System.out.println() for the time being
        write("\taload_0");
        write("\taload " + std::to_string(offset));
        write("\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
    }
}

void Java::selection(const IRConditionnal * instruction)
{
    write(";conditionnal");
}

Java::~Java()
{
    close();
}
