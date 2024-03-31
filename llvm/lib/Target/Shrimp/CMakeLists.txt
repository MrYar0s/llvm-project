add_llvm_component_group(Shrimp)

set(LLVM_TARGET_DEFINITIONS Shrimp.td)

tablegen(LLVM ShrimpGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(ShrimpCommonTableGen)

add_llvm_target(ShrimpCodeGen
  ShrimpTargetMachine.cpp
  ShrimpRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  MC
  Support
  Target
  ShrimpInfo

  ADD_TO_COMPONENT
  Shrimp
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)