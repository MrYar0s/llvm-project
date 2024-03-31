include "llvm/Target/Target.td"
include "ShrimpRegisterInfo.td"

include "ShrimpInstrInfo.td"

def ShrimpInstrInfo : InstrInfo;
def Shrimp : Target {
  let InstructionSet = ShrimpInstrInfo;
}