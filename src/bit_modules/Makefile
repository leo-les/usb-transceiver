VERILATE := verilator
VERILATE_FLAGS := --binary --trace-fst

PISO: PISO.sv tb_PISO.sv
	$(VERILATE) $(VERILATE_FLAGS) --top-module tb_piso_shift_register $^
	cp obj_dir/Vtb_piso_shift_register .

SIPO: SIPO.sv tb_SIPO.sv
	$(VERILATE) $(VERILATE_FLAGS) --top-module tb_sipo_shift_register $^
	cp obj_dir/Vtb_sipo_shift_register .

clean:
	rm -rf obj_dir
	rm -rf waveform.fst
	rm -f Vtb_SIPO
	rm -f Vtb_PISO