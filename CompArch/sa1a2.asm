.data
    string: .space 20
    request: .asciiz "String:"

.text 
    main:
        la $a0, request #Ouput request
        li $v0, 4
        syscall

        li $v0, 10 #τέλος προγράμματος
        syscall
        
