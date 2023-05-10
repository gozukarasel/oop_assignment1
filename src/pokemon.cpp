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

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//
class pokemon
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon()
        {
            this->name=name;
            this->hpValue=hpValue;
            this->atkValue=atkValue;
        };
        pokemon(string neWname,int neWatkValue)
        {
            this->name = neWname;
            this-> atkValue= neWatkValue;
            this->hpValue =100;
        };
        pokemon(const pokemon &t)
        {
            this->name = t.name;
            this->atkValue = t.atkValue;
            this->hpValue = t.hpValue;
        };
        string get_name(){return this->name;};
        int get_hpValue(){return this->hpValue;};
        int get_atkValue(){return this->atkValue;};
};

class pokedex
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int position;
    public:
        pokedex() {this->position = 0;};
        void updatePokedex(pokemon newPokemon)
        {
            pokedexArray[position++] = newPokemon;
        }
        void printPokedex()
        {
            int size = sizeof(pokedexArray)/sizeof(pokedexArray[0]);

            cout<< "---------------Pokedex---------------"<<endl;

            for(int i = 0; i<size;i++)
            {
                cout<<pokedexArray[i].get_name()<<endl;
            }
        }     
};

class player
{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        player()
        {
            this->name = name;
            this->pokemonNumber = pokemonNumber;
            this->pokeballNumber = pokeballNumber;
            this->badgeNumber = badgeNumber;
        };
        player(string playername, pokemon playerPokemon)
        {
            this->pokemonNumber = 0;
            this->badgeNumber = 0;
            this->pokeballNumber = 10;
            this-> name = playername;
            this-> playerPokemon = playerPokemon;
        };
        int showPokeballNumber()
        {
            return this->pokeballNumber;
        };
        int showPokemonNumber()
        {
            return this->pokemonNumber;
        };
        int showBadgeNumber()
        {
            return this->badgeNumber;
        };
        pokemon get_pokemon()
        {
            return this->playerPokemon;
        }
        void battleWon()
        {

        }
        pokedex playerPokedex;
};

class enemy
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy()
        {
            this->name = name;
            this->enemyPokemon = enemyPokemon;
        };
        enemy(string neWname, pokemon neWenemyPokemon)
        {
            this->name = neWname;
            this->enemyPokemon = neWenemyPokemon;
        };
        string get_enemy_name() { return this->name;};
        pokemon get_enemy_pokemon() { return this->enemyPokemon;};
};
