# PracticaEspacialProgramacionII

## IDEA DE PROYECTO
La idea general del proyecto es inicialmente crear una clase Mision en la cual implementaremos todo lo necesario para cumplir con los requisitos de la práctica.

Hemos utilzado clases "apoyo" llamadas verificarX (donde x es el nombre de lo que queremos verificar). 
Al utilizar los setters llamamos a las clases verificar y si no hay ningún vaor inválido vamos a settear los valores a los atributos.

En la práctica se pedía sobreescribir 1 vez el método registrarEstado(). Pero he decidido sobreescribirlo 1 vez más, añadiendo la posibilidad de ponerle prioridad.

Además hemos sobreescrito el operador<< y el operador++. He decidido que sería una buena idea el operador++ ya que así rápidamente podemos subirle la prioridad, en caso de tener prioridad.

Finalmente, para subir nota utilizaré assets, que SOLO se utilizan en el momento de depurar el programa. Cuando los utilzas el programa no debería llegas hasta el asset si está bien programado. Vamos a poner todo en práctica en el main.

### DÍA 20 DE MAYO
En la siguiente parte de la práctica hemos creado la clase Recursos que será la clase base y otras dos clases derivadas. 
Además hemos creado una clase Mochila<template> que recibirá artilugios. La he creado genérica para poder meter artilugios derivados de la clase artilugio. Entonces la estructura es. Mochila (en la cual metemos artilugios). Artilugio(clase base). Laser(clase derivada de artilugio) y Escudo(clase derivada de artilugio). He utilizado la herencia ya que Artilugio contiene nombre y descripción que es común en todos los artilugios, además de el método usar() que también es común. En la clase Mochila cuando la instanciamos en el main diremos que es de tipo<Artilugio> aunque luego cuando hagamos el addArtilugio. La he diseñado para que añada un template distinto a atilugio, es decir; cualquier clase en este caso que derive de Artilugio. Con esto podemos explicar el buen uso del polimorfismo y de la herencia. Además estamos cumpliendo con las buenas prácticas que entre ellas está el poder expandir nuestro código a partir del que ya tenemos.
