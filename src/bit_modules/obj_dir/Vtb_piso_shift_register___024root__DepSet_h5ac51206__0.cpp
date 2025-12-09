// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_piso_shift_register.h for the primary calling header

#include "Vtb_piso_shift_register__pch.h"
#include "Vtb_piso_shift_register___024root.h"

VlCoroutine Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__0(Vtb_piso_shift_register___024root* vlSelf);
VlCoroutine Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__1(Vtb_piso_shift_register___024root* vlSelf);

void Vtb_piso_shift_register___024root___eval_initial(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_initial\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__1(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb_PISO.sv", 
                                             22);
        vlSelfRef.tb_piso_shift_register__DOT__clk 
            = (1U & (~ (IData)(vlSelfRef.tb_piso_shift_register__DOT__clk)));
    }
}

void Vtb_piso_shift_register___024root___eval_act(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_act\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_piso_shift_register___024root___nba_sequent__TOP__0(Vtb_piso_shift_register___024root* vlSelf);

void Vtb_piso_shift_register___024root___eval_nba(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_nba\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_piso_shift_register___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_piso_shift_register___024root___nba_sequent__TOP__0(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___nba_sequent__TOP__0\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data;
    __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data = 0;
    CData/*2:0*/ __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt;
    __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt = 0;
    CData/*0:0*/ __Vdly__tb_piso_shift_register__DOT__busy;
    __Vdly__tb_piso_shift_register__DOT__busy = 0;
    // Body
    __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data 
        = vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data;
    __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt 
        = vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__bit_cnt;
    __Vdly__tb_piso_shift_register__DOT__busy = vlSelfRef.tb_piso_shift_register__DOT__busy;
    if (vlSelfRef.tb_piso_shift_register__DOT__nRST) {
        vlSelfRef.tb_piso_shift_register__DOT__done = 0U;
        if (((IData)(vlSelfRef.tb_piso_shift_register__DOT__load) 
             & (~ (IData)(vlSelfRef.tb_piso_shift_register__DOT__busy)))) {
            __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data 
                = vlSelfRef.tb_piso_shift_register__DOT__data_in;
            __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt = 0U;
            __Vdly__tb_piso_shift_register__DOT__busy = 1U;
        } else if (((IData)(vlSelfRef.tb_piso_shift_register__DOT__busy) 
                    & (IData)(vlSelfRef.tb_piso_shift_register__DOT__shift_enable))) {
            vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__i = 0U;
            vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp 
                = (1U & ((IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data) 
                         >> 7U));
            if ((7U == (IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__bit_cnt))) {
                __Vdly__tb_piso_shift_register__DOT__busy = 0U;
                vlSelfRef.tb_piso_shift_register__DOT__done = 1U;
                __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt = 0U;
            } else {
                __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__bit_cnt)));
            }
            __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data 
                = (0xfeU & ((IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data) 
                            << 1U));
        }
    } else {
        __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data = 0U;
        __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt = 0U;
        __Vdly__tb_piso_shift_register__DOT__busy = 0U;
        vlSelfRef.tb_piso_shift_register__DOT__done = 0U;
        vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp = 0U;
    }
    vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data 
        = __Vdly__tb_piso_shift_register__DOT__DUT__DOT__data;
    vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__bit_cnt 
        = __Vdly__tb_piso_shift_register__DOT__DUT__DOT__bit_cnt;
    vlSelfRef.tb_piso_shift_register__DOT__busy = __Vdly__tb_piso_shift_register__DOT__busy;
}

void Vtb_piso_shift_register___024root___timing_resume(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___timing_resume\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h724a30e7__0.resume(
                                                   "@(posedge tb_piso_shift_register.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_piso_shift_register___024root___timing_commit(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___timing_commit\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h724a30e7__0.commit(
                                                   "@(posedge tb_piso_shift_register.clk)");
    }
}

void Vtb_piso_shift_register___024root___eval_triggers__act(Vtb_piso_shift_register___024root* vlSelf);

bool Vtb_piso_shift_register___024root___eval_phase__act(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_phase__act\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_piso_shift_register___024root___eval_triggers__act(vlSelf);
    Vtb_piso_shift_register___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_piso_shift_register___024root___timing_resume(vlSelf);
        Vtb_piso_shift_register___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_piso_shift_register___024root___eval_phase__nba(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_phase__nba\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_piso_shift_register___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_piso_shift_register___024root___dump_triggers__nba(Vtb_piso_shift_register___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_piso_shift_register___024root___dump_triggers__act(Vtb_piso_shift_register___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_piso_shift_register___024root___eval(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_piso_shift_register___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_PISO.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_piso_shift_register___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_PISO.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_piso_shift_register___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_piso_shift_register___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_piso_shift_register___024root___eval_debug_assertions(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_debug_assertions\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
