main:
	lui	$a0,0x8000
	jal	first1pos
	jal	printv0
	lui	$a0,0x0001
	jal	first1pos
	jal	printv0
	li	$a0,1
	jal	first1pos
	jal	printv0
	add	$a0,$0,$0
	jal	first1pos
	jal	printv0
	li	$v0,10
	syscall

first1pos:	# your code goes here
	beqz 	$a0 return1
	li 	$t7, 0x80000000 
	li 	$t2, 31 
	and 	$t1, $a0, $t7 
	beqz 	$t1 loop
	j 	return2

loop:
	srl 	$t7, $t7, 1 
	addi 	$t2, $t2, -1
	and 	$t1, $a0, $t7 
	beqz 	$t1, loop
	j 	return2

return1:
	addi 	$v0, $zero, -1
	jr 	$ra

return2:
	move 	$v0, $t2
	jr 	$ra
	
printv0:
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	add	$a0,$v0,$0
	li	$v0,1
	syscall
	li	$v0,11
	li	$a0,'\n'
	syscall
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	jr	$ra