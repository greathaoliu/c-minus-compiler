import os 
import re
import io

regs={'t1', 't2', 't3', 't4', 't5', 't6', 't7', 't8', 't9', 's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7'}

a={'a3','a2','a1','a0'}
reg_ready={}
table={}
variables=[]
arg_num=0

def Recode_Var(Intercode):
    global variables
    temp_re='(temp\d*|var\d)'
    for line in Intercode:
        temps=re.findall(temp_re, ' '.join(line))
        variables+=temps


def Lord_Intercode(Filename):
    lines=[]
    for line in io.open(Filename, 'r', encoding='utf-8'):
        line=line.replace('\r','').replace('\n', '')
        if line=='':
            continue
        lines.append(line.split(' '))

    return lines


def Get_Reg(String):
    try:
        variables.remove(String)
    except:
        pass

    if String in table:             
        return '$'+table[String]
    else:
        Strings=[]
        for key in table:
            Strings.append(key)
        for key in Strings:
            if 'temp' in key and key not in variables:  
                reg_ready[table[key]]=1
                del table[key]
            if 'var' in key and key not in variables:  
                del table[key]


        for reg in regs:
            if reg_ready[reg]==1:
                table[String]=reg
                reg_ready[reg]=0
                return '$'+reg



def translate(line):
    global arg_num
    global param_num
    if line[0]=='LABEL':
        return line[1]+':'
    if line[0]=='PARAM':
        param_judge=1
        if param_num==0:
            param_num=param_num+1
            table[line[1]]='a0'
            Get_Reg(line[1])
        elif param_num==1:
            param_num=param_num+1
            table[line[1]]='a1'
            Get_Reg(line[1])
        elif param_num==2:
            param_num=param_num+1
            table[line[1]]='a2'
            Get_Reg(line[1])
        elif param_num==3:
            param_num=param_num+1
            table[line[1]]='a3'
            Get_Reg(line[1])

    if line[0]=='GOTO':
        return '\tj %s'%line[-1]
    if line[0]=='RETURN':
        return_judge =1
        return '\tmove $v0,%s\n\tjr $ra'%Get_Reg(line[-1])
    if line[0]=='ARG':
        if arg_num==0:
            arg_num=arg_num+1
            return '\tmove $t0,$a0\n\tmove $a0,%s'%Get_Reg(line[-1])
        elif arg_num==1:
            arg_num=arg_num+1
            return '\tmove $t1,$a1\n\tmove $a1,%s'%Get_Reg(line[-1])
        elif arg_num==2:
            arg_num=arg_num+1
            return '\tmove $t2,$a2\n\tmove $a2,%s'%Get_Reg(line[-1])
        elif arg_num==3:
            arg_num=arg_num+1
            return '\tmove $t3,$a3\n\tmove $a3,%s'%Get_Reg(line[-1])
    if line[0]=='FUNCTION':
        param_num=0
        return '%s:'%line[1]
    if line[0]=='READ':
        if len(line)==1:
            return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal read\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4\n\t'
        else:
            return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal read\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4\n\tmove %s,$v0\n\t'%(Get_Reg(line[1]))
    if line[0]=='WRITE':
        if len(line)==1:
            return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal write\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4\n\t'
        else:
            return '\tmove $a0,%s\n\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal write\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4\n\t'%(Get_Reg(line[1]))
    if line[0]=='CALL':
        if arg_num==1:
            arg_num=0
            return '\taddi $sp,$sp,-8\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\taddi $sp,$sp,8\n\t'%(line[-1])
        elif arg_num==2:
            arg_num=0
            return '\taddi $sp,$sp,-12\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $ra,8($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $ra,8($sp)\n\taddi $sp,$sp,12\n\t'%(line[-1])
        elif arg_num==3:
            arg_num=0
            return '\taddi $sp,$sp,-16\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $t2,8($sp)\n\tsw $ra,12($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $a2,8($sp)\n\tlw $ra,12($sp)\n\taddi $sp,$sp,16\n\t'%(line[-1])
        elif arg_num==4:
            arg_num=0
            return '\taddi $sp,$sp,-20\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $t2,8($sp)\n\tsw $t3,12($sp)\n\tsw $ra,16($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $a2,8($sp)\n\tlw $a3,12($sp)\n\tlw $ra,16($sp)\n\taddi $sp,$sp,20\n\t'%(line[-1])


    if line[0]=='IF':
        if line[2]=='==':
            return '\tbeq %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])
        if line[2]=='!=':
            return '\tbne %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])
        if line[2]=='>':
            return '\tbgt %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])
        if line[2]=='<':
            return '\tblt %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])
        if line[2]=='>=':
            return '\tbge %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])
        if line[2]=='<=':
            return '\tble %s,%s,%s'%(Get_Reg(line[1]),Get_Reg(line[3]),line[-1])

    if line[1]=='=':
        if len(line)==3:
            if line[2][0]=='#':
                return '\tli %s,%s'%(Get_Reg(line[0]), line[2].replace('#',''))
            else:
                return '\tmove %s,%s'%(Get_Reg(line[0]), Get_Reg(line[2]))
        elif len(line)==4:
           if line[2]=='CALL':
                if arg_num==1:
                    arg_num=0
                    return '\taddi $sp,$sp,-8\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\taddi $sp,$sp,8\n\tmove %s,$v0'%(line[-1],Get_Reg(line[0]))
                elif arg_num==2:
                    arg_num=0
                    return '\taddi $sp,$sp,-12\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $ra,8($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $ra,8($sp)\n\taddi $sp,$sp,12\n\tmove %s,$v0'%(line[-1],Get_Reg(line[0]))
                elif arg_num==3:
                    arg_num=0
                    return '\taddi $sp,$sp,-16\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $t2,8($sp)\n\tsw $ra,12($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $a2,8($sp)\n\tlw $ra,12($sp)\n\taddi $sp,$sp,16\n\tmove %s,$v0'%(line[-1],Get_Reg(line[0]))
                elif arg_num==4:
                    arg_num=0
                    return '\taddi $sp,$sp,-20\n\tsw $t0,0($sp)\n\tsw $t1,4($sp)\n\tsw $t2,8($sp)\n\tsw $t3,12($sp)\n\tsw $ra,16($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $a1,4($sp)\n\tlw $a2,8($sp)\n\tlw $a3,12($sp)\n\tlw $ra,16($sp)\n\taddi $sp,$sp,20\n\tmove %s,$v0'%(line[-1],Get_Reg(line[0]))

        elif len(line)==5:
            if line[1]=='=':
                if line[3]=='+':
                    if line[-1][0]=='#':
                        return '\taddi %s,%s,%s'%(Get_Reg(line[0]), Get_Reg(line[2]),line[4].replace('#', ''))
                    else:
                        return '\tadd %s,%s,%s'%(Get_Reg(line[0]), Get_Reg(line[2]), Get_Reg(line[4]))
                elif line[3]=='-':
                    if line[-1][0]=='#':
                        return '\taddi %s,%s,-%s'%(Get_Reg(line[0]), Get_Reg(line[2]),line[4].replace('#', ''))
                    else:
                        return '\tsub %s,%s,%s'%(Get_Reg(line[0]), Get_Reg(line[2]),Get_Reg(line[4]))
                elif line[3]=='*':
                    return '\tmul %s,%s,%s'%(Get_Reg(line[0]), Get_Reg(line[2]),Get_Reg(line[4]))
                elif line[3]=='/':
                    return '\tdiv %s,%s\n\tmflo %s'%(Get_Reg(line[2]),Get_Reg(line[-1]),Get_Reg(line[0]))
                elif line[3]=='==':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])
                elif line[3]=='!=':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])
                elif line[3]=='>':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])
                elif line[3]=='<':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])
                elif line[3]=='>=':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])
                elif line[3]=='<=':
                    Get_Reg(line[0])
                    Get_Reg(line[2])
                    Get_Reg(line[4])

    return ''

def write_to_txt(obj):
    f=open('result.asm', 'w')
    code='''
.data
_prompt: .asciiz "Enter your integar:"
_ret: .asciiz "\\n"
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
'''
    f.write(code)
    for line in obj:
        f.write(line+'\n')
    f.close()


def parser():
    for reg in regs:
        reg_ready[reg]=1  
    Intercode=Lord_Intercode('intercode.txt')  
    Recode_Var(Intercode)   
    obj=[]
    arg_num=0
    for line in Intercode:
        obj_line=translate(line) 
        if obj_line=='':
            continue
        obj.append(obj_line)
    write_to_txt(obj)

parser()





