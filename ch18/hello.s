.section .data,
.section .text,
.globl start
start:
movl $1,%eax
movl $4,%ebx
int $0x80
