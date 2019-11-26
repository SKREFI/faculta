.data
	readBuf: .word 0
	argBuf: .word 0
	
	N: .byte '\n'
	A: .byte 'A'
	p: .word 0
	g: .word 0
	normalTxt: .space 64
	criptTxt: .space 64
	vectorCriptare: .space 256
	vectorDecriptare: .space 256
	
	newl: .asciiz "\n"
	space: .asciiz " "
	notPrimeMsg: .asciiz "Nr. p nu este prim"
	lessThanTwoMsg: .asciiz "Nr. p este invalid"
	exitMessage: .asciiz "SKREFI's out :D (ignora nickul =)"
	isPrimeMsg: .asciiz "Este prim /debug /delete"
	DEBUG: .asciiz "DEBUG"
.text
	
main:
	jal readInt		# aple functie citire int
	lw $t0, readBuf		# il trag din memorie (unde a fost urcat in functia de citire)
	sw $t0, p		# salvez in p (.data)
	sw $t0, argBuf		# de asemenea urc in argument Buffer pentru ulteriorul apel al functiei isPrime
	jal isPrime		# exit if not prime / continue if it is
	jal smallestGenerator	# saves the smallest generator to g (.data)
	jal genVectorCriptat 	# generate the vector using g and store in vectorCriptare
	jal readNormalText	# read normalTxt
	jal readCriptedText	# read criptTxt
	jal cript		# cripteaza textul normal
	jal genVectorDecriptat  # salvat in vectorDecriptare
	jal decript		# decripteaza textul citit
	
	j stopProgram 		# end_main ^_^

cript:
	la $s0, normalTxt
	criptWhile:
		lb $s1, 0($s0)			# incarca in s1 byte cu index s0
		lb $t4, N			# incarca in t4 caracterul \n
		beq $s1, $t4, encryptEnd	# inchide cand s1 = \n
		li $t1, 0			
		lb $t4, A			# initializare cu A pentru numarare pana ajunge la X litera citita
		
		whileNotEqual:			# numara al cate-lea element este litera pe care se lucreaza
			beq $t4, $s1, t1Found	# in caz de C t1 devine 4
			addi $t1, $t1, 1	#
			addi $t4, $t4, 1	#
   			j whileNotEqual		#
   		t1Found:
   		
   		li $t4, 4			#
   		mult $t1, $t4			#
   		mflo $t1 			### t2 = vC[t1]
   		lw $t2, vectorCriptare($t1)	#
   		divu $t1, $t1, 4		#
   		
   		li $t3, 0			### explicit pentru fiecare
   		blt $t1, $t2, imvi		#   caci aveam probleme si
   		bgt $t1, $t2, iMvi		#   voiam sa fiu sigur ca aici
   		beq $t1, $t2, ievi		#   nu sunt :)
   		ievi:				# i == v[i]
   			li $v0, 11
   			move $a0, $s1
   			syscall
   			j doneMEM
   		iMvi:				# i > v[i]  			
   			subu $t3, $t1, $t2
   			subu $s1, $s1, $t3
   			
  			li $v0, 11		### print char
   			move $a0, $s1		#
   			syscall			#
   			j doneMEM		#
   		imvi:				# i < v[i]
   			subu $t3, $t2, $t1	# v[i] - i
   			addu $s1, $s1, $t3	# a0 += v[i] - i
   			
   			li $v0, 11		### print char
   			move $a0, $s1		#
   			syscall			#
   			j doneMEM	
   		doneMEM:	
   			#addu $t1, $t1, 1		# i++
   			addi $s0, $s0, 1		# increment adress
   			j criptWhile
   		
	encryptEnd:
	li $v0, 4
	la $a0, newl
	syscall
	jr $ra
	
genVectorDecriptat:
	li $t1, 0				# merge din 4 in 4
	li $t2, 0				# merge din 1 in 1
	decriptVectorWhile:
		lw $a0, vectorCriptare($t1)	# a0 = vc[t1]
		beqz $a0, decriptVectorWhileDone# a iesit cand a intalnit 0 (care se afla la final mereu)
		
		li $t4, 4			### a0 *= 4
		mult $a0, $t4			#
		mflo $a0			#
		addi $a0, $a0, -4 		# pentru a stora 0 2 1 4 5 3 in loc de 0 0 2 1 5 4 3
		
		sw $t2, vectorDecriptare($a0)
				
		addi $t2, $t2, 1		
		addi $t1, $t1, 4		
		j decriptVectorWhile
	decriptVectorWhileDone:
	
	lw $s0, p
	addi $s0, $s0, -1	# shift la stanga, trebuie sa fac asta, ref: linia 52
	li $t4, 4		### p *= 4
	mult $s0, $t4		#
	mflo $s0		#
	li $t1, 0		# contor i
	test_:
		lw $a0, vectorDecriptare($t1)
		bge $t1, $s0, testDone
		
		addi $t1, $t1, 4
		j test_
	testDone:
	jr $ra

decript:
	li $t8, 0
	la $s0, criptTxt
	deWhile:
		lb $s1, 0($s0)
		lb $t4, N
		addi $s1, $s1, 1
		beq $s1, $t4, decriptingDone
		
		li $t1, 0
		lb $t4, A
		
		whileIndexNotFound:		#t1 = indexul literei
			beq $t4, $s1, indexFound
			addi $t1, $t1, 1
			addi $t4, $t4, 1
			j whileIndexNotFound
		indexFound:
		
		li $t4, 4			#
   		mult $t1, $t4			#
   		mflo $t1 			### t2 = vD[t1]
   		lw $t2, vectorDecriptare($t1)	#
   		divu $t1, $t1, 4		#
		
		#addi $t1, $t1, -1
		
		blt $t1, $t2, diMvi		#   caci aveam probleme si
   		bgt $t1, $t2, dimvi		#   voiam sa fiu sigur ca aici
   			j ddoneMEM
   		diMvi:				# i > v[i]  			
   			subu $t3, $t1, $t2
   			subu $s1, $s1, $t3
   			j ddoneMEM		#
   		dimvi:				# i < v[i]
   			subu $t3, $t2, $t1	# v[i] - i
   			addu $s1, $s1, $t3	# a0 += v[i] - i
   			j ddoneMEM	
		ddoneMEM:
		li $v0, 11
   		move $a0, $t4
   		syscall
   		
   		# Printez t4, ar trebui s1 in care storez valoare lui in functie
   		# de contor i (t1) dar care-mi da output la altceva, am incercat
   		# de o gramada de chestii, mult prea multe ore, am depus deja prea multe ore
   		# la acest proiect si m-am saturat :)) asa ca o sa ma multumesc cu nota primita pe ce am facut. Multumesc.
   		# Pentru un anumit se mai si blocheaza in acest loop si nu-mi mai ajunge la exitMsg... idk why	
		addi $s0, $s0, 1
		j deWhile
	decriptingDone:
	jr $ra

readCriptedText:
	li $v0, 8
    	la $a0, criptTxt 
    	li $a1, 50   
    	syscall
    	jr $ra

readNormalText:
	li $v0, 8       	# take in input
    	la $a0, normalTxt  	# a0 = string u want to store in
    	li $a1, 50      	# a1 = size
    	syscall
    	jr $ra
	
genVectorCriptat:
	li $s7, 0
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
