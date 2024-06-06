// Adottak:
//  - ok(i) - a függvény, ami eldönti, hogy az adott index megfelel-e
// cél - megtalálni az első indexet, ahol váltás van

int my_binary_search(int L, int R) {
  // megállási feltétel: ha összeért a két intervallum vége
  if(L == R) {
    return L;
  }

  // speciális eset
  if(L == R - 1) {
    if(ok(R)) {
      return R;
    }

    return L;
  }

  int M = (R - L) / 2 + L; // túlcsordulás miatt
  if(ok(M)) { // jobbra kell mennünk
    return my_binary_search(M, R);
  }
  else { // balra kell mennünk
    return my_binary_search(L, M - 1);
  }
}  

// Használat:
cout << my_binary_search(1, 9) << '\n';