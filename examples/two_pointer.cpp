// Adottak:
//  - x[] - tömb/vektor
//  - N - x hossza

void two_pointer() {
  int i = 1;
  int j = N;
  
  while(i <= j) {
    if(i_needs_to_move()) {
      ++i;
    }
    else if(j_needs_to_move()) {
      --j;
    }
    else if(both_needs_to_move()) {
      ++i;
      --j;
    }
  }
}