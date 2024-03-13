add_llvm_component_library(LLVMShrimpDesc
  ShrimpMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  ShrimpInfo

  ADD_TO_COMPONENT
  Shrimp
 )
