#include "ShrimpRegisterInfo.h"
#include "MCTargetDesc/ShrimpMCTargetDesc.h"
#include "ShrimpFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ShrimpGenRegisterInfo.inc"

ShrimpRegisterInfo::ShrimpRegisterInfo() : ShrimpGenRegisterInfo(Shrimp::R0) {}