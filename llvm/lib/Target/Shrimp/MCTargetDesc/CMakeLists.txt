add_llvm_component_library(LLVMShrimpDesc
  ShrimpMCTargetDesc.cpp
  ShrimpMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  ShrimpInfo

  ADD_TO_COMPONENT
  Shrimp
 )
