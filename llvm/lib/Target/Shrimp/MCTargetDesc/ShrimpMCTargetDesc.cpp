#include "MCTargetDesc/ShrimpInfo.h"
#include "ShrimpMCTargetDesc.h"
#include "ShrimpMCAsmInfo.h"
#include "TargetInfo/ShrimpTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ShrimpGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ShrimpGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "ShrimpGenSubtargetInfo.inc"

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

static MCSubtargetInfo *createShrimpMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  return createShrimpMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createShrimpMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new ShrimpELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Shrimp::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

// We need to define this function for linking succeed
extern "C" void LLVMInitializeShrimpTargetMC() {
	Target &TheShrimpTarget = getTheShrimpTarget();
	RegisterMCAsmInfoFn X(TheShrimpTarget, createShrimpMCAsmInfo);
	// Register the MC register info
	TargetRegistry::RegisterMCRegInfo(TheShrimpTarget, createShrimpMCRegisterInfo);
	// Register the MC instruction info.
	TargetRegistry::RegisterMCInstrInfo(TheShrimpTarget, createShrimpMCInstrInfo);
	// Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheShrimpTarget,
                                          createShrimpMCSubtargetInfo);
}
