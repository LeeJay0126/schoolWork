#ifndef POKEMON_100357736H
#define POKEMON_100357736H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Pokemon{
    public:
        Pokemon();
        ~Pokemon();
        void setName(string name);
        void setTotal(int total);
        void setHp(int hp);
        void setAttack(int attack);
        void setDefence(int defence);
        void setAtkSpeed(int atkSpeed);
        void setSpDefence(int spDefence);
        void setSpeed(int speed);
        string getName() const;
        int getTotal() const;
        int getHp() const;
        int getAttack() const;
        int getDefence() const;
        int getAtkSpeed() const;
        int getSpDefence() const;
        int getSpeed() const;
        void operator<<(Pokemon n);
        Pokemon * next;
        Pokemon * previous;
        
    private:
        string name;
        int total;
        int hp;
        int attack;
        int defence;
        int atkSpeed;
        int spDefence;
        int speed;
        
};
#endif