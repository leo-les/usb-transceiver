// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sipo_shift_register.h for the primary calling header

#include "Vtb_sipo_shift_register__pch.h"
#include "Vtb_sipo_shift_register___024root.h"

VL_ATTR_COLD void Vtb_sipo_shift_register___024root___eval_static(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_static\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__CLK__0 
        = vlSelfRef.tb_sipo_shift_register__DOT__CLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__nRST__0 
        = vlSelfRef.tb_sipo_shift_register__DOT__nRST;
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root___eval_final(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_final\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_sipo_shift_register___024root___eval_settle(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_settle\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sipo_shift_register___024root___dump_triggers__act(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___dump_triggers__act\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_sipo_shift_register.CLK)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_sipo_shift_register.nRST)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sipo_shift_register___024root___dump_triggers__nba(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___dump_triggers__nba\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_sipo_shift_register.CLK)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_sipo_shift_register.nRST)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sipo_shift_register___024root___ctor_var_reset(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___ctor_var_reset\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_sipo_shift_register__DOT__CLK = VL_RAND_RESET_I(1);
    vlSelf->tb_sipo_shift_register__DOT__nRST = VL_RAND_RESET_I(1);
    vlSelf->tb_sipo_shift_register__DOT__shift_enable = VL_RAND_RESET_I(1);
    vlSelf->tb_sipo_shift_register__DOT__serial_in = VL_RAND_RESET_I(1);
    vlSelf->tb_sipo_shift_register__DOT__done = VL_RAND_RESET_I(1);
    vlSelf->tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_sipo_shift_register__DOT__DUT__DOT__data = VL_RAND_RESET_I(8);
    vlSelf->tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt = VL_RAND_RESET_I(3);
    vlSelf->tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__tmp = VL_RAND_RESET_I(8);
    vlSelf->tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__CLK__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__nRST__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
