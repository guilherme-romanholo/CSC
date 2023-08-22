import java.util.ArrayList;

public class Livro {
    private String sobrenomeEditor;
    private String tituloLivro;
    private int ano;
    private int edicao;
    private double preco;
    private ArrayList<Capitulo> capitulos;

    public Livro(String sobrenomeEditor, String tituloLivro, int ano, int edicao, double preco) {
        this.sobrenomeEditor = sobrenomeEditor;
        this.tituloLivro = tituloLivro;
        this.ano = ano;
        this.edicao = edicao;
        this.preco = preco;
        this.capitulos = new ArrayList<>();
    }

    public void insereCapitulo(Capitulo capitulo) {
        this.capitulos.add(capitulo);
    }

    public void imprimirInformações() {
        System.out.printf("Editor: %s\n",this.sobrenomeEditor);
        System.out.printf("Título: %s\n",this.tituloLivro);
        System.out.printf("Ano: %d\n",this.ano);
        System.out.printf("Edição: %s\n",this.edicao);
        System.out.printf("Preço: %.2f\n",this.preco);
        System.out.println("Capítulos:");
        this.imprimirCapitulos();
    }

    public void imprimirCapitulos() {
        for (Capitulo cap : this.capitulos) {
            System.out.println("==================");
            System.out.printf("Título: %s\n",cap.getTitulo());
            System.out.printf("Autor: %s\n",cap.getSobrenomeAutor());
            System.out.printf("Número de páginas: %d\n",cap.getNumPag());
            System.out.println("==================");
        }
    }

}
