include "llvm/Target/Target.td"
include "ShrimpRegisterInfo.td"
include "ShrimpInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def ShrimpInstrInfo : InstrInfo;
def Shrimp : Target {
  let InstructionSet = ShrimpInstrInfo;
}