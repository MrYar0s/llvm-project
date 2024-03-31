#include "ShrimpMCTargetDesc.h"
#include "TargetInfo/ShrimpTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ShrimpGenRegisterInfo.inc"

static MCRegisterInfo *createShrimpMCRegisterInfo(const Triple &TT) {
	MCRegisterInfo *X = new MCRegisterInfo();
	InitShrimpMCRegisterInfo(X, Shrimp::R0);
	return X;
}

// We need to define this function for linking succeed
extern "C" void LLVMInitializeShrimpTargetMC() {
	Target &TheShrimpTarget = getTheShrimpTarget();
	// Register the MC register info
	TargetRegistry::RegisterMCRegInfo(TheShrimpTarget, createShrimpMCRegisterInfo);
}
