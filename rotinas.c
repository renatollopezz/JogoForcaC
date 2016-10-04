void mostrarTema(int op){
	char temas[7][12]={"Animais","Paises","Times de Futebol","Pokemons","Nomes","Frutas","Bandas"};

	printf("TEMA: %s",temas[op-1]);
}
void listarPalavras(int op,char retornoPalavras[][3][54]){
	int i,j,k,cont=0,random[3],randomValidar;
	char palavras[7][12][54]={"rato","boi","leao","vaca","macaco","cavalo","baleia","gato","tucano","leoa","girafa","cachorro","uruguai","brasil","russia","japao","china","italia","argentina","paraguai","venezuela","alemanha","franca","inglaterra","fast","flamengo","botafogo","gremio","vasco","palmeiras","fluminense","santos","corinthians","cruzeiro","sport","ceara","pikachu","ratata","charmander","dratine","dragoniti","zapdos","articuno","lapras","mew","mewtwo","chicorita","muk","renato","marcos","fernando","juliana","maria","lorena","adriano","leticia","michael","pedro","jefferson","marcelo","cereja","morango","laranja","uva","melancia","banana","pera","goiaba","maracuja","caju","cupuacu","tangerina","detonaltas","fresno","scalene","supercombo","radiohead","coldplay","gloria","oasis","hillsong","rouge","shinedown","Pitty"};	
        	srand( (unsigned)time(NULL) );			
			for(i=0;i<3;i++){
				random[i] = rand() % 11;	
			}
		    for (i = 0; i < 3; ++i) {
      			 do {
				random[i] = rand() % 11;	
   		  		     randomValidar = 1;
   	      			 for (j = 0; j < i; ++j)
           			  	if (random[i] == random[j])
   		   				    randomValidar = 0;
      			} while (randomValidar == 0);   
		    }
			for(i=0;i<3;i++){
				strcpy(retornoPalavras[0][i],palavras[op-1][random[i]]);
			}	
}

int selecionarOp(){
	char respostas[7][100];
	int op=0;
		printf("Escolha um tema:");
		printf("\n1-Animais\n2-Paises\n3-Times de Futebol\n4-Pokemons\n5-Nomes\n6-Frutas\n7-Bandas\n\nInforme sua opcao:");
		scanf("%d",&op);	
		while(op <= 0 || op > 7){	
			system("cls");
			printf("Opcao invalida!\n");
			printf("\n1-Animais\n2-Paises\n3-Times de Futebol\n4-Filmes\n5-Frutas\n6-Signos\n7-Desenhos\n\nInforme sua opcao:");
			scanf("%d",&op);
		}
		return op;
}
int validarJogada(char letra[],char letraJogada,int *cont){
int i,teste,j=0;//,validar=0;
		for(i=0;i<*cont;i++){
			 if(letraJogada == letra[i] && *cont > 0 ){

			 	printf("letra ja informada!\n\n");
				return 0;
			 }
		}
		*cont = *cont +1;
		return 1;
}
int carregarTelaRespostas(char letrasInformadas[],char palavras[][3][54],int cont,int op){
int i,j,k,w,tamanhoRespostas=0,totalAcertos=0;
int imprimir =0;
		for(i=0;i<1;i++){
			for(j=0;j<3;j++){
				for(k=0;k<strlen(palavras[i][j]);k++){
					tamanhoRespostas++;
					for(w=0;w<cont;w++){
						if (palavras[i][j][k]==letrasInformadas[w] ){
							printf("\t%c",letrasInformadas[w]);
							imprimir= 1;
							totalAcertos++;
						}
					}
					if(imprimir == 0){
						printf("\t__");
					}
					imprimir = 0;
				}
		printf("\n\n");
			}
		}
		mostrarTema(op);
	if(totalAcertos == tamanhoRespostas){
		return 1;
	}else{
		return 0;
	}
}
int validarErros(int qtdErros,char palavras[][3][54],char letraJogada){
int i,j,k,acertou =0;		
		for(i=0;i<1;i++){
			for(j=0;j<3;j++){
				for(k=0;k<strlen(palavras[i][j]);k++){
					if(palavras[i][j][k] == letraJogada){
						acertou = 1;
					}
				}
			}
		}
		if(acertou == 1){
			return qtdErros;
		}else{
			return qtdErros += 1;
		}
}	

int montarQuadroPalavras(char palavras[][3][54],int op){
int i,j,k,qtdErros=0,cont=0,statusJogo,novaPartida;
char letrasInformadas[26];
char letraJogada,letraJogada2;
		system("cls");
		printf("\n\n");
		for(i=0;i<1;i++){
			for(j=0;j<3;j++){
				for(k=0;k<strlen(palavras[i][j]);k++){
						printf("\t__");			
				}
			printf("\n\n");
			}
		}	
				mostrarTema(op);
	do{
			do{			
			printf("\nInforme a letra:");
			scanf(" %c",&letraJogada);
			letrasInformadas[cont]= letraJogada;
			}while(validarJogada(letrasInformadas,letraJogada,&cont) == 0);		
			system("cls");
		    statusJogo = carregarTelaRespostas(letrasInformadas,palavras,cont,op);
		    qtdErros = validarErros(qtdErros,palavras,letraJogada);
		    printf("\nTotal de erros: %d/7",qtdErros);
	}while(qtdErros <7 && statusJogo == 0);
		system("cls");
		if(statusJogo == 1){
			printf("\nParabens,voce acertou todoas as palavras!");
		}else{
			printf("\nVocê perdeu!");
		}
		do{
			printf("\nGostaria de jogar de novo ? 1-sim 2-nao\n");
			scanf("%d",&novaPartida);
			system("cls");
		}while(novaPartida < 1 || novaPartida >2);
		return novaPartida;
}
