add_llvm_component_group(Shrimp)

add_llvm_target(ShrimpCodeGen
  ShrimpTargetMachine.cpp

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