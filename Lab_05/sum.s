        .data 
n:      .word 7


        .text
main:   
	lw      $t0, 0($s0)
sum: 	beq     $t3, $0, finish
	add     $t2,$t1,$t0
	move    $t0, $t1
	move    $t1, $t2
	subi    $t3, $t3, 1
	j       sum
finish: addi    $a0, $t0, 0
	li      $v0, 1
	syscall			
	li      $v0, 10		
	syscall			