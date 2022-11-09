# C++ - Listas en seudocódigo
Hace ya bastante tiempo que uso seudocódigo en español para la enseñanza de Programación.
Es un recurso valioso como meta lenguaje (un lenguaje más abstracto y simple anterior al lenguaje propiamente dicho).
Las directivas de preprocesador C/C++ han sido de gran ayuda y permiten el uso de cualquier entorno de desarrollo C/C++. Sin embargo hemos preferido ZinjaI del profesor Pablo Novara, de la Universidad Nacional del Litoral. Pruébese y quedará claro por qué lo elegí como entorno de desarrollo (IDE).
Las directivas fueron diseñadas para GNU Linux y actualmente hay una directiva comentada //#define WINDOWS que descomentada las hace servir para cualquier W.
Dos contras - entre muchas virtudes - de usar C/C++ como el motor bajo el capot son el manejo bastante flojo de las cadenas y la ausencia de listas genéricas como las de Lisp/Logo. Ambas se han vuelto mucho más amigables con el tiempo.
La implementación de las listas genéricas se basa en una union que tiene casi todo lo que podemos necesitar incorporado a un TAD (Tipo Abstracto de Datos) jocosamente denominado Algo. Puede contener números enteros y de punto flotante, textos de un solo caracter y cadenas de hasta 64 caracteres, así como un campo de bits que se encarga - por ejemplo - de copiar un valor prescindiendo de los detalles de su almacenamiento. También puede tener un puntero a una sublista que puede contener... ¡lo mismo! Fue de gran utilidad el uso de una union de punteros (tóquese con cuidado).
Las listas fueron basadas en contenedores vector y básicamente una Lista es un vector de Algo. Se ha mantenido el operador [] para acceder a un elemento usando el acceso directo (todos los valores de la unión ocupan el mismo espacio en memoria y son fácilmente direccionables). Esto sin dejar de tener la flexibilidad de tener cualquier valor de cualquier tipo y la velocidad del acceso directo. Dicho esto, la responsabilidad de averiguar de qué tipo es un valor almacenado y el uso de múltiples índices en referencias subindicadas corre por cuenta del desarrollador ayudado por 2  herramientas: 1) un enumerado de tipo de datos que se establece al crear la variable mediante el constructor adecuado o redefiniendo el operador de asignación. 2) una función que regresa el tipo de datos del elemento del vector<Algo> encuestado.
Esto posibilita el diseño orientado por los datos, que es un paradigma que vincula el diseño descendente de una lista de estructura homogénea (o no) definida en tiempo de ejecución con el código que lo implementa.
Se piensa incluir numerosos ejemplos de uso, empezando por un minisistema académico cuyo desarrollo paso a paso es explicado y analizado al detalle.
