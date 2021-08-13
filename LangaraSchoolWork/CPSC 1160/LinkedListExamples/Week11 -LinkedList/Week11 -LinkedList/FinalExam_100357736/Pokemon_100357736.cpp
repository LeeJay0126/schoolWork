#include "Pokemon_100357736.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Pokemon::Pokemon(){
    
}

Pokemon::~Pokemon(){
    
}

void Pokemon::setName(string name){
    this->name = name;
}

void Pokemon::setTotal(int total){
    this->total = total;
}

void Pokemon::setHp(int hp){
    this->hp = hp;
}

void Pokemon::setAttack(int attack){
    this->attack = attack;
}

void Pokemon::setDefence(int defence){
    this->defence = defence;
}

void Pokemon::setSpeed(int speed){
    this->speed = speed;
}

string Pokemon::getName() const{
    return name;
}

int Pokemon::getTotal() const{
    return total;
}

int Pokemon::getHp() const{
    return hp;
}

int Pokemon::getAttack() const{
    return attack;
}

int Pokemon::getDefence() const{
    return defence;
}

int Pokemon::getAtkSpeed() const{
    return atkSpeed;
}

int Pokemon::getSpDefence() const{
    return spDefence;
}

int Pokemon::getSpeed() const{
    return speed;
}

void Pokemon::operator<<(Pokemon n){
    cout << setw(15) << n.getName() << setw(10) << n.getTotal() << setw(10) << n.getHp() << setw(10) << n.getAttack() << setw(10) << n.getDefence() << setw(10) << n.getSpeed() << endl;
}