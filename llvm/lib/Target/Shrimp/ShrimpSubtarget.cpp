#include "ShrimpSubtarget.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "shrimp-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ShrimpGenSubtargetInfo.inc"

ShrimpSubtarget::ShrimpSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : ShrimpGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {}