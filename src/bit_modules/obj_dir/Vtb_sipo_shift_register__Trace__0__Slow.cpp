// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb_sipo_shift_register__Syms.h"


VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_init_sub__TOP__0(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_init_sub__TOP__0\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_sipo_shift_register", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+5,0,"CLK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"nRST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"shift_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"serial_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"test_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("DUT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+5,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"shift_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"serial_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+3,0,"bit_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_init_top(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_init_top\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_sipo_shift_register___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb_sipo_shift_register___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb_sipo_shift_register___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_register(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_register\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_sipo_shift_register___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_sipo_shift_register___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_sipo_shift_register___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_sipo_shift_register___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_const_0_sub_0(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_const_0\n"); );
    // Init
    Vtb_sipo_shift_register___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sipo_shift_register___024root*>(voidSelf);
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_sipo_shift_register___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_const_0_sub_0(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_const_0_sub_0\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+10,(0xb6U),8);
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_full_0_sub_0(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_full_0\n"); );
    // Init
    Vtb_sipo_shift_register___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sipo_shift_register___024root*>(voidSelf);
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_sipo_shift_register___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root__trace_full_0_sub_0(Vtb_sipo_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root__trace_full_0_sub_0\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data),8);
    bufp->fullBit(oldp+2,(vlSelfRef.tb_sipo_shift_register__DOT__done));
    bufp->fullCData(oldp+3,(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt),3);
    bufp->fullIData(oldp+4,(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+5,(vlSelfRef.tb_sipo_shift_register__DOT__CLK));
    bufp->fullBit(oldp+6,(vlSelfRef.tb_sipo_shift_register__DOT__nRST));
    bufp->fullBit(oldp+7,(vlSelfRef.tb_sipo_shift_register__DOT__shift_enable));
    bufp->fullBit(oldp+8,(vlSelfRef.tb_sipo_shift_register__DOT__serial_in));
    bufp->fullIData(oldp+9,(vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i),32);
}
