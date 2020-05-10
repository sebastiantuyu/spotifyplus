#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <time.h>
using namespace std;

struct user{
	string nickname;
	string pasw;
}usr_[5];

struct song{
	string artista;
	string sname;
	string duracion;
	int milisec;
}qsong[3];

void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int actualX, int actualY){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = actualX;
	dwPos.Y = actualY;
	SetConsoleCursorPosition(hcon,dwPos);
}

void color(int num){
	if(num==2){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void textC(char caracter,int color){
	//NEGRO  0
	//VERDE  1
	//BLANCO 2
	if(color==0){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);		
	}
	else if(color==1){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	
	}
	else if(color==2){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		
	}
	cout<<char(caracter);
}

void menu(){
	for(int j=0;j<2;j++){	
	for(int i=0;i<120;i++){
		gotoxy(i,(j*28));
		textC(219,1);
	}
	}
	
	for(int i=0;i<2;i++){
	for(int j=0;j<28;j++){	
	gotoxy((i*119),j);
	textC(219,1);
		}
	}
}

void logo1(int x,int y){
	ifstream m;
	m.open("spot.txt",ios::out);
	string uno;
	while(!m.eof()){
	m>>uno;
	}
	for(int j=0;j<(uno.length()-1);j+=16){
		for(int i=0;i<16;i++){
		if(uno[j+i]=='0'){
			//NEGRO
			gotoxy(x+i,y+(j/15));
			textC(219,0);
		}
		if(uno[j+i]=='1'){
			//VERDE
			gotoxy(x+i,y+(j/15));
			textC(219,1);
		}
		if(uno[j+i]=='2'){
			//BLANCO
			gotoxy(x+i,y+(j/15));	
			textC(219,2);
			}
		}
		
	}
}

void logo2(){
	int x=45,y=12;
	ifstream m;
	m.open("spotd.txt",ios::out);
	string uno;
	while(!m.eof()){
	m>>uno;
	}
	for(int j=0;j<(uno.length()-1);j+=29){
		for(int i=0;i<29;i++){
		if(uno[j+i]=='0'){
			//NEGRO
			gotoxy(x+i,y+(j/29));
			textC(219,0);
		}
		if(uno[j+i]=='1'){
			//VERDE
			gotoxy(x+i,y+(j/29));
			textC(219,1);
		}
		if(uno[j+i]=='4'){
			//VERDE
			gotoxy(x+i,y+(j/29));
			textC(169,1);
		}
		}
		
	}
}	

int sesion(string user,string pass){
	system("cls");
	int spass=0;
	
	int ok=0,pos;
	
	for(int i=0;i<5;i++){
	if(user.length()==usr_[i].nickname.length()){
		for(int j=0;j<user.length();j++){
			if(user[j]==usr_[i].nickname[j])
			pos=i;
			ok++;
		}
		if(ok==user.length()){
			spass=1;
		}
	}	
	}
	
	if(spass==1){
	ok=0;
	
	if(pass.length()==usr_[pos].pasw.length()){
		for(int j=0;j<pass.length();j++){
			if(pass[j]==usr_[pos].pasw[j])
			ok++;
		}
		if(ok==(pass.length())){
			return 1;
		}
		else if(ok!=pass.length()){
			return 0;
		}
		}	
		
		
		
	}
	else if(spass==0){
		cout<<"USUARIO NO ENCONTRADO"<<endl;
		return 0;
	}
	
}

int muestracanciones(){
	//obten nombre de canciones de base de datos y su duracion		
	for(int i=0;i<3;i++){
	gotoxy(23,5+(i*2));
	cout<<qsong[i].artista;
	gotoxy(45,5+(i*2));	
	cout<<qsong[i].sname;
	gotoxy(65,5+(i*2));
	cout<<"["<<i<<"]";
	}
	
}

void inicia(){
	gotoxy(51,12);
	cout<<"INICIAR SESION";
}

int escoje(){
	int numero;
	for(int i=0;i<28;i++){
	gotoxy(21,1+i);
	textC(219,1);
	}
	
	for(int i=0;i<28;i++){
	gotoxy(73,1+i);
	textC(219,1);
	}
	
	for(int i=0;i<53;i++){
	gotoxy(21+i,12);
	textC(219,1);
	}
	gotoxy(95,27);
	cout<<"PARA SALIR PULSE 3";
	gotoxy(23,2);
	cout<<"ARTISTA";
	gotoxy(40,2);
	cout<<"NOMBRE DE CANCION";
	gotoxy(65,2);
	cout<<"OPCION";
	
	
	do{
		gotoxy(66,11);
		cin>>numero;
	}while(numero>3);
	//INTRODUCE EL NOMBRE DE UNA CANCION
	switch(numero){
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
	}
}

void salir(){
	Sleep(2500);
}

void reproductor(int nums){
	color(2);
	ifstream letra;
	switch(nums){
		case 0:
			letra.open("0.txt");
			
		 break;
		case 1:
			letra.open("1.txt");
			
		 break;
		case 2:
			letra.open("2.txt");
			
		 break;
	}
	string lycris;
	int i=0;
	while(!letra.eof()){
		getline(letra,lycris);
		gotoxy(75,5+i);
		cout<<lycris;
		i++;
	}
	gotoxy(95,3);
	cout<<"LETRA";
	gotoxy(40,14);
	cout<<"REPRODUCIENDO";
	gotoxy(42,16);
	cout<<qsong[nums].sname;
	for(int i=0;i<45;i++){
		gotoxy(23+i,18);
	}
	
	
	float dur;
	dur = qsong[nums].milisec;
	//dur = 1000;
	dur = dur/45;
	
	for(int j=0;j<46;j++){
		gotoxy(25+j,19);
		textC(219,1);		
		Sleep(dur);
	}
	
}

void guarda(int reloj){
	ofstream play;
	play.open("record.txt",ios::out);
	play<<" Su tiempo de escucha del playlist fue de: "<<reloj<<" segundos";
}

int main(){
	char song[] = "nonstop.wav" ;
	char song2[] = "sourei.wav" ;
	char song3[] = "remainder.wav" ;
	int pr=0,spass=0,nums,final=0;
	string user,pass,dato_2,dato;
	fstream rolitas;
	fstream base;
	rolitas.open("canciones.csv");
	base.open("userpass.csv");
	
	/*---------------------------------------------------------------*/
	//INICIAR SESION RECUPERANDO INFORMACION PRIMERO	
		for (string recover; getline(base, recover); ){	
		stringstream registro(recover);
		for (int columna = 0; getline(registro, dato, ','); ++columna){
			switch (columna){
			case 0: //NICKNAME
					usr_[pr].nickname = dato;
					break;
			case 1: // PASSWORD
					usr_[pr].pasw = dato;
					break;
			}
		}
		pr++;
	}
	/*---------------------------------------------------------------*/
	int k=0;
	//RECUPERAR INFORMACION DE CANCIONES
		for (string recover_2; getline(rolitas, recover_2); ){	
		stringstream reg(recover_2);
		for (int columna = 0; getline(reg, dato_2, ','); ++columna){
			switch (columna){
			case 0: //DURACION
					qsong[k].artista = dato_2;
					break;
			case 1: //NOMBRE
					qsong[k].sname = dato_2;
					break;
			case 2: //DURACION
					qsong[k].duracion = dato_2;
					break;
			}
		}
		k++;
	}
	/*---------------------------------------------------------------*/
	
	
	
	//TIEMPOS DE CANCIONES
	for(int j=0;j<3;j++){
		stringstream enter(qsong[j].duracion);
		enter>>qsong[j].milisec;
	}
	/*---------------------------------------------------------------*/
	//INICIA
	menu();
	logo1(50,2);
	logo2();
	Sleep(1500);
	system("cls");
	menu();
	logo1(50,2);
	color(2);
	inicia();
	//INICIAR SESION	
	gotoxy(48,13);
	cout<<"Introduce tu usuario";
	gotoxy(50,14);
	cin>>user;
	gotoxy(48,15);
	cout<<"Introduce tu contrase"<<char(164)<<"a";
	gotoxy(50,16);
	cin>>pass;
	
	int correcto,reloj_time,reloj;
	correcto=sesion(user,pass);
	
	if(correcto==1){
	reloj_time = clock();
		do{	
		system("cls");
		menu();
		logo1(3,2);
		color(2);
		muestracanciones();
		gotoxy(5,12);
		cout<<user;
		nums = escoje();
		hidecursor();
		if(nums!=3){
			switch(nums){
				case 0:
			cout<<PlaySound((LPCSTR)song, NULL, SND_FILENAME | SND_ASYNC );
		 	break;
			case 1:
			cout<<PlaySound((LPCSTR)song2, NULL, SND_FILENAME | SND_ASYNC );
		 	break;
			case 2:
			cout<<PlaySound((LPCSTR)song3, NULL, SND_FILENAME | SND_ASYNC );
		 	break;
				
			}
		reproductor(nums);
		}else{
			final=1;
		}
		}while(final==0);
		correcto=1;
	}
	
	reloj = (clock() - reloj)/1000;
	guarda(reloj);
	system("pause");
	//MOSTRAR CANCIONES
	//REPORDUCTOR
	return 0;
}
