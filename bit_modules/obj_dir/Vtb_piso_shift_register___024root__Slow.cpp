// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_piso_shift_register.h for the primary calling header

#include "Vtb_piso_shift_register__pch.h"
#include "Vtb_piso_shift_register__Syms.h"
#include "Vtb_piso_shift_register___024root.h"

void Vtb_piso_shift_register___024root___ctor_var_reset(Vtb_piso_shift_register___024root* vlSelf);

Vtb_piso_shift_register___024root::Vtb_piso_shift_register___024root(Vtb_piso_shift_register__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_piso_shift_register___024root___ctor_var_reset(this);
}

void Vtb_piso_shift_register___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_piso_shift_register___024root::~Vtb_piso_shift_register___024root() {
}
