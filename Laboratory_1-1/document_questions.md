## Preguntas

**1. ¿Cuál es la ruta absoluta de home?**
Ruta absoluta:_ `/home`

**2. ¿Cuál es la ruta de home relativa a work?**
Ruta relativa: `../../`

**3. Si estoy ubicado en el directorio home, ¿Cuál es la ruta absoluta y relativa para ubicarse en photos?**
Ruta absoluta: `/home/jono/photos`
Ruta relativa: `./jono/photos`

**4. Si estoy ubicado en el directorio jono, ¿Cuál es la ruta absoluta y relativa para ubicarse en photos?**
Ruta absoluta: `/home/jono/photos`
Ruta relativa: `./photos`

**5. Si estoy ubicado en el directorio jono, ¿Cuál es la ruta absoluta y relativa para ubicarse en lib?**
Ruta absoluta: `/usr/lib`
Ruta relativa: `../../usr/lib`

_Para las siguientes preguntas asuma que se encuentra ubicado en la ruta /home_

**6. ¿Cuáles son los comandos para ir y crear el directorio Italy dentro de photos?**
`cd ./jono/photos`
`mkdir Italy`

**7. ¿Cuál es el comando para crear el directorio Spain dentro de photos permaneciendo en home?**
`mkdir ./jono/photos/Spain`

**8. ¿Cuál es el comando (o secuencia de comandos) para crear 2 directorios llamados dir1 y dir2 dentro de work?**
Opción 1:
`mkdir ./jono/work/dir1 ./jono/work/dir2`
Opción 2:
`mkdir ./jono/work/dir1`
`mkdir ./jono/work/dir2`
Opción 3:
`cd ./jono/work`
`mkdir dir1`
`mkdir dir2`

**9 ¿Como se elimina el directorio dir1 asumiendo que este no esta vacio?**
`rm -r /jono/work/dir1`

**10. ¿Cuál es el comando (o conjunto de comandos ) para listar el contenido del directorio jono con sus propiedades y archivos ocultos?**
`ls -la ./jono`
