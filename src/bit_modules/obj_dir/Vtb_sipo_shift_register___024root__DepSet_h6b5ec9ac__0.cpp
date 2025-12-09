// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sipo_shift_register.h for the primary calling header

#include "Vtb_sipo_shift_register__pch.h"
#include "Vtb_sipo_shift_register__Syms.h"
#include "Vtb_sipo_shift_register___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sipo_shift_register___024root___dump_triggers__act(Vtb_sipo_shift_register___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sipo_shift_register___024root___eval_triggers__act(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_triggers__act\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_sipo_shift_register__DOT__CLK) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__CLK__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_sipo_shift_register__DOT__nRST)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__nRST__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__CLK__0 
        = vlSelfRef.tb_sipo_shift_register__DOT__CLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__nRST__0 
        = vlSelfRef.tb_sipo_shift_register__DOT__nRST;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sipo_shift_register___024root___dump_triggers__act(vlSelf);
    }
#endif
}
