#include "testIR.h"

CFG *testIR1()
{
	CFG* cfg = new CFG();

	BasicBlock* mainPrologBB = new BasicBlock(cfg, "main_prologue"); 
	BasicBlock* mainBB = new BasicBlock(cfg, "main"); 
	BasicBlock* mainEpilogBB = new BasicBlock(cfg, "main_entry"); 

	cfg->getBasicBlocks().push_back(mainPrologBB);
	cfg->getBasicBlocks().push_back(mainBB);
	cfg->getBasicBlocks().push_back(mainEpilogBB);

	mainPrologBB->setExitTrue(mainBB);
	mainPrologBB->setExitFalse(nullptr);

	mainBB->setExitTrue(mainEpilogBB);
	mainBB->setExitFalse(nullptr);

	mainBB->setExitTrue(nullptr);
	mainBB->setExitFalse(nullptr);
}

CFG *testIR2()
{
	return nullptr;
}

CFG *testIR3()
{
	return nullptr;
}

CFG *testIR4()
{
	return nullptr;
}

CFG *testIR5()
{
	return nullptr;
}

CFG *testIR6()
{
	return nullptr;
}

CFG *testIR7()
{
	return nullptr;
}

CFG *testIR8()
{
	return nullptr;
}

CFG *testIR9()
{
	return nullptr;
}

CFG *testIR10()
{
	return nullptr;
}

CFG *testIR11()
{
	return nullptr;
}

CFG *testIR12()
{
	return nullptr;
}

CFG *testIR13()
{
	return nullptr;
}

CFG *testIR14()
{
	return nullptr;
}

CFG *testIR15()
{
	return nullptr;
}