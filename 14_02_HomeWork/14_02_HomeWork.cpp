#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    string name;
    int damage;
    int health;
    int maxHealth;
    int armor;
    bool isAlive;
public:
    Character() : name("No name"), damage(0), health(0),
        maxHealth(0), armor(0), isAlive(false) {}
    Character(string n, int d, int h, int a)
        : name(n), damage(d), health(h),
        maxHealth(h), armor(a), isAlive(true) {}

    int Attack() {
        if (!isAlive) return 0;
        cout << "Attack with damage: " << damage << endl;
        return damage;
    }
    void TakeDamage(int d) {
        if (!isAlive) return;

        int receivedDamage = d - armor;
        if (receivedDamage < 0) receivedDamage = 0;
        cout << "Getting damage: " << receivedDamage << endl;
        health -= receivedDamage;
        if (health <= 0) {
            health = 0;
            isAlive = false;
            cout << name << " died!" << endl;
        }
    }
    void Heal(int h) {
        if (!isAlive) return;

        cout << "Healing with: " << h << endl;
        health += h;
        if (health > maxHealth)
            health = maxHealth;
    }
    void PrintInfo() {
        cout << "Name: " << name << endl;
        cout << "Damage: " << damage << endl;
        cout << "Health: " << health << '/' << maxHealth << endl;
        cout << "Armor: " << armor << endl;
        cout << "Alive: " << isAlive << endl;
    }
};


class Enemy : public Character {
public:
    int gold_reward;
    int experience_reward;

public:
    Enemy() : Character(), gold_reward(0), experience_reward(0) {}
    Enemy(string n, int d, int h, int a, int g, int e)
        : Character(n, d, h, a),
        gold_reward(g), experience_reward(e) {
    }

    void DropReward() {
        cout << "Dropping reward: " << gold_reward << " gold and " << experience_reward << " experience" << endl;
    }
};

class Goblin : public Enemy {
    int dodge_chance;
    int poison_damage;

public:
    Goblin() : Enemy(), dodge_chance(20), poison_damage(5) {}
    Goblin(string n, int d, int h, int a, int g, int e)
        : Enemy(n, d, h, a, g, e),
        dodge_chance(20), poison_damage(5) {
    }

    bool Dodge() {
        int chance = rand() % 100 + 1;

        if (chance <= dodge_chance) {
            cout << "Goblin dodged the attack!" << endl;
            return true;
        }
        return false;
    }
    int PoisonAttack() {
        cout << "Poison attack! Damage: "
            << damage + poison_damage << endl;

        return damage + poison_damage;
    }
};
class Skeleton : public Enemy {
    bool canRevive;

public:
    Skeleton() : Enemy(), canRevive(true) {}
    Skeleton(string n, int d, int h, int a, int g, int e)
        : Enemy(n, d, h, a, g, e), canRevive(true) {
    }

    void Revive() {
        if (canRevive && !isAlive) {
            canRevive = false;
            health = maxHealth / 2;
            isAlive = true;

            cout << "Skeleton revived!" << endl;
        }
        else {
            cout << "Skeleton cannot revive!" << endl;
        }
    }
    int BoneAttack() {
        cout << "Bone attack! Damage: " << damage + 5 << endl;
        return damage + 5;
    }
};
class Orc : public Enemy {
    int rage;
    bool isBerserk;

public:
    Orc() : Enemy(), rage(0), isBerserk(false) {}
    Orc(string n, int d, int h, int a, int g, int e)
        : Enemy(n, d, h, a, g, e),
        rage(0), isBerserk(false) {
    }

    int HeavyAttack() {
        if (!isAlive) return 0;

        rage += 10;

        cout << "Heavy attack! Damage: " << damage * 2 << endl;
        return damage * 2;
    }
    void Berserk() {
        if (rage >= 30 && !isBerserk) {
            isBerserk = true;
            damage *= 2;
            rage -= 30;

            cout << "Orc entered Berserk mode!" << endl;
        }
        else {
            cout << "Not enough rage or already Berserk!" << endl;
        }
    }
};
class Dragon : public Enemy {
    int fire_damage;

public:
    Dragon() : Enemy(), fire_damage(15) {}
    Dragon(string n, int d, int h, int a, int g, int e)
        : Enemy(n, d, h, a, g, e), fire_damage(15) {
    }

    int FireBreath() {
        cout << "Fire Breath! Damage: " << fire_damage << endl;
        return fire_damage;
    }
    int ClawAttack() {
        cout << "Claw attack! Damage: " << damage * 2 << endl;
        return damage * 2;
    }
};


class Hero : public Character {
protected:
    int gold;
    int experience;

public:
    Hero() : Character(), gold(0), experience(0) {}
    Hero(string n, int d, int h, int a, int g, int e)
        : Character(n, d, h, a), gold(g), experience(e) {
    }

