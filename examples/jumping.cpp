// Adottak:
//  - x[] - tömb/vektor, amiben "tömbösítve" vannak számok; pl 1, 1, 1, 3, 5, 5, 2, 2, 2, 2, ...
//  - N - x hossza

void jump() {
  int i = 1;
  int j = 1;
  
  while(i <= N) {
    j = i;
    while(j + 1 <= N && x[j + 1] == x[i]) {
      ++j;
    }

    i = j + 1;
  }
}