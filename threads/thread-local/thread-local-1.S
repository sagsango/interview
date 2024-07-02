	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_functionA                      ; -- Begin function functionA
	.p2align	2
_functionA:                             ; @functionA
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, _threadVar@TLVPPAGE
	ldr	x0, [x0, _threadVar@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
                                        ; kill: def $w1 killed $w0
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	mov	w8, #10
	str	w8, [x0]
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_functionB                      ; -- Begin function functionB
	.p2align	2
_functionB:                             ; @functionB
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, _threadVar@TLVPPAGE
	ldr	x0, [x0, _threadVar@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
                                        ; kill: def $w1 killed $w0
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	mov	w8, #20
	str	w8, [x0]
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_func                           ; -- Begin function func
	.p2align	2
_func:                                  ; @func
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, _threadVar@TLVPPAGE
	ldr	x0, [x0, _threadVar@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #1
	str	w8, [x0]
	adrp	x0, _hello@TLVPPAGE
	ldr	x0, [x0, _hello@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #2
	str	w8, [x0]
	adrp	x0, _hi@TLVPPAGE
	ldr	x0, [x0, _hi@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #3
	str	w8, [x0]
	adrp	x0, _bye@TLVPPAGE
	ldr	x0, [x0, _bye@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #4
	str	w8, [x0]
	adrp	x0, _ola@TLVPPAGE
	ldr	x0, [x0, _ola@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #5
	str	w8, [x0]
	adrp	x0, _namaste@TLVPPAGE
	ldr	x0, [x0, _namaste@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	mov	w8, #6
	str	w8, [x0]
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	stur	w8, [x29, #-8]                  ; 4-byte Folded Spill
	stur	w8, [x29, #-4]
	bl	_func
	adrp	x0, _threadVar@TLVPPAGE
	ldr	x0, [x0, _threadVar@TLVPPAGEOFF]
	ldr	x8, [x0]
	blr	x8
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	bl	_functionA
	bl	_functionB
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	ldr	w8, [x0]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
                                        ; kill: def $w1 killed $w0
	ldur	w0, [x29, #-8]                  ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
.tbss _threadVar$tlv$init, 4, 2         ; @threadVar

	.section	__DATA,__thread_vars,thread_local_variables
	.globl	_threadVar
_threadVar:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_threadVar$tlv$init

.tbss _hello$tlv$init, 4, 2             ; @hello

	.globl	_hello
_hello:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_hello$tlv$init

	.section	__DATA,__thread_data,thread_local_regular
	.p2align	2, 0x0                          ; @hi
_hi$tlv$init:
	.long	1                               ; 0x1

	.section	__DATA,__thread_vars,thread_local_variables
	.globl	_hi
_hi:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_hi$tlv$init

	.section	__DATA,__thread_data,thread_local_regular
	.p2align	2, 0x0                          ; @bye
_bye$tlv$init:
	.long	2                               ; 0x2

	.section	__DATA,__thread_vars,thread_local_variables
	.globl	_bye
_bye:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_bye$tlv$init

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"In functionA, threadVar = %d\n"

l_.str.1:                               ; @.str.1
	.asciz	"In functionA after modification, threadVar = %d\n"

l_.str.2:                               ; @.str.2
	.asciz	"In functionB, threadVar = %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"In functionB after modification, threadVar = %d\n"

.tbss _ola$tlv$init, 4, 2               ; @ola

	.section	__DATA,__thread_vars,thread_local_variables
	.globl	_ola
_ola:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_ola$tlv$init

.tbss _namaste$tlv$init, 4, 2           ; @namaste

	.globl	_namaste
_namaste:
	.quad	__tlv_bootstrap
	.quad	0
	.quad	_namaste$tlv$init

	.section	__TEXT,__cstring,cstring_literals
l_.str.4:                               ; @.str.4
	.asciz	"In main, threadVar = %d\n"

l_.str.5:                               ; @.str.5
	.asciz	"Back in main, threadVar = %d\n"

.subsections_via_symbols
