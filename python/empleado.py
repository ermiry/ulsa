import string
import random
from datetime import datetime, date

class Empleado:
	def __init__(self, nombre, apellido_paterno, apellido_materno):
		self.nombre = nombre
		self.apellido_paterno = apellido_paterno
		self.apellido_materno = apellido_materno
		self.fecha = None
		self.RFC = None

	def fecha_nacimiento(self, dia, mes, anio):
		self.fecha = Fecha(dia, mes, anio)

	def formar_RFC(self):
		self.RFC = RFC(self.nombre, self.apellido_paterno, self.apellido_materno, self.fecha)
		self.RFC.formar_RFC()

	def edad(self):
		today = date.today()
		birth = datetime(self.fecha.anio, self.fecha.mes, self.fecha.dia)
		return today.year - birth.year - ((today.month, today.day) < (birth.month, birth.day))

	def __str__(self):
		return f'Empleado: {self.nombre} {self.apellido_paterno} {self.apellido_materno}'

class Fecha:
	def __init__(self, dia, mes, anio):
		self.dia= dia
		self.mes = mes
		self.anio = anio

	def validar_fecha(self, dia, mes, anio):
		pass

	def fecha_string(self):
		if self.dia < 10:
			fecha_str = "0" + str(self.dia)
		else:
			fecha_str = str(self.dia)
		if self.mes < 10:
			fecha_str += "/0" + str(self.mes)
		else:
			fecha_str += "/" + str(self.mes)
		a = self.anio % 100
		fecha_str += "/" + str(a)
		return fecha_str

class RFC:
	def __init__(self, nombre, apellido_paterno, apellido_materno, fecha):
		self.nombre = nombre
		self.apellido_paterno = apellido_paterno
		self.apellido_materno = apellido_materno
		self.fecha = fecha
		self.value = None

	def formar_RFC(self):
		ini_last_name = self.apellido_paterno[0:1]
		last_name_vowel = search_vowel(self.apellido_paterno).upper()
		ini_mothlast_name = self.apellido_materno[0:1]
		ini_first_name = self.nombre[0:1]

		self.value = '%s%s%s%s%d%d%d%s' % (
			ini_last_name, 
			last_name_vowel, 
			ini_mothlast_name, 
			ini_first_name,
			self.fecha.anio,
			self.fecha.mes,
			self.fecha.dia,
			get_random_string (3)
		)

	def __str__(self):
		return f'RFC: {self.value}'


def get_vocal(v):
	for i in ('a', 'e', 'i', 'o', 'u'):
		if i == v:
			return True
			break
	return False

def search_vowel(last_name):
	size = len(last_name) - 1
	last_name = last_name[1:size]
	vocal = ''

	for v in last_name:
		if get_vocal(v):
			vocal = v
			break
	return vocal

def get_random_string(length):
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str.upper()

def registrar():
	nombre = input ("Nombre(s): ")
	paterno = input ("Apellido paterno: ")
	materno = input ("Apellido materno: ")

	empleado = Empleado(nombre, paterno, materno)
	print(empleado)

	fecha_str = input ("Fecha de nacimiento (dd/mm/yy): ")
	fecha = datetime.strptime (fecha_str, '%d/%m/%y')

	empleado.fecha_nacimiento(fecha.day, fecha.month, fecha.year)

	print ("Edad: " + str(empleado.edad()))

	empleado.formar_RFC ()
	print (empleado.RFC)

	return empleado

def main():
	todos = []

	option = 0
	while option != 3:
		print ("******************************************************************")
		print ("Registro de empleados")
		print ("1. Desplegar empleados")
		print ("2. Registrar")
		print ("3. Salir")
		option = int (input ("Opcion: "))

		if (option == 1):
			if not todos:
				print("\n")
				print("No hay empleados!")
				print("\n")
			for x in todos:
				print(x)
				print(x.RFC)			
				print("\n")
		elif (option == 2):
			todos.append(registrar ())

if __name__ =='__main__':
	main()
