#ifndef TEMPO_H
#define TEMPO_H

// Arquivo de cabeçalho

class Tempo {
  // Membros privados
private:
  int hora, minuto, segundo; // Membros de dados

public:
  Tempo(); // Construtor - Inicializar
  Tempo(int, int, int);
  void setTempo(int, int, int);
  void imprime();
  ~Tempo(){ } // Destrutor
};

#endif // !TEMPO_H
