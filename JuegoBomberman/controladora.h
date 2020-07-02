#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__

#include "mapa.h"
#include "jugador.h"
 
class CControladora{
public:
	CControladora(){
		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
	}
	 
	~CControladora(){}
	
	void cambiarNivel(){
		oEscenario->generarMatriz();
	}
	
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpJugador){
		oEscenario->pintarBase(g, bmpBase);
		oEscenario->generarMatriz(g, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador);
					
	}
	CJugador *getoJugador(){
		return oJugador;
	}

private:
	CEscenario *oEscenario;
	CJugador *oJugador;
	
};



#endif
