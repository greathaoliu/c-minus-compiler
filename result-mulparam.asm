
.data
_prompt: .asciiz "Enter your integar:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
    syscall
    li $v0,5
    syscall
    jr $ra

write:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
fact:
	mul $s0,$a0,$a1
	mul $s7,$a2,$a3
	add $t8,$s0,$s7
	move $v0,$t8
	jr $ra
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $s7,$s0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $t8,$s0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $t9,$s0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $t6,$s0
	move $t0,$a0
	move $a0,$t6
	move $t1,$a1
	move $a1,$t9
	move $t2,$a2
	move $a2,$t8
	move $t3,$a3
	move $a3,$s7
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $ra,16($sp)
	jal fact
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $a2,8($sp)
	lw $a3,12($sp)
	lw $ra,16($sp)
	addi $sp,$sp,20
	move $s0,$v0
	move $t7,$s0
	move $a0,$t7
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal write
	lw $ra,0($sp)
	addi $sp,$sp,4
	
	li $s0,0
	move $v0,$s0
	jr $ra
