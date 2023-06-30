# Guia para o Usuário

### Versão utilizada
- Esse código foi feito usando o java-20-openjdk e o maven.
- Código testado no sistema operacional Linux

### Rodando o projeto pré-compilado 
- Para isso, é necessário rodar o arquivo jar disponível no diretório raíz do projeto.
- Para rodar corretamente, é necessário usar o seguinte comando: 
    `java -cp BibliotecaUnesp-1.0-RELEASE.jar:lib/sqlite-jdbc-3.41.2.1.jar com.example.biblioteca.display.Main`
- Isso é necessário para incluir o driver do JDBC no classpath e não ocorrer o erro na execução.
- OBS: Caso seja conveniente, estou disponibilizando um shell script para Linux (e possívelmente MacOS) que realiza
  a compilação e execução automática do programa.

### Compilando e rodando o projeto por conta própria
- Para compilar o projeto é necessário seguir os seguintes passos:
  1. `mvn package clean` (para limpar o projeto compilado anteriormente)
  2. `mvn package install` (para recompilar o projeto com o maven)
  3. `mv target/BibliotecaUnesp-1.0-RELEASE.jar .` (para mover o jar para o diretório raíz do projeto)
  4. `java -cp BibliotecaUnesp-1.0-RELEASE.jar:lib/sqlite-jdbc-3.41.2.1.jar com.example.biblioteca.display.Main`
- OBS: É interessante mover o jar para o diretório raíz do projeto devido a localização do driver JDBC na pasta
  lib, além do caminho da localização do banco de dados na classe Main do projeto.

### Problemas
- Caso o programa dê algum erro no driver JDBC é interessante mudar o caminho do banco de dados dentro da classe
  Main e recompilar o projeto com o maven.

### Localização dos arquivos
- O código fonte fica localizado dentro da pasta 'src/main', com o banco de dados em 'resources' e os códigos 
  dentro de 'java/com/example/biblioteca'.
- O javadoc pode ser gerado pelo comando `mvn javadoc:javadoc`, e fica localizado dentro de 'target/site/apidocs'.
- manifest.txt e pom.xml são arquivos usados na compilação do projeto pelo maven.
 
