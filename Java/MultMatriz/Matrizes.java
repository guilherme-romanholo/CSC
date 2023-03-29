public class Matrizes {
    private int lin = 0;
    private int col = 0;
    private double[][] mat;

    public void setCol(int c){
        this.col = c;
    }

    public void setLin(int l){
        this.lin = l;
    }

    public int getCol() {
        return this.col;
    }

    public int getLin() {
        return this.lin;
    }

    public void alloc() {
        if (this.lin == 0 || this.col == 0){
            System.out.println("Matriz sem linhas ou colunas");
        } else {
            this.mat = new double[this.lin][this.col];
        }
    }
    
    public void printMat() {
        for (int i = 0; i < this.lin; i++){
            for (int j = 0; j < this.col; j++){
                System.out.print(this.mat[i][j] + " ");
            } 
            System.out.println();
        }
    }

    public double getMat(int lin, int col) {
        return this.mat[lin][col];
    }

    public void setMat(int lin, int col, double val) {
        this.mat[lin][col] = val;
    }

    public void multMat(Matrizes mat2){
        try {
            if (this.col != mat2.getLin()){
                throw new Exception("Matrizes incompatíveis.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        int soma;

        for (int i = 0; i < this.lin; i++) {
            for (int j = 0; j < mat2.getCol() ; j++) {
                soma = 0;
                for (int k = 0; k < mat2.getLin(); k++) {
                    soma += this.mat[i][k] * mat2.getMat(k, j);
                } 
                System.out.print(soma + " ");   
            }
            System.out.println();
        }
    }
}
