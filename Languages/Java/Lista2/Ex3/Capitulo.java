public class Capitulo {
    private String titulo;
    private int numPag;
    private String sobrenomeAutor;

    public Capitulo(String titulo, int numPag, String sobrenomeAutor) {
        this.titulo = titulo;
        this.numPag = numPag;
        this.sobrenomeAutor = sobrenomeAutor;
    }

    public String getSobrenomeAutor() {
        return sobrenomeAutor;
    }

    public int getNumPag() {
        return numPag;
    }

    public String getTitulo() {
        return titulo;
    }
}
