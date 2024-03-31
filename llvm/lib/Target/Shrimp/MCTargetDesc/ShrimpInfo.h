#ifndef LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPINFO_H
#define LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace ShrimpOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace ShrimpOp

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SHRIMP_MCTARGETDESC_SHRIMPINFO_H