// Scenario:
// You are building a text-based RPG game.
// You need to create a Hero object.
// The hero has a name, lives somewhere in memory, and has the ability to attack enemies.
// Requirements:
// The Blueprint (struct Hero):Create a structure named struct Hero.
// Inside it, create a function pointer method named attack.
// The attack method needs to take two parameters:
// a string for the enemy's name (e.g., "Goblin") and an integer for the damage points dealt (e.g., 45).
// The Function Behavior:Write a standalone function that matches your attack signature.
// Inside this function, print a message like: "[HERO] Attacked the Goblin for 45 damage!" (using the parameters passed to it).
// The Execution (main):Instantiate your hero object inside main.Bind your attack function to the object's method pointer.
// Execute the method by passing an enemy name and a damage value through the object.
#include<stdio.h>
struct Hero {
    void(*fighting)(const char *heroname,int health);
};
void fighting(char heroname[],int health) {
    while (health>=0){
        printf("\n%s acttaked Emu by 45 hp of his health by using gear 5th Nika form \n ",heroname);
        health=health-45;
        printf("\nAnd Now Emu s health is %d",health);
    }
}
int main(void) {
    struct Hero object;
    object.fighting=fighting;
    object.fighting("Luffy",1000);
}