.data
	saveRa: .space 4
	
	list: .space 1024
	n: .word 0			# lungimea vectorului citit
	sumFun: .word 0		# variabila in care adun 1^2, 2^2, 3^2 etc.
	
	readBuf: .word 0	# readInt "returneaza' in readBuf
	argBuf: .word 0		# "argumentul" pentru functia print int si altele
	
	exitMessage: .asciiz "Craciun Fericit! :D\n" # mai bine decat sa vad "Singur Acasa" a 10-a oara   <<<<-----------------------------------------------------------
	newl: .asciiz "\n"
	space: .asciiz " "
	debug: .asciiz "DEBUG\n"
.text
main:
	################### numele cred ca sunt destul de self explanatory
	jal readInt	    #
	lw $t0, readBuf ### aici decat nut din readBuf in n (functia de citire salveaza valoare in raedBuf)
	sw $t0, n 	    #
	jal readListF   #
	jal modifica    #
	jal printListF  #
	j stopProgram   #
	#################
modifica:
	li $t5, 0
	lw $t9, n
	mul $t9, $t9, 4
	addi $t9, $t9, -4
	modifyVector: bgt $t5, $t9, modifyVectorDone
		addi $sp, $sp, -4
			sw $ra, 0($sp)		# save $ra
			lw $s0, list($t5)	# s0 = numar din vector
			sw $zero, sumFun	# sumFun = 0
			jal suma_patrate	# calculeaza suma patrate
			lw $s0, sumFun		# suma_patrate pune valoare calculata un sumFun (inainte sa vad ca trebuie denumita suma_patrate functia era numita function :D)
			sw $s0, list($t5)	# storeaza inapoi suma calculata
			lw $ra, 0($sp)		# restore $ra
		addi $t5, $t5, 4
		j modifyVector
	modifyVectorDone:
	jr $ra
	
printListF:
	li $t0, 0
	lw $t9, n
	mul $t9, $t9, 4
	addi $t9, $t9, -4
	printList: bgt $t0, $t9, printListDone
		li $v0, 1
		lw $a0, list($t0)
		syscall			
			li $v0, 4		### print space
			la $a0, space	#
			syscall			#
		addi $t0, $t0, 4
		j printList
	printListDone:
	jr $ra

readListF:
	li $t0, 0		# t0 = i = 0
	move $t9, $v0	# t9 = n
	mul $t9, $t9, 4
	addi $t9, $t9, -4
	
	readList: bgt $t0, $t9, readListDone
		li $v0, 5
		syscall
		sw $v0, list($t0)
		addi $t0, $t0, 4
		j readList
		readListDone:
	jr $ra	
	
# Nota: ca asta sa suma_patrateeaze, argumentul trebuie pasat in a0 si sumFun trebuie sa aiba in ram valoarea 0
suma_patrate:						# functia recursiva pentru calcularea fiecarui element
	addi $s0, $s0, -1			# parametru -= 1
	ble $s0, 0, smallerThanOne  
	beq $s0, 1, eqTwo	# daca parametru <= 1
		# else
		lw $t0, sumFun			# load din memorie	
		mult $s0, $s0			# ^2
		mflo $t1			
		add $t0, $t0, $t1		# se adauga patratul numarului
		sw $t0, sumFun			# se urca inapoi in memorie
		j suma_patrate			# apleul recursiv catre functie
	eqTwo:						# cand ajunge la 2 se returneaza unu si atat
		lw $t0, sumFun			
		addi $t0, $t0, 1		
		sw $t0, sumFun
		jr $ra
	smallerThanOne:
		jr $ra					# return direct nu mai face nimic pentru orice mai mic sau egal decat unu
	
	
# Utility functions :))
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
