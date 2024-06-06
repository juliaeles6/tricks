// Adottak:
//   1. from[] - egy tömb/vektor, amelyben mindenkire benne van, hogy ki az őt megelőző
//   2. from[A] = -1

// Ahogyan én szoktam:

void print_path(int p) {
  // megállási feltétel: a csúcs, ahova érkeztem, tulajdonképpen nem is létezik
  // alternatív: p == A, ha nem kell a kezdőcsúcs
  if(p == -1) {
    return;
  }

  // apró trükk: előbb elmegyek az őt megelőző csúcsba. Ha azt befejeztem, akkor kiírom az aktuális csúcsot. Így a csúcsok sorrendben lesznek.
  print_path(from[p]);
  cout << p << ' ';
}

// Használat:
print_path(B);