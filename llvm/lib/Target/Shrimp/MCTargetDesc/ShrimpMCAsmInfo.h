#ifndef LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPMCASMINFO_H
#define LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class ShrimpELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit ShrimpELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPMCASMINFO_H