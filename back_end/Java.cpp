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
    write();
    
}

void Java::parse()
{
    for (std::map<std::string, CFG*>::iterator itCFG = listCFG.begin(); itCFG != listCFG.end(); ++itCFG)
    {
        const BasicBlock* block = itCFG->second->getRootBasicBlock();

        parseBasicBlocks(itCFG->second, block, true, itCFG->second->getPrologMaximalOffset(), nullptr);

        write("\treturn");
        write(".end method");
        write();
    }
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

void Java::parseBasicBlocks(CFG * cfg, const BasicBlock* block, bool prolog, int offsetBasicBlock, BasicBlock* terminal)
{
    std::string label;
    std::vector<IRInstruction*> instructions;

    while (block != terminal)
    {
        label = block->getLabel();
        if (label == "main")
        {
            write(".method public static main([Ljava/lang/String;)V");
        }
        else
        {
            write(label + ":");
        }

        if (prolog) // Prolog
        {
            int offset = offsetBasicBlock;
            write("\t.limit locals " + std::to_string(offset + 1));
            write("\t.limit stack " + std::to_string(offset + 1));

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
                    case IRInstruction::Operation::RWMEMORYARRAY :
                        rwmemoryarray((IRRWMemoryArray*) iri);
                        break;
                    case IRInstruction::Operation::CALL :
                        call((IRCall*) iri);
                        break;
                    case IRInstruction::Operation::CONDITIONNAL :
                        selection(cfg, (IRConditionnal*) iri);
                        break;
                    default:
                        break;
                }
            }
        }

        if (block->getExitTrue() != nullptr)
        {
            block = block->getExitTrue();
            write("\tgoto " + block->getLabel());
        }
        else if (block->getExitFalse() != nullptr)
        {
            block = block->getExitFalse();
            write("\tgoto " + block->getLabel());
        }
        else
        {
            block = nullptr;
        }
    }
}

void Java::binaryOp(const IRBinaryOp* instruction)
{
    write(";binaryOp");

    const Symbol* destination = instruction->getDestination();
    const Symbol* operand1 = instruction->getOperand_1();
    const Symbol* operand2 = instruction->getOperand_2();

    write("\tiload " + std::to_string(operand1->getOffset()));
    write("\tiload " + std::to_string(operand2->getOffset()));

    switch (instruction->getType())
    {
        case IRBinaryOp::Type::ADD :
            write("\tiadd");
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
    write("\tistore " + std::to_string(destination->getOffset()));
}

void Java::loadConstant(const IRLoadConstant* instruction)
{
    write(";loadConstant");

    const Symbol* destination = instruction->getDestination();
    const int value = instruction->getValue();

    write("\tbipush " + std::to_string(value));
    write("\tistore " + std::to_string(destination->getOffset()));
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
            write("\tiload " + std::to_string(source->getOffset()));
            write("\tistore " + std::to_string(destination->getOffset()));
            break;
        default:
            std::cout << "Erreur : type d'instruction IRRWMemory invalide [back_end:Java:rwmemory()]." << std::endl;
            break;
    }
}

void Java::rwmemoryarray(const IRRWMemoryArray* instruction)
{
    write(";rwmemoryarray");
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
        write("\tiload " + std::to_string(offset));
        write("\ti2c");
        write("\tinvokestatic java/lang/String/valueOf(C)Ljava/lang/String;");
        write("\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
    }
}

void Java::selection(CFG* cfg, const IRConditionnal * instruction)
{
    write(";conditionnal");

    // True/False -> condition

    const Symbol* condition = instruction->getCondition();
    BasicBlock* blockCondition = instruction->getBlockCondition();

    write("\tiload " + std::to_string(condition->getOffset()));

    switch (instruction->getType())
    {
        case IRConditionnal::Type::SELECTION :
            write("\tif_icmplt " + blockCondition->getExitTrue()->getLabel());
            if (blockCondition->getExitFalse() != nullptr)
            {
                write("\tgoto " + blockCondition->getExitFalse()->getLabel());

                BasicBlock* block = blockCondition->getExitFalse();
                BasicBlock* blockEnd = instruction->getBlockEnd();

                parseBasicBlocks(cfg, block, false, 0, blockEnd);
            }
            else
            {
                write("\tgoto " + instruction->getBlockEnd()->getLabel());
            }
            break;
        case IRConditionnal::Type::FOR :
            break;
        case IRConditionnal::Type::WHILE :
            break;
        default:
            break;
    }
}

Java::~Java()
{
    close();
}
