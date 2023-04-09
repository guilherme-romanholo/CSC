public class Main {
    public static void main(String[] args) {
        Livro livro = new Livro("Torvalds","Linguagens de Programação",2023,1,50.0);
        Capitulo jv = new Capitulo("Java",100,"Romanholo");
        Capitulo c = new Capitulo("C",100,"Romanholo");
        Capitulo py = new Capitulo("Python",80,"Romanholo");

        livro.insereCapitulo(jv);
        livro.insereCapitulo(c);
        livro.insereCapitulo(py);

        livro.imprimirInformações();
    }
}
