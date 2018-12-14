.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!\n"
str1: .asciiz "Please enter the price of a BobCat Bar:\n"
str2: .asciiz "Please enter the number of wrappers needed to exchange for a new bar:\n"
str3: .asciiz "How much do you have?\n"
str4: .asciiz "Good! Let me run the numbers...\n"
str5: .asciiz "First you buy "
str6: .asciiz " bars.\n"
str7: .asciiz "Then, you will get another "
str8: .asciiz " bars.\n"
str9: .asciiz "With $"
str10: .asciiz ", you will receive a maximum of "
str11: .asciiz " BobCat Bars!\n"


.text

main:
		#This is the main program.
		#It first asks user to enter the price of each BobCat Bar.
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		#It then asks user to enter how much money he/she has.
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		addi $sp, $sp -12	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here
		li $v0, 4
		la $a0, str0
		syscall

		li $v0, 4
		la $a0, str1
		syscall

		li $v0, 5
		syscall
		move $a1, $v0

		li $v0, 4
		la $a0, str2
		syscall
		
		li $v0, 5
		syscall
		move $t0, $v0

		li $v0, 4
		la $a0, str3
		syscall

		li $v0, 5
		syscall
		move $a2, $v0
		
		li $v0, 4
		la $a0, str4
		syscall
		
		move $a0, $t0

		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars
		move $t0, $v0
		
		# Print out final statement here
		li $v0, 4
		la $a0, str9
		syscall
		
		li $v0, 1
		move $a0, $a2
		syscall
		
		li $v0, 4
		la $a0, str10
		syscall
		
		li $v0, 1
		move $a0, $t0
		syscall
		
		li $v0, 4
		la $a0, str11
		syscall

		j end			# Jump to end of program

maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars
		sw $ra, 4($sp)
		
		move $s0, $a0
		move $s1, $a1
		move $s2, $a2
		
		addu $v0, $zero, $zero
		blt $a2, $a1, returnMax 

		divu $v0, $a2, $a1
		
		move $s3, $v0
		li $v0, 4
		la $a0, str5
		syscall
			
		li $v0, 1
		move $a0, $s3
		syscall
		
		li $v0, 4
		la $a0, str6
		syscall

		move $a0, $s3
		move $a1, $s0
		jal newBars 	# Call a helper function to keep track of the number of bars.
		
		addu $s3, $s3, $v0
		move $v0, $s3
		
returnMax:	lw $ra, 4($sp)
		jr $ra
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of bars so far and n.
		sw $ra, 8($sp)
		
		move $s4, $a0
		move $s5, $a1

		addu $v0, $zero, $zero
		blt $a0, $a1, returnNew
		
		divu $v0, $a0, $a1
		
		add $s6, $s6, $v0
		move $t0, $v0
		li $v0, 4
		la $a0, str7
		syscall
			
		li $v0, 1
		move $a0, $t0
		syscall
		
		li $v0, 4
		la $a0, str8
		syscall
		
		move $v0, $t0
		addu $t1, $s4, $zero
		mul $t2, $v0, $a1
		subu $t1, $t1, $t2
		addu $v0, $v0, $t1
		
		move $a0, $v0
		
		j newBars
		
returnNew: 	move $v0 $s6
		jr $ra
		# End of newBars

end: 
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp 4
		li $v0, 10 
		syscall