    void CollectGold(int g) {
        gold += g;
        cout << "Collected gold: " << g << endl;
    }
    void DealDamage(Enemy& enemy, int d) {
        if (!isAlive || !enemy.isAlive) return;

        enemy.TakeDamage(d);
        if (!enemy.isAlive) {
            CollectGold(enemy.gold_reward);
            experience += enemy.experience_reward;
            cout << "Enemy defeated! Gained " << enemy.experience_reward << " experience." << endl;
            enemy.DropReward();
        }
    }
    void Attack(Enemy& enemy) {
        cout << "Hero attacks enemy!" << endl;
        DealDamage(enemy, Character::Attack());
    }
    void ShowStats() {
        PrintInfo();
        cout << "Gold: " << gold << endl;
        cout << "Experience: " << experience << endl;
    }
};

class Wizard : public Hero {
    int mana;
    int maxMana;
public:
    Wizard() : Hero(), mana(0), maxMana(0) {}
    Wizard(string n, int d, int h, int a, int m, int g, int e)
        : Hero(n, d, h, a, g, e), mana(m), maxMana(m) {
    }

    void Fireball(Enemy& enemy) {
        if (mana >= 10 && isAlive) {
            cout << "Casting Fireball!" << endl;
            DealDamage(enemy, 20);
            mana -= 10;
        }
        else cout << "Not enough mana!" << endl;
    }
    void IceSpell(Enemy& enemy) {
        if (mana >= 5 && isAlive) {
            cout << "Casting Ice Spell!" << endl;
            DealDamage(enemy, 10);
            mana -= 5;
        }
        else cout << "Not enough mana!" << endl;
    }
    void Lightning(Enemy& enemy) {
        if (mana >= 15 && isAlive) {
            cout << "Casting Lightning!" << endl;
            DealDamage(enemy, 30);
            mana -= 15;
        }
        else cout << "Not enough mana!" << endl;
    }
    void RestoreMana(int m) {
        mana += m;
        if (mana > maxMana) mana = maxMana;
    }
    void ShowStats() {
        Hero::ShowStats();
        cout << "Mana: " << mana << '/' << maxMana << endl;
    }
};
class Warrior : public Hero {
    int rage;
    int maxRage;
public:
    Warrior() : Hero(), rage(0), maxRage(0) {}
    Warrior(string n, int d, int h, int a, int m, int g, int e)
        : Hero(n, d, h, a, g, e), rage(m), maxRage(m) {
    }

    void Berserk(Enemy& enemy) {
        if (rage >= 10 && isAlive) {
            cout << "Entering Berserk mode!" << endl;
            DealDamage(enemy, 30);
            rage -= 10;
        }
        else cout << "Not enough rage!" << endl;
    }
    void PowerStrike(Enemy& enemy) {
        if (rage >= 5 && isAlive) {
            cout << "Performing Power Strike!" << endl;
            DealDamage(enemy, 20);
            rage -= 5;
        }
        else cout << "Not enough rage!" << endl;
    }
    void RestoreRage(int r) {
        rage += r;
        if (rage > maxRage) rage = maxRage;
    }
    void ShowStats() {
        Hero::ShowStats();
        cout << "Rage: " << rage << '/' << maxRage << endl;
    }
};
class Rogue : public Hero {
    int critical_chance;
    int dodge_chance;

public:
    Rogue() : Hero(), critical_chance(0), dodge_chance(0) {}
    Rogue(string n, int d, int h, int a, int g, int e, int c, int dc)
        : Hero(n, d, h, a, g, e),
        critical_chance(c), dodge_chance(dc) {
    }

    void CriticalAttack(Enemy& enemy) {
        if (!isAlive || !enemy.isAlive) return;

        int chance = rand() % 100 + 1;
        if (chance <= critical_chance) {
            cout << "Critical hit!" << endl;
            DealDamage(enemy, damage * 2);
        }
        else {
            cout << "Critical attack failed!" << endl;
            Attack(enemy);
        }
    }
    void Block(Enemy& enemy) {
        if (!isAlive || !enemy.isAlive) return;

        cout << "Blocking the attack!" << endl;
        int chance = rand() % 100 + 1;
        if (chance <= dodge_chance) {
            cout << "Dodged the attack!" << endl;
        }
        else {
            TakeDamage(enemy.Attack());
        }
    }
    void Backstab(Enemy& enemy) {
        if (!isAlive || !enemy.isAlive) return;
        cout << "Backstab!" << endl;
        DealDamage(enemy, damage * 3);
    }
};
class Paladin : public Hero {
    int mana;
    int max_mana;
    int holy_power;

public:
    Paladin() : Hero(), mana(0), max_mana(0), holy_power(0) {}
    Paladin(string n, int d, int h, int a, int m, int g, int e)
        : Hero(n, d, h, a, g, e),
        mana(m), max_mana(m), holy_power(10) {
    }

