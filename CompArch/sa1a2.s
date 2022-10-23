	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	wzr, [sp, #44]
	str	wzr, [sp, #16]
	str	wzr, [sp, #12]
	adrp	x8, l_.str@PAGE
	add	x8, x8, l_.str@PAGEOFF
	str	x8, [sp, #32]
	str	wzr, [sp, #20]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #20]
	ldrsb	w8, [x8, x9]
	cbz	w8, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_1
LBB0_4:
	ldr	w8, [sp, #16]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_5
LBB0_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	tbnz	w8, #31, LBB0_8
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #20]
	add	x8, x8, x9
	ldrb	w8, [x8]
	ldr	x9, [sp, #24]
	ldr	w10, [sp, #16]
	ldr	w11, [sp, #20]
	subs	w10, w10, w11
	subs	w10, w10, #1
	add	x9, x9, w10, sxtw
	strb	w8, [x9]
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldr	w8, [sp, #20]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_5
LBB0_8:
	mov	w8, #1
	str	w8, [sp, #12]
	str	wzr, [sp, #20]
	b	LBB0_9
LBB0_9:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #16]
	subs	w8, w8, w9
	b.ge	LBB0_14
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_9 Depth=1
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #20]
	ldrsb	w8, [x8, x9]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #20]
	ldrsb	w9, [x9, x10]
	subs	w8, w8, w9
	b.eq	LBB0_12
	b	LBB0_11
LBB0_11:                                ;   in Loop: Header=BB0_9 Depth=1
	str	wzr, [sp, #12]
	b	LBB0_12
LBB0_12:                                ;   in Loop: Header=BB0_9 Depth=1
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_9 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_9
LBB0_14:
	ldr	w0, [sp, #44]
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"abba"

.subsections_via_symbols
