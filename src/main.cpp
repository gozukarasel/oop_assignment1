//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"


//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string,int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void fightMenu();
//void catchPokemon(player*, string*);
//------------------------------------------------------------------//

const char* enemyNamestxt = "enemyNames.txt";
const char* pokemonNamestxt ="pokemonNames.txt";

int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            //catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE; 
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv) // pushlarken bunu değiştirmeyi unutma 
{
    ifstream inFile;
    inFile.open("enemyNames.txt");

    string firstLine;    
    getline(inFile,firstLine);
    int intdata = stoi (firstLine);

    string* enemyNames = new string[intdata];
    
    string name;
    int counter=0;


    while (getline(inFile, name)) {
        enemyNames[counter] = name;
        counter++;
    }
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv)
{
    ifstream fileName;
    fileName.open("pokemonNames.txt");

    string firstLine;    
    getline(fileName,firstLine);
    int intdata = stoi (firstLine);

    string* pokemonNames = new string[intdata];
    
    string name;
    int counter =0;
    

    while (getline(fileName, name)) {
        pokemonNames[counter] = name;
        counter++;
    }
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice)
{    
    if(pokemonChoice == 1)
    {
        pokemon p("Bulbasaur",PLAYER_POKEMON_ATTACK);
        pokemon Bulbasaur(p);
        player player(playerName,Bulbasaur);
        return player;
    }
    if (pokemonChoice == 2)
    {
        pokemon p("Charmender",PLAYER_POKEMON_ATTACK);
        pokemon Charmender(p);
        player player(playerName,Charmender);
        return player;
    }
    if (pokemonChoice == 3)
    {
        pokemon p("Squirtle",PLAYER_POKEMON_ATTACK);
        pokemon Squirtle(p);
        player player(playerName,Squirtle);
        return player;
    }
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
void fightMenu()
{
    cout << endl;
    cout << "1-Fight"<<endl;
    cout << "2-Runaway"<<endl;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames)
{   
    pokemon enemyPokemon(pokemonNames[0],ENEMY_POKEMON_ATTACK);
    enemy* newEnemy = new enemy(enemyNames[0],enemyPokemon);

    int player_pokemon_fight_health = newPlayer->get_pokemon().get_hpValue();
    int player_pokemon_attack_value = newPlayer->get_pokemon().get_atkValue();

    int enemy_pokemon_fight_health = newEnemy->get_enemy_pokemon().get_hpValue();
    int enemy_pokemon_fight_attack_value = newEnemy->get_enemy_pokemon().get_atkValue();

    int fightChoice;

    cout<< "You encounter with " << newEnemy->get_enemy_name() << " and his/hers pokemon "<< newEnemy->get_enemy_pokemon().get_name() <<endl;
    cout<< newEnemy->get_enemy_pokemon().get_name() << " Health: "<< newEnemy->get_enemy_pokemon().get_hpValue() << " Attack: " << newEnemy->get_enemy_pokemon().get_atkValue() <<endl;

    cout<<endl;

    
    while(player_pokemon_fight_health > 0 && enemy_pokemon_fight_health > 0)
    {
        fightMenu();
        cin>>fightChoice;
        
        cout<<endl;
        
        cout << "Choice: " << fightChoice << endl;

        switch(fightChoice)
        {
            case 1:
                player_pokemon_fight_health = player_pokemon_fight_health - enemy_pokemon_fight_attack_value;
                enemy_pokemon_fight_health = enemy_pokemon_fight_health - player_pokemon_attack_value;

                cout << "Your Pokemons health: " << player_pokemon_fight_health << endl;
                cout << newEnemy->get_enemy_name() << " Pokemons health:" << enemy_pokemon_fight_health << endl;

                if(enemy_pokemon_fight_health<=0)
                {
                    cout << "You Won!"<< endl;
                    newPlayer->set_badge_number(1);
                    
                    if(!newPlayer->playerPokedex.checkPokedex(enemyPokemon))
                    {
                        newPlayer->playerPokedex.updatePokedex(enemyPokemon);
                    }
                    delete newEnemy;
                }
                if(player_pokemon_fight_health <= 0)
                {
                    delete newPlayer;
                }
                break;
            case 2:
                break;
            default:
                break;
        }
    }   
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    //---Code Here---//
    // 
    //
    //
    //---------------//
};
//--------------------------------------------//
