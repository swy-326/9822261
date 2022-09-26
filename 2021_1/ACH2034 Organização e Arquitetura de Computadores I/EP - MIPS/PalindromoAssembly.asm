.text
.globl main
main:
	# Imprime $textoInicial na tela
	la $a0,$textoInicial
	li $v0,4
	syscall
	
	# Recebe uma string do usuário
	la $a0,$buffer
	li $a1,50
	li $v0,8
	syscall
	
	# Remove espaços da string
	jal removerEspacos
	
	# Calcula e guarda o tamanho da string em $a1
	la $t0,($a0)
	li $a1,0
	loopTamanho:
		lb $t2,($t0)
		addiu $t0,$t0,1
		addiu $a1,$a1,1
		bne $t2,'\n',loopTamanho
	subiu $a1,$a1,1		# Retira o byte de newline do contador
	
	ble $a1,2,menorQueDois	# Termina o programa caso a string tenha menos que 3 caracteres
	
	subiu $a1,$a1,1		# Deixa o contador no formato para uso em arrays
	jal checarPalindromo	# Chama a função que checa se a string é palíndromo
	beq $a2,0,false		# Condição do resultado da função
	
	# Caso a string for palíndromo, retorna um texto correspondente e termina o programa
	true:
		la $a0,$textoPalindromo
		li $v0,4
		syscall
		j end
	# Caso a string não for palíndromo, retorna um texto correspondente e termina o programa
	false:
		la $a0,$textoNaoPalindromo
		li $v0,4
		syscall
		j end
	# Caso a string tiver menos que 3 caracteres, retorna um texto correspondente e termina o programa
	menorQueDois:
		la $a0,$textoErro
		li $v0,4
		syscall	
	# Termina o programa
	end:
		li $v0,10
		syscall

# Função que checa se a string guardada em $a0 com seu tamanho em $a1 é palíndromo, retorna 1 caso for ou 0 caso contrário.
checarPalindromo:
	# Início da string
	la $t0,($a0)
	# Fim da string
	la $t1,($a0)
	addu $t1,$t1,$a1
	
	# Loop principal para checar se a string é palíndromo
	loopPalindromo:
		beq $t0,$t1,stringPalindromo
		bgt $t0,$t1,stringPalindromo
		
		lb $t2,($t0)
		lb $t3,($t1)
		
		bne $t2,$t3,stringNaoPalindromo
		
		addiu $t0,$t0,1
		subiu $t1,$t1,1
		
		j loopPalindromo
		
	# Caso a string for palíndromo, guarda 1 (True) em $a2 e retorna
	stringPalindromo:
		li $a2,1
		jr $ra
	
	# Caso a string não for palíndromo, guarda 0 (False) em $a2 e retorna
	stringNaoPalindromo:
		li $a2,0
		jr $ra

# Função que remove os espaços de uma string guardada em $a0
removerEspacos:
	# Guarda o endereço da string em dois registradores, um para percorrer os espaços e o outro para editar a string
	la $t0,($a0)
	la $t2,($t0)
	
	loopEspacos:
		# Percorre pelos espaços com $t2 até chegar no próximo caractere
		condicaoEspaco:
			lb $t1,($t2)
			bne $t1,32,condicaoEspacoFim
			addiu $t2,$t2,1
			j condicaoEspaco
			
		condicaoEspacoFim:
		# Guarda o valor de $t2 em $t0 para todo caractere, assim removendo todos os espaços da string 
		lb $t1,($t2)
		sb $t1,($t0)
		
		addiu $t2,$t2,1
		addiu $t0,$t0,1
		
		lb $t1,($t2)
		bne $t1,0,loopEspacos
	
	# Adiciona o caractere null que pode faltar e retorna
	lb $t1,($t2)
	sb $t1,($t0)
	jr $ra
			  	  	  	  
.data
$textoInicial: .asciiz "Digite a string: "
$textoErro: .asciiz "Uma string deve ter no mínimo 3 caracteres para ser um palíndromo."
$textoPalindromo: .asciiz "A string inserida é palindromo"
$textoNaoPalindromo: .asciiz "A string inserida não é palindromo"
$buffer: .space 50
