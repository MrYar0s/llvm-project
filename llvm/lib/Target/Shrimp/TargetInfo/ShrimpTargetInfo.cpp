#include "TargetInfo/ShrimpTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheShrimpTarget() {
  static Target TheShrimpTarget;
  return TheShrimpTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeShrimpTargetInfo() {
  RegisterTarget<Triple::shrimp> X(getTheShrimpTarget(), "shrimp", "Shrimp (64-bit simulator arch)",
                                   "SHRIMP");
}