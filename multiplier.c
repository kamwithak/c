 #include <stdio.h>

int mult(int x, int y);  //include data types in function prototype

int main()
{
  int x,y;
  printf( "Please input two numbers to be multiplied: " );
  scanf( "%d", &x );
  scanf( "%d", &y );
  printf( "The product of your two numbers is %d\n", mult(x,y) ); // dont include datatypes when calling function
  getchar(); 
}

int mult (int x, int y) // include data types when creating function
{
  return x * y;
}
