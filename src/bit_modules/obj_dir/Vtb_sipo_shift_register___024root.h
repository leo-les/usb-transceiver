// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sipo_shift_register.h for the primary calling header

#ifndef VERILATED_VTB_SIPO_SHIFT_REGISTER___024ROOT_H_
#define VERILATED_VTB_SIPO_SHIFT_REGISTER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_sipo_shift_register__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sipo_shift_register___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_sipo_shift_register__DOT__CLK;
    CData/*0:0*/ tb_sipo_shift_register__DOT__nRST;
    CData/*0:0*/ tb_sipo_shift_register__DOT__shift_enable;
    CData/*0:0*/ tb_sipo_shift_register__DOT__serial_in;
    CData/*0:0*/ tb_sipo_shift_register__DOT__done;
    CData/*7:0*/ tb_sipo_shift_register__DOT__DUT__DOT__data;
    CData/*2:0*/ tb_sipo_shift_register__DOT__DUT__DOT__bit_cnt;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__CLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sipo_shift_register__DOT__nRST__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_sipo_shift_register__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_sipo_shift_register__DOT__DUT__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h58e14599__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_sipo_shift_register__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sipo_shift_register___024root(Vtb_sipo_shift_register__Syms* symsp, const char* v__name);
    ~Vtb_sipo_shift_register___024root();
    VL_UNCOPYABLE(Vtb_sipo_shift_register___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
