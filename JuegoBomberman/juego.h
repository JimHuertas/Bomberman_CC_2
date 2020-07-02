#pragma once
#include "controladora.h"
namespace JuegoBomberman{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	

	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		CControladora *oControladora=new CControladora();
		Bitmap^bmpSolido=gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^bmpDestruible=gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^bmpSuelo=gcnew Bitmap("Imagenes\\bmpSuelo.png"); 
		Bitmap^bmpJugador=gcnew Bitmap("Imagenes\\Juganod.png")
		Juego(void){
			InitializeComponent();
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0,0));
		}
	protected:
		~Juego(){
			if(components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private:System::ComponentsModel::IContainer^ components;
	
	private:
		
#pragma region Windows Form Designer generated code
	void InitializeComponent(void);
	{
		this->components = (gcnew System::ComponentsModel::Container());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		
		//timer 1
		
		this->timer1->Enable = true;
		this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
		
		//juego
		
		this->AutoScaleDimensions = Sytem::Drawing::Sizeof(6, 13);
		this->AutoScalMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(405,402);
		this->Name = L"Juego";
		this->Text = L"Juego";
		this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
		this->ResumeLayout(false);
	}
#pragma endregion 
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e){
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsMananger::Current;
		BufferedGraphics^buffer=espacio->Allocate(g,this->ClientRectangule);
		oControladora->cambiarNivel();
		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDestruible, bmpJugador); 
		buffer->Render(g);
		delete buffer, espacio, g; 
	}

	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e){
		oControladora->cambiarNivel();
	}
	
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
		switch (e->KeyCode)
		{
		case Keys::Up:
			oControladora->getoJugador()->setDireccion(Direccion::Arriba);
			break;
		case Keys::Down:
			oControladora->getoJugador()->setDireccion(Direccion::Abajo);
			break;
		case Keys::Right:
			oControladora->getoJugador()->setDireccion(Direccion::Derecha);
			break;
		case Keys::Left:
			oControladora->getoJugador()->setDireccion(Direccion::Izquierda);
			break;
		default:
			break;
		}
	}
	
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
		switch(e->KeyCode){
		default:
			oControladora->getoJugador()->setDireccion(Direccion::Ninguna);
			break;
		}
	}
		
	};
}












