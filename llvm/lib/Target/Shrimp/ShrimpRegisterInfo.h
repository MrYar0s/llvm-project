#ifndef LLVM_LIB_TARGET_SHRIMP_SHRIMPREGISTERINFO_H
#define LLVM_LIB_TARGET_SHRIMP_SHRIMPREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "ShrimpGenRegisterInfo.inc"

namespace llvm {

struct ShrimpRegisterInfo : public ShrimpGenRegisterInfo {
public:
  ShrimpRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SHRIMP_SHRIMPREGISTERINFO_H