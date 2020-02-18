.data
	space: .asciiz " "
	newl: .asciiz "\n"
	list: .space 1024
	n: .word 0
	i: .word -4
	j: .word -4
	ts: .asciiz "Those are t0, t1, t8, t9: "
.text
	#Read n
	li $v0, 5
	syscall
	sw $v0, n
	#done
	
	#initializare loop
	addi $t0, $0, 0 #t0 = i = 0
	addi $t9, $v0, 0 #t9 = n / 4
	mul $t9, $t9, 4 #t9 = n
	addi $t9, $t9, -4 #t9 = n - 1
	#read array loop
	readList: bgt $t0, $t9, readListDone
		#read value
		li $v0, 5
		syscall
		#store value in list(i)
		sw $v0, list($t0)
		addi $t0, $t0, 4
		j readList
	readListDone:
	sw $t9, n
	#sorting
	lw $t0, i
	lw $t8, j
	lw $t1, n
	sub $t1, $t1, 4
	lw $t9, n
	sub $t9, $t9, 4
	######################################################
	iLoop:
		lw $t0, i
		addi $t0, $t0, 4
		sw $t0, i
		bgt $t0, $t1, iLoopDone
	
		addi $t8, $0, -4
		sw $t8, j
		
		jLoop:
			lw $t8, j
			addi $t8, $t8, 4
			sw $t8, j
			
			bgt $t8, $t9, jLoopDone
			### $t0 for i ### $t8 for j ###
			#############
			# t2 - t7 free
			
			addi $t2, $t8, 0 #t2 = j
			lw $t3, list($t2) #t3 = list(j)
			addi $t2, $t2, 4 #t2 = j + 1
			lw $t4, list($t2) #t4 = list(j+1)
			
			bgt $t3, $t4, swap
				j jLoop
			swap:
			sw $t3, list($t2)
			addi $t2, $t2, -4
			sw $t4, list($t2)
			
			
			#############
			#li $v0, 1
			#addi $a0, $t0, 0
			#syscall
			#addi $a0, $t8, 0
			#syscall
			#jal printSpace
			j jLoop
			jLoopDone:
			#jal printNewl
		j iLoop
	iLoopDone:
	######################################################
	#initializare loop
	addi $t0, $0, 0
	addi $t9, $t9, 4
	#print array loop
	printList: bgt $t0, $t9, printListDone
		li $v0, 1
		lw $a0, list($t0)
		syscall
		jal printSpace
		addi $t0, $t0, 4
		j printList
	printListDone:
	
exit:
li $v0, 10
syscall

	printSpace:
		li $v0, 4
		la $a0, space
		syscall
		
		jr $ra
	
	printNewl:
		li $v0, 4
		la $a0, newl
		syscall
		
		jr $ra
		
	printTs:
		li $v0, 4
		la $a0, ts
		syscall
		li $v0, 1
		addi $a0, $t0, 0
		syscall
		li $v0, 4
		la $a0, space
		syscall
		li $v0, 1
		addi $a0, $t1, 0
		syscall
		li $v0, 4
		la $a0, space
		syscall
		li $v0, 1
		addi $a0, $t8, 0
		syscall
		li $v0, 4
		la $a0, space
		syscall
		li $v0, 1
		addi $a0, $t9, 0
		syscall
		li $v0, 4
		la $a0, newl
		syscall
		
		jr $ra
