.data
	readBuf: .word 0
	argBuf: .word 0
	
	p: .word 0
	g: .word 0
	normalTxt: .space 50
	criptTxt: .space 50
	vectorCriptare: .space 256 
	
	newl: .asciiz "\n"
	space: .asciiz " "
	notPrimeMsg: .asciiz "Nr. p nu este prim"
	lessThanTwoMsg: .asciiz "Nr. p este invalid"
	exitMessage: .asciiz "SKREFI's out :D (ignora nickul =)"
	isPrimeMsg: .asciiz "Este prim /debug /delete"
.text
	
main:
	jal readInt		# aple functie citire int
	lw $t0, readBuf		# il trag din memorie (unde a fost urcat in functia de citire)
	sw $t0, p		# salvez in p (.data)
	sw $t0, argBuf		# de asemenea urc in argument Buffer pentru ulteriorul apel al functiei isPrime
	jal isPrime		# exit if not prime / continue if it is
	jal smallestGenerator	# saves the smallest generator to g (.data)
	jal genVectorCriptat
	jal readNormalText	# read normalTxt
	#jal readCriptedText	# read criptTxt
	jal playGround
	
	j stopProgram 		# end_main ^_^

playGround:
	la $a0, normalTxt
	lw $t1, 0($a0)
	move $t1, $a0
	li $v0, 11
	syscall
	jr $ra

readCriptedText:
	li $v0, 8
    	la $a0, criptTxt 
    	li $a1, 50   
    	syscall
    	jr $ra

readNormalText:
	li $v0, 8       # take in input
    	la $a0, normalTxt  # a0 = string u want to store in
    	li $a1, 50      # a1 = size
    	syscall
    	jr $ra
	
genVectorCriptat:
	lw $s0, p		# s0 = p
	lw $s1, g		# s1 = g
	move $t0, $s1		# last = g
	li $t1, 0		# contor i
	
	# pun prima data pe 1 la inceput
	li $t2, 1
	sw $t2, vectorCriptare($t1)
	addi $t1, $t1, 4	
	
	genWhile:
		beq $t0, 1, doneGenerating	
		
		sw $t0, vectorCriptare($t1)	# vectorCriptare(i) = last
		addi $t1, $t1, 4		# i ++
		multu $t0, $s1			# last * g
		mflo $t0			# last = last * g
		div $t0, $s0			# last / p
		mfhi $t0			# last = last % p
		
		j genWhile
	doneGenerating:
	jr $ra
	
smallestGenerator:
	lw $t4, p 		# t0 = p
	addi $t0, $t4, -1	# forul merge pana la p - 1
	li $t1, 2		# i = 2 care este cel mai mic generator posibil
	li $t2, 1		# counter = t2 = 1
				# last = t3 = numarul generat anteroir (la inceput = i in sine)
	genForLoop:
		bgt $t1, $t0, generatorFound 		# generatorul se gaseste pana sa ajung aici oricum
		li $t2, 1 				# counter
		addi $t3, $t1, 0			# last
		genForWhile:				
			beq $t3, 1, genForWhileDone	# while 1 != last
			addi $t2, $t2, 1		# counter ++
			multu $t3, $t1			# last * i
			mflo $t3			# last = last * i
			div $t3, $t4			# last / p
			mfhi $t3			# last = last % p
			j genForWhile			# back to while
		 genForWhileDone:
		 beq $t2, $t0, generatorFound		# if generator is found (counter == p - 1) (t2 == t0)
		 addi $t1, $t1, 1
		 j genForLoop 				# goes back to for
		 generatorFound: 			# g = 1 and goto main
		 	sw $t1, g
		 	jr $ra
		 		
isPrime:
	lw $t0, argBuf		# t0 = p
	li $t1, 2		# t1 = 2
	addi $t2, $t0, 0	# t2 = p
	divu $t2, $t2, 2 	# t2 = t2 / 2
	
	blt $t0, $t1, pNotPrime # daca t0 < 2 return direct 
	
	isPrimeLoop:
		bge $t1, $t2, pIsPrime 		# if t1 > t2 breaks to pIsPrime
		
		div $t0, $t1			# t0 / t1
		mfhi $t3			# t3 = hi
		beqz $t3, pNotPrime 		# daca reminderul == 0 goto pNotPrime
		
		addi $t1, $t1, 1		# t1++
		j isPrimeLoop
		
	lessThanTwo:
		li $v0, 4
		la $a0, lessThanTwoMsg
		syscall
		la $a0, newl
		syscall
		j stopProgram
	pIsPrime:
		jr $ra 		# if good jump back to main
	pNotPrime:
		li $v0, 4
		la $a0, notPrimeMsg
		syscall
		la $a0, newl
		syscall
		j stopProgram 	# daca nu este prim inchide direct

# Utility functions :)
stopProgram:
	li $v0, 4      		# load 4 to print string
	la $a0, newl
	syscall		
	la $a0, exitMessage	# print good bye message
	syscall
	li $v0, 10		# exit
	syscall
readInt:			
	li $v0, 5
	syscall
	sw $v0, readBuf		
	jr $ra
printInt:
	li $v0, 4
	la $a0, newl
	syscall
	li $v0, 1
	lw $a0, argBuf 
	syscall
	jr $ra
