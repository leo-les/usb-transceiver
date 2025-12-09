// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_piso_shift_register.h for the primary calling header

#include "Vtb_piso_shift_register__pch.h"
#include "Vtb_piso_shift_register__Syms.h"
#include "Vtb_piso_shift_register___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__0(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"wave.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb_piso_shift_register__DOT__clk = 0U;
    vlSelfRef.tb_piso_shift_register__DOT__nRST = 0U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 0U;
    vlSelfRef.tb_piso_shift_register__DOT__load = 0U;
    vlSelfRef.tb_piso_shift_register__DOT__data_in = 0U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         41);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_piso_shift_register__DOT__nRST = 1U;
    vlSelfRef.tb_piso_shift_register__DOT__data_in = 0xb7U;
    VL_WRITEF_NX("Loading data: %b\n",0,8,vlSelfRef.tb_piso_shift_register__DOT__data_in);
    vlSelfRef.tb_piso_shift_register__DOT__load = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         48);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_piso_shift_register__DOT__load = 0U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         50);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 1U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 2U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 3U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 4U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 5U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 6U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 7U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         27);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Time=%0t, serial_out=%b, data=%b\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__tmp),
                 8,vlSelfRef.tb_piso_shift_register__DOT__DUT__DOT__data);
    vlSelfRef.tb_piso_shift_register__DOT__unnamedblk1__DOT__i = 8U;
    vlSelfRef.tb_piso_shift_register__DOT__shift_enable = 0U;
    co_await vlSelfRef.__VtrigSched_h724a30e7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_piso_shift_register.clk)", 
                                                         "tb_PISO.sv", 
                                                         57);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Shift complete. done=%b, busy=%b\n",0,
                 1,vlSelfRef.tb_piso_shift_register__DOT__done,
                 1,(IData)(vlSelfRef.tb_piso_shift_register__DOT__busy));
    VL_FINISH_MT("tb_PISO.sv", 59, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_piso_shift_register___024root___dump_triggers__act(Vtb_piso_shift_register___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_piso_shift_register___024root___eval_triggers__act(Vtb_piso_shift_register___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_piso_shift_register___024root___eval_triggers__act\n"); );
    Vtb_piso_shift_register__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_piso_shift_register__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_piso_shift_register__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_piso_shift_register__DOT__nRST)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_piso_shift_register__DOT__nRST__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_piso_shift_register__DOT__clk__0 
        = vlSelfRef.tb_piso_shift_register__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_piso_shift_register__DOT__nRST__0 
        = vlSelfRef.tb_piso_shift_register__DOT__nRST;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_piso_shift_register___024root___dump_triggers__act(vlSelf);
    }
#endif
}
