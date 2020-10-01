int main()
{
  int a = 1;

  switch ( a ) {
    case 1:
      a = 10;
      break;
    case 2:
      a = 20;
      break;
    case 3:
      a = 50;
      break;
    default: 
      a = 100;
      break;
  }
  return a;
}
