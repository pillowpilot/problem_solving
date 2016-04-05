#include <iostream>
#include <queue>

using namespace std;

typedef unsigned long long ull;

int main(){
  int test; // Cantidad de test cases
  ull ferry_length; // Longitud del ferry
  
  cin >> test; // Entrada de un int
  while( test-- > 0 ){
    queue<ull> left, right; // Colas
    int m; // cantidad de lineas de datos
    
    cin >> ferry_length >> m;
    ferry_length *= 100; // de metros a cm
    while( m-- > 0 ){ // leemos los datos
      ull length;
      string side;
      cin >> length >> side;
      if( side == "right" ){ // Si esta del lado de la derecha, a la cola de la derecha
	right.push(length);
	//cout << ">> " << length << " - right" << endl;
      }else{
	left.push(length);
	//cout << ">> " << length << " - left" << endl;
      }
    }

    int travels = 0; // Viajes
    while( !right.empty() || !left.empty() ){
      ull load = 0; //Carga del ferry
      // empezamos a la izquierda
      while( !left.empty() && load + left.front() <= ferry_length ){
	// Si podemos cargar mas...
	load += left.front(); // ...cargamos
	left.pop(); // Eliminamos ese auto
      }
      //cout << "To right with " << load << endl;
      travels++; // Viajamos
      // Travels to the other side...
      load = 0; // Descargamos
      if( !left.empty() || !right.empty() ){
	// Si existe algo que transportar
	while( !right.empty() && load + right.front() <= ferry_length ){
	  load += right.front(); //Cargamos
	  right.pop();
	}
	// viamajos
	travels++;
	//cout << "To left with " << load << endl;
      }
    }
    // Imprimimos la salida (los viajes)
    cout << travels << endl;
  }
  
  return 0;
}

// AC
