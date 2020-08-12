
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
	li $t6,1
	beq $a0,$t6,label0
	j label1
label0:
	move $v0,$a0
	jr $ra
	j label2
label1:
	li $t6,1
	sub $s5,$a0,$t6
	move $t0,$a0
	move $a0,$s5
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $t6,$v0
	mul $s5,$a0,$t6
	move $t6,$s5
	move $v0,$t6
	jr $ra
label2:
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s5,$v0
	
	move $t5,$s5
label3:
	li $s5,0
	bne $t5,$s5,label4
	j label5
label4:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $s5,$v0
	
	move $t9,$s5
	li $s5,1
	bgt $t9,$s5,label6
	j label7
label6:
	move $t0,$a0
	move $a0,$t9
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $s5,$v0
	move $s2,$s5
	j label8
label7:
	li $s5,1
	move $s2,$s5
label8:
	move $a0,$s2
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal write
	lw $ra,0($sp)
	addi $sp,$sp,4
	
	j label3
label5:
	li $s5,1
	sub $t8,$t5,$s5
	move $t5,$t8
	li $s5,0
	move $v0,$s5
	jr $ra
