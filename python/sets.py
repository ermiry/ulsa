def crear_set(name):
	print ('Cuantos elementos quieres en el', name, 'conjunto? ')
	n = int (input ())
	A = set ()
	for i in range(0, n):
		value = input ("Elemento " + str(i) + ": ")
		A.add (int (value))

	return A

def single(A):
	option = 0
	while option != 4:
		print ("******************************************************************")
		print ("Operaciones sobre el conjunto: ")
		print (A)
		print ("1. Anadir elemento")
		print ("2. Eliminar elemento")
		print ("3. Buscar elemento")
		print ("4. Regresar")
		option = int (input ("Opcion: "))

		if (option == 1):
			A.add (int (input ("Agregar: ")))
		elif (option == 2):
			A.remove (int (input ("Remover: ")))
		elif (option == 3):
			if int (input ("Remover: ")) in A:
				print ("Se encontro el elemento!")
			else:
				print ("El elemento NO fue encontrado!")

def multiple(A, B):
	option = 0
	while option != 5:
		print ("******************************************************************")
		print ("Operaciones sobre dos Conjuntos:")
		print ("Conjunto A")
		print (A)
		print ("Conjunto B")
		print (B)
		print ("1. Cambio de Elementos de los conjuntos")
		print ("2. Intersectar")
		print ("3. Unir")
		print ("4. Restar")
		print ("5. Regresar")
		option = int (input ("Opcion: "))

		if (option == 1):
			C = A
			A = B
			B = C
		elif (option == 2):
			print (A.intersection (B))
		elif (option == 3):
			print (A | B)
		elif (option == 4):
			print ("A - B")
			print (A - B)
			print ("B - A")
			print (B - A)


option = 0
while option != 3:
	print ("******** Sets ********")
	print ("1. Operaciones con un solo conjunto")
	print ("2. Operaciones con dos conjuntos")
	print ("3. Salir")
	option = int (input ("Opcion: "))

	if (option == 1):
		A = crear_set("primer")
		single (A)

	elif (option == 2):
		A = crear_set("primer")
		B = crear_set("segundo")
		multiple (A, B)
