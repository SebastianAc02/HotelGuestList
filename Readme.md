
### Requisitos del sistema
El programa requiere un compilador de C++ 11 minimo para poder ser compilado y ejecutado. Se recomienda utilizar una versión actualizada del compilador para evitar posibles errores de compilación. Se esta usando C++ 14.

### Cómo compilar el programa
Para compilar el programa, abre la terminal en el directorio del proyecto y ejecuta los siguientes comandos:

# Por favor revisar cuando se construya un objeto main 
Pasarle el path hacia el file txt desde el archivo GuestRecords.cpp.h para poder asignar 1: en la variable estatica FILEPATH donde se esta almacenando el archivo HotelGuestList.txt. Para esto podemos ir a console, buscar la carpeta y usar el comando "realpath (HotelGuestList.txt)"
Realpath debe ser el realpath del archivo HotelGuestList.txt . Tambien cambiar el path en la funcion replace y asignale el mismo path del primer archivo, cambiando su nombre. 

g++ main.cpp Guest.cpp -o hotel-management-guest-list
Este comando compilará el programa y generará un archivo ejecutable llamado "hotel-management-guest-list".

###Cómo utilizar el programa
Una vez que el programa está compilado, puedes ejecutarlo en la terminal usando el siguiente comando:

bash
Copy code
./hotel-management-guest-list
El programa mostrará un menú de opciones que te permitirán agregar, eliminar, buscar y mostrar invitados en la lista.

## Contribuciones
Este proyecto es de código abierto y las contribuciones son bienvenidas. Si deseas contribuir, por favor haz un fork del repositorio, realiza tus cambios y envía un pull request.

## Licencia
Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más información.

## Contacto
Si tienes alguna pregunta o sugerencia, por favor envía un correo electrónico a sacostamolina@outlook.com
