
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
	move $s0,$a0
	li $s7,1
	beq $a0,$s7,label0
	j label1
label0:
	move $v0,$s0
	jr $ra
	j label2
label1:
	li $s7,1
	sub $t8,$a0,$s7
	move $t0,$a0
	move $a0,$t8
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $s7,$v0
	mul $t8,$a0,$s7
	move $s0,$t8
	move $v0,$s0
	jr $ra
label2:
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $s7,$s0
label3:
	li $s0,0
	bne $s7,$s0,label4
	j label5
label4:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s0,$v0
	
	move $t8,$s0
	li $s0,1
	bgt $t8,$s0,label6
	j label7
label6:
	move $t0,$a0
	move $a0,$t8
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $s0,$v0
	move $t8,$s0
	j label8
label7:
	li $s0,1
	move $t8,$s0
label8:
	move $a0,$t8
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal write
	lw $ra,0($sp)
	addi $sp,$sp,4
	
	j label3
label5:
	li $s0,1
	sub $t8,$s7,$s0
	move $s7,$t8
	li $s0,0
	move $v0,$s0
	jr $ra
