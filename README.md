# Juego de Pájaro Flappy Bird en C++

Este es un simple juego de Flappy Bird implementado en C++ utilizando la consola de Windows. El juego consta de un pájaro que puede saltar para evitar tubos que se mueven hacia él.

## Contenido del Código

### Clases

#### `Bird`

- Representa al pájaro en el juego.
- Tiene métodos para dibujar el pájaro, gestionar la entrada del usuario y obtener la posición del pájaro.

#### `Tubos`

- Representa los tubos que el pájaro debe evitar.
- Contiene métodos para dibujar los tubos, reiniciar su posición y obtener la posición de los tubos.

#### `Juego`

- Gestiona el flujo del juego, incluyendo el puntaje, la detección de colisiones y la finalización del juego.
- También gestiona el registro del puntaje más alto.

#### `Interfaz`

- Controla la interfaz del usuario en la consola, incluyendo la selección de opciones del menú.

### Uso del Juego

1. **Compilación:**
   - Compila el código usando un compilador de C++. Por ejemplo:
     ```bash
     g++ nombre_del_archivo.cpp -o juego.exe
     ```

2. **Ejecución:**
   - Ejecuta el juego:
     ```bash
     ./juego.exe
     ```

3. **Menú Principal:**
   - En el menú principal, puedes seleccionar las siguientes opciones:
     - Jugar: Inicia el juego.
     - Cambiar tecla de salto: Permite al usuario cambiar la tecla de salto del pájaro.
     - Salir: Cierra el programa.
     - Copyright: Muestra información sobre el autor.

4. **Registro del Puntaje:**
   - El juego registra automáticamente el puntaje más alto en el archivo `record.txt`.

## Notas Adicionales

- El juego utiliza la consola de Windows y puede no funcionar correctamente en otros sistemas operativos.
- Ten en cuenta que el juego es una implementación básica y puede haber áreas de mejora.

---

Hecho por [EDGAAR]