    void HolyStrike(Enemy& enemy) {
        if (mana >= 5 && isAlive) {
            cout << "Holy Strike!" << endl;
            DealDamage(enemy, damage + holy_power);
            mana -= 5;
        }
        else cout << "Not enough mana!" << endl;
    }
    void HealAlly(Character& ally) {
        if (mana >= 10 && isAlive) {
            cout << "Healing ally!" << endl;
            ally.Heal(holy_power);
            mana -= 10;
        }
        else cout << "Not enough mana!" << endl;
    }
    int HolyShield() {
        cout << "Holy shield activated!" << endl;
        return holy_power;
    }
    void ShowStats() {
        Hero::ShowStats();
        cout << "Mana: " << mana << '/' << max_mana << endl;
        cout << "Holy power: " << holy_power << endl;
    }
};

int main() {
    srand(time(0));

    // CHARACTER
    cout << "\n========== CHARACTER ==========\n";
    Character character("Test Character", 20, 100, 5);
    character.PrintInfo();
    character.TakeDamage(30);
    character.Heal(10);
    character.PrintInfo();


    // ENEMY
    cout << "\n========== ENEMY ==========\n";
    Enemy enemy("Enemy", 15, 100, 5, 50, 20);
    enemy.Attack();
    enemy.DropReward();
    enemy.PrintInfo();


    // GOBLIN
    cout << "\n========== GOBLIN ==========\n";
    Goblin goblin("Goblin", 10, 50, 2, 20, 10);
    goblin.PrintInfo();
    goblin.PoisonAttack();
    if (goblin.Dodge())
        cout << "Attack missed!\n";
    else
        cout << "Goblin failed to dodge!\n";


    // SKELETON
    cout << "\n========== SKELETON ==========\n";
    Skeleton skeleton("Skeleton", 15, 80, 5, 30, 15);
    skeleton.BoneAttack();
    skeleton.TakeDamage(100);
    skeleton.Revive();
    skeleton.PrintInfo();


    // ORC
    cout << "\n========== ORC ==========\n";
    Orc orc("Orc", 20, 150, 10, 50, 30);
    orc.HeavyAttack();
    orc.HeavyAttack();
    orc.HeavyAttack();

    orc.Berserk();
    orc.Attack();
    orc.PrintInfo();


    // DRAGON
    cout << "\n========== DRAGON ==========\n";
    Dragon dragon("Dragon", 40, 500, 20, 200, 100);
    dragon.FireBreath();
    dragon.ClawAttack();
    dragon.PrintInfo();


    // HERO
    cout << "\n========== HERO ==========\n";
    Hero hero("Hero", 20, 120, 10, 100, 50);
    Enemy target("Target", 10, 100, 0, 30, 15);
    hero.ShowStats();
    hero.Attack(target);
    hero.ShowStats();


    // WIZARD
    cout << "\n========== WIZARD ==========\n";
    Wizard wizard("Wizard", 10, 80, 2, 50, 0, 0);
    Enemy wizardTarget("Training Dummy", 5, 200, 0, 20, 10);
    wizard.ShowStats();
    wizard.Fireball(wizardTarget);
    wizard.IceSpell(wizardTarget);
    wizard.Lightning(wizardTarget);
    wizard.RestoreMana(20);
    wizard.ShowStats();


    // WARRIOR
    cout << "\n========== WARRIOR ==========\n";
    Warrior warrior("Warrior", 25, 150, 15, 20, 0, 0);
    Enemy warriorTarget("Training Dummy", 5, 200, 0, 20, 10);
    warrior.ShowStats();
    warrior.Berserk(warriorTarget);
    warrior.PowerStrike(warriorTarget);
    warrior.RestoreRage(10);
    warrior.ShowStats();


    // ROGUE
    cout << "\n========== ROGUE ==========\n";
    Rogue rogue("Rogue", 20, 100, 5, 0, 0, 100, 100);
    Enemy rogueTarget("Training Dummy", 5, 200, 0, 20, 10);
    rogue.ShowStats();
    rogue.CriticalAttack(rogueTarget);
    rogue.Backstab(rogueTarget);
    rogue.Block(rogueTarget);
    rogue.ShowStats();


    // PALADIN
    cout << "\n========== PALADIN ==========\n";
    Paladin paladin("Paladin", 20, 150, 15, 50, 0, 0);
    Character ally("Ally", 10, 50, 0);
    Enemy paladinTarget("Training Dummy", 5, 200, 0, 20, 10);
    paladin.ShowStats();
    paladin.HolyStrike(paladinTarget);
    paladin.HealAlly(ally);
    paladin.HolyShield();
    ally.PrintInfo();
    paladin.ShowStats();
}
