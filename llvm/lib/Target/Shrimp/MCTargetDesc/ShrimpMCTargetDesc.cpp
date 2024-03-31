#include "MCTargetDesc/ShrimpInfo.h"
#include "ShrimpMCTargetDesc.h"
#include "TargetInfo/ShrimpTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ShrimpGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ShrimpGenInstrInfo.inc"

static MCRegisterInfo *createShrimpMCRegisterInfo(const Triple &TT) {
	MCRegisterInfo *X = new MCRegisterInfo();
	InitShrimpMCRegisterInfo(X, Shrimp::R0);
	return X;
}

static MCInstrInfo *createShrimpMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitShrimpMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" void LLVMInitializeShrimpTargetMC() {
	Target &TheShrimpTarget = getTheShrimpTarget();
	// Register the MC register info
	TargetRegistry::RegisterMCRegInfo(TheShrimpTarget, createShrimpMCRegisterInfo);
	// Register the MC instruction info.
	TargetRegistry::RegisterMCInstrInfo(TheShrimpTarget, createShrimpMCInstrInfo);
}
