// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sipo_shift_register.h for the primary calling header

#include "Vtb_sipo_shift_register__pch.h"
#include "Vtb_sipo_shift_register___024root.h"

VlCoroutine Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__0(Vtb_sipo_shift_register___024root* vlSelf);
VlCoroutine Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__1(Vtb_sipo_shift_register___024root* vlSelf);

void Vtb_sipo_shift_register___024root___eval_initial(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_initial\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__0(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_sipo_shift_register__DOT__CLK = 0U;
    vlSelfRef.tb_sipo_shift_register__DOT__nRST = 0U;
    vlSelfRef.tb_sipo_shift_register__DOT__shift_enable = 0U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 0U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         29);
    vlSelfRef.tb_sipo_shift_register__DOT__nRST = 1U;
    VL_WRITEF_NX("Shifting data bits: 10110110\n",0);
    vlSelfRef.tb_sipo_shift_register__DOT__shift_enable = 1U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 1U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=1, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 6U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 0U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=0, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 5U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 1U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=1, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 4U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 1U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=1, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 3U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 0U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=0, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 2U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 1U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=1, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 1U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 1U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=1, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 0U;
    vlSelfRef.tb_sipo_shift_register__DOT__serial_in = 0U;
    co_await vlSelfRef.__VtrigSched_h58e14599__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_sipo_shift_register.CLK)", 
                                                         "tb_SIPO.sv", 
                                                         37);
    VL_WRITEF_NX("Time=%0t, shifted bit=0, data_out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data));
    vlSelfRef.tb_sipo_shift_register__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    vlSelfRef.tb_sipo_shift_register__DOT__shift_enable = 0U;
    VL_WRITEF_NX("Final data_out = %b (expected 10110110), done = %b\n",0,
                 8,vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data,
                 1,(IData)(vlSelfRef.tb_sipo_shift_register__DOT__done));
    VL_FINISH_MT("tb_SIPO.sv", 44, "");
}

VL_INLINE_OPT VlCoroutine Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__1(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb_SIPO.sv", 
                                             21);
        vlSelfRef.tb_sipo_shift_register__DOT__CLK 
            = (1U & (~ (IData)(vlSelfRef.tb_sipo_shift_register__DOT__CLK)));
    }
}

void Vtb_sipo_shift_register___024root___eval_act(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_act\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_sipo_shift_register___024root___nba_sequent__TOP__0(Vtb_sipo_shift_register___024root* vlSelf);

void Vtb_sipo_shift_register___024root___eval_nba(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_nba\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_sipo_shift_register___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_sipo_shift_register___024root___nba_sequent__TOP__0(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___nba_sequent__TOP__0\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt;
    __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt = 0;
    // Body
    __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt 
        = vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt;
    if (vlSelfRef.tb_sipo_shift_register__DOT__nRST) {
        vlSelfRef.tb_sipo_shift_register__DOT__done = 0U;
        if (vlSelfRef.tb_sipo_shift_register__DOT__shift_enable) {
            vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0U;
            vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__tmp 
                = vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data;
            vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data 
                = ((0xfeU & ((IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data) 
                             << 1U)) | (IData)(vlSelfRef.tb_sipo_shift_register__DOT__serial_in));
            if ((7U == (IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt))) {
                vlSelfRef.tb_sipo_shift_register__DOT__done = 1U;
                __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt = 0U;
            }
            __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt)));
        }
    } else {
        vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__data = 0U;
        __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt = 0U;
        vlSelfRef.tb_sipo_shift_register__DOT__done = 0U;
    }
    vlSelfRef.tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt 
        = __Vdly__tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt;
}

void Vtb_sipo_shift_register___024root___timing_resume(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___timing_resume\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h58e14599__0.resume(
                                                   "@(posedge tb_sipo_shift_register.CLK)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_sipo_shift_register___024root___timing_commit(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___timing_commit\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h58e14599__0.commit(
                                                   "@(posedge tb_sipo_shift_register.CLK)");
    }
}

void Vtb_sipo_shift_register___024root___eval_triggers__act(Vtb_sipo_shift_register___024root* vlSelf);

bool Vtb_sipo_shift_register___024root___eval_phase__act(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_phase__act\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_sipo_shift_register___024root___eval_triggers__act(vlSelf);
    Vtb_sipo_shift_register___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_sipo_shift_register___024root___timing_resume(vlSelf);
        Vtb_sipo_shift_register___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_sipo_shift_register___024root___eval_phase__nba(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_phase__nba\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_sipo_shift_register___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sipo_shift_register___024root___dump_triggers__nba(Vtb_sipo_shift_register___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sipo_shift_register___024root___dump_triggers__act(Vtb_sipo_shift_register___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sipo_shift_register___024root___eval(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_sipo_shift_register___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_SIPO.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_sipo_shift_register___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_SIPO.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_sipo_shift_register___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_sipo_shift_register___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_sipo_shift_register___024root___eval_debug_assertions(Vtb_sipo_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sipo_shift_register___024root___eval_debug_assertions\n"); );
    Vtb_sipo_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
