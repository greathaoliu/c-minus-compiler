
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
	li $s0,1
	beq $a0,$s0,label0
	j label1
label0:
	move $v0,$a0
	jr $ra
	j label2
label1:
	li $s0,1
	sub $s7,$a0,$s0
	move $t0,$a0
	move $a0,$s7
	li $s0,1
	move $t1,$a1
	move $a1,$s0
	addi $sp,$sp,-12
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $ra,8($sp)
	jal fact
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $ra,8($sp)
	addi $sp,$sp,12
	move $s0,$v0
	mul $s7,$a0,$s0
	move $s0,$s7
	move $v0,$s0
	jr $ra
label2:
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s7,$v0
	
	move $t8,$s7
label3:
	li $s7,0
	bne $t8,$s7,label4
	j label5
label4:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s7,$v0
	
	move $t9,$s7
	li $s7,1
	bgt $t9,$s7,label6
	j label7
label6:
	move $t0,$a0
	move $a0,$t9
	li $s7,1
	move $t1,$a1
	move $a1,$s7
	addi $sp,$sp,-12
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $ra,8($sp)
	jal fact
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $ra,8($sp)
	addi $sp,$sp,12
	move $s7,$v0
	move $t6,$s7
	j label8
label7:
	li $s7,1
	move $t6,$s7
label8:
	move $a0,$t6
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal write
	lw $ra,0($sp)
	addi $sp,$sp,4
	
	j label3
label5:
	li $s7,1
	sub $t7,$t8,$s7
	move $t8,$t7
	li $s7,0
	move $v0,$s7
	jr $ra
