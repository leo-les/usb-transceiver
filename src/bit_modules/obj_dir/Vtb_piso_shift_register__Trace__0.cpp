// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb_piso_shift_register__Syms.h"


void Vtb_piso_shift_register___024root__trace_chg_0_sub_0(Vtb_piso_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtb_piso_shift_register___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root__trace_chg_0\n"); );
    // Init
    Vtb_piso_shift_register___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_piso_shift_register___024root*>(voidSelf);
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_piso_shift_register___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_piso_shift_register___024root__trace_chg_0_sub_0(Vtb_piso_shift_register___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root__trace_chg_0_sub_0\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb_piso_shift_register__DOT__nRST));
        bufp->chgBit(oldp+1,(vlSelfRef.tb_piso_shift_register__DOT__shift_enable));
        bufp->chgCData(oldp+2,(vlSelfRef.tb_piso_shift_register__DOT__data_in),8);
        bufp->chgBit(oldp+3,(vlSelfRef.tb_piso_shift_register__DOT__load));
        bufp->chgIData(oldp+4,(vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+5,(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp));
        bufp->chgBit(oldp+6,(vlSelfRef.tb_piso_shift_register__DOT__busy));
        bufp->chgBit(oldp+7,(vlSelfRef.tb_piso_shift_register__DOT__done));
        bufp->chgCData(oldp+8,(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data),8);
        bufp->chgCData(oldp+9,(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__bit_cnt),3);
        bufp->chgIData(oldp+10,(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+11,(vlSelfRef.tb_piso_shift_register__DOT__clk));
}

void Vtb_piso_shift_register___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root__trace_cleanup\n"); );
    // Init
    Vtb_piso_shift_register___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_piso_shift_register___024root*>(voidSelf);
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
