#ifndef LLVM_LIB_TARGET_SHRIMP_SHRIMPINSTRINFO_H
#define LLVM_LIB_TARGET_SHRIMP_SHRIMPINSTRINFO_H

#include "ShrimpRegisterInfo.h"
#include "MCTargetDesc/ShrimpInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "ShrimpGenInstrInfo.inc"

namespace llvm {

class ShrimpSubtarget;

class ShrimpInstrInfo : public ShrimpGenInstrInfo {
public:
  ShrimpInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SHRIMP_SHRIMPINSTRINFO_H