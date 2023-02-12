# RegistrosDeLibros
Sistema de registro de revistas y libros con detalles de año, código y título en C+

El sistema de registro de revistas y libros es un programa que permite registrar las publicaciones en una base de datos virtual, con el objetivo de llevar un registro organizado y eficiente. El programa cuenta con una clase base llamada Publicaciones que es una clase virtual que recibe el código, el título y el año de publicación, y cuenta con métodos para establecer y obtener los datos correspondientes.

Además, existen dos clases hijas, una llamada Libro y otra llamada Revista. La clase Libro recibe en su constructor el código, el título y un booleano que indica el estado de préstamo. Además, cuenta con métodos para establecer y obtener el estado de préstamo, así como para establecer y obtener el tipo de publicación.

La clase Revista recibe en su constructor el código, el título, el año de publicación y el número de la revista, y cuenta con un método para obtener el tipo de publicación.

El programa cuenta con cinco opciones disponibles:

Registro de publicaciones: Permite registrar una publicación en el sistema, pidiendo si se trata de una revista o un libro, el código, el título y el año de publicación.

Mostrar publicaciones: Muestra las publicaciones registradas en el sistema.

Prestamo de libro: Permite hacer un préstamo de un libro con su ID, y si se busca una revista el programa indica que no se pudo hacer el préstamo.

Devolución de libro: Permite devolver un libro con su ID.

Salir: Salir del programa.

El sistema de registro de revistas y libros es una herramienta útil para mantener un registro organizado y eficiente de las publicaciones, y para facilitar el préstamo y devolución de libros.
