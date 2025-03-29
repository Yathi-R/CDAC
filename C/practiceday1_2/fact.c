int fact(int n){
  long double f=1;
  for(int i=1; i<=n; i++){
    f *=i;
  }
  return f;
}
