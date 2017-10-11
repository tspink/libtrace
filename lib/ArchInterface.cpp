#include "libtrace/ArchInterface.h"

using namespace libtrace;

ArchInterface::~ArchInterface()
{

}

DefaultArchInterface::~DefaultArchInterface()
{

}

std::string DefaultArchInterface::DisassembleInstruction(const InstructionCodeRecord &record) {
	return "???";
}

std::string DefaultArchInterface::GetRegisterSlotName(int idx) {
	return "???";
}
std::string DefaultArchInterface::GetRegisterBankName(int idx) {
	return "???";
}

uint32_t DefaultArchInterface::GetRegisterSlotWidth(int idx) {
	return 0;
}
uint32_t DefaultArchInterface::GetRegisterBankWidth(int idx) {
	return 0;
}
